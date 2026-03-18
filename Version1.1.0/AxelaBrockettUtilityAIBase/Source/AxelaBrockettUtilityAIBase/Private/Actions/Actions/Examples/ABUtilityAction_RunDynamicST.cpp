// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Actions/Actions/Examples/ABUtilityAction_RunDynamicST.h"

#include "Components/ABUtilityComponent.h"
#include "GameFramework/Actor.h"
#include "Helpers/ABUtilityHelpers.h"
#include "StateTreeExecutionContext.h"
#include "StateTreeExecutionTypes.h"

#if WITH_GAMEPLAY_DEBUGGER_MENU
#include "GameplayDebuggerCategory.h"
#endif // WITH_GAMEPLAY_DEBUGGER_MENU

bool UABUtilityAction_RunDynamicStateTree::SetDynamicStateTree(
	UABUtilityComponent& OwnerComp,
	FGameplayTag InInjectionTag,
	const FStateTreeReference& InStateTree,
	const FSetContextDataDelegate& InSetContextDataDelegate,
	float InInterval,
	float InRandomDeviation
)
{
	if (InInjectionTag != InjectionTag)
	{
		return false;
	}

	SetStateTreeToBeRun(OwnerComp, InStateTree, InSetContextDataDelegate, InInterval, InRandomDeviation);

	ABUtility::Helpers::UtilityVLOG(
		ELogVerbosity::Log,
		FString::Printf(
			TEXT("%s - Replaced the State Tree in Run Dynamic State Tree with State Tree [ %s ] with tag [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*GetNameSafe(InStateTree.GetStateTree()),
			*InInjectionTag.ToString()
		),
		OwnerComp.GetOwner()
	);

	return true;
}

EABUtilityActionRunStatus UABUtilityAction_RunDynamicStateTree::DoAction(
	UABUtilityComponent& OwnerComp,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	if (!StateTreeRef.IsValid())
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(
				TEXT("%s - No State Tree Ref set, please set one by running SetDynamicStateTree()."),
				ANSI_TO_TCHAR(__FUNCTION__)
			),
			OwnerComp.GetOwner()
		);
		return EABUtilityActionRunStatus::Failed;
	}

	UABUtilityActionRunDynamicSTIM* const RunDynamicSTIM = Cast<UABUtilityActionRunDynamicSTIM>(InstanceMemory);
	if (!IsValid(RunDynamicSTIM))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(
				TEXT("%s - Instance Memory [ %s ] is not for Run Dynamic State Tree Action."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*GetNameSafe(InstanceMemory)
			),
			OwnerComp.GetOwner()
		);
		return EABUtilityActionRunStatus::Failed;
	}

	FStateTreeExecutionContext Context(*OwnerComp.GetOwner(), *StateTreeRef.GetStateTree(), RunDynamicSTIM->InstanceData);
	SetContextDataDelegate.ExecuteIfBound(Context, OwnerComp, InjectionTag);
	return ABUtility::Helpers::StateTreeRunStatusToUtilityActionRunStatus(Context.Start(&StateTreeRef.GetParameters()));
}

EABUtilityActionRunStatus UABUtilityAction_RunDynamicStateTree::Tick(
	UABUtilityComponent& OwnerComp,
	float DeltaSeconds,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	if (!StateTreeRef.IsValid())
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(
				TEXT("%s - No State Tree Ref set, please set one by running SetDynamicStateTree()."),
				ANSI_TO_TCHAR(__FUNCTION__)
			),
			OwnerComp.GetOwner()
		);
		return EABUtilityActionRunStatus::Failed;
	}

	UABUtilityActionRunDynamicSTIM* const RunDynamicSTIM = Cast<UABUtilityActionRunDynamicSTIM>(InstanceMemory);
	if (!IsValid(RunDynamicSTIM))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(
				TEXT("%s - Instance Memory [ %s ] is not for Run Dynamic State Tree Action."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*GetNameSafe(InstanceMemory)
			),
			OwnerComp.GetOwner()
		);
		return EABUtilityActionRunStatus::Failed;
	}

	RunDynamicSTIM->CurrentTickTime += DeltaSeconds;
	if (RunDynamicSTIM->CurrentTickTime < RunDynamicSTIM->NextTickTime)
	{
		return EABUtilityActionRunStatus::Running;
	}

	EStateTreeRunStatus TickStatus = EStateTreeRunStatus::Unset;
	{
		FStateTreeExecutionContext Context(*OwnerComp.GetOwner(), *StateTreeRef.GetStateTree(), RunDynamicSTIM->InstanceData);
		SetContextDataDelegate.ExecuteIfBound(Context, OwnerComp, InjectionTag);
		TickStatus = Context.Tick(DeltaSeconds);
	}

	if (TickStatus == EStateTreeRunStatus::Running)
	{
		RunDynamicSTIM->NextTickTime = FMath::Max(0.0f, Interval + FMath::RandRange(-RandomDeviation, RandomDeviation));
	}

	return ABUtility::Helpers::StateTreeRunStatusToUtilityActionRunStatus(TickStatus);
}

