// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Actions/Actions/Examples/ABUtilityAction_ZGMoveTo.h"

#include "AIController.h"
#include "AISystem.h"
#include "Components/ABUtilityComponent.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "NavFilters/NavigationQueryFilter.h"
#include "Navigation/PathFollowingComponent.h"
#include "VisualLogger/VisualLogger.h"
#include "ZoneGraphSubsystem.h"

#if WITH_GAMEPLAY_DEBUGGER_MENU
#include "GameplayDebuggerCategory.h"
#include "GameplayDebuggerTypes.h"
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

UABUtilityAction_ZGMoveTo::UABUtilityAction_ZGMoveTo()
{
	AllowPartialPath.DefaultValue = GET_AI_CONFIG_VAR(bAcceptPartialPaths);
	AllowStrafe.DefaultValue = GET_AI_CONFIG_VAR(bAllowStrafing);
	ReachTestIncludesAgentRadius.DefaultValue = ReachTestIncludesGoalRadius.DefaultValue = GET_AI_CONFIG_VAR(bFinishMoveOnGoalOverlap);
	RequireNavigableEndLocation.DefaultValue = true;
	ProjectGoalLocation.DefaultValue = true;
	UsePathFinding.DefaultValue = true;
	StartFromPreviousPath.DefaultValue = false;
	RestartActionOnMoveCompleted.DefaultValue = false;
	const float AcceptanceRadius = GET_AI_CONFIG_VAR(AcceptanceRadius);
	AcceptableRadius.DefaultValue = AcceptanceRadius;
}

/*
* Validation
*/

const bool UABUtilityAction_ZGMoveTo::ValidateAction(FString& InvalidationReason) const
{
	bool bIsValid = Super::ValidateAction(InvalidationReason);

	AcceptableRadius.BindData(this, INDEX_NONE);
	if (AcceptableRadius.GetValue() < 0.0f)
	{
		InvalidationReason += FString::Printf(TEXT("Acceptance Radius is less than 0\n"));
		bIsValid = false;
	}

	MovementGoalAdvancementDistance.BindData(this, INDEX_NONE);
	if (MovementGoalAdvancementDistance.GetValue() <= 0.0f)
	{
		InvalidationReason += FString::Printf(TEXT("Movement Goal Advancement Distance is less than or equal to 0\n"));
		bIsValid = false;
	}

	return bIsValid;
}

/*
* Debugging
*/

#if WITH_GAMEPLAY_DEBUGGER_MENU
void UABUtilityAction_ZGMoveTo::DescribeSelfToGameplayDebugger(const UABUtilityComponent& OwnerComp, const bool bUseConsiderationFactor, FGameplayDebuggerCategory* DebuggerCategory) const
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
		RestartActionOnMoveCompleted.BindData(AIPawn, INDEX_NONE);
		AcceptableRadius.BindData(AIPawn, INDEX_NONE);
		MovementGoalAdvancementDistance.BindData(AIPawn, INDEX_NONE);
	}

	DebuggerCategory->AddTextLine(
		FString::Printf(TEXT("        {green}Filter Class: %s / Allow Partial Path: %s / Allow Strafe: %s / Reach Test Includes Agent Radius: %s / Reach Test Includes Goal Radius: %s / Require Navigable End Location: %s"),
			*GetNameSafe(FilterClass),
			AllowPartialPath.GetValue() ? TEXT("true") : TEXT("false"),
			AllowStrafe.GetValue() ? TEXT("true") : TEXT("false"),
			ReachTestIncludesAgentRadius.GetValue() ? TEXT("true") : TEXT("false"),
			ReachTestIncludesGoalRadius.GetValue() ? TEXT("true") : TEXT("false"),
			RequireNavigableEndLocation.GetValue() ? TEXT("true") : TEXT("false")
		)
	);

	DebuggerCategory->AddTextLine(
		FString::Printf(TEXT("        {green}Project Goal Location: %s / Use Path Finding: %s / Start From Previous Path: %s / Restart Action On Move Completed: %s / Acceptable Radius: %f / Movement Goal Advancement Distance: %f"),
			ProjectGoalLocation.GetValue() ? TEXT("true") : TEXT("false"),
			UsePathFinding.GetValue() ? TEXT("true") : TEXT("false"),
			StartFromPreviousPath.GetValue() ? TEXT("true") : TEXT("false"),
			RestartActionOnMoveCompleted.GetValue() ? TEXT("true") : TEXT("false"),
			AcceptableRadius.GetValue(),
			MovementGoalAdvancementDistance.GetValue()
		)
	);

	if (CurrentRunStatus == EABUtilityActionRunStatus::Running)
	{
		const APawn* const AIPawn = AIController->GetPawn();
		if (IsValid(AIPawn))
		{
			DebuggerCategory->AddShape(FGameplayDebuggerShape::MakeBox(AIPawn->GetActorLocation(), ZGQueryExtent, FColor::Green, FString::Printf(TEXT("ZG Query Extent"))));
		}

		DebuggerCategory->AddShape(FGameplayDebuggerShape::MakePoint(DebugStartLocation, 10.0f, FColor::Green, FString::Printf(TEXT("Start Location"))));
		DebuggerCategory->AddShape(FGameplayDebuggerShape::MakePoint(CurrentLane.Position, 10.0f, FColor::Green, FString::Printf(TEXT("Destination"))));
		DebuggerCategory->AddShape(FGameplayDebuggerShape::MakeArrow(CurrentLane.Position, CurrentLane.Position + (CurrentLane.Direction * 20.0f), 10.0f, 10.0f, FColor::Green, FString::Printf(TEXT("Zone lane direction"))));
	}
}
#endif // WITH_GAMEPLAY_DEBUGGER_MENU

