// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Actions/Actions/ABUtilityActionBase.h"
#include "Helpers/ABUtilityTypes.h"
#include "IStateTreeSchemaProvider.h"
#include "StateTreeInstanceData.h"
#include "StateTreeReference.h"
#include "Templates/SubclassOf.h"

#include "ABUtilityAction_RunStateTree.generated.h"

class AActor;
class FGameplayDebuggerCategory;
class UABUtilityComponent;
class UStateTree;
class UStateTreeSchema;
struct FStateTreeDataView;
struct FStateTreeExecutionContext;
struct FStateTreeExternalDataDesc;

UCLASS()
class UABUtilityActionRunStateTreeInstanceMemory : public UABUtilityActionInstanceMemoryBase
{
	GENERATED_BODY()

public:
	void Reset() override
	{
		StateTreeInstanceData.Reset();
		SchemaActor.Reset();
		TimeSinceLastTick = 0.0f;
		TickInterval = 0.001f;
	}

	friend UABUtilityAction_RunStateTree;

protected:
	UPROPERTY(Transient)
	FStateTreeInstanceData StateTreeInstanceData;

	TWeakObjectPtr<AActor> SchemaActor;

	float TimeSinceLastTick = 0.0f;
	float TickInterval = 0.001f;
};

/**
 * 
 */
UCLASS(meta = (DisplayName = "Utility Run State Tree"))
class AXELABROCKETTUTILITYAIBASE_API UABUtilityAction_RunStateTree : public UABUtilityActionBase, public IStateTreeSchemaProvider
{
	GENERATED_BODY()
	
public:
	TSubclassOf<UStateTreeSchema> GetSchema() const override;

	const TSubclassOf<UABUtilityActionInstanceMemoryBase> GetInstanceMemoryType() const override
	{
		return UABUtilityActionRunStateTreeInstanceMemory::StaticClass();
	}

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

	void OnActionCompleted(
		UABUtilityActionInstanceMemoryBase* InstanceMemory,
		const EABUtilityActionRunStatus ActionStatus
	) override;

private:
	bool SetContextRequirements(
		UABUtilityComponent& OwnerComp,
		FStateTreeExecutionContext& Context
	);
	bool CollectExternalData(
		const FStateTreeExecutionContext& Context,
		const UStateTree* StateTree,
		TArrayView<const FStateTreeExternalDataDesc> ExternalDataDescs,
		TArrayView<FStateTreeDataView> OutDataViews
	);

	// The State Tree to run when this Action is run
	UPROPERTY(EditAnywhere, Category = "State Tree", meta = (Schema = "/Script/GameplayStateTreeModule.StateTreeAIComponentSchema", SchemaCanBeOverriden))
	FStateTreeReference StateTreeRef;

	// The interval at which the State Tree will tick
	UPROPERTY(EditAnywhere, Category = "State Tree", meta = (ClampMin = 0.001, UIMin = 0.001))
	float TickInterval = 0.01f;

	// Random deviation to be added to the Tick Interval
	UPROPERTY(EditAnywhere, Category = "State Tree", meta = (ClampMin = 0.0, UIMin = 0.0))
	float TickIntervalRandomDeviation = 0.0f;
};