void UABUtilityAction_RunDynamicStateTree::OnActionCompleted(
	UABUtilityActionInstanceMemoryBase* InstanceMemory,
	const EABUtilityActionRunStatus ActionStatus
)
{
	UABUtilityActionRunDynamicSTIM* const RunDynamicSTIM = Cast<UABUtilityActionRunDynamicSTIM>(InstanceMemory);
	if (StateTreeRef.IsValid() && IsValid(RunDynamicSTIM))
	{
		const UABUtilitySubsystem& UtilitySubsystem = ABUtility::Helpers::GetUtilitySubsystemChecked(this);
		UABUtilityComponent* const OwnerComp = UtilitySubsystem.GetMutableComponentForActionInstanceMemory(*this, *RunDynamicSTIM);
		if (IsValid(OwnerComp))
		{
			FStateTreeExecutionContext Context(*OwnerComp->GetOwner(), *StateTreeRef.GetStateTree(), RunDynamicSTIM->InstanceData);
			SetContextDataDelegate.ExecuteIfBound(Context, *OwnerComp, InjectionTag);
			Context.Stop();
		}
	}

	Super::OnActionCompleted(InstanceMemory, ActionStatus);
}

void UABUtilityAction_RunDynamicStateTree::SetStateTreeToBeRun(
	UABUtilityComponent& OwnerComp,
	const FStateTreeReference& InStateTreeToRun,
	const FSetContextDataDelegate& InSetContextDataDelegate,
	float InInterval,
	float InRandomDeviation
)
{
	if (StateTreeRef.IsValid())
	{
		UABUtilityActionRunDynamicSTIM* const RunDynamicSTIM =
			ABUtility::Helpers::GetMutableActionInstanceMemoryOfType<UABUtilityActionRunDynamicSTIM>(*this, OwnerComp);
		if (IsValid(RunDynamicSTIM))
		{
			FStateTreeExecutionContext Context(*OwnerComp.GetOwner(), *StateTreeRef.GetStateTree(), RunDynamicSTIM->InstanceData);
			if (Context.GetStateTreeRunStatus() == EStateTreeRunStatus::Running)
			{
				SetContextDataDelegate.ExecuteIfBound(Context, OwnerComp, InjectionTag);
				Context.Stop();
			}
		}
	}

	StateTreeRef = InStateTreeToRun;
	SetContextDataDelegate = InSetContextDataDelegate;
	Interval = InInterval;
	RandomDeviation = InRandomDeviation;
}

const bool UABUtilityAction_RunDynamicStateTree::ValidateAction(FString& InvalidationReason) const
{
	bool bIsValid = Super::ValidateAction(InvalidationReason);

	if (!InjectionTag.IsValid())
	{
		InvalidationReason += FString::Printf(TEXT("Injection Tag is not set."));
		bIsValid = false;
	}

	return bIsValid;
}

#if WITH_GAMEPLAY_DEBUGGER_MENU
void UABUtilityAction_RunDynamicStateTree::DescribeSelfToGameplayDebugger(
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
		FString::Printf(TEXT("        {green}Injection Tag: %s / State Tree: %s / Interval: %f / Random Deviation : %f"),
			*InjectionTag.ToString(),
			*GetNameSafe(StateTreeRef.GetStateTree()),
			Interval,
			RandomDeviation
		)
	);

	const UABUtilityActionRunDynamicSTIM* const RunDynamicSTIM = Cast<UABUtilityActionRunDynamicSTIM>(InstanceMemory);
	if (IsValid(RunDynamicSTIM) && RunDynamicSTIM->NeedsTick())
	{
		DebuggerCategory->AddTextLine(
			FString::Printf(TEXT("        {green}Next Tick Time: %f / Current Tick Time: %f"),
				RunDynamicSTIM->NextTickTime,
				RunDynamicSTIM->CurrentTickTime
			)
		);
	}
}
#endif // WITH_GAMEPLAY_DEBUGGER_MENU