/*
* Internal action logic
*/

EABUtilityActionRunStatus UABUtilityAction_ZGMoveTo::DoAction(UABUtilityComponent& OwnerComp)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_ZGMoveTo::DoAction"))

	EABUtilityActionRunStatus ActionStatus = EABUtilityActionRunStatus::Running;

	AAIController* const AIController = OwnerComp.GetAIOwner();
	if (!IsValid(AIController))
	{
		UE_VLOG_UELOG(
			OwnerComp.GetOwner(),
			LogABUtility,
			Error,
			TEXT("%s - Could not get valid AI owner from Owner Component [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*OwnerComp.GetName()
		);
		ActionStatus = EABUtilityActionRunStatus::Failed;
	}
	else
	{
		ActionStatus = GenerateZGMoveToLocation(OwnerComp, *AIController);

		if (ActionStatus == EABUtilityActionRunStatus::Running)
		{
			ActionStatus = StartZGMoveTo(*AIController);
		}
	}
	
	return ActionStatus;
}

/*
* Internal tick logic
*/

void UABUtilityAction_ZGMoveTo::Tick(UABUtilityComponent& OwnerComp, float DeltaSeconds)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_ZGMoveTo::Tick"))

	if (!bNewMovementRequired)
	{
		return;
	}

	bNewMovementRequired = false;

	AAIController* const AIController = OwnerComp.GetAIOwner();
	if (!IsValid(AIController))
	{
		UE_VLOG_UELOG(
			OwnerComp.GetOwner(),
			LogABUtility,
			Error,
			TEXT("%s - Could not get valid AI owner from Owner Component [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*OwnerComp.GetName()
		);
		CurrentRunStatus = EABUtilityActionRunStatus::Failed;
		return;
	}

	CurrentRunStatus = StartZGMoveTo(*AIController);
}

/*
* Internal move logic
*/

