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
UENUM()
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
	UFUNCTION(BlueprintCallable, Category = "Utility Component")
	const UABUtilityActionBase* GetCurrentAction() const { return CurrentAction; }
	UFUNCTION(BlueprintCallable, Category = "Utility Component")
	const UABUtilityActionBase* GetLastSuccessfulAction() const { return LastSuccessfulAction; }
	UFUNCTION(BlueprintCallable, Category = "Utility Component")
	const EABActionSelectionMode& GetActionSelectionMode() const { return ActionSelectionMode; }
	const FTimerHandle& GetSuccessfulActionCooldownHandle() const { return SuccessfulActionCooldownHandle; }
	const FAJBUtilityComponentAsyncData& GetAsyncData() const { return AsyncData; }
	FAJBUtilityComponentAsyncData& GetMutableAsyncData() { return AsyncData; }

	// Pause and abort functions
	UFUNCTION(BlueprintCallable, Category = "Utility Component")
	virtual void AbortCurrentAction(const EABUtilityAbortActionLogic& AbortLogic);
	UFUNCTION(BlueprintCallable, Category = "Utility Component")
	virtual void PauseLogicWithActionDecision(
		const FString& Reason,
		const EABUtilityComponentPauseActionLogic& ActionDecision
	);

	// Inlines
	UFUNCTION(BlueprintCallable, Category = "Utility Component")
	const bool ShouldRestartLogicWhenResumingComponentLogic() const;
	UFUNCTION(BlueprintCallable, Category = "Utility Component")
	const bool IsComponentRunningAsynchronously() const;
	UFUNCTION(BlueprintCallable, Category = "Utility Component")
	const bool IsUsingParallelRequirementChecking() const;
	UFUNCTION(BlueprintCallable, Category = "Utility Component")
	const bool ShouldRetryOnFailure() const;
	UFUNCTION(BlueprintCallable, Category = "Utility Component")
	const bool IsUsingConsiderationFactor() const;

	// Replication functions
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Debugging
#if WITH_GAMEPLAY_DEBUGGER_MENU
	virtual void DescribeSelfToGameplayDebugger(FGameplayDebuggerCategory* DebuggerCategory, const int32 ActionIndex) const;
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

protected:
	// Replication functions
	UFUNCTION(BlueprintNativeEvent)
	void OnRep_CurrentAction();

	UFUNCTION(BlueprintNativeEvent)
	void OnRep_LastSuccessfulAction();

	UFUNCTION(BlueprintNativeEvent)
	void OnRep_CurrentRunStatus();

	virtual void OnRep_CurrentAction_Implementation();
	virtual void OnRep_LastSuccessfulAction_Implementation();
	virtual void OnRep_CurrentRunStatus_Implementation();

	// Delegate binding functions
	UFUNCTION()
	virtual void OnActionCompleted(
		UABUtilityActionBase* Action,
		const EABUtilityActionRunStatus ActionStatus,
		const UABUtilityActionInstanceMemoryBase* ActionMemory
	);

	// Data assets
	// Data asset class of type UABUtilityDataAsset
	UPROPERTY(EditAnywhere, Category = "Utility")
	TSoftObjectPtr<UABUtilityDataAsset> UtilityDataAssetClass = nullptr;

	// Replicated properties
	UPROPERTY(ReplicatedUsing = OnRep_CurrentAction)
	TObjectPtr<UABUtilityActionBase> CurrentAction = nullptr;

	UPROPERTY(ReplicatedUsing = OnRep_LastSuccessfulAction)
	TObjectPtr<UABUtilityActionBase> LastSuccessfulAction = nullptr;

	UPROPERTY(ReplicatedUsing = OnRep_CurrentRunStatus)
	EABUtilityActionRunStatus CurrentRunStatus = EABUtilityActionRunStatus::NotRunning;

private:
	// Action logic functions
	bool PerformUtilityAction();
	bool RequestUtilityAction();
	void AsyncRequestUtilityAction();
	void GetPossibleActions(TMap<UABUtilityActionBase*, const float>& PossibleActionsToScores);
	void ParallelGetPossibleActions(TMap<UABUtilityActionBase*, const float>& PossibleActionsToScores);
	void AsyncGetPossibleActions();
	void ParallelAsyncGetPossibleActions();
	void GetAvailableActionsFromSubsystem(TArray<const UABUtilityActionBase*>& AvailableActions) const;
	void GetAvailableMutableActionsFromSubsystem(TArray<UABUtilityActionBase*>& AvailableActions);
	const UABUtilityActionInstanceMemoryBase* GetActionInstanceMemoryFromSubsystem(const UABUtilityActionBase& Action) const;
	UABUtilityActionInstanceMemoryBase* GetMutableActionInstanceMemoryFromSubsystem(const UABUtilityActionBase& Action);

	// Retry logic
	UFUNCTION(BlueprintCallable, Category = "Utility Component")
	bool AttemptRetry();

	// Delegate binding functions
	UFUNCTION()
	void OnActionRequirementsChecked(UABUtilityActionBase* Action, const bool bRequirementsPassed);

	// Inlines
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

	// Enabling this will make all Factors within all Actions use the Consideration Factor score modifier
	UPROPERTY(EditAnywhere, Category = "Scoring")
	uint32 bUseConsiderationFactorScoreModifier : 1;

	// Actions
	UPROPERTY(EditAnywhere, Category = "Actions")
	EABActionSelectionMode ActionSelectionMode = EABActionSelectionMode::HighestScore;

	// Async functionality
	FAJBUtilityComponentAsyncData AsyncData;

	// Timers
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

FORCEINLINE const bool UABUtilityComponent::IsUsingConsiderationFactor() const
{
	return bUseConsiderationFactorScoreModifier;
}