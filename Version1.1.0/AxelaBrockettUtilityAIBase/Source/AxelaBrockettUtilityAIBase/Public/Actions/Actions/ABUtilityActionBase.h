// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "DataProviders/AIDataProvider.h"
#include "Engine/EngineBaseTypes.h"
#include "Helpers/ABUtilityTypes.h"
#include "Templates/SubclassOf.h"
#include "UObject/NoExportTypes.h"

#include "ABUtilityActionBase.generated.h"

class FGameplayDebuggerCategory;
class UABUtilityComponent;
class UABUtilityFactorBase;
class UABUtilityRequirementBase;
class UWorld;

// The method used for totalling the scores of the actions factors
UENUM()
enum class EABFactorScoreTotallingMethod : uint8
{
	Sum,
	Multiply,
	Average,
	Min,
	Max
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnActionCompletedDelegate, UABUtilityActionBase*, Action, const EABUtilityActionRunStatus, ActionStatus, const UABUtilityActionInstanceMemoryBase*, InstanceMemory);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAsyncRequirementsChecked, UABUtilityActionBase*, Action, const bool, bRequirementsPassed);

/**
 * Utility AI action
 * Contains Requirements that determine whether the action can run
 * Contains factors that determine the score of the action
 */
UCLASS(EditInlineNew, Abstract)
class AXELABROCKETTUTILITYAIBASE_API UABUtilityActionBase : public UObject
{
	GENERATED_BODY()
	
public:
	UABUtilityActionBase();

	// Initialization
	virtual void Initialize(UWorld* InWorld);
	virtual void Deinitialize();

	// Instance memory
	virtual const TSubclassOf<UABUtilityActionInstanceMemoryBase> GetInstanceMemoryType() const
	{
		return UABUtilityActionInstanceMemoryBase::StaticClass();
	}

	// World operations
	UWorld* GetWorld() const override { return CachedWorld; }

	// Action requirement checking
	const bool CheckAllRequirements(const UABUtilityComponent& OwnerComp) const;
	void AsyncCheckAllRequirements(const UABUtilityComponent& OwnerComp);

	// Getters
	const TArray<UABUtilityRequirementBase*>& GetRequirements() const { return Requirements; }
	const TArray<UABUtilityFactorBase*>& GetFactors() const { return Factors; }
	const float GetOnSuccessCooldownValue(UABUtilityComponent& OwnerComp) const;
	const float GetUtilityWeightValue(const UABUtilityComponent& OwnerComp) const;

	// Action scoring
	const float GetActionScore(
		const UABUtilityComponent& OwnerComp,
		const bool bUseConsiderationFactor
	) const;

	// Action logic
	const EABUtilityActionRunStatus PerformAction(
		UABUtilityComponent& OwnerComp,
		UABUtilityActionInstanceMemoryBase* InstanceMemory
	);
	virtual void OnActionCompleted(
		UABUtilityActionInstanceMemoryBase* InstanceMemory,
		const EABUtilityActionRunStatus ActionStatus
	);

	// Pause, resume and abort logic
	virtual void PauseAction(
		UABUtilityComponent* OwnerComp,
		const FString& Reason,
		UABUtilityActionInstanceMemoryBase* InstanceMemory = nullptr
	);
	virtual bool ResumeAction(
		UABUtilityComponent* OwnerComp,
		UABUtilityActionInstanceMemoryBase* InstanceMemory = nullptr
	);
	virtual void AbortAction(
		UABUtilityComponent* OwnerComp,
		const FString& Reason,
		UABUtilityActionInstanceMemoryBase* InstanceMemory = nullptr
	);

	// Tick logic
	virtual EABUtilityActionRunStatus TickAction(
		float DeltaTime,
		UABUtilityComponent& OwnerComp,
		UABUtilityActionInstanceMemoryBase* InstanceMemory
	);

	// If true, action is ticked even if TickType == LEVELTICK_ViewportsOnly
	virtual const bool ShouldTickIfViewportsOnly() const
	{
		return bShouldTickIfViewportsOnly;
	}

	// Inlines
	const bool IsUsingParallelRequirementChecking() const;
	const bool IsConsideringFactorScoreZero() const;
	const bool ShouldTick() const;

	// Validation
	virtual const bool ValidateAction(FString& InvalidationReason) const;

	// Debugging
#if WITH_GAMEPLAY_DEBUGGER_MENU
	virtual void DescribeSelfToGameplayDebugger(
		const UABUtilityComponent& OwnerComp,
		const bool bUseConsiderationFactor,
		const UABUtilityActionInstanceMemoryBase* InstanceMemory,
		FGameplayDebuggerCategory* DebuggerCategory
	) const;
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

	// Delegate broadcasts
	FOnActionCompletedDelegate OnActionCompletedDelegate;
	FOnAsyncRequirementsChecked OnAsyncRequirementsCheckedDelegate;

protected:
	// Internal action logic
	virtual EABUtilityActionRunStatus DoAction(
		UABUtilityComponent& OwnerComp,
		UABUtilityActionInstanceMemoryBase* InstanceMemory
	)
	{
		return EABUtilityActionRunStatus::Succeeded;
	}

	// Internal tick logic
	virtual EABUtilityActionRunStatus Tick(
		UABUtilityComponent& OwnerComp,
		float DeltaSeconds,
		UABUtilityActionInstanceMemoryBase* InstanceMemory
	)
	{
		return EABUtilityActionRunStatus::Running;
	}

	// Internal action requirement checking
	const bool InternalCheckAllRequirements(const UABUtilityComponent& OwnerComp) const;
	const bool InternalParallelCheckAllRequirements(const UABUtilityComponent& OwnerComp) const;
	void InternalAsyncCheckAllRequirements(const UABUtilityComponent& OwnerComp);
	void InternalParallelAsyncCheckAllRequirements(const UABUtilityComponent& OwnerComp);

	UFUNCTION()
	virtual void OnAsyncRequirementChecked(
		const UABUtilityRequirementBase* const Requirement,
		const bool bRequirementPassed
	);

	// Internal action scoring
	void ModifyTotalScore(
		const float& ModifyingScore,
		const float& NumFactors,
		const int32& CurrentIndex,
		float& OutTotalScore
	) const;

	// If true, action is ticked even if TickType == LEVELTICK_ViewportsOnly
	UPROPERTY(EditAnywhere, Category = "Utility AI Action Base")
	bool bShouldTickIfViewportsOnly = false;

	UPROPERTY()
	TObjectPtr<UWorld> CachedWorld = nullptr;

	// Requirements and Factors
	// The list of requirements for the action to be possible, will run through an AND operator
	UPROPERTY(EditAnywhere, Instanced, Category = "Utility AI Action Base")
	TArray<TObjectPtr<UABUtilityRequirementBase>> Requirements;

	// The list of factors affecting the utility score of the action
	UPROPERTY(EditAnywhere, Instanced, Category = "Utility AI Action Base")
	TArray<TObjectPtr<UABUtilityFactorBase>> Factors;

	struct FAJBUtilityActionAsyncData
	{
		int32 AsyncRequirementsToCheck = 0;
		int32 AsyncRequirementsChecked = 0;
		bool bAsyncRequirementsPassed = true;

		void Reset()
		{
			AsyncRequirementsToCheck = 0;
			AsyncRequirementsChecked = 0;
			bAsyncRequirementsPassed = true;
		}
	};

	// Async functionality
	FAJBUtilityActionAsyncData AsyncData;

private:
	// Data providers
	// Weight multiplier that gets multiplied in at the end of scoring all factors
	UPROPERTY(EditAnywhere, meta = (ClampMin = 0.0, UIMin = 0.0), Category = "Utility AI Action Base")
	FAIDataProviderFloatValue UtilityWeight;

	// Cooldown time after the action has been successful
	UPROPERTY(EditAnywhere, meta = (ClampMin = 0.0, UIMin = 0.0), Category = "Utility AI Action Base")
	FAIDataProviderFloatValue OnSuccessCooldown;

	// Scoring
	// Method for working out the total score
	UPROPERTY(EditAnywhere, Category = "Utility AI Action Base")
	EABFactorScoreTotallingMethod ScoreAggregationMethod = EABFactorScoreTotallingMethod::Multiply;

	//Inlines
	// Use ParallelFor to check action requirements
	UPROPERTY(EditAnywhere, Category = "Utility AI Action Base")
	uint32 bUseParallelRequirementChecking : 1;

	// Consider a factors score even if it's 0
	UPROPERTY(EditAnywhere, Category = "Utility AI Action Base")
	uint32 bConsiderFactorScoreZero : 1;

	// If true, this action will tick for each component currently running it
	UPROPERTY(EditAnywhere, Category = "Utility AI Action Base")
	uint32 bShouldTick : 1;
};

/*
* Inlines
*/

FORCEINLINE const bool UABUtilityActionBase::IsUsingParallelRequirementChecking() const
{
	return bUseParallelRequirementChecking;
}

FORCEINLINE const bool UABUtilityActionBase::IsConsideringFactorScoreZero() const
{
	return bConsiderFactorScoreZero;
}

FORCEINLINE const bool UABUtilityActionBase::ShouldTick() const
{
	return bShouldTick;
}