EABUtilityActionRunStatus UABUtilityAction_ZGMoveTo::GenerateZGMoveToLocation(UABUtilityComponent& OwnerComp, AAIController& AIController)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_ZGMoveTo::GenerateZGMoveToLocation"))

	const UWorld* const World = OwnerComp.GetWorld();
	if (!IsValid(World))
	{
		UE_VLOG_UELOG(
			OwnerComp.GetOwner(),
			LogABUtility,
			Error,
			TEXT("%s - Could not get valid world from Owner Component [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*OwnerComp.GetName()
		);
		return EABUtilityActionRunStatus::Failed;
	}

	const UZoneGraphSubsystem* const ZoneGraphSubsystem = World->GetSubsystem<UZoneGraphSubsystem>();
	if (!IsValid(ZoneGraphSubsystem))
	{
		UE_VLOG_UELOG(
			World,
			LogABUtility,
			Error,
			TEXT("%s - Could not get valid Zone Graph Subsystem from World [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*World->GetName()
		);
		return EABUtilityActionRunStatus::Failed;
	}

	const APawn* const Pawn = AIController.GetPawn();
	if (!IsValid(Pawn))
	{
		UE_VLOG_UELOG(
			&AIController,
			LogABUtility,
			Error,
			TEXT("%s - Could not get valid Pawn from AI Controller [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*AIController.GetName()
		);
		return EABUtilityActionRunStatus::Failed;
	}

	const FVector& PawnLocation = Pawn->GetActorLocation();
	if (PawnLocation == FAISystem::InvalidLocation)
	{
		UE_VLOG_UELOG(
			Pawn,
			LogABUtility,
			Error,
			TEXT("%s - Could not get valid location from Pawn [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*Pawn->GetName()
		);
		return EABUtilityActionRunStatus::Failed;
	}

	const FBox QueryBox(PawnLocation - ZGQueryExtent, PawnLocation + ZGQueryExtent);
	FZoneGraphLaneLocation FoundLaneLocation;
	float FoundLaneLocationDist = 0.0f;

	if (!ZoneGraphSubsystem->FindNearestLane(
		QueryBox,
		TagFilter,
		FoundLaneLocation,
		FoundLaneLocationDist
	))
	{
		UE_VLOG_UELOG(
			&AIController,
			LogABUtility,
			Warning,
			TEXT("%s - Zone graph subsystem [ %s ] could not find valid nearest lane within area:\n")
			TEXT("[ Min [ x: %f ; y: %f ; z: %f ]\n[ Max [ x: %f ; y: %f ; z: %f ]]"),
			ANSI_TO_TCHAR(__FUNCTION__),
			*ZoneGraphSubsystem->GetName(),
			QueryBox.Min.X,
			QueryBox.Min.Y,
			QueryBox.Min.Z,
			QueryBox.Max.X,
			QueryBox.Max.Y,
			QueryBox.Max.Z
		);
		UE_VLOG_BOX(
			&AIController,
			LogABUtility,
			Warning,
			QueryBox,
			FColor::Yellow,
			TEXT("Query Box for finding Zone Graph")
		);
		return EABUtilityActionRunStatus::Failed;
	}

	if (!ZoneGraphSubsystem->FindNearestLocationOnLane(
		FoundLaneLocation.LaneHandle,
		QueryBox,
		FoundLaneLocation,
		FoundLaneLocationDist
	))
	{
		UE_VLOG_UELOG(
			&AIController,
			LogABUtility,
			Warning, TEXT("%s - Could not find closest location on ZG lane [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*FoundLaneLocation.LaneHandle.ToString()
		);
		return EABUtilityActionRunStatus::Failed;
	}

	CurrentLane = FoundLaneLocation;
	
	return EABUtilityActionRunStatus::Running;
}

EABUtilityActionRunStatus UABUtilityAction_ZGMoveTo::StartZGMoveTo(AAIController& AIController)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_ZGMoveTo::StartZGMoveTo"))

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
	MoveReq.SetGoalLocation(CurrentLane.Position);

	if (!MoveReq.IsValid())
	{
		// The move request has failed to be created
		UE_VLOG_UELOG(
			&AIController,
			LogABUtility,
			Warning,
			TEXT("%s - Failed to create an FAIMoveRequest for ZG Move To action [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*GetName()
		);
		return EABUtilityActionRunStatus::Failed;
	}

	// Run the move
	const FPathFollowingRequestResult MoveToResult = AIController.MoveTo(MoveReq);

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
			CurrentRunStatus = EABUtilityActionRunStatus::Failed;
			break;
		}
		case (EPathFollowingRequestResult::RequestSuccessful):
		{
			// Move successful, we are moving
			CachedRequestID = MoveToResult.MoveId;
			UPathFollowingComponent* const PathFollowingComponent = AIController.GetPathFollowingComponent();
			if (IsValid(PathFollowingComponent))
			{
				PathFollowingComponent->OnRequestFinished.AddUObject(this, &UABUtilityAction_ZGMoveTo::OnMoveFinished);
			}
#if WITH_GAMEPLAY_DEBUGGER_MENU
			if (IsValid(AIPawn))
			{
				DebugStartLocation = AIPawn->GetActorLocation();
			}
#endif
			break;
		}
		case (EPathFollowingRequestResult::AlreadyAtGoal):
		{
			// We don't need to move
			CachedRequestID = MoveToResult.MoveId;
			OnMoveFinished(MoveToResult.MoveId, FPathFollowingResult(EPathFollowingResult::Success, FPathFollowingResultFlags::AlreadyAtGoal));
			break;
		}
		default:
		{
			UE_VLOG_UELOG(
				&AIController,
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
	
	return EABUtilityActionRunStatus::Running;
}

const bool UABUtilityAction_ZGMoveTo::HandleAdvancingLaneLocation(const AAIController& AIController)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_ZGMoveTo::HandleAdvancingLaneLocation"))

	const UWorld* const World = AIController.GetWorld();
	if (!IsValid(World))
	{
		UE_VLOG_UELOG(
			&AIController,
			LogABUtility,
			Warning,
			TEXT("%s - Could not get valid world from AI Controller [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*AIController.GetName()
		);
		return false;
	}

	const UZoneGraphSubsystem* const ZoneGraphSubsystem = World->GetSubsystem<UZoneGraphSubsystem>();
	if (!IsValid(ZoneGraphSubsystem))
	{
		UE_VLOG_UELOG(
			&AIController,
			LogABUtility,
			Warning,
			TEXT("%s - Could not get valid zone graph subsystem from world [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*World->GetName()
		);
		return false;
	}

	// If we're at the end of the lane, get first linked lane stuff
	// Otherwise, advance lane location

	float LaneLength = 0.0f;
	if (ZoneGraphSubsystem->GetLaneLength(CurrentLane.LaneHandle, LaneLength))
	{
		// We're at the end of the lane, find next lane
		if (FMath::IsNearlyZero(LaneLength - CurrentLane.DistanceAlongLane))
		{
			FZoneGraphLinkedLane LinkedLane;
			if (!ZoneGraphSubsystem->GetFirstLinkedLane(
				CurrentLane.LaneHandle,
				EZoneLaneLinkType::Outgoing,
				EZoneLaneLinkFlags::All,
				EZoneLaneLinkFlags::None,
				LinkedLane
			))
			{
				UE_VLOG_UELOG(
					&AIController,
					LogABUtility,
					Error,
					TEXT("%s - Reached end of lane but could not find next lane."),
					ANSI_TO_TCHAR(__FUNCTION__)
				);
				return false;
			}

			if (!LinkedLane.IsValid())
			{
				UE_VLOG_UELOG(
					&AIController,
					LogABUtility,
					Error,
					TEXT("%s - Linked Lane found by Zone Graph Subsystem is invalid."),
					ANSI_TO_TCHAR(__FUNCTION__)
				);
				return false;
			}

			FZoneGraphLaneLocation StartOfLinkedLane;
			if (!ZoneGraphSubsystem->CalculateLocationAlongLane(LinkedLane.DestLane, 0.0f, StartOfLinkedLane))
			{
				UE_VLOG_UELOG(
					&AIController,
					LogABUtility,
					Error,
					TEXT("%s - Zone Graph Subsystem failed to calculate the start of the next lane."),
					ANSI_TO_TCHAR(__FUNCTION__)
				);
				return false;
			}

			if (!StartOfLinkedLane.IsValid())
			{
				UE_VLOG_UELOG(
					&AIController,
					LogABUtility,
					Error,
					TEXT("%s - Start of linked lane is invalid."),
					ANSI_TO_TCHAR(__FUNCTION__)
				);
				return false;
			}

			CurrentLane = StartOfLinkedLane;
			return true;
		}
	}

	MovementGoalAdvancementDistance.BindData(AIController.GetPawn(), INDEX_NONE);
	const float MovementGoalAdvancementDistanceValue = MovementGoalAdvancementDistance.GetValue();

	if (!ZoneGraphSubsystem->AdvanceLaneLocation(
		CurrentLane,
		MovementGoalAdvancementDistanceValue,
		CurrentLane
	))
	{
		UE_VLOG_UELOG(
			&AIController,
			LogABUtility,
			Error,
			TEXT("%s - Zone Graph Subsystem could not advance the lane location."),
			ANSI_TO_TCHAR(__FUNCTION__)
		);
		return false;
	}

	return true;
}

/*
* Delegate callbacks
*/

void UABUtilityAction_ZGMoveTo::OnMoveFinished(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_ZGMoveTo::OnMoveFinished"))

	if (RequestID != CachedRequestID)
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

	RequestID = FAIRequestID::InvalidRequest;

	UABUtilityComponent* const OwnerComp = OwnerComponent.IsValid() ? OwnerComponent.Get() : nullptr;
	if (!IsValid(OwnerComp))
	{
		CurrentRunStatus = Result.IsSuccess() ? EABUtilityActionRunStatus::Succeeded : EABUtilityActionRunStatus::Failed;
		return;
	}

	const AAIController* const AIController = OwnerComp->GetAIOwner();
	if (!IsValid(AIController))
	{
		UE_VLOG_UELOG(
			OwnerComp->GetOwner(),
			LogABUtility,
			Error,
			TEXT("%s - Could not get valid AI Controller owner from Owner Comp [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*OwnerComp->GetName()
		);
		CurrentRunStatus = EABUtilityActionRunStatus::Failed;
		return;
	}

	RestartActionOnMoveCompleted.BindData(AIController->GetPawn(), INDEX_NONE);

	if (RestartActionOnMoveCompleted.GetValue())
	{
		CurrentRunStatus = Result.IsSuccess() ? EABUtilityActionRunStatus::Succeeded : EABUtilityActionRunStatus::Failed;
		return;
	}

	if (!HandleAdvancingLaneLocation(*AIController))
	{
		UE_VLOG_UELOG(
			AIController,
			LogABUtility,
			Error,
			TEXT("%s - Failed to advance lane location."),
			ANSI_TO_TCHAR(__FUNCTION__)
		);
		CurrentRunStatus = EABUtilityActionRunStatus::Failed;
	}

	bNewMovementRequired = true;
}