// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "DataProviders/AIDataProvider.h"
#include "Engine/EngineBaseTypes.h"
#include "Helpers/ABUtilityTypes.h"
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

// Tick function for the utility action
USTRUCT()
struct FABUtilityActionTickFunction : public FTickFunction
{
	GENERATED_BODY()

	// Action that is the target of this tick
	class UABUtilityActionBase* Action;

	// Abstract function actually execute the tick
	void ExecuteTick(
		float DeltaTime,
		ELevelTick TickType,
		ENamedThreads::Type CurrentThread,
		const FGraphEventRef& MyCompletionGraphEvent
	) override;

	FString DiagnosticMessage() override;
	FName DiagnosticContext(bool bDetailed) override;
};

template<>
struct TStructOpsTypeTraits<FABUtilityActionTickFunction> : public TStructOpsTypeTraitsBase2<FABUtilityActionTickFunction>
{
	enum
	{
		WithCopy = false
	};
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActionCompletedDelegate, UABUtilityActionBase*, Action);
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

	// Delegate binding and unbinding functions
	void BindToRequirementDelegates() const;
	void UnbindFromRequirementDelegates() const;

	// World operations
	void CacheWorld(UWorld* InWorld) { CachedWorld = InWorld; }
	UWorld* GetCachedWorld() { return CachedWorld; }

	// Action requirement checking
	const bool CheckAllRequirements(const UABUtilityComponent& OwnerComp) const;
	void AsyncCheckAllRequirements(const UABUtilityComponent& OwnerComp);

	// Getters
	const TArray<UABUtilityRequirementBase*>& GetRequirements() const { return Requirements; }
	const TArray<UABUtilityFactorBase*>& GetFactors() const { return Factors; }
	const float GetOnSuccessCooldownValue(UABUtilityComponent& OwnerComp) const;
	const float GetUtilityWeightValue(const UABUtilityComponent& OwnerComp) const;

	// Action scoring
	const float GetActionScore(const UABUtilityComponent& OwnerComp, const bool bUseConsiderationFactor) const;

	// Action logic
	const EABUtilityActionRunStatus& PerformAction(UABUtilityComponent& OwnerComp);

	// Run status
	const EABUtilityActionRunStatus& GetCurrentRunStatus() const { return CurrentRunStatus; }
	void ResetCurrentRunStatus() { CurrentRunStatus = EABUtilityActionRunStatus::NotRunning; }

	// Pause, resume and abort logic
	virtual void PauseAction(UABUtilityComponent* OwnerComp, const FString& Reason);
	virtual bool ResumeAction(UABUtilityComponent* OwnerComp);
	virtual void AbortAction(UABUtilityComponent* OwnerComp, const FString& Reason);

	// Tick logic
	virtual void TickAction(
		float DeltaTime,
		enum ELevelTick TickType,
		FABUtilityActionTickFunction& ThisTickFunction
	);

	// If true, action is ticked even if TickType == LEVELTICK_ViewportsOnly
	virtual const bool ShouldTickIfViewportsOnly() const { return bShouldTickIfViewportsOnly; }

	// Inlines
	const bool IsUsingParallelRequirementChecking() const;
	const bool IsConsideringFactorScoreZero() const;

	// Validation
	virtual const bool ValidateAction(FString& InvalidationReason) const;

	// Debugging
#if WITH_GAMEPLAY_DEBUGGER_MENU
	virtual void DescribeSelfToGameplayDebugger(const UABUtilityComponent& OwnerComp, const bool bUseConsiderationFactor, FGameplayDebuggerCategory* DebuggerCategory) const;
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

	FOnActionCompletedDelegate OnActionCompletedDelegate;
	FOnAsyncRequirementsChecked OnAsyncRequirementsCheckedDelegate;

	// Tick function
	UPROPERTY(EditDefaultsOnly, Category = Tick)
	struct FABUtilityActionTickFunction PrimaryUtilityActionTick;

protected:
	// Internal action logic
	virtual EABUtilityActionRunStatus DoAction(UABUtilityComponent& OwnerComp) { return EABUtilityActionRunStatus::Succeeded; }
	virtual void OnActionCompleted();

	// Internal tick logic
	virtual void Tick(UABUtilityComponent& OwnerComp, float DeltaSeconds) {}

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

	EABUtilityActionRunStatus CurrentRunStatus = EABUtilityActionRunStatus::NotRunning;
	TWeakObjectPtr<UABUtilityComponent> OwnerComponent = nullptr;

	// Cached instance of the world
	UPROPERTY()
	TObjectPtr<UWorld> CachedWorld = nullptr;

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
	FAJBUtilityActionAsyncData AsyncData;

private:
	// Weight multiplier that gets multiplied in at the end of scoring all factors
	UPROPERTY(EditAnywhere, meta = (ClampMin = 0.0, UIMin = 0.0), Category = "Utility AI Action Base")
	FAIDataProviderFloatValue UtilityWeight;

	// Cooldown time after the action has been successful
	UPROPERTY(EditAnywhere, meta = (ClampMin = 0.0, UIMin = 0.0), Category = "Utility AI Action Base")
	FAIDataProviderFloatValue OnSuccessCooldown;

	// Method for working out the total score
	UPROPERTY(EditAnywhere, Category = "Utility AI Action Base")
	EABFactorScoreTotallingMethod ScoreAggregationMethod = EABFactorScoreTotallingMethod::Multiply;

	// The list of requirements for the action to be possible, will run through an AND operator
	UPROPERTY(EditAnywhere, Instanced, Category = "Utility AI Action Base")
	TArray<TObjectPtr<UABUtilityRequirementBase>> Requirements;

	// The list of factors affecting the utility score of the action
	UPROPERTY(EditAnywhere, Instanced, Category = "Utility AI Action Base")
	TArray<TObjectPtr<UABUtilityFactorBase>> Factors;

	// Use ParallelFor to check action requirements
	UPROPERTY(EditAnywhere, Category = "Utility AI Action Base")
	uint32 bUseParallelRequirementChecking : 1;

	// Consider a factors score even if it's 0
	UPROPERTY(EditAnywhere, Category = "Utility AI Action Base")
	uint32 bConsiderFactorScoreZero : 1;
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