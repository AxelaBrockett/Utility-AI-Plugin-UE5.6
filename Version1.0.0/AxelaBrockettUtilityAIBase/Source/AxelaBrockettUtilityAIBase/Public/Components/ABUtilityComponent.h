// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "BrainComponent.h"
#include "DataAssets/ABUtilityDataAsset.h"
#include "Helpers/ABUtilityTypes.h"

#include "ABUtilityComponent.generated.h"

class FGameplayDebuggerCategory;
class UABUtilityActionBase;
class UABUtilityDataAsset;

// Pause logic for the utility component
enum class EABUtilityComponentPauseActionLogic : uint8
{
	PauseAction,
	AbortAction
};

/**
 * Utility brain component
 */
UCLASS(BlueprintType, meta = (BlueprintSpawnableComponent), ClassGroup = "AI")
class AXELABROCKETTUTILITYAIBASE_API UABUtilityComponent : public UBrainComponent
{
	GENERATED_BODY()

protected:
	// Async required data
	struct FAJBUtilityComponentAsyncData
	{
		int32 AsyncActionsToCheck = 0;
		int32 AsyncActionsChecked = 0;
		TMap<UABUtilityActionBase*, const float> AsyncPossibleActionsToScores;

		void Reset()
		{
			AsyncActionsToCheck = 0;
			AsyncActionsChecked = 0;
			AsyncPossibleActionsToScores.Empty();
		}
	};
	
public:
	UABUtilityComponent();

	// UBrainComponent overrides
	void SetComponentTickEnabled(bool bEnabled) override;
	void StartLogic() override;
	void PauseLogic(const FString& Reason) override;
	EAILogicResuming::Type ResumeLogic(const FString& Reason) override;
	void RestartLogic() override;
	void StopLogic(const FString& Reason) override;
	void Cleanup() override;

	// Getters
	const UABUtilityActionBase* GetCurrentAction() const { return CurrentAction; }
	const UABUtilityActionBase* GetLastSuccessfulAction() const { return LastSuccessfulAction; }
	const EABActionSelectionMode& GetActionSelectionMode() const { return ActionSelectionMode; }
	const FTimerHandle& GetSuccessfulActionCooldownHandle() const { return SuccessfulActionCooldownHandle; }
	const FAJBUtilityComponentAsyncData& GetAsyncData() const { return AsyncData; }
	FAJBUtilityComponentAsyncData& GetMutableAsyncData() { return AsyncData; }
	const TArray<TObjectPtr<UABUtilityActionBase>>& GetUtilityActions() const { return UtilityActions; }

	// Pause and abort functions
	virtual void AbortCurrentAction(const EABUtilityAbortActionLogic& AbortLogic);
	virtual void PauseLogicWithActionDecision(
		const FString& Reason,
		const EABUtilityComponentPauseActionLogic& ActionDecision
	);

	// Inlines
	const bool ShouldRestartLogicWhenResumingComponentLogic() const;
	const bool IsComponentRunningAsynchronously() const;
	const bool IsUsingParallelRequirementChecking() const;
	const bool ShouldRetryOnFailure() const;

	// Replication functions
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Debugging
#if WITH_GAMEPLAY_DEBUGGER_MENU
	virtual void DescribeSelfToGameplayDebugger(FGameplayDebuggerCategory* DebuggerCategory) const;
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

protected:
	UFUNCTION(BlueprintNativeEvent)
	void OnRep_CurrentAction();

	UFUNCTION(BlueprintNativeEvent)
	void OnRep_LastSuccessfulAction();

	virtual void OnRep_CurrentAction_Implementation();
	virtual void OnRep_LastSuccessfulAction_Implementation();

	// Delegate binding functions
	UFUNCTION()
	virtual void OnActionCompleted(UABUtilityActionBase* Action);

	// Data asset of type UABUtilityDataAsset
	UPROPERTY(EditAnywhere, Category = "Utility")
	TObjectPtr<UABUtilityDataAsset> UtilityDataAsset = nullptr;

	// Replicated properties
	UPROPERTY(ReplicatedUsing = OnRep_CurrentAction)
	TObjectPtr<UABUtilityActionBase> CurrentAction = nullptr;

	UPROPERTY(ReplicatedUsing = OnRep_LastSuccessfulAction)
	TObjectPtr<UABUtilityActionBase> LastSuccessfulAction = nullptr;

	// Cached actions from the data asset
	UPROPERTY()
	TArray<TObjectPtr<UABUtilityActionBase>> UtilityActions;

private:
	// Action logic functions
	bool PerformUtilityAction();
	bool RequestUtilityAction();
	void AsyncRequestUtilityAction();
	void GetPossibleActions(TMap<UABUtilityActionBase*, const float>& PossibleActionsToScores);
	void ParallelGetPossibleActions(TMap<UABUtilityActionBase*, const float>& PossibleActionsToScores);
	void AsyncGetPossibleActions();
	void ParallelAsyncGetPossibleActions();

	// Delegate binding functions
	UFUNCTION()
	void OnActionRequirementsChecked(UABUtilityActionBase* Action, const bool bRequirementsPassed);

	// Restart the component when resuming after pausing
	UPROPERTY(EditAnywhere, Category = "Pausing")
	uint32 bRestartLogicWhenResumingComponentLogic : 1;

	// Use available async functions
	UPROPERTY(EditAnywhere, Category = "Async")
	uint32 bRunComponentAsynchronously : 1;

	// Use ParallelFor to check action requirements
	UPROPERTY(EditAnywhere, Category = "Async")
	uint32 bUseParallelRequirementChecking : 1;

	// In the event of all actions failing, retry
	UPROPERTY(EditAnywhere, Category = "Utility")
	uint32 bRetryOnFailure : 1;

	FAJBUtilityComponentAsyncData AsyncData;
	EABActionSelectionMode ActionSelectionMode = EABActionSelectionMode::HighestScore;
	FTimerHandle SuccessfulActionCooldownHandle;
};

/*
* Inlines
*/

FORCEINLINE const bool UABUtilityComponent::ShouldRestartLogicWhenResumingComponentLogic() const
{
	return bRestartLogicWhenResumingComponentLogic;
}

FORCEINLINE const bool UABUtilityComponent::IsComponentRunningAsynchronously() const
{
	return bRunComponentAsynchronously;
}

FORCEINLINE const bool UABUtilityComponent::IsUsingParallelRequirementChecking() const
{
	return bUseParallelRequirementChecking;
}

FORCEINLINE const bool UABUtilityComponent::ShouldRetryOnFailure() const
{
	return bRetryOnFailure;
}