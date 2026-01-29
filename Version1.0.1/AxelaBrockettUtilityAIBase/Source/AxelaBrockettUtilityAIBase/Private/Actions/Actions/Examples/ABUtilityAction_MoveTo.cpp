// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Actions/Actions/Examples/ABUtilityAction_MoveTo.h"

#include "AIController.h"
#include "AISystem.h"
#include "Components/ABUtilityComponent.h"
#include "Engine/World.h"
#include "EnvironmentQuery/EnvQuery.h"
#include "EnvironmentQuery/EnvQueryManager.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "NavFilters/NavigationQueryFilter.h"
#include "Navigation/PathFollowingComponent.h"
#include "VisualLogger/VisualLogger.h"

#if WITH_GAMEPLAY_DEBUGGER_MENU
#include "GameplayDebuggerCategory.h"
#include "GameplayDebuggerTypes.h"
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

UABUtilityAction_MoveTo::UABUtilityAction_MoveTo()
{
	QueryFinishedDelegate = FQueryFinishedSignature::CreateUObject(this, &UABUtilityAction_MoveTo::OnEQSFinished);

	AllowPartialPath.DefaultValue = GET_AI_CONFIG_VAR(bAcceptPartialPaths);
	AllowStrafe.DefaultValue = GET_AI_CONFIG_VAR(bAllowStrafing);
	ReachTestIncludesAgentRadius.DefaultValue = ReachTestIncludesGoalRadius.DefaultValue = GET_AI_CONFIG_VAR(bFinishMoveOnGoalOverlap);
	RequireNavigableEndLocation.DefaultValue = true;
	ProjectGoalLocation.DefaultValue = true;
	UsePathFinding.DefaultValue = true;
	StartFromPreviousPath.DefaultValue = false;
	const float AcceptanceRadius = GET_AI_CONFIG_VAR(AcceptanceRadius);
	AcceptableRadius.DefaultValue = AcceptanceRadius;
}

// Pause, resume and abort logic

void UABUtilityAction_MoveTo::PauseAction(UABUtilityComponent* OwnerComp, const FString& Reason)
{
	if (!IsValid(OwnerComp))
	{
		UE_VLOG_UELOG(
			this,
			LogABUtility,
			Warning,
			TEXT("%s - Move To action [ %s ] has an invalid Utility Component owner."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*GetName()
		);
		return;
	}

	if (!ActionMemory.RequestID.IsValid())
	{
		UE_VLOG_UELOG(
			OwnerComp->GetOwner(),
			LogABUtility,
			Warning,
			TEXT("%s - Stored Move Request ID is invalid for Move To action [ %s ] owned by Utility Component [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*GetName(),
			*OwnerComp->GetName()
		);
		return;
	}

	AAIController* const AIController = OwnerComp->GetAIOwner();
	if (!IsValid(AIController))
	{
		UE_VLOG_UELOG(
			OwnerComp->GetOwner(),
			LogABUtility,
			Warning,
			TEXT("%s - Move To action owned by Utility Component [ %s ] does not have a valid owning AI Controller."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*OwnerComp->GetName()
		);
		return;
	}

	UPathFollowingComponent* const PathFollowingComp = AIController->GetPathFollowingComponent();
	if (!IsValid(PathFollowingComp))
	{
		UE_VLOG_UELOG(
			AIController,
			LogABUtility,
			Warning,
			TEXT("%s - AI Controller [ %s ] owning Utility Component [ %s ] running Move To action [ %s ] does not have a valid Path Following Component."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*AIController->GetName(),
			*OwnerComp->GetName(),
			*GetName()
		);
		return;
	}

	AbortMoveOnPause.BindData(AIController->GetPawn(), INDEX_NONE);
	const bool bAbortMoveOnPauseValue = AbortMoveOnPause.GetValue();

	if (bAbortMoveOnPauseValue)
	{
		PathFollowingComp->AbortMove(*this, FPathFollowingResultFlags::OwnerFinished, ActionMemory.RequestID, EPathFollowingVelocityMode::Reset);
		OnMoveFinished(ActionMemory.RequestID, FPathFollowingResult(EPathFollowingResult::Aborted, FPathFollowingResultFlags::OwnerFinished));
	}
	else
	{
		PathFollowingComp->PauseMove(ActionMemory.RequestID, EPathFollowingVelocityMode::Reset);
	}

	Super::PauseAction(OwnerComp, Reason);
}

bool UABUtilityAction_MoveTo::ResumeAction(UABUtilityComponent* OwnerComp)
{
	if (!IsValid(OwnerComp))
	{
		UE_VLOG_UELOG(
			this,
			LogABUtility,
			Warning,
			TEXT("%s - Move To action [ %s ] has an invalid Utility Component owner."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*GetName()
		);
		return false;
	}

	AAIController* const AIController = OwnerComp->GetAIOwner();
	if (!IsValid(AIController))
	{
		UE_VLOG_UELOG(
			OwnerComp->GetOwner(),
			LogABUtility,
			Warning,
			TEXT("%s - Move To action owned by Utility Component [ %s ] does not have a valid owning AI Controller."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*OwnerComp->GetName()
		);
		return false;
	}

	UPathFollowingComponent* const PathFollowingComp = AIController->GetPathFollowingComponent();
	if (!IsValid(PathFollowingComp))
	{
		UE_VLOG_UELOG(
			AIController,
			LogABUtility,
			Warning,
			TEXT("%s - AI Controller [ %s ] owning Utility Component [ %s ] running Move To action [ %s ] does not have a valid Path Following Component."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*AIController->GetName(),
			*OwnerComp->GetName(),
			*GetName()
		);
		return false;
	}

	AbortMoveOnPause.BindData(AIController->GetPawn(), INDEX_NONE);
	const bool bAbortMoveOnPauseValue = AbortMoveOnPause.GetValue();

	if (!bAbortMoveOnPauseValue && ActionMemory.RequestID.IsValid())
	{
		// We paused the move before and now we're resuming it
		PathFollowingComp->ResumeMove(ActionMemory.RequestID);
		return Super::ResumeAction(OwnerComp);
	}

	switch (MoveToTargetType)
	{
		case (EABUtilityAction_MoveToTypes::EQSGeneratedPoint):
		{
			check(IsValid(PointGenerationEQS));
			CurrentRunStatus = StartEQS(*PointGenerationEQS, *AIController);
			break;
		}
		case (EABUtilityAction_MoveToTypes::EQSGeneratedActor):
		{
			check(IsValid(ActorGenerationEQS));
			CurrentRunStatus = StartEQS(*ActorGenerationEQS, *AIController);
			break;
		}
		case (EABUtilityAction_MoveToTypes::ActorOfType):
		{
			CurrentRunStatus = StartMoveTowardsActorOfClass(*AIController);
			break;
		}
		default:
		{
			UE_VLOG_UELOG(
				AIController,
				LogABUtility,
				Error,
				TEXT("%s - Invalid Move To Target Type for Move To action [ %s ] owned by Utility Component [ %s ]."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*GetName(),
				*OwnerComp->GetName()
			);
			CurrentRunStatus = EABUtilityActionRunStatus::Failed;
			return false;
			break;
		}
	}

	return Super::ResumeAction(OwnerComp);
}

void UABUtilityAction_MoveTo::AbortAction(UABUtilityComponent* OwnerComp, const FString& Reason)
{
	if (!IsValid(OwnerComp))
	{
		UE_VLOG_UELOG(
			this,
			LogABUtility,
			Warning,
			TEXT("%s - Move To action [ %s ] has an invalid Utility Component owner."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*GetName()
		);
		return;
	}

	if (!ActionMemory.RequestID.IsValid())
	{
		UE_VLOG_UELOG(
			OwnerComp->GetOwner(),
			LogABUtility,
			Warning,
			TEXT("%s - Stored Move Request ID is invalid for Move To action [ %s ] owned by Utility Component [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*GetName(),
			*OwnerComp->GetName()
		);
		return;
	}

	AAIController* const AIController = OwnerComp->GetAIOwner();
	if (!IsValid(AIController))
	{
		UE_VLOG_UELOG(
			OwnerComp->GetOwner(),
			LogABUtility,
			Warning,
			TEXT("%s - Move To action owned by Utility Component [ %s ] does not have a valid owning AI Controller."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*OwnerComp->GetName()
		);
		return;
	}

	UPathFollowingComponent* const PathFollowingComp = AIController->GetPathFollowingComponent();
	if (!IsValid(PathFollowingComp))
	{
		UE_VLOG_UELOG(
			AIController,
			LogABUtility,
			Warning,
			TEXT("%s - AI Controller [ %s ] owning Utility Component [ %s ] running Move To action [ %s ] does not have a valid Path Following Component."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*AIController->GetName(),
			*OwnerComp->GetName(),
			*GetName()
		);
		return;
	}

	PathFollowingComp->AbortMove(*this, FPathFollowingResultFlags::OwnerFinished, ActionMemory.RequestID);
	OnMoveFinished(ActionMemory.RequestID, FPathFollowingResult(EPathFollowingResult::Aborted, FPathFollowingResultFlags::OwnerFinished));
	Super::AbortAction(OwnerComp, Reason);
}

/*
* Validation
*/

const bool UABUtilityAction_MoveTo::ValidateAction(FString& InvalidationReason) const
{
	bool bIsValid = Super::ValidateAction(InvalidationReason);

	// Validate the EQS or actor subclass according to the chosen target type
	switch (MoveToTargetType)
	{
		case (EABUtilityAction_MoveToTypes::EQSGeneratedPoint):
		{
			if (!IsValid(PointGenerationEQS))
			{
				InvalidationReason +=
					FString::Printf(
						TEXT("Move To Target Type is EQS Generated Point but Point Generation EQS is not valid\n")
					);
				bIsValid = false;
			}
			break;
		}
		case (EABUtilityAction_MoveToTypes::EQSGeneratedActor):
		{
			if (!IsValid(ActorGenerationEQS))
			{
				InvalidationReason +=
					FString::Printf(
						TEXT("Move To Target Type is EQS Generated Actor but Actor Generated EQS is not valid\n")
					);
				bIsValid = false;
			}
			break;
		}
		case (EABUtilityAction_MoveToTypes::ActorOfType):
		{
			if (!IsValid(ActorSubclass))
			{
				InvalidationReason +=
					FString::Printf(
						TEXT("Move To Target Type is Actor Of Type but Actor Subclass is not valid\n")
					);
				bIsValid = false;
			}
			break;
		}
	}

	// Validate the acceptance radius
	AcceptableRadius.BindData(this, INDEX_NONE);
	if (AcceptableRadius.GetValue() < 0.0f)
	{
		InvalidationReason += FString::Printf(TEXT("Acceptance Radius is less than 0\n"));
		bIsValid = false;
	}

	// Validate the tracking movement tolerance
	ActorTrackingGoalMovementTolerance.BindData(this, INDEX_NONE);
	if (ActorTrackingGoalMovementTolerance.GetValue() < 1.0f)
	{
		InvalidationReason += FString::Printf(TEXT("Actor Tracking Goal Movement Tolerance is less than 1\n"));
		bIsValid = false;
	}

	return bIsValid;
}

/*
* Debugging
*/

#if WITH_GAMEPLAY_DEBUGGER_MENU
void UABUtilityAction_MoveTo::DescribeSelfToGameplayDebugger(const UABUtilityComponent& OwnerComp, const bool bUseConsiderationFactor, FGameplayDebuggerCategory* DebuggerCategory) const
{
	if (DebuggerCategory == nullptr)
	{
		return;
	}

	Super::DescribeSelfToGameplayDebugger(OwnerComp, bUseConsiderationFactor, DebuggerCategory);

	const AAIController* const AIController = OwnerComp.GetAIOwner();
	if (IsValid(AIController))
	{
		const APawn* const AIPawn = AIController->GetPawn();
		AllowPartialPath.BindData(AIPawn, INDEX_NONE);
		AllowStrafe.BindData(AIPawn, INDEX_NONE);
		ReachTestIncludesAgentRadius.BindData(AIPawn, INDEX_NONE);
		ReachTestIncludesGoalRadius.BindData(AIPawn, INDEX_NONE);
		RequireNavigableEndLocation.BindData(AIPawn, INDEX_NONE);
		ProjectGoalLocation.BindData(AIPawn, INDEX_NONE);
		UsePathFinding.BindData(AIPawn, INDEX_NONE);
		StartFromPreviousPath.BindData(AIPawn, INDEX_NONE);
		TrackMovingActor.BindData(AIPawn, INDEX_NONE);
		AbortMoveOnPause.BindData(AIPawn, INDEX_NONE);
		AcceptableRadius.BindData(AIPawn, INDEX_NONE);
		ActorTrackingGoalMovementTolerance.BindData(AIPawn, INDEX_NONE);
	}

	DebuggerCategory->AddTextLine(
		FString::Printf(TEXT("        {green}Move To Target Type: %s / Point Generation EQS: %s / Actor Generation EQS: %s / EQS Run Mode: %s / Actor Subclass: %s / Filter Class: %s"),
			MoveToTargetType == EABUtilityAction_MoveToTypes::EQSGeneratedPoint ? TEXT("EQS Generated Point") :
			MoveToTargetType == EABUtilityAction_MoveToTypes::EQSGeneratedActor ? TEXT("EQS Generated Actor") :
			MoveToTargetType == EABUtilityAction_MoveToTypes::ActorOfType ? TEXT("Actor Of Type") :
			TEXT("None"),
			*GetNameSafe(PointGenerationEQS),
			*GetNameSafe(ActorGenerationEQS),
			RunMode == EEnvQueryRunMode::AllMatching ? TEXT("All Matching") :
			RunMode == EEnvQueryRunMode::RandomBest25Pct ? TEXT("Random From Best 25 Percent") :
			RunMode == EEnvQueryRunMode::RandomBest5Pct ? TEXT("Random From Best 5 Percent") :
			RunMode == EEnvQueryRunMode::SingleResult ? TEXT("Single Result") :
			TEXT("None"),
			*GetNameSafe(ActorSubclass),
			*GetNameSafe(FilterClass)
		)
	);

	DebuggerCategory->AddTextLine(
		FString::Printf(TEXT("        {green}Allow Partial Path: %s / Allow Strafe: %s / Reach Test Includes Agent Radius: %s / Reach Test Includes Goal Radius: %s / Require Navigable End Location  : %s / Project Goal Location: %s"),
			AllowPartialPath.GetValue() ? TEXT("true") : TEXT("false"),
			AllowStrafe.GetValue() ? TEXT("true") : TEXT("false"),
			ReachTestIncludesAgentRadius.GetValue() ? TEXT("true") : TEXT("false"),
			ReachTestIncludesGoalRadius.GetValue() ? TEXT("true") : TEXT("false"),
			RequireNavigableEndLocation.GetValue() ? TEXT("true") : TEXT("false"),
			ProjectGoalLocation.GetValue() ? TEXT("true") : TEXT("false")
		)
	);

	DebuggerCategory->AddTextLine(
		FString::Printf(TEXT("        {green}Use Path Finding: %s / Start From Previous Path: %s / Track Moving Actor: %s / Abort Move On Pause: %s / Acceptable Radius: %f / Actor Tracking Goal Movement Tolerance: %f"),
			UsePathFinding.GetValue() ? TEXT("true") : TEXT("false"),
			StartFromPreviousPath.GetValue() ? TEXT("true") : TEXT("false"),
			TrackMovingActor.GetValue() ? TEXT("true") : TEXT("false"),
			AbortMoveOnPause.GetValue() ? TEXT("true") : TEXT("false"),
			AcceptableRadius.GetValue(),
			ActorTrackingGoalMovementTolerance.GetValue()
		)
	);

	if (CurrentRunStatus == EABUtilityActionRunStatus::Running)
	{
		DebuggerCategory->AddShape(FGameplayDebuggerShape::MakePoint(ActionMemory.StartLocation, 10.0f, FColor::Green, FString::Printf(TEXT("Start Location"))));
		DebuggerCategory->AddShape(FGameplayDebuggerShape::MakePoint(ActionMemory.MoveReq.GetDestination(), 10.0f, FColor::Green, FString::Printf(TEXT("Destination"))));
	}
}
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

/*
* Internal action logic
*/

EABUtilityActionRunStatus UABUtilityAction_MoveTo::DoAction(UABUtilityComponent& OwnerComp)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_MoveTo::DoAction"))

	EABUtilityActionRunStatus ActionStatus = EABUtilityActionRunStatus::Running;

	AAIController* const AIController = OwnerComp.GetAIOwner();
	if (!IsValid(AIController))
	{
		// If we don't have a valid controller, we cannot continue
		UE_VLOG_UELOG(
			OwnerComp.GetOwner(),
			LogABUtility,
			Error,
			TEXT("%s - Could not get AI Controller from Owner Utility Component [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*OwnerComp.GetName()
		);
		ActionStatus = EABUtilityActionRunStatus::Failed;
	}
	else
	{
		PrepareMoveRequest(*AIController);
		switch (MoveToTargetType)
		{
			case (EABUtilityAction_MoveToTypes::EQSGeneratedPoint):
			{
				checkf(IsValid(PointGenerationEQS), TEXT("Action has invalid Point Generation EQS - likely not set."));
				ActionStatus = StartEQS(*PointGenerationEQS, *AIController);
				break;
			}
			case (EABUtilityAction_MoveToTypes::EQSGeneratedActor):
			{
				checkf(IsValid(ActorGenerationEQS), TEXT("Action has invalid Actor Generation EQS - likely not set."));
				ActionStatus = StartEQS(*ActorGenerationEQS, *AIController);
				break;
			}
			case (EABUtilityAction_MoveToTypes::ActorOfType):
			{
				ActionStatus = StartMoveTowardsActorOfClass(*AIController);
				break;
			}
			default:
			{
				UE_VLOG_UELOG(
					AIController,
					LogABUtility,
					Error,
					TEXT("%s - Invalid Move To Target Type for Move To action [ %s ] owned by Utility Component [ %s ]."),
					ANSI_TO_TCHAR(__FUNCTION__),
					*GetName(),
					*OwnerComp.GetName()
				);
				ActionStatus = EABUtilityActionRunStatus::Failed;
				break;
			}
		}
	}
	
	return ActionStatus;
}

/*
* Internal tick logic
*/

void UABUtilityAction_MoveTo::Tick(UABUtilityComponent& OwnerComp, float DeltaSeconds)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_MoveTo::Tick"))

	// We need a valid Movement Request to continue here
	if (!ActionMemory.MoveReq.IsValid())
	{
		if (ActionMemory.bEQSComplete)
		{
			// If the request isn't valid but the EQS has completed, the EQS failed
			CurrentRunStatus = EABUtilityActionRunStatus::Failed;
		}

		return;
	}

	// Handle updating the Move To Task
	if (!HandleMoveTask(*OwnerComp.GetAIOwner()))
	{
		UE_VLOG_UELOG(
			OwnerComp.GetAIOwner(),
			LogABUtility,
			Warning,
			TEXT("%s - Could not handle the current move task for Move To action [ %s ] owned by Utility Component [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*GetName(),
			*OwnerComp.GetName()
		);
		CurrentRunStatus = EABUtilityActionRunStatus::Failed;
		return;
	}
}

/*
* Internal move logic
*/

void UABUtilityAction_MoveTo::PrepareMoveRequest(AAIController& AIController)
{
	// Bind all data providers
	const APawn* const AIPawn = AIController.GetPawn();
	AllowPartialPath.BindData(AIPawn, INDEX_NONE);
	AllowStrafe.BindData(AIPawn, INDEX_NONE);
	ReachTestIncludesAgentRadius.BindData(AIPawn, INDEX_NONE);
	ReachTestIncludesGoalRadius.BindData(AIPawn, INDEX_NONE);
	RequireNavigableEndLocation.BindData(AIPawn, INDEX_NONE);
	ProjectGoalLocation.BindData(AIPawn, INDEX_NONE);
	UsePathFinding.BindData(AIPawn, INDEX_NONE);
	StartFromPreviousPath.BindData(AIPawn, INDEX_NONE);
	AcceptableRadius.BindData(AIPawn, INDEX_NONE);

	// Create the move request
	FAIMoveRequest MoveReq;
	MoveReq.SetNavigationFilter(*FilterClass ? FilterClass : AIController.GetDefaultNavigationFilterClass());
	MoveReq.SetAllowPartialPath(AllowPartialPath.GetValue());
	MoveReq.SetAcceptanceRadius(AcceptableRadius.GetValue());
	MoveReq.SetCanStrafe(AllowStrafe.GetValue());
	MoveReq.SetReachTestIncludesAgentRadius(ReachTestIncludesAgentRadius.GetValue());
	MoveReq.SetReachTestIncludesGoalRadius(ReachTestIncludesGoalRadius.GetValue());
	MoveReq.SetRequireNavigableEndLocation(RequireNavigableEndLocation.GetValue());
	MoveReq.SetProjectGoalLocation(ProjectGoalLocation.GetValue());
	MoveReq.SetUsePathfinding(UsePathFinding.GetValue());
	MoveReq.SetStartFromPreviousPath(StartFromPreviousPath.GetValue());

	ActionMemory.MoveReq = MoveReq;
}

EABUtilityActionRunStatus UABUtilityAction_MoveTo::StartEQS(const UEnvQuery& EQSToRun, AAIController& AIController)
{
	FEnvQueryRequest QueryRequest(&EQSToRun, AIController.GetPawn());
	const int32 QueryRequestID = QueryRequest.Execute(RunMode, QueryFinishedDelegate);
	return QueryRequestID != INDEX_NONE ? EABUtilityActionRunStatus::Running : EABUtilityActionRunStatus::Failed;
}

EABUtilityActionRunStatus UABUtilityAction_MoveTo::StartMoveTowardsActorOfClass(AAIController& AIController)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_MoveTo::StartMoveTowardsActorOfClass"))

	const UWorld* const World = AIController.GetWorld();
	if (!IsValid(World))
	{
		UE_VLOG_UELOG(
			&AIController,
			LogABUtility,
			Error,
			TEXT("%s - Could not get valid world from AI Controller [ %s ]. Failing action."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*AIController.GetName()
		);
		return EABUtilityActionRunStatus::Failed;
	}
	
	// Get all the actors of the chosen subclass
	TArray<AActor*> ActorsOfSubclass;
	UGameplayStatics::GetAllActorsOfClass(World, ActorSubclass, ActorsOfSubclass);

	if (ActorsOfSubclass.IsEmpty())
	{
		// No actors of this subclass in world
		return EABUtilityActionRunStatus::Failed;
	}

	// Pick a random one
	const AActor* const ActorOfSubclass = ActorsOfSubclass[FMath::RandRange(0, ActorsOfSubclass.Num() - 1)];

	// Finish setting up the move request
	TrackMovingActor.BindData(AIController.GetPawn(), INDEX_NONE);
	if (TrackMovingActor.GetValue())
	{
		ActionMemory.MoveReq.SetGoalActor(ActorOfSubclass);
		ActionMemory.PreviousTrackedActorLocation = ActorOfSubclass->GetActorLocation();
	}
	else
	{
		ActionMemory.MoveReq.SetGoalLocation(ActorOfSubclass->GetActorLocation());
	}

	if (!ActionMemory.MoveReq.IsValid())
	{
		// The move request has failed to be created
		UE_VLOG_UELOG(
			&AIController,
			LogABUtility,
			Warning,
			TEXT("%s - Failed to create an FAIMoveRequest for Move To action [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*GetName()
		);
		return EABUtilityActionRunStatus::Failed;
	}

	const FPathFollowingRequestResult MoveToResult = AIController.MoveTo(ActionMemory.MoveReq);

	switch (MoveToResult.Code)
	{
		case (EPathFollowingRequestResult::Failed):
		{
			// The move failed
			UE_VLOG_UELOG(
				&AIController,
				LogABUtility,
				Warning,
				TEXT("%s - Move to for AI Controller [ %s ] failed for Move To action [ %s ]."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*AIController.GetName(),
				*GetName()
			);
			return EABUtilityActionRunStatus::Failed;
			break;
		}
		case (EPathFollowingRequestResult::RequestSuccessful):
		{
			// Move successful, we are moving
			ActionMemory.RequestID = MoveToResult.MoveId;
			UPathFollowingComponent* const PathFollowingComponent = AIController.GetPathFollowingComponent();
			if (IsValid(PathFollowingComponent))
			{
				PathFollowingComponent->OnRequestFinished.AddUObject(this, &UABUtilityAction_MoveTo::OnMoveFinished);
			}
#if WITH_GAMEPLAY_DEBUGGER_MENU
			const APawn* const AIPawn = AIController.GetPawn();
			if (IsValid(AIPawn))
			{
				ActionMemory.StartLocation = AIPawn->GetActorLocation();
			}
#endif //WITH_GAMEPLAY_DEBUGGER_MENU
			return EABUtilityActionRunStatus::Running;
			break;
		}
		case (EPathFollowingRequestResult::AlreadyAtGoal):
		{
			// We don't need to move
			ActionMemory.RequestID = MoveToResult.MoveId;
			OnMoveFinished(MoveToResult.MoveId, FPathFollowingResult(EPathFollowingResult::Success, FPathFollowingResultFlags::AlreadyAtGoal));
			return EABUtilityActionRunStatus::Succeeded;
			break;
		}
		default:
		{
			// We shouldn't get here
			UE_VLOG_UELOG(
				&AIController,
				LogABUtility,
				Warning,
				TEXT("%s - Move Request returned unexpected value for Move To action [ %s ]. Failing."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*GetName()
			);
			return EABUtilityActionRunStatus::Failed;
			break;
		}
	}
	
	return EABUtilityActionRunStatus::Running;
}

const bool UABUtilityAction_MoveTo::HandleMoveTask(AAIController& AIController)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_MoveTo::HandleMoveTask"))

	if (!ShouldUpdateMove(AIController))
	{
		// No need to update the move
		return true;
	}

	// We should update the move
	if (ActionMemory.MoveReq.IsValid())
	{
		// Abort the current move
		UPathFollowingComponent* const PathFollowingComponent = AIController.GetPathFollowingComponent();
		if (IsValid(PathFollowingComponent))
		{
			PathFollowingComponent->AbortMove(*this, FPathFollowingResultFlags::NewRequest, 0, EPathFollowingVelocityMode::Keep);
		}
	}

	ActionMemory.Reset();

	// Remake the move request
	PrepareMoveRequest(AIController);

	switch (MoveToTargetType)
	{
		case (EABUtilityAction_MoveToTypes::EQSGeneratedActor):
		{
			check(IsValid(PointGenerationEQS));
			CurrentRunStatus = StartEQS(*PointGenerationEQS, AIController);
			break;
		}
		case (EABUtilityAction_MoveToTypes::ActorOfType):
		{
			CurrentRunStatus = StartMoveTowardsActorOfClass(AIController);
			break;
		}
		case (EABUtilityAction_MoveToTypes::EQSGeneratedPoint):
		default:
		{
			UE_VLOG_UELOG(
				&AIController,
				LogABUtility,
				Error,
				TEXT("%s - We should not have been able to get here if we're not tracking an actor."),
				ANSI_TO_TCHAR(__FUNCTION__)
			);
			return false;
			break;
		}
	}

	return true;
}

const bool UABUtilityAction_MoveTo::ShouldUpdateMove(AAIController& AIController)
{
	const APawn* const AIPawn = AIController.GetPawn();
	
	TrackMovingActor.BindData(AIPawn, INDEX_NONE);
	if (!TrackMovingActor.GetValue())
	{
		// We have a valid task and we're not tracking a moving actor
		return false;
	}

	const AActor* const GoalActor = ActionMemory.MoveReq.GetGoalActor();
	if (!IsValid(GoalActor))
	{
		// We're tracking an actor but the actor is invalid
		return false;
	}

	const float DistPrevLocToNewLoc =
		FVector::DistSquared(ActionMemory.PreviousTrackedActorLocation, GoalActor->GetActorLocation());

	ActorTrackingGoalMovementTolerance.BindData(AIPawn, INDEX_NONE);

	// We're tracking an actor and the actors location is further away from the
	// previous goal than the tolerance allows for
	return DistPrevLocToNewLoc > ActorTrackingGoalMovementTolerance.GetValue();
}

/*
* Delegate callbacks
*/

void UABUtilityAction_MoveTo::OnEQSFinished(TSharedPtr<FEnvQueryResult> Result)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_MoveTo::OnEQSFinished"))

	ActionMemory.bEQSComplete = true;

	if (Result->IsAborted() || !Result->IsSuccessful() || Result->Items.Num() <= 0)
	{
		// EQS failed
		UE_VLOG_UELOG(
			Result->Owner.Get(),
			LogABUtility,
			Warning,
			TEXT("%s - EQS failed for Move To action [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*GetName()
		);
		CurrentRunStatus = EABUtilityActionRunStatus::Failed;
		return;
	}

	// Get the results
	TArray<FVector> ResultLocations;
	TArray<AActor*> ResultActors;
	Result->GetAllAsLocations(ResultLocations);
	Result->GetAllAsActors(ResultActors);

	// Finish setting up the Move Request with a goal actor or goal location
	if (!ResultLocations.IsEmpty() &&
		MoveToTargetType == EABUtilityAction_MoveToTypes::EQSGeneratedPoint)
	{
		const FVector& MoveToLocation = ResultLocations[0];
		ActionMemory.MoveReq.SetGoalLocation(MoveToLocation);
	}
	else if (!ResultActors.IsEmpty() &&
		MoveToTargetType == EABUtilityAction_MoveToTypes::EQSGeneratedActor &&
		Result->Owner.IsValid())
	{
		const AActor* const MoveToActor = ResultActors[0];
		TrackMovingActor.BindData(Result->Owner.Get(), INDEX_NONE);
		if (TrackMovingActor.GetValue())
		{
			ActionMemory.MoveReq.SetGoalActor(MoveToActor);
			ActionMemory.PreviousTrackedActorLocation = MoveToActor->GetActorLocation();
		}
		else
		{
			ActionMemory.MoveReq.SetGoalLocation(MoveToActor->GetActorLocation());
		}
	}
	else
	{
		// No valid results, EQS failed
		UE_VLOG_UELOG(
			Result->Owner.Get(),
			LogABUtility,
			Warning,
			TEXT("%s - EQS failed to return any valid results for the given Move To Target Type for Move To action [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*GetName()
		);
		CurrentRunStatus = EABUtilityActionRunStatus::Failed;
		return;
	}

	if (!ActionMemory.MoveReq.IsValid())
	{
		// The move request has failed to be created
		UE_VLOG_UELOG(
			Result->Owner.Get(),
			LogABUtility,
			Warning,
			TEXT("%s - Failed to create an FAIMoveRequest for Move To action [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*GetName()
		);
		CurrentRunStatus = EABUtilityActionRunStatus::Failed;
		return;
	}

	AAIController* AIController = Cast<AAIController>(Result->Owner.Get());
	if (!IsValid(AIController))
	{
		APawn* AIPawn = Cast<APawn>(Result->Owner.Get());
		if (IsValid(AIPawn))
		{
			AIController = Cast<AAIController>(AIPawn->GetController());
		}

		if (!IsValid(AIController))
		{
			// We need the AI controller to be valid to continue
			UE_VLOG_UELOG(
				Result->Owner.Get(),
				LogABUtility,
				Error,
				TEXT("%s - Could not get AI Controller for Move To action [ %s ]."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*GetName()
			);
			CurrentRunStatus = EABUtilityActionRunStatus::Failed;
			return;
		}
	}

	// Run the move
	const FPathFollowingRequestResult MoveToResult = AIController->MoveTo(ActionMemory.MoveReq);

	switch (MoveToResult.Code)
	{
		case (EPathFollowingRequestResult::Failed):
		{
			// The move failed
			UE_VLOG_UELOG(
				AIController,
				LogABUtility,
				Warning,
				TEXT("%s - Move to for AI Controller [ %s ] failed for Move To action [ %s ]."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*AIController->GetName(),
				*GetName()
			);
			CurrentRunStatus = EABUtilityActionRunStatus::Failed;
			break;
		}
		case (EPathFollowingRequestResult::RequestSuccessful):
		{
			// Move successful, we are moving
			ActionMemory.RequestID = MoveToResult.MoveId;
			UPathFollowingComponent* const PathFollowingComponent = AIController->GetPathFollowingComponent();
			if (IsValid(PathFollowingComponent))
			{
				PathFollowingComponent->OnRequestFinished.AddUObject(this, &UABUtilityAction_MoveTo::OnMoveFinished);
			}
#if WITH_GAMEPLAY_DEBUGGER_MENU
			const APawn* const AIPawn = AIController->GetPawn();
			if (IsValid(AIPawn))
			{
				ActionMemory.StartLocation = AIPawn->GetActorLocation();
			}
#endif //WITH_GAMEPLAY_DEBUGGER_MENU
			break;
		}
		case (EPathFollowingRequestResult::AlreadyAtGoal):
		{
			// We don't need to move
			ActionMemory.RequestID = MoveToResult.MoveId;
			OnMoveFinished(MoveToResult.MoveId, FPathFollowingResult(EPathFollowingResult::Success, FPathFollowingResultFlags::AlreadyAtGoal));
			break;
		}
		default:
		{
			UE_VLOG_UELOG(
				AIController,
				LogABUtility,
				Warning,
				TEXT("%s - Move Request returned unexpected value for Move To action [ %s ]. Failing."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*GetName()
			);
			CurrentRunStatus = EABUtilityActionRunStatus::Failed;
			break;
		}
	}
}

void UABUtilityAction_MoveTo::OnMoveFinished(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	if (RequestID != ActionMemory.RequestID)
	{
		// This is the wrong ID and doesn't have anything to do with this instance of this action
		return;
	}

	if (Result.HasFlag(FPathFollowingResultFlags::UserAbort) &&
		Result.HasFlag(FPathFollowingResultFlags::NewRequest) &&
		!Result.HasFlag(FPathFollowingResultFlags::ForcedScript))
	{
		// Ignoring OnMoveFinished logic as we have a new move request
		return;
	}

	// Reset the action memory
	ActionMemory.Reset();

	CurrentRunStatus = Result.IsSuccess() ? EABUtilityActionRunStatus::Succeeded : EABUtilityActionRunStatus::Failed;
}