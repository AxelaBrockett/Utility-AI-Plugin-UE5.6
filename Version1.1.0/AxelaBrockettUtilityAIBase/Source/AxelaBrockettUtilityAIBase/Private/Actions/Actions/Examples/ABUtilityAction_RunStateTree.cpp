// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Actions/Actions/Examples/ABUtilityAction_RunStateTree.h"

#include "AIController.h"
#include "Components/ABUtilityComponent.h"
#include "Components/StateTreeAIComponentSchema.h"
#include "GameFramework/Actor.h"
#include "Helpers/ABUtilityHelpers.h"
#include "StateTree.h"
#include "StateTreeExecutionContext.h"
#include "StateTreeExecutionTypes.h"
#include "StateTreeSchema.h"
#include "StateTreeTypes.h"
#include "Subsystems/ABUtilitySubsystem.h"

#if WITH_GAMEPLAY_DEBUGGER_MENU
#include "GameplayDebuggerCategory.h"
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

namespace ABUtility::StateTree::Private
{
	const FLazyName ActorName = "Actor";
	AActor* GetSchemeActorContext(FStateTreeExecutionContext& Context)
	{
		FStateTreeDataView ActorContextView = Context.GetContextDataByName(ActorName);
		return ActorContextView.IsValid() && ActorContextView.GetStruct()->IsChildOf(AActor::StaticClass()) ? ActorContextView.GetMutablePtr<AActor>() : nullptr;
	}
}

TSubclassOf<UStateTreeSchema> UABUtilityAction_RunStateTree::GetSchema() const
{
	return UStateTreeAIComponentSchema::StaticClass();
}

const bool UABUtilityAction_RunStateTree::ValidateAction(FString& InvalidationReason) const
{
	bool bIsValid = Super::ValidateAction(InvalidationReason);

	if (!StateTreeRef.IsValid())
	{
		InvalidationReason += FString::Printf(TEXT("StateTreeRef has not been set\n"));
		bIsValid = false;
	}

	if (TickInterval < 0.001f)
	{
		InvalidationReason += FString::Printf(TEXT("TickInterval is less than the clamping value of 0.001"));
		bIsValid = false;
	}

	if (TickIntervalRandomDeviation < 0.0f)
	{
		InvalidationReason += FString::Printf(TEXT("TickIntervalRandomDeviation is less than the clamping value of 0.0"));
		bIsValid = false;
	}

	return bIsValid;
}

#if WITH_GAMEPLAY_DEBUGGER_MENU
void UABUtilityAction_RunStateTree::DescribeSelfToGameplayDebugger(
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

	DebuggerCategory->AddTextLine(
		FString::Printf(TEXT("        {green}State Tree: %s / Tick Interval: %f / Tick Interval Random Deviation: %f"),
			*GetNameSafe(StateTreeRef.GetStateTree()),
			TickInterval,
			TickIntervalRandomDeviation
		)
	);

	const UABUtilityActionRunStateTreeInstanceMemory* const RunSTMemory = Cast<UABUtilityActionRunStateTreeInstanceMemory>(InstanceMemory);
	if (IsValid(RunSTMemory))
	{
		DebuggerCategory->AddTextLine(
			FString::Printf(TEXT("        {green}IM Schema Actor: %s / IM Tick Interval: %f / IM Time Since Last Tick: %f"),
				RunSTMemory->SchemaActor.IsValid() ? *RunSTMemory->SchemaActor.Get()->GetName() : TEXT("None"),
				RunSTMemory->TickInterval,
				RunSTMemory->TimeSinceLastTick
			)
		);
	}
}
#endif // WITH_GAMEPLAY_DEBUGGER_MENU

EABUtilityActionRunStatus UABUtilityAction_RunStateTree::DoAction(
	UABUtilityComponent& OwnerComp,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_RunStateTree::DoAction"))
	
	checkf(StateTreeRef.IsValid(), TEXT("State Tree Ref is invalid."));

	UABUtilityActionRunStateTreeInstanceMemory* const RunSTMemory =
		Cast<UABUtilityActionRunStateTreeInstanceMemory>(InstanceMemory);
	if (!IsValid(RunSTMemory))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Instance Memory for component [ %s ] is not for Run State Tree action."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp.GetName()),
			OwnerComp.GetAIOwner()
		);
		return EABUtilityActionRunStatus::Failed;
	}

	FStateTreeExecutionContext Context(
		*OwnerComp.GetOwner(),
		*StateTreeRef.GetStateTree(),
		RunSTMemory->StateTreeInstanceData
	);

	if (!SetContextRequirements(OwnerComp, Context))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Failed to set context requirements for component [ %s ]."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp.GetName()),
			OwnerComp.GetAIOwner()
		);
		return EABUtilityActionRunStatus::Failed;
	}

	const EStateTreeRunStatus StartStatus = Context.Start(&StateTreeRef.GetParameters());
	if (StartStatus == EStateTreeRunStatus::Running)
	{
		RunSTMemory->SchemaActor = ABUtility::StateTree::Private::GetSchemeActorContext(Context);
		RunSTMemory->TickInterval = FMath::Max(0.0f, TickInterval + FMath::FRandRange(-TickIntervalRandomDeviation, TickIntervalRandomDeviation));
	}

	return ABUtility::Helpers::StateTreeRunStatusToUtilityActionRunStatus(StartStatus);
}

