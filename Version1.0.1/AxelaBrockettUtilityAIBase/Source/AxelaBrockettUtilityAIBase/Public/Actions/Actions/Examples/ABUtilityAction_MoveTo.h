// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Actions/Actions/ABUtilityActionBase.h"
#include "AITypes.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "Helpers/ABUtilityTypes.h"
#include "Templates/SubclassOf.h"

#include "ABUtilityAction_MoveTo.generated.h"

class AActor;
class AAIController;
class FGameplayDebuggerCategory;
class UABUtilityComponent;
class UEnvQuery;
class UNavigationQueryFilter;
struct FPathFollowingResult;

UENUM()
enum class EABUtilityAction_MoveToTypes
{
	EQSGeneratedPoint,
	EQSGeneratedActor,
	ActorOfType
};

struct FABUtilityAction_MoveToMemory
{
	FAIMoveRequest MoveReq;
	FAIRequestID RequestID = FAIRequestID::InvalidRequest;
	FVector PreviousTrackedActorLocation = FAISystem::InvalidLocation;
	bool bEQSComplete = false;

#if WITH_GAMEPLAY_DEBUGGER_MENU
	FVector StartLocation = FAISystem::InvalidLocation;
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

	bool Reset()
	{
		MoveReq = FAIMoveRequest();
		RequestID = FAIRequestID::InvalidRequest;
		PreviousTrackedActorLocation = FAISystem::InvalidLocation;
		bEQSComplete = false;

#if WITH_GAMEPLAY_DEBUGGER_MENU
		StartLocation = FAISystem::InvalidLocation;
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

		return true;
	}
};

/**
 * Move agent to location
 */
UCLASS(meta = (DisplayName = "Utility Move To"))
class AXELABROCKETTUTILITYAIBASE_API UABUtilityAction_MoveTo : public UABUtilityActionBase
{
	GENERATED_BODY()
	
public:
	UABUtilityAction_MoveTo();

	// Pause, resume and abort logic
	void PauseAction(UABUtilityComponent* OwnerComp, const FString& Reason) override;
	bool ResumeAction(UABUtilityComponent* OwnerComp) override;
	void AbortAction(UABUtilityComponent* OwnerComp, const FString& Reason) override;

	// Validation
	const bool ValidateAction(FString& InvalidationReason) const override;

	// Debugging
#if WITH_GAMEPLAY_DEBUGGER_MENU
	void DescribeSelfToGameplayDebugger(const UABUtilityComponent& OwnerComp, const bool bUseConsiderationFactor, FGameplayDebuggerCategory* DebuggerCategory) const override;
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

protected:
	// Internal action logic
	EABUtilityActionRunStatus DoAction(UABUtilityComponent& OwnerComp) override;

	// Internal tick logic
	void Tick(UABUtilityComponent& OwnerComp, float DeltaSeconds) override;

private:
	// Internal move logic
	void PrepareMoveRequest(AAIController& AIController);
	EABUtilityActionRunStatus StartEQS(const UEnvQuery& EQSToRun, AAIController& AIController);
	EABUtilityActionRunStatus StartMoveTowardsActorOfClass(AAIController& AIController);
	const bool HandleMoveTask(AAIController& AIController);
	const bool ShouldUpdateMove(AAIController& AIController);

	// Delegate callbacks
	void OnEQSFinished(TSharedPtr<FEnvQueryResult> Result);
	void OnMoveFinished(FAIRequestID RequestID, const FPathFollowingResult& Result);

	// How to generate the point to move to
	// EQSGeneratedPoint expects an EQS that returns a vector
	// EQSGeneratedActor expects an EQS that returns an actor
	// ActorOfType expects a subclass of AActor
	UPROPERTY(EditAnywhere, Category = "Utility AI Move To")
	EABUtilityAction_MoveToTypes MoveToTargetType = EABUtilityAction_MoveToTypes::EQSGeneratedPoint;

	// EQS for generating a point to move to
	UPROPERTY(EditAnywhere, meta = (EditCondition = "MoveToTargetType==EABUtilityAction_MoveToTypes::EQSGeneratedPoint", EditConditionHides), Category = "Utility AI Move To")
	TObjectPtr<UEnvQuery> PointGenerationEQS = nullptr;

	// EQS for generating an actor to move to
	UPROPERTY(EditAnywhere, meta = (EditCondition = "MoveToTargetType==EABUtilityAction_MoveToTypes::EQSGeneratedActor", EditConditionHides), Category = "Utility AI Move To")
	TObjectPtr<UEnvQuery> ActorGenerationEQS = nullptr;

	// Determines the items that will be returned by the EQS
	UPROPERTY(EditAnywhere, meta = (EditCondition = "MoveToTargetType!=EABUtilityAction_MoveToTypes::ActorOfType", EditConditionHides), Category = "Utility AI Move To")
	TEnumAsByte<EEnvQueryRunMode::Type> RunMode;

	// Subclass of Actor to find and move to
	UPROPERTY(EditAnywhere, meta = (EditCondition = "MoveToTargetType==EABUtilityAction_MoveToTypes::ActorOfType", EditConditionHides), Category = "Utility AI Move To")
	TSubclassOf<AActor> ActorSubclass = TSubclassOf<AActor>();

	// "None" will result in the default filter being used
	UPROPERTY(EditAnywhere, Category = "Utility AI Move To")
	TSubclassOf<UNavigationQueryFilter> FilterClass = TSubclassOf<UNavigationQueryFilter>();

	// If true, AI will use an incomplete path when the goal cannot be reached
	UPROPERTY(EditAnywhere, Category = "Utility AI Move To")
	FAIDataProviderBoolValue AllowPartialPath;

	// If true, AI will be able to strafe along paths
	UPROPERTY(EditAnywhere, Category = "Utility AI Move To")
	FAIDataProviderBoolValue AllowStrafe;

	// If true, AI's capsule radius is added to the goal reach threshold
	UPROPERTY(EditAnywhere, Category = "Utility AI Move To")
	FAIDataProviderBoolValue ReachTestIncludesAgentRadius;

	// If true, goal's capsule radius is added to the goal reach threshold
	UPROPERTY(EditAnywhere, Category = "Utility AI Move To")
	FAIDataProviderBoolValue ReachTestIncludesGoalRadius;

	// If true, end location must be navigable
	UPROPERTY(EditAnywhere, Category = "Utility AI Move To")
	FAIDataProviderBoolValue RequireNavigableEndLocation;

	// If true, goal location will be projected onto NavMesh before usage
	UPROPERTY(EditAnywhere, Category = "Utility AI Move To")
	FAIDataProviderBoolValue ProjectGoalLocation;

	// Setting to false will move the AI directly towards the goal location
	UPROPERTY(EditAnywhere, Category = "Utility AI Move To")
	FAIDataProviderBoolValue UsePathFinding;

	// If true, new path will start at the end of the previous path (if any)
	// Generated path will merge with remaining points of the previous path
	UPROPERTY(EditAnywhere, Category = "Utility AI Move To")
	FAIDataProviderBoolValue StartFromPreviousPath;

	// If true, the goal location will be updated as the goal actor moves
	UPROPERTY(EditAnywhere, meta = (EditCondition = "MoveToTargetType!=EABUtilityAction_MoveToTypes::EQSGeneratedPoint", EditConditionHides), Category = "Utility AI Move To")
	FAIDataProviderBoolValue TrackMovingActor;

	// If true, when pausing, the move will abort, otherwise it will pause the move
	UPROPERTY(EditAnywhere, Category = "Utility AI Move To")
	FAIDataProviderBoolValue AbortMoveOnPause;

	// A fixed distance added to the goal reach threshold
	UPROPERTY(EditAnywhere, Category = "Utility AI Move To")
	FAIDataProviderFloatValue AcceptableRadius;

	// If tracking an actor, this value defines when the goal location is recalculated
	// It is recommended that this value is less than AcceptanceRadius
	UPROPERTY(EditAnywhere, Category = "Utility AI Move To")
	FAIDataProviderFloatValue ActorTrackingGoalMovementTolerance;

	FABUtilityAction_MoveToMemory ActionMemory;
	FQueryFinishedSignature QueryFinishedDelegate;
};