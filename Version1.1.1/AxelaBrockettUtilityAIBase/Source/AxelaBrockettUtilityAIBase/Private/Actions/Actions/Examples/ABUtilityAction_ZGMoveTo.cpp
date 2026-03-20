// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Actions/Actions/Examples/ABUtilityAction_ZGMoveTo.h"

#include "AIController.h"
#include "AISystem.h"
#include "Components/ABUtilityComponent.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "Helpers/ABUtilityHelpers.h"
#include "NavFilters/NavigationQueryFilter.h"
#include "Navigation/PathFollowingComponent.h"
#include "Subsystems/ABUtilitySubsystem.h"
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
void UABUtilityAction_ZGMoveTo::DescribeSelfToGameplayDebugger(
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

	const UABUtilityActionZGMoveToInstanceMemory* const ZGMemory = Cast<UABUtilityActionZGMoveToInstanceMemory>(InstanceMemory);
	if (IsValid(ZGMemory) && ZGMemory->NeedsTick())
	{
		const APawn* const AIPawn = AIController->GetPawn();
		if (IsValid(AIPawn))
		{
			DebuggerCategory->AddShape(FGameplayDebuggerShape::MakeBox(AIPawn->GetActorLocation(), ZGQueryExtent, FColor::Green, FString::Printf(TEXT("ZG Query Extent"))));
		}

		DebuggerCategory->AddShape(FGameplayDebuggerShape::MakePoint(ZGMemory->DebugStartLocation, 10.0f, FColor::Green, FString::Printf(TEXT("Start Location"))));
		DebuggerCategory->AddShape(FGameplayDebuggerShape::MakePoint(ZGMemory->CurrentLane.Position, 10.0f, FColor::Green, FString::Printf(TEXT("Destination"))));
		DebuggerCategory->AddShape(FGameplayDebuggerShape::MakeArrow(ZGMemory->CurrentLane.Position, ZGMemory->CurrentLane.Position + (ZGMemory->CurrentLane.Direction * 20.0f), 10.0f, 10.0f, FColor::Green, FString::Printf(TEXT("Zone lane direction"))));
	}
}
#endif // WITH_GAMEPLAY_DEBUGGER_MENU

/*
* Internal action logic
*/

EABUtilityActionRunStatus UABUtilityAction_ZGMoveTo::DoAction(
	UABUtilityComponent& OwnerComp,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_ZGMoveTo::DoAction"))

	UABUtilityActionZGMoveToInstanceMemory* const ZGMemory = Cast<UABUtilityActionZGMoveToInstanceMemory>(InstanceMemory);
	if (!IsValid(ZGMemory))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Instance memory for component [ %s ] is not for ZG Move To Action."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp.GetName()),
			OwnerComp.GetAIOwner()
		);
		return EABUtilityActionRunStatus::Failed;
	}
		
	EABUtilityActionRunStatus ActionStatus = EABUtilityActionRunStatus::Running;

	AAIController* const AIController = OwnerComp.GetAIOwner();
	if (!IsValid(AIController))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Could not get valid AI owner from Owner Component [ %s ]."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp.GetName()),
			OwnerComp.GetOwner()
		);
		ActionStatus = EABUtilityActionRunStatus::Failed;
	}
	else
	{
		ActionStatus = GenerateZGMoveToLocation(OwnerComp, *AIController, *ZGMemory);

		if (ActionStatus == EABUtilityActionRunStatus::Running)
		{
			ActionStatus = StartZGMoveTo(*AIController, *ZGMemory);
		}
	}
	
	return ActionStatus;
}

/*
* Internal tick logic
*/