EABUtilityActionRunStatus UABUtilityAction_RunStateTree::Tick(
	UABUtilityComponent& OwnerComp,
	float DeltaSeconds,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_RunStateTree::Tick"))

	checkf(StateTreeRef.IsValid(), TEXT("State Tree Ref is invalid."));

	UABUtilityActionRunStateTreeInstanceMemory* const RunSTMemory =
		Cast<UABUtilityActionRunStateTreeInstanceMemory>(InstanceMemory);
	if (!IsValid(RunSTMemory))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Instance Memory for component [ %s ] is not for Run State Tree action."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp.GetName()),
			OwnerComp.GetAIOwner()
		);
		return EABUtilityActionRunStatus::Failed;
	}

	RunSTMemory->TimeSinceLastTick += DeltaSeconds;

	if (RunSTMemory->TimeSinceLastTick < RunSTMemory->TickInterval)
	{
		return EABUtilityActionRunStatus::Running;
	}

	FStateTreeExecutionContext Context(
		*OwnerComp.GetOwner(),
		*StateTreeRef.GetStateTree(),
		RunSTMemory->StateTreeInstanceData
	);

	if (!SetContextRequirements(OwnerComp, Context))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Failed to set context requirements for component [ %s ]."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp.GetName()),
			OwnerComp.GetAIOwner()
		);
		return EABUtilityActionRunStatus::Failed;
	}

	ensureMsgf(RunSTMemory->SchemaActor == ABUtility::StateTree::Private::GetSchemeActorContext(Context),
		TEXT("The schema actor is not the same from the previous tick."));

	const EStateTreeRunStatus TickStatus = Context.Tick(DeltaSeconds);
	if (TickStatus == EStateTreeRunStatus::Running)
	{
		RunSTMemory->TimeSinceLastTick = 0.0f;
		RunSTMemory->TickInterval = FMath::Max(0.0f, TickInterval + FMath::FRandRange(-TickIntervalRandomDeviation, TickIntervalRandomDeviation));
	}

	return ABUtility::Helpers::StateTreeRunStatusToUtilityActionRunStatus(TickStatus);
}

void UABUtilityAction_RunStateTree::OnActionCompleted(
	UABUtilityActionInstanceMemoryBase* InstanceMemory,
	const EABUtilityActionRunStatus ActionStatus
)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_RunStateTree::OnActionCompleted"))

	checkf(StateTreeRef.IsValid(), TEXT("State Tree Ref is invalid."));

	const UABUtilitySubsystem& UtilitySubsystem = ABUtility::Helpers::GetUtilitySubsystemChecked(this);
	UABUtilityComponent* const OwnerComp = UtilitySubsystem.GetMutableComponentForActionInstanceMemory(*this, *InstanceMemory);
	if (!IsValid(OwnerComp))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Could not get valid Utility Component from utility subsystem for instance memory [ %s ]."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*InstanceMemory->GetName()),
			this
		);
		Super::OnActionCompleted(InstanceMemory, ActionStatus);
		return;
	}

	UABUtilityActionRunStateTreeInstanceMemory* const RunSTMemory =
		Cast<UABUtilityActionRunStateTreeInstanceMemory>(InstanceMemory);
	if (!IsValid(RunSTMemory))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Instance Memory for component [ %s ] is not for Run State Tree action."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp->GetName()),
			OwnerComp->GetAIOwner()
		);
		Super::OnActionCompleted(InstanceMemory, ActionStatus);
		return;
	}

	FStateTreeExecutionContext Context(
		*OwnerComp->GetOwner(),
		*StateTreeRef.GetStateTree(),
		RunSTMemory->StateTreeInstanceData
	);

	if (!SetContextRequirements(*OwnerComp, Context))
	{
		Context.SetContextDataByName(ABUtility::StateTree::Private::ActorName, FStateTreeDataView(RunSTMemory->SchemaActor.Get()));
	}

	if (ensure(Context.AreContextDataViewsValid()))
	{
		Context.Stop();
	}
	
	Super::OnActionCompleted(InstanceMemory, ActionStatus);
}

bool UABUtilityAction_RunStateTree::SetContextRequirements(
	UABUtilityComponent& OwnerComp,
	FStateTreeExecutionContext& Context
)
{
	Context.SetCollectExternalDataCallback(
		FOnCollectStateTreeExternalData::CreateUObject(
			this,
			&UABUtilityAction_RunStateTree::CollectExternalData
		)
	);
	return UStateTreeAIComponentSchema::SetContextRequirements(OwnerComp, Context);
}

bool UABUtilityAction_RunStateTree::CollectExternalData(
	const FStateTreeExecutionContext& Context,
	const UStateTree* StateTree,
	TArrayView<const FStateTreeExternalDataDesc> ExternalDataDescs,
	TArrayView<FStateTreeDataView> OutDataViews
)
{
	return UStateTreeAIComponentSchema::CollectExternalData(Context, StateTree, ExternalDataDescs, OutDataViews);
}