// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Actions/Actions/ABUtilityActionBase.h"
#include "AITypes.h"
#include "DataProviders/AIDataProvider.h"
#include "Helpers/ABUtilityTypes.h"
#include "Templates/SubclassOf.h"
#include "ZoneGraphTypes.h"

#include "ABUtilityAction_ZGMoveTo.generated.h"

class AAIController;
class FGameplayDebuggerCategory;
class UABUtilityComponent;
class UNavigationQueryFilter;
struct FPathFollowingResult;

/**
 * Move agent to Zone Graph location
 */
UCLASS(meta = (DisplayName = "Utility ZG Move To"))
class AXELABROCKETTUTILITYAIBASE_API UABUtilityAction_ZGMoveTo : public UABUtilityActionBase
{
	GENERATED_BODY()
	
public:
	UABUtilityAction_ZGMoveTo();

	const bool ValidateAction(FString& InvalidationReason) const override;

	// Debugging
#if WITH_GAMEPLAY_DEBUGGER_MENU
	void DescribeSelfToGameplayDebugger(const UABUtilityComponent& OwnerComp, FGameplayDebuggerCategory* DebuggerCategory) const override;
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

protected:
	// Internal action logic
	EABUtilityActionRunStatus DoAction(UABUtilityComponent& OwnerComp) override;

	// Internal tick logic
	void Tick(UABUtilityComponent& OwnerComp, float DeltaSeconds) override;

private:
	// Internal move logic
	EABUtilityActionRunStatus GenerateZGMoveToLocation(UABUtilityComponent& OwnerComp, AAIController& AIController);
	EABUtilityActionRunStatus StartZGMoveTo(AAIController& AIController);
	const bool HandleAdvancingLaneLocation(const AAIController& AIController);

	// Delegate callbacks
	void OnMoveFinished(FAIRequestID RequestID, const FPathFollowingResult& Result);

	// The extent from the actor for which to search for Zone Graphs
	UPROPERTY(EditAnywhere, Category = "Utility AI ZG Move To")
	FVector ZGQueryExtent = FVector::ZeroVector;

	// The Zone Graphs tag requirements to include in the search
	UPROPERTY(EditAnywhere, Category = "Utility AI ZG Move To")
	FZoneGraphTagFilter TagFilter;

	// "None" will result in the default filter being used
	UPROPERTY(EditAnywhere, Category = "Utility AI ZG Move To")
	TSubclassOf<UNavigationQueryFilter> FilterClass = TSubclassOf<UNavigationQueryFilter>();

	// If true, AI will use an incomplete path when the goal cannot be reached
	UPROPERTY(EditAnywhere, Category = "Utility AI ZG Move To")
	FAIDataProviderBoolValue AllowPartialPath;

	// If true, AI will be able to strafe along paths
	UPROPERTY(EditAnywhere, Category = "Utility AI ZG Move To")
	FAIDataProviderBoolValue AllowStrafe;

	// If true, AI's capsule radius is added to the goal reach threshold
	UPROPERTY(EditAnywhere, Category = "Utility AI ZG Move To")
	FAIDataProviderBoolValue ReachTestIncludesAgentRadius;

	// If true, goal's capsule radius is added to the goal reach threshold
	UPROPERTY(EditAnywhere, Category = "Utility AI ZG Move To")
	FAIDataProviderBoolValue ReachTestIncludesGoalRadius;

	// If true, end location must be navigable
	UPROPERTY(EditAnywhere, Category = "Utility AI ZG Move To")
	FAIDataProviderBoolValue RequireNavigableEndLocation;

	// If true, goal location will be projected onto NavMesh before usage
	UPROPERTY(EditAnywhere, Category = "Utility AI ZG Move To")
	FAIDataProviderBoolValue ProjectGoalLocation;

	// Setting to false will move the AI directly towards the goal location
	UPROPERTY(EditAnywhere, Category = "Utility AI ZG Move To")
	FAIDataProviderBoolValue UsePathFinding;

	// If true, new path will start at the end of the previous path (if any)
	// Generated path will merge with remaining points of the previous path
	UPROPERTY(EditAnywhere, Category = "Utility AI ZG Move To")
	FAIDataProviderBoolValue StartFromPreviousPath;

	// If true, the action will complete when the move is finished
	// If false, the action will loop and move again without the action completing
	// The action will need to be aborted if this is false as there is no other completion criteria
	UPROPERTY(EditAnywhere, Category = "Utility AI ZG Move To")
	FAIDataProviderBoolValue RestartActionOnMoveCompleted;

	// A fixed distance added to the goal reach threshold
	UPROPERTY(EditAnywhere, Category = "Utility AI ZG Move To")
	FAIDataProviderFloatValue AcceptableRadius;

	// The distance along the ZG the movement goal will advance in one go
	UPROPERTY(EditAnywhere, Category = "Utility AI ZG Move To")
	FAIDataProviderFloatValue MovementGoalAdvancementDistance;

	FAIRequestID CachedRequestID = FAIRequestID::InvalidRequest;
	FZoneGraphLaneLocation CurrentLane;
	bool bNewMovementRequired = false;
#if WITH_GAMEPLAY_DEBUGGER_MENU
	FVector DebugStartLocation = FAISystem::InvalidLocation;
#endif
};