EABUtilityActionRunStatus UABUtilityAction_ZGMoveTo::Tick(
	UABUtilityComponent& OwnerComp,
	float DeltaSeconds,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_ZGMoveTo::Tick"))

	UABUtilityActionZGMoveToInstanceMemory* const ZGMemory = Cast<UABUtilityActionZGMoveToInstanceMemory>(InstanceMemory);
	if (!IsValid(ZGMemory))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Instance memory for component [ %s ] is not for ZG Move To Action."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp.GetName()),
			OwnerComp.GetAIOwner()
		);
		return EABUtilityActionRunStatus::Failed;
	}

	if (ZGMemory->IsTickableActionComplete())
	{
		return ZGMemory->WasSuccessful() ? EABUtilityActionRunStatus::Succeeded : EABUtilityActionRunStatus::Failed;
	}
		
	if (!ZGMemory->bNewMovementRequired)
	{
		return EABUtilityActionRunStatus::Running;
	}

	ZGMemory->bNewMovementRequired = false;

	AAIController* const AIController = OwnerComp.GetAIOwner();
	if (!IsValid(AIController))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Could not get valid AI owner from Owner Component [ %s ]."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp.GetName()),
			OwnerComp.GetOwner()
		);
		return EABUtilityActionRunStatus::Failed;
	}

	return StartZGMoveTo(*AIController, *ZGMemory);
}

/*
* Internal move logic
*/

EABUtilityActionRunStatus UABUtilityAction_ZGMoveTo::GenerateZGMoveToLocation(
	UABUtilityComponent& OwnerComp,
	AAIController& AIController,
	UABUtilityActionZGMoveToInstanceMemory& ZGMemory
)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_ZGMoveTo::GenerateZGMoveToLocation"))

	const UWorld* const World = GetWorld();
	if (!IsValid(World))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Could not get valid world."),
				ANSI_TO_TCHAR(__FUNCTION__)
			),
			OwnerComp.GetAIOwner()
		);
		return EABUtilityActionRunStatus::Failed;
	}

	const UZoneGraphSubsystem* const ZoneGraphSubsystem = World->GetSubsystem<UZoneGraphSubsystem>();
	if (!IsValid(ZoneGraphSubsystem))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Could not get valid Zone Graph Subsystem from World [ %s ]."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*World->GetName()),
			World
		);
		return EABUtilityActionRunStatus::Failed;
	}

	const APawn* const Pawn = AIController.GetPawn();
	if (!IsValid(Pawn))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Culd not get valid Pawn from AI Controller [ %s ]."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*AIController.GetName()
			),
			&AIController
		);
		return EABUtilityActionRunStatus::Failed;
	}

	const FVector& PawnLocation = Pawn->GetActorLocation();
	if (PawnLocation == FAISystem::InvalidLocation)
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Could not get valid location from Pawn [ %s ]."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*Pawn->GetName()
			),
			Pawn
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
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Warning,
			FString::Printf(
				TEXT("%s - Zone Graph Subsystem could not find valid nearest lane within area:\n")
				TEXT("[Min[x:% f; y: % f; z: % f]]\n[Max[x:% f; y: % f; z: % f]]"),
				ANSI_TO_TCHAR(__FUNCTION__),
				QueryBox.Min.X,
				QueryBox.Min.Y,
				QueryBox.Min.Z,
				QueryBox.Max.X,
				QueryBox.Max.Y,
				QueryBox.Max.Z
			),
			&AIController
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
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Warning,
			FString::Printf(TEXT("%s - Could not find closest location on ZG Lane [ %s ]."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*FoundLaneLocation.LaneHandle.ToString()
			),
			&AIController
		);
		return EABUtilityActionRunStatus::Failed;
	}

	ZGMemory.CurrentLane = FoundLaneLocation;
	
	return EABUtilityActionRunStatus::Running;
}

EABUtilityActionRunStatus UABUtilityAction_ZGMoveTo::StartZGMoveTo(
	AAIController& AIController,
	UABUtilityActionZGMoveToInstanceMemory& ZGMemory
)
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
	MoveReq.SetGoalLocation(ZGMemory.CurrentLane.Position);

	if (!MoveReq.IsValid())
	{
		// The move request has failed to be created
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Warning,
			FString::Printf(TEXT("%s - Failed to create an FAIMoveRequest for ZG Move To Action."),
				ANSI_TO_TCHAR(__FUNCTION__)
			),
			&AIController
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
			ABUtility::Helpers::UtilityVLOG(
				ELogVerbosity::Warning,
				FString::Printf(TEXT("%s - Move To for AI Controller [ %s ] failed for ZG Move To Action."),
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
			ZGMemory.CachedRequestID = MoveToResult.MoveId;
			UPathFollowingComponent* const PathFollowingComponent = AIController.GetPathFollowingComponent();
			if (IsValid(PathFollowingComponent) && !PathFollowingComponent->OnRequestFinished.IsBoundToObject(this))
			{
				PathFollowingComponent->OnRequestFinished.AddUObject(this, &UABUtilityAction_ZGMoveTo::OnMoveFinished, &ZGMemory);
			}
#if WITH_GAMEPLAY_DEBUGGER_MENU
			if (IsValid(AIPawn))
			{
				ZGMemory.DebugStartLocation = AIPawn->GetActorLocation();
			}
#endif
			break;
		}
		case (EPathFollowingRequestResult::AlreadyAtGoal):
		{
			// We don't need to move
			ZGMemory.CachedRequestID = MoveToResult.MoveId;
			OnMoveFinished(MoveToResult.MoveId, FPathFollowingResult(EPathFollowingResult::Success, FPathFollowingResultFlags::AlreadyAtGoal), &ZGMemory);
			break;
		}
		default:
		{
			ABUtility::Helpers::UtilityVLOG(
				ELogVerbosity::Warning,
				FString::Printf(TEXT("%s - Move Request returned unexteced value for Move To Action. Failing."),
					ANSI_TO_TCHAR(__FUNCTION__)
				),
				&AIController
			);
			return EABUtilityActionRunStatus::Failed;
			break;
		}
	}
	
	return !ZGMemory.IsTickableActionComplete() ? EABUtilityActionRunStatus::Running :
		ZGMemory.WasSuccessful() ? EABUtilityActionRunStatus::Succeeded : EABUtilityActionRunStatus::Failed;
}

const bool UABUtilityAction_ZGMoveTo::HandleAdvancingLaneLocation(
	const AAIController& AIController,
	UABUtilityActionZGMoveToInstanceMemory& ZGMemory
)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_ZGMoveTo::HandleAdvancingLaneLocation"))

	const UWorld* const World = GetWorld();
	if (!IsValid(World))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Could not get valid world."),
				ANSI_TO_TCHAR(__FUNCTION__)
			),
			&AIController
		);
		return false;
	}

	const UZoneGraphSubsystem* const ZoneGraphSubsystem = World->GetSubsystem<UZoneGraphSubsystem>();
	if (!IsValid(ZoneGraphSubsystem))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Could not get valid Zone Graph Subsystem from World [ %s ]."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*World->GetName()),
			World
		);
		return false;
	}

	// If we're at the end of the lane, get first linked lane stuff
	// Otherwise, advance lane location

	float LaneLength = 0.0f;
	if (ZoneGraphSubsystem->GetLaneLength(ZGMemory.CurrentLane.LaneHandle, LaneLength))
	{
		// We're at the end of the lane, find next lane
		if (FMath::IsNearlyZero(LaneLength - ZGMemory.CurrentLane.DistanceAlongLane))
		{
			FZoneGraphLinkedLane LinkedLane;
			if (!ZoneGraphSubsystem->GetFirstLinkedLane(
				ZGMemory.CurrentLane.LaneHandle,
				EZoneLaneLinkType::Outgoing,
				EZoneLaneLinkFlags::All,
				EZoneLaneLinkFlags::None,
				LinkedLane
			))
			{
				ABUtility::Helpers::UtilityVLOG(
					ELogVerbosity::Error,
					FString::Printf(TEXT("%s - Reached end of lane but could not find next lane."),
						ANSI_TO_TCHAR(__FUNCTION__)
					),
					&AIController
				);
				return false;
			}

			if (!LinkedLane.IsValid())
			{
				ABUtility::Helpers::UtilityVLOG(
					ELogVerbosity::Error,
					FString::Printf(TEXT("%s - Linked Lane foudnby Zone Graph Subsystem is invalid."),
						ANSI_TO_TCHAR(__FUNCTION__)
					),
					&AIController
				);
				return false;
			}

			FZoneGraphLaneLocation StartOfLinkedLane;
			if (!ZoneGraphSubsystem->CalculateLocationAlongLane(LinkedLane.DestLane, 0.0f, StartOfLinkedLane))
			{
				ABUtility::Helpers::UtilityVLOG(
					ELogVerbosity::Error,
					FString::Printf(TEXT("%s - Zone Graph Subsystem failed to calculate the start of the next lane."),
						ANSI_TO_TCHAR(__FUNCTION__)
					),
					&AIController
				);
				return false;
			}

			if (!StartOfLinkedLane.IsValid())
			{
				ABUtility::Helpers::UtilityVLOG(
					ELogVerbosity::Error,
					FString::Printf(TEXT("%s - Start of linked lane is invalid."),
						ANSI_TO_TCHAR(__FUNCTION__)
					),
					&AIController
				);
				return false;
			}

			ZGMemory.CurrentLane = StartOfLinkedLane;
			return true;
		}
	}

	MovementGoalAdvancementDistance.BindData(AIController.GetPawn(), INDEX_NONE);
	const float MovementGoalAdvancementDistanceValue = MovementGoalAdvancementDistance.GetValue();

	if (!ZoneGraphSubsystem->AdvanceLaneLocation(
		ZGMemory.CurrentLane,
		MovementGoalAdvancementDistanceValue,
		ZGMemory.CurrentLane
	))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s  Zone Graph Subsystem could not advance the lane location."),
				ANSI_TO_TCHAR(__FUNCTION__)
			),
			&AIController
		);
		return false;
	}

	return true;
}

/*
* Delegate callbacks
*/

void UABUtilityAction_ZGMoveTo::OnMoveFinished(
	FAIRequestID RequestID,
	const FPathFollowingResult& Result,
	UABUtilityActionZGMoveToInstanceMemory* ZGMemory
)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_ZGMoveTo::OnMoveFinished"))

	if (!IsValid(ZGMemory))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Failed to pass valid ZG Move To Instance Memory to OnMoveFinished callback."),
				ANSI_TO_TCHAR(__FUNCTION__)
			),
			this
		);
		return;
	}
		
	if (RequestID != ZGMemory->CachedRequestID)
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Log,
			FString::Printf(TEXT("%s - OnMoveFinished triggered before memory [ %s ] RequestID could be set - may already be at goal."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*ZGMemory->GetName()
			),
			this
		);
		ZGMemory->SetTickableActionComplete(true, true);
		return;
	}

	if (Result.HasFlag(FPathFollowingResultFlags::UserAbort) &&
		Result.HasFlag(FPathFollowingResultFlags::NewRequest) &&
		!Result.HasFlag(FPathFollowingResultFlags::ForcedScript))
	{
		// Ignoring OnMoveFinished logic as we have a new move request
		return;
	}

	UABUtilitySubsystem& UtilitySubsystem = ABUtility::Helpers::GetMutableUtilitySubsystemChecked(GetWorld());
	UABUtilityComponent* const OwnerComp = UtilitySubsystem.GetMutableComponentForActionInstanceMemory(*this, *ZGMemory);
	if (!IsValid(OwnerComp))
	{
		ZGMemory->SetTickableActionComplete(true, false);
		return;
	}

	const AAIController* const AIController = OwnerComp->GetAIOwner();
	if (!IsValid(AIController))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Could not get valid AI Controller owner from Owner Comp [ %s ]."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp->GetName()
			),
			OwnerComp->GetOwner()
		);
		ZGMemory->SetTickableActionComplete(true, false);
		return;
	}

	RestartActionOnMoveCompleted.BindData(AIController->GetPawn(), INDEX_NONE);

	if (RestartActionOnMoveCompleted.GetValue())
	{
		ZGMemory->Reset();
		ZGMemory->SetTickableActionComplete(true, true);
		return;
	}

	if (!HandleAdvancingLaneLocation(*AIController, *ZGMemory))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Failed to advance lane location."),
				ANSI_TO_TCHAR(__FUNCTION__)
			),
			AIController
		);
		ZGMemory->SetTickableActionComplete(true, false);
		return;
	}

	ZGMemory->bNewMovementRequired = true;
	ZGMemory->SetTickableActionComplete(false, false);
}