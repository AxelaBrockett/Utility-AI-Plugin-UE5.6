// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Actions/Actions/ABUtilityActionBase.h"
#include "Helpers/ABUtilityTypes.h"
#include "Templates/SubclassOf.h"

#include "ABUtilityAction_RunParallel.generated.h"

class FGameplayDebuggerCategory;
class UABUtilityComponent;
class UABUtilityFactorBase;
class UABUtilityRequirementBase;
class UWorld;

UCLASS()
class UABUtilityActionRunParallelInstanceMemory : public UABUtilityActionInstanceMemoryBase
{
	GENERATED_BODY()

public:
	void Reset() override
	{
		
	}

	friend UABUtilityAction_RunParallel;

private:
};

UENUM()
enum class EABRunParallelFailureType : uint8
{
	OneFails UMETA(ToolTip = "If one contained Action fails, this owning Action fails"),
	AllFail UMETA(ToolTip = "This owning Action will only fail if all contained Actions fail")
};

/**
 * Allows for multiple Actions to be run together at the same time
 * Requirements of all contained Actions must pass for this to run
 * Score will take into account score of all contained Actions
 */
UCLASS(meta = (DisplayName = "Utility Run Parallel Actions"))
class AXELABROCKETTUTILITYAIBASE_API UABUtilityAction_RunParallel : public UABUtilityActionBase
{
	GENERATED_BODY()

public:
	void Initialize(UWorld* InWorld) override;
	void Deinitialize() override;

	const TSubclassOf<UABUtilityActionInstanceMemoryBase> GetInstanceMemoryType() const override
	{
		return UABUtilityActionRunParallelInstanceMemory::StaticClass();
	}

	void OnActionCompleted(
		UABUtilityActionInstanceMemoryBase* InstanceMemory,
		const EABUtilityActionRunStatus ActionStatus
	) override;

	void PauseAction(
		UABUtilityComponent* OwnerComp,
		const FString& Reason,
		UABUtilityActionInstanceMemoryBase* InstanceMemory = nullptr
	) override;
	bool ResumeAction(
		UABUtilityComponent* OwnerComp,
		UABUtilityActionInstanceMemoryBase* InstanceMemory = nullptr
	) override;
	void AbortAction(
		UABUtilityComponent* OwnerComp,
		const FString& Reason,
		UABUtilityActionInstanceMemoryBase* InstanceMemory = nullptr
	) override;

	const bool ValidateAction(FString& InvalidationReason) const override;

#if WITH_GAMEPLAY_DEBUGGER_MENU
	void DescribeSelfToGameplayDebugger(
		const UABUtilityComponent& OwnerComp,
		const bool bUseConsiderationFactor,
		const UABUtilityActionInstanceMemoryBase* InstanceMemory,
		FGameplayDebuggerCategory* DebuggerCategory
	) const override;
#endif //WITH_GAMEPLAY_DEBUGGER_MENU
	
protected:
	EABUtilityActionRunStatus DoAction(
		UABUtilityComponent& OwnerComp,
		UABUtilityActionInstanceMemoryBase* InstanceMemory
	) override;

	EABUtilityActionRunStatus Tick(
		UABUtilityComponent& OwnerComp,
		float DeltaSeconds,
		UABUtilityActionInstanceMemoryBase* InstanceMemory
	) override;

private:
	UFUNCTION()
	void OnParallelActionCompleted(
		UABUtilityActionBase* Action,
		const EABUtilityActionRunStatus ActionStatus,
		const UABUtilityActionInstanceMemoryBase* ActionMemory
	);

	const bool CheckActionFailure(const TArray<EABUtilityActionRunStatus>& ParallelActionRunStatuses) const;

	UPROPERTY(EditAnywhere, Category = "Utility Actions")
	EABRunParallelFailureType FailureType = EABRunParallelFailureType::OneFails;

	// List of Actions to be run at the same time
	UPROPERTY(EditAnywhere, Instanced, Category = "Utility Actions")
	TArray<UABUtilityActionBase*> ParallelActions;

	UPROPERTY()
	TMap<UABUtilityActionBase*, UABUtilityActionInstanceMemoryBase*> ActionInstanceMemory;

	UPROPERTY()
	TArray<TObjectPtr<UABUtilityFactorBase>> OwnFactors;

	UPROPERTY()
	TArray<TObjectPtr<UABUtilityRequirementBase>> OwnRequirements;
};