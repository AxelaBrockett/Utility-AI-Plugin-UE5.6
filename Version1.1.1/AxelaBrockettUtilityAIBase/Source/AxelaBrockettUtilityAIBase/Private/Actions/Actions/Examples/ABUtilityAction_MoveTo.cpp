// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Actions/Actions/Examples/ABUtilityAction_MoveTo.h"

#include "AIController.h"
#include "AISystem.h"
#include "Components/ABUtilityComponent.h"
#include "Engine/World.h"
#include "EnvironmentQuery/EnvQuery.h"
#include "EnvironmentQuery/EnvQueryManager.h"
#include "GameFramework/Actor.h"
#include "Helpers/ABUtilityHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "NavFilters/NavigationQueryFilter.h"
#include "Navigation/PathFollowingComponent.h"

#if WITH_GAMEPLAY_DEBUGGER_MENU
#include "GameplayDebuggerCategory.h"
#include "GameplayDebuggerTypes.h"
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

UABUtilityAction_MoveTo::UABUtilityAction_MoveTo()
{
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

void UABUtilityAction_MoveTo::PauseAction(
	UABUtilityComponent* OwnerComp,
	const FString& Reason,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	if (!IsValid(OwnerComp))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Warning,
			FString::Printf(TEXT("%s - Move To Action has been passed an invalid Utility Component owner."),
				ANSI_TO_TCHAR(__FUNCTION__)
			),
			this
		);
		return;
	}

	UABUtilityActionMoveToInstanceMemory* const MoveToMemory =
		IsValid(InstanceMemory) ?
		Cast<UABUtilityActionMoveToInstanceMemory>(InstanceMemory) :
		ABUtility::Helpers::GetMutableActionInstanceMemoryOfType<UABUtilityActionMoveToInstanceMemory>(*this, *OwnerComp);

	if (!IsValid(MoveToMemory))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Instance Memory for component [ %s ] is not for Move To Action."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp->GetName()
			),
			OwnerComp->GetOwner()
		);
		return;
	}

	if (!MoveToMemory->RequestID.IsValid())
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Warning,
			FString::Printf(TEXT("%s - Stored Move Request ID in memory [ %s ] is invalid for Move To Action."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*MoveToMemory->GetName()
			),
			OwnerComp->GetOwner()
		);
		return;
	}

	AAIController* const AIController = OwnerComp->GetAIOwner();
	if (!IsValid(AIController))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Warning,
			FString::Printf(TEXT("%s - Component [ %s ] does not have a valid AI owner."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp->GetName()
			),
			OwnerComp->GetOwner()
		);
		return;
	}

	UPathFollowingComponent* const PathFollowingComp = AIController->GetPathFollowingComponent();
	if (!IsValid(PathFollowingComp))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Warning,
			FString::Printf(TEXT("%s - AI Controller [ %s ] does not have a valid Path Following Component."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*AIController->GetName()
			),
			AIController
		);
		return;
	}

	AbortMoveOnPause.BindData(AIController->GetPawn(), INDEX_NONE);
	const bool bAbortMoveOnPauseValue = AbortMoveOnPause.GetValue();

	if (bAbortMoveOnPauseValue)
	{
		PathFollowingComp->AbortMove(*this, FPathFollowingResultFlags::OwnerFinished, MoveToMemory->RequestID, EPathFollowingVelocityMode::Reset);
		OnMoveFinished(
			MoveToMemory->RequestID,
			FPathFollowingResult(EPathFollowingResult::Aborted, FPathFollowingResultFlags::OwnerFinished),
			MoveToMemory
		);
	}
	else
	{
		PathFollowingComp->PauseMove(MoveToMemory->RequestID, EPathFollowingVelocityMode::Reset);
	}

	Super::PauseAction(OwnerComp, Reason, InstanceMemory);
}

bool UABUtilityAction_MoveTo::ResumeAction(
	UABUtilityComponent* OwnerComp,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	if (!IsValid(OwnerComp))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Warning,
			FString::Printf(TEXT("%s - Move To Action has been passed an invalid Utility Component."),
				ANSI_TO_TCHAR(__FUNCTION__)
			),
			this
		);
		return false;
	}

	AAIController* const AIController = OwnerComp->GetAIOwner();
	if (!IsValid(AIController))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Warning,
			FString::Printf(TEXT("%s - Component [ %s ] does not have a valid AI owner."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp->GetName()
			),
			OwnerComp->GetOwner()
		);
		return false;
	}

	UPathFollowingComponent* const PathFollowingComp = AIController->GetPathFollowingComponent();
	if (!IsValid(PathFollowingComp))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Warning,
			FString::Printf(TEXT("%s - AI Controller [ %s ] does not have a valid Path Following Component."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*AIController->GetName()
			),
			AIController
		);
		return false;
	}

	AbortMoveOnPause.BindData(AIController->GetPawn(), INDEX_NONE);
	const bool bAbortMoveOnPauseValue = AbortMoveOnPause.GetValue();

	UABUtilityActionMoveToInstanceMemory* const MoveToMemory =
		IsValid(InstanceMemory) ?
		Cast<UABUtilityActionMoveToInstanceMemory>(InstanceMemory) :
		ABUtility::Helpers::GetMutableActionInstanceMemoryOfType<UABUtilityActionMoveToInstanceMemory>(*this, *OwnerComp);

	if (!IsValid(MoveToMemory))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Instance Memory for component [ %s ] is not for Move To Action."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp->GetName()
			),
			AIController
		);
		return false;
	}

	if (!bAbortMoveOnPauseValue && MoveToMemory->RequestID.IsValid())
	{
		// We paused the move before and now we're resuming it
		PathFollowingComp->ResumeMove(MoveToMemory->RequestID);
		return Super::ResumeAction(OwnerComp, InstanceMemory);
	}

	EABUtilityActionRunStatus CurrentRunStatus = EABUtilityActionRunStatus::NotRunning;

	switch (MoveToTargetType)
	{
		case (EABUtilityAction_MoveToTypes::EQSGeneratedPoint):
		{
			check(IsValid(PointGenerationEQS));
			CurrentRunStatus = StartEQS(*PointGenerationEQS, *AIController, *MoveToMemory);
			break;
		}
		case (EABUtilityAction_MoveToTypes::EQSGeneratedActor):
		{
			check(IsValid(ActorGenerationEQS));
			CurrentRunStatus = StartEQS(*ActorGenerationEQS, *AIController, *MoveToMemory);
			break;
		}
		case (EABUtilityAction_MoveToTypes::ActorOfType):
		{
			CurrentRunStatus = StartMoveTowardsActorOfClass(*AIController, *MoveToMemory);
			break;
		}
		default:
		{
			ABUtility::Helpers::UtilityVLOG(
				ELogVerbosity::Error,
				FString::Printf(TEXT("%s - Invalid Move To Type."),
					ANSI_TO_TCHAR(__FUNCTION__)
				),
				AIController
			);
			CurrentRunStatus = EABUtilityActionRunStatus::Failed;
			break;
		}
	}

	return CurrentRunStatus == EABUtilityActionRunStatus::Failed ? false : Super::ResumeAction(OwnerComp, InstanceMemory);
}

void UABUtilityAction_MoveTo::AbortAction(
	UABUtilityComponent* OwnerComp,
	const FString& Reason,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	if (!IsValid(OwnerComp))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Warning,
			FString::Printf(TEXT("%s - Move To Action has been passed an invalid Utility Component."),
				ANSI_TO_TCHAR(__FUNCTION__)
			),
			this
		);
		return;
	}

	UABUtilityActionMoveToInstanceMemory* const MoveToMemory =
		IsValid(InstanceMemory) ?
		Cast<UABUtilityActionMoveToInstanceMemory>(InstanceMemory) :
		ABUtility::Helpers::GetMutableActionInstanceMemoryOfType<UABUtilityActionMoveToInstanceMemory>(*this, *OwnerComp);

	if (!IsValid(MoveToMemory))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Instance Memory for component [ %s ] is not for Move To Action."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp->GetName()
			),
			OwnerComp->GetOwner()
		);
		return;
	}

	if (!MoveToMemory->RequestID.IsValid())
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Warning,
			FString::Printf(TEXT("%s - Stored Move Request ID in Instance Memory [ %s ] is invalid."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*MoveToMemory->GetName()
			),
			OwnerComp->GetOwner()
		);
		return;
	}

	AAIController* const AIController = OwnerComp->GetAIOwner();
	if (!IsValid(AIController))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Warning,
			FString::Printf(TEXT("%s - Component [ %s ] does not have a valid AI owner."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp->GetName()
			),
			OwnerComp->GetOwner()
		);
		return;
	}

	UPathFollowingComponent* const PathFollowingComp = AIController->GetPathFollowingComponent();
	if (!IsValid(PathFollowingComp))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Warning,
			FString::Printf(TEXT("%s - AI Controller [ %s ] does not have a valid Path Following Component."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*AIController->GetName()
			),
			AIController
		);
		return;
	}

	PathFollowingComp->AbortMove(*this, FPathFollowingResultFlags::OwnerFinished, MoveToMemory->RequestID);
	OnMoveFinished(
		MoveToMemory->RequestID,
		FPathFollowingResult(EPathFollowingResult::Aborted, FPathFollowingResultFlags::OwnerFinished),
		MoveToMemory
	);
	Super::AbortAction(OwnerComp, Reason, InstanceMemory);
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
void UABUtilityAction_MoveTo::DescribeSelfToGameplayDebugger(
	const UABUtilityComponent& OwnerComp,
	const bool bUseConsiderationFactor,
	const UABUtilityActionInstanceMemoryBase* InstanceMemory,
	FGameplayDebuggerCategory* DebuggerCategory
) const
{
	if (DebuggerCategory == nullptr)
	{
		return;
	}

	Super::DescribeSelfToGameplayDebugger(OwnerComp, bUseConsiderationFactor, InstanceMemory, DebuggerCategory);

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

	const UABUtilityActionMoveToInstanceMemory* const MoveToMemory = Cast<UABUtilityActionMoveToInstanceMemory>(InstanceMemory);
	if (IsValid(MoveToMemory) && MoveToMemory->NeedsTick())
	{
		DebuggerCategory->AddShape(FGameplayDebuggerShape::MakePoint(MoveToMemory->StartLocation, 10.0f, FColor::Green, FString::Printf(TEXT("Start Location"))));
		DebuggerCategory->AddShape(FGameplayDebuggerShape::MakePoint(MoveToMemory->MoveReq.GetDestination(), 10.0f, FColor::Green, FString::Printf(TEXT("Destination"))));
	}
}
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

/*
* Internal action logic
*/

EABUtilityActionRunStatus UABUtilityAction_MoveTo::DoAction(
	UABUtilityComponent& OwnerComp,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_MoveTo::DoAction"))

	UABUtilityActionMoveToInstanceMemory* const MoveToMemory = Cast<UABUtilityActionMoveToInstanceMemory>(InstanceMemory);
	if (!IsValid(MoveToMemory))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Instance Memory for Component [ %s ] is not for Move To Action."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp.GetName()
			),
			OwnerComp.GetAIOwner()
		);
		return EABUtilityActionRunStatus::Failed;
	}
		
	EABUtilityActionRunStatus ActionStatus = EABUtilityActionRunStatus::Running;

	AAIController* const AIController = OwnerComp.GetAIOwner();
	if (!IsValid(AIController))
	{
		// If we don't have a valid controller, we cannot continue
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Component [ %s ] does not have a valid AI owner."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp.GetName()
			),
			OwnerComp.GetOwner()
		);
		ActionStatus = EABUtilityActionRunStatus::Failed;
	}
	else
	{
		PrepareMoveRequest(*AIController, *MoveToMemory);
		switch (MoveToTargetType)
		{
			case (EABUtilityAction_MoveToTypes::EQSGeneratedPoint):
			{
				checkf(IsValid(PointGenerationEQS), TEXT("Action has invalid Point Generation EQS - likely not set."));
				ActionStatus = StartEQS(*PointGenerationEQS, *AIController, *MoveToMemory);
				break;
			}
			case (EABUtilityAction_MoveToTypes::EQSGeneratedActor):
			{
				checkf(IsValid(ActorGenerationEQS), TEXT("Action has invalid Actor Generation EQS - likely not set."));
				ActionStatus = StartEQS(*ActorGenerationEQS, *AIController, *MoveToMemory);
				break;
			}
			case (EABUtilityAction_MoveToTypes::ActorOfType):
			{
				ActionStatus = StartMoveTowardsActorOfClass(*AIController, *MoveToMemory);
				break;
			}
			default:
			{
				ABUtility::Helpers::UtilityVLOG(
					ELogVerbosity::Error,
					FString::Printf(TEXT("%s - Invalid Move To Type."),
						ANSI_TO_TCHAR(__FUNCTION__)
					),
					AIController
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

EABUtilityActionRunStatus UABUtilityAction_MoveTo::Tick(
	UABUtilityComponent& OwnerComp,
	float DeltaSeconds,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_MoveTo::Tick"))
		
	UABUtilityActionMoveToInstanceMemory* const MoveToMemory = Cast<UABUtilityActionMoveToInstanceMemory>(InstanceMemory);
	if (!IsValid(MoveToMemory))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Instance Memory [ %s ] is not for Move To Action."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*InstanceMemory->GetName()
			),
			OwnerComp.GetAIOwner()
		);
		return EABUtilityActionRunStatus::Failed;
	}

	if (MoveToMemory->IsTickableActionComplete())
	{
		return MoveToMemory->WasSuccessful() ? EABUtilityActionRunStatus::Succeeded : EABUtilityActionRunStatus::Failed;
	}
		
	// We need a valid Movement Request to continue here
	if (!MoveToMemory->MoveReq.IsValid())
	{
		if (MoveToMemory->bEQSComplete)
		{
			// If the request isn't valid but the EQS has completed, the EQS failed
			return EABUtilityActionRunStatus::Failed;
		}

		return EABUtilityActionRunStatus::Running;
	}

	// Handle updating the Move To Task
	if (!HandleMoveTask(*OwnerComp.GetAIOwner(), *MoveToMemory))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Warning,
			FString::Printf(TEXT("%s - Failed to handle to move task for Instance Memory [ %s ]."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*MoveToMemory->GetName()
			),
			OwnerComp.GetAIOwner()
		);
		return EABUtilityActionRunStatus::Failed;
	}

	return EABUtilityActionRunStatus::Running;
}

/*
* Internal move logic
*/

void UABUtilityAction_MoveTo::PrepareMoveRequest(AAIController& AIController, UABUtilityActionMoveToInstanceMemory& MoveToMemory)
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

	MoveToMemory.MoveReq = MoveReq;
}

EABUtilityActionRunStatus UABUtilityAction_MoveTo::StartEQS(
	const UEnvQuery& EQSToRun,
	AAIController& AIController,
	UABUtilityActionMoveToInstanceMemory& MoveToMemory
)
{
	FEnvQueryRequest QueryRequest(&EQSToRun, AIController.GetPawn());
	MoveToMemory.QueryID =
		QueryRequest.Execute(
			RunMode,
			FQueryFinishedSignature::CreateUObject(
				this,
				&UABUtilityAction_MoveTo::OnEQSFinished,
				&MoveToMemory
			)
		);
	return MoveToMemory.QueryID != INDEX_NONE ? EABUtilityActionRunStatus::Running : EABUtilityActionRunStatus::Failed;
}

EABUtilityActionRunStatus UABUtilityAction_MoveTo::StartMoveTowardsActorOfClass(
	AAIController& AIController,
	UABUtilityActionMoveToInstanceMemory& MoveToMemory
)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_MoveTo::StartMoveTowardsActorOfClass"))

	const UWorld* const World = GetWorld();
	if (!IsValid(World))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Failed to get world."),
				ANSI_TO_TCHAR(__FUNCTION__)
			),
			&AIController
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
		MoveToMemory.MoveReq.SetGoalActor(ActorOfSubclass);
		MoveToMemory.PreviousTrackedActorLocation = ActorOfSubclass->GetActorLocation();
	}
	else
	{
		MoveToMemory.MoveReq.SetGoalLocation(ActorOfSubclass->GetActorLocation());
	}

	if (!MoveToMemory.MoveReq.IsValid())
	{
		// The move request has failed to be created
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Warning,
			FString::Printf(TEXT("%s - Failed to create an FAIMoveRequest."),
				ANSI_TO_TCHAR(__FUNCTION__)
			),
			&AIController
		);
		return EABUtilityActionRunStatus::Failed;
	}

	const FPathFollowingRequestResult MoveToResult = AIController.MoveTo(MoveToMemory.MoveReq);

	switch (MoveToResult.Code)
	{
		case (EPathFollowingRequestResult::Failed):
		{
			// The move failed
			ABUtility::Helpers::UtilityVLOG(
				ELogVerbosity::Warning,
				FString::Printf(TEXT("%s - Move To for AI Controller [ %s ] failed."),
					ANSI_TO_TCHAR(__FUNCTION__),
					*AIController.GetName()
				),
				&AIController
			);
			return EABUtilityActionRunStatus::Failed;
			break;
		}
		case (EPathFollowingRequestResult::RequestSuccessful):
		{
			// Move successful, we are moving
			MoveToMemory.RequestID = MoveToResult.MoveId;
			UPathFollowingComponent* const PathFollowingComponent = AIController.GetPathFollowingComponent();
			if (IsValid(PathFollowingComponent))
			{
				PathFollowingComponent->OnRequestFinished.AddUObject(this, &UABUtilityAction_MoveTo::OnMoveFinished, &MoveToMemory);
			}
#if WITH_GAMEPLAY_DEBUGGER_MENU
			const APawn* const AIPawn = AIController.GetPawn();
			if (IsValid(AIPawn))
			{
				MoveToMemory.StartLocation = AIPawn->GetActorLocation();
			}
#endif //WITH_GAMEPLAY_DEBUGGER_MENU
			return EABUtilityActionRunStatus::Running;
			break;
		}
		case (EPathFollowingRequestResult::AlreadyAtGoal):
		{
			// We don't need to move
			MoveToMemory.RequestID = MoveToResult.MoveId;
			OnMoveFinished(
				MoveToResult.MoveId,
				FPathFollowingResult(EPathFollowingResult::Success, FPathFollowingResultFlags::AlreadyAtGoal),
				&MoveToMemory
			);
			return EABUtilityActionRunStatus::Succeeded;
			break;
		}
		default:
		{
			// We shouldn't get here
			ABUtility::Helpers::UtilityVLOG(
				ELogVerbosity::Warning,
				FString::Printf(TEXT("%s - Move To for AI Controller [ %s ] returned unexpected value."),
					ANSI_TO_TCHAR(__FUNCTION__),
					*AIController.GetName()
				),
				&AIController
			);
			return EABUtilityActionRunStatus::Failed;
			break;
		}
	}
	
	return EABUtilityActionRunStatus::Running;
}

const bool UABUtilityAction_MoveTo::HandleMoveTask(AAIController& AIController, UABUtilityActionMoveToInstanceMemory& MoveToMemory)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_MoveTo::HandleMoveTask"))

	if (!ShouldUpdateMove(AIController, MoveToMemory))
	{
		// No need to update the move
		return true;
	}

	// We should update the move
	if (MoveToMemory.MoveReq.IsValid())
	{
		// Abort the current move
		UPathFollowingComponent* const PathFollowingComponent = AIController.GetPathFollowingComponent();
		if (IsValid(PathFollowingComponent))
		{
			PathFollowingComponent->AbortMove(*this, FPathFollowingResultFlags::NewRequest, 0, EPathFollowingVelocityMode::Keep);
		}
	}

	MoveToMemory.Reset();

	// Remake the move request
	PrepareMoveRequest(AIController, MoveToMemory);

	EABUtilityActionRunStatus CurrentRunStatus = EABUtilityActionRunStatus::NotRunning;

	switch (MoveToTargetType)
	{
		case (EABUtilityAction_MoveToTypes::EQSGeneratedActor):
		{
			check(IsValid(PointGenerationEQS));
			CurrentRunStatus = StartEQS(*PointGenerationEQS, AIController, MoveToMemory);
			break;
		}
		case (EABUtilityAction_MoveToTypes::ActorOfType):
		{
			CurrentRunStatus = StartMoveTowardsActorOfClass(AIController, MoveToMemory);
			break;
		}
		case (EABUtilityAction_MoveToTypes::EQSGeneratedPoint):
		default:
		{
			ABUtility::Helpers::UtilityVLOG(
				ELogVerbosity::Error,
				FString::Printf(TEXT("%s - We should not have been able to get here if we're not tracking an actor."),
					ANSI_TO_TCHAR(__FUNCTION__)
				),
				&AIController
			);
			CurrentRunStatus = EABUtilityActionRunStatus::Failed;
			break;
		}
	}

	return CurrentRunStatus != EABUtilityActionRunStatus::Failed;
}

const bool UABUtilityAction_MoveTo::ShouldUpdateMove(AAIController& AIController, const UABUtilityActionMoveToInstanceMemory& MoveToMemory)
{
	const APawn* const AIPawn = AIController.GetPawn();
	
	TrackMovingActor.BindData(AIPawn, INDEX_NONE);
	if (!TrackMovingActor.GetValue())
	{
		// We have a valid task and we're not tracking a moving actor
		return false;
	}

	const AActor* const GoalActor = MoveToMemory.MoveReq.GetGoalActor();
	if (!IsValid(GoalActor))
	{
		// We're tracking an actor but the actor is invalid
		return false;
	}

	const float DistPrevLocToNewLoc =
		FVector::DistSquared(MoveToMemory.PreviousTrackedActorLocation, GoalActor->GetActorLocation());

	ActorTrackingGoalMovementTolerance.BindData(AIPawn, INDEX_NONE);

	// We're tracking an actor and the actors location is further away from the
	// previous goal than the tolerance allows for
	return DistPrevLocToNewLoc > ActorTrackingGoalMovementTolerance.GetValue();
}

/*
* Delegate callbacks
*/

void UABUtilityAction_MoveTo::OnEQSFinished(
	TSharedPtr<FEnvQueryResult> Result,
	UABUtilityActionMoveToInstanceMemory* MoveToMemory
)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_MoveTo::OnEQSFinished"))

	if (!IsValid(MoveToMemory))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Failed to pass valid Move to Instance Memory to OnEQSFinished callback."),
				ANSI_TO_TCHAR(__FUNCTION__)
			),
			Result->Owner.Get()
		);
		return;
	}

	if (Result->QueryID != MoveToMemory->QueryID)
	{
		return;
	}

	MoveToMemory->bEQSComplete = true;

	if (Result->IsAborted() || !Result->IsSuccessful() || Result->Items.Num() <= 0)
	{
		// EQS failed
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Warning,
			FString::Printf(TEXT("%s - EQS failed."),
				ANSI_TO_TCHAR(__FUNCTION__)
			),
			Result->Owner.Get()
		);
		MoveToMemory->SetTickableActionComplete(true, false);
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
		MoveToMemory->MoveReq.SetGoalLocation(MoveToLocation);
	}
	else if (!ResultActors.IsEmpty() &&
		MoveToTargetType == EABUtilityAction_MoveToTypes::EQSGeneratedActor &&
		Result->Owner.IsValid())
	{
		const AActor* const MoveToActor = ResultActors[0];
		TrackMovingActor.BindData(Result->Owner.Get(), INDEX_NONE);
		if (TrackMovingActor.GetValue())
		{
			MoveToMemory->MoveReq.SetGoalActor(MoveToActor);
			MoveToMemory->PreviousTrackedActorLocation = MoveToActor->GetActorLocation();
		}
		else
		{
			MoveToMemory->MoveReq.SetGoalLocation(MoveToActor->GetActorLocation());
		}
	}
	else
	{
		// No valid results, EQS failed
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Warning,
			FString::Printf(TEXT("%s - EQS failed."),
				ANSI_TO_TCHAR(__FUNCTION__)
			),
			Result->Owner.Get()
		);
		MoveToMemory->SetTickableActionComplete(true, false);
		return;
	}

	if (!MoveToMemory->MoveReq.IsValid())
	{
		// The move request has failed to be created
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Warning,
			FString::Printf(TEXT("%s - Failed to create an FAIMoveRequest."),
				ANSI_TO_TCHAR(__FUNCTION__)
			),
			Result->Owner.Get()
		);
		MoveToMemory->SetTickableActionComplete(true, false);
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
			ABUtility::Helpers::UtilityVLOG(
				ELogVerbosity::Error,
				FString::Printf(TEXT("%s - EQS Owner [ %s ] is not an AI Controller or Pawn with AI Controller."),
					ANSI_TO_TCHAR(__FUNCTION__),
					*Result->Owner.Get()->GetName()
				),
				Result->Owner.Get()
			);
			MoveToMemory->SetTickableActionComplete(true, false);
			return;
		}
	}

	// Run the move
	const FPathFollowingRequestResult MoveToResult = AIController->MoveTo(MoveToMemory->MoveReq);

	switch (MoveToResult.Code)
	{
		case (EPathFollowingRequestResult::Failed):
		{
			// The move failed
			ABUtility::Helpers::UtilityVLOG(
				ELogVerbosity::Warning,
				FString::Printf(TEXT("%s - Move To for AI Controller [ %s ] failed."),
					ANSI_TO_TCHAR(__FUNCTION__),
					*AIController->GetName()
				),
				AIController
			);
			MoveToMemory->SetTickableActionComplete(true, false);
			break;
		}
		case (EPathFollowingRequestResult::RequestSuccessful):
		{
			// Move successful, we are moving
			MoveToMemory->RequestID = MoveToResult.MoveId;
			UPathFollowingComponent* const PathFollowingComponent = AIController->GetPathFollowingComponent();
			if (IsValid(PathFollowingComponent) && !PathFollowingComponent->OnRequestFinished.IsBoundToObject(this))
			{
				PathFollowingComponent->OnRequestFinished.AddUObject(this, &UABUtilityAction_MoveTo::OnMoveFinished, MoveToMemory);
			}
#if WITH_GAMEPLAY_DEBUGGER_MENU
			const APawn* const AIPawn = AIController->GetPawn();
			if (IsValid(AIPawn))
			{
				MoveToMemory->StartLocation = AIPawn->GetActorLocation();
			}
#endif //WITH_GAMEPLAY_DEBUGGER_MENU
			break;
		}
		case (EPathFollowingRequestResult::AlreadyAtGoal):
		{
			// We don't need to move
			MoveToMemory->RequestID = MoveToResult.MoveId;
			OnMoveFinished(
				MoveToResult.MoveId,
				FPathFollowingResult(EPathFollowingResult::Success, FPathFollowingResultFlags::AlreadyAtGoal),
				MoveToMemory
			);
			break;
		}
		default:
		{
			ABUtility::Helpers::UtilityVLOG(
				ELogVerbosity::Warning,
				FString::Printf(TEXT("%s - Move To returned unexpected value."),
					ANSI_TO_TCHAR(__FUNCTION__)
				),
				AIController
			);
			MoveToMemory->SetTickableActionComplete(true, false);
			break;
		}
	}
}

void UABUtilityAction_MoveTo::OnMoveFinished(
	FAIRequestID RequestID,
	const FPathFollowingResult& Result,
	UABUtilityActionMoveToInstanceMemory* MoveToMemory
)
{
	if (!IsValid(MoveToMemory))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Received invalid Move To Instance Memory."),
				ANSI_TO_TCHAR(__FUNCTION__)
			),
			this
		);
		return;
	}
	
	if (RequestID != MoveToMemory->RequestID)
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Log,
			FString::Printf(TEXT("%s - OnMoveFinished triggered before memory [ %s ] Request ID could be set - may already be at goal."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*MoveToMemory->GetName()
			),
			this
		);
		MoveToMemory->SetTickableActionComplete(true, true);
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
	MoveToMemory->Reset();
	MoveToMemory->SetTickableActionComplete(true, true);
}