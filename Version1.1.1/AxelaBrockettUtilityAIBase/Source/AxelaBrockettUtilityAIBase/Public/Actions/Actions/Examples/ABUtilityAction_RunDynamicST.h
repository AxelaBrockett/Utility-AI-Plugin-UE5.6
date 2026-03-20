// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Actions/Actions/ABUtilityActionBase.h"
#include "GameplayTagContainer.h"
#include "Helpers/ABUtilityTypes.h"
#include "StateTreeInstanceData.h"
#include "StateTreeReference.h"

#include "ABUtilityAction_RunDynamicST.generated.h"

class FGameplayDebuggerCategory;
class UABUtilityComponent;
struct FStateTreeExecutionContext;
struct FStateTreeInstanceData;

UCLASS()
class UABUtilityActionRunDynamicSTIM : public UABUtilityActionInstanceMemoryBase
{
	GENERATED_BODY()

public:
	void Reset() override
	{
		InstanceData.Reset();
		NextTickTime = 0.0f;
		CurrentTickTime = 0.0f;
	}

	friend UABUtilityAction_RunDynamicStateTree;

private:
	UPROPERTY(Transient)
	FStateTreeInstanceData InstanceData;
	float NextTickTime = 0.0f;
	float CurrentTickTime = 0.0f;
};

/**
 * 
 */
UCLASS()
class AXELABROCKETTUTILITYAIBASE_API UABUtilityAction_RunDynamicStateTree : public UABUtilityActionBase
{
	GENERATED_BODY()
	
public:
	DECLARE_DELEGATE_ThreeParams(FSetContextDataDelegate, FStateTreeExecutionContext&, UABUtilityComponent&, FGameplayTag InjectionTag);

	const TSubclassOf<UABUtilityActionInstanceMemoryBase> GetInstanceMemoryType() const override
	{
		return UABUtilityActionRunDynamicSTIM::StaticClass();
	}

	void OnActionCompleted(
		UABUtilityActionInstanceMemoryBase* InstanceMemory,
		const EABUtilityActionRunStatus ActionStatus
	) override;

	bool SetDynamicStateTree(
		UABUtilityComponent& OwnerComp,
		FGameplayTag InInjectionTag,
		const FStateTreeReference& InStateTree,
		const FSetContextDataDelegate& InSetContextDataDelegate,
		float InInterval,
		float InRandomDeviation
	);

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
	void SetStateTreeToBeRun(
		UABUtilityComponent& OwnerComp,
		const FStateTreeReference& InStateTreeToRun,
		const FSetContextDataDelegate& InSetContextDataDelegate,
		float InInterval,
		float InRandomDeviation
	);

	// The tag to use to inject a State Tree at run time
	UPROPERTY(EditAnywhere, Category = "Utility Run Dynamic ST")
	FGameplayTag InjectionTag;

	UPROPERTY(Transient)
	FStateTreeReference StateTreeRef;

	FSetContextDataDelegate SetContextDataDelegate;
	float Interval = 1.0f;
	float RandomDeviation = 0.0f;
};