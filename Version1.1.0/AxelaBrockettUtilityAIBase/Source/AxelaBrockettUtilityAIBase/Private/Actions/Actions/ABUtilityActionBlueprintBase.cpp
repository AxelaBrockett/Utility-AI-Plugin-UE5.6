// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Actions/Actions/ABUtilityActionBlueprintBase.h"

#include "Components/ABUtilityComponent.h"

#if WITH_GAMEPLAY_DEBUGGER_MENU
#include "GameplayDebuggerCategory.h"
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

/*
* Internal action logic
*/

EABUtilityActionRunStatus UABUtilityActionBlueprintBase::DoAction(
	UABUtilityComponent& OwnerComp,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	return DoBlueprintAction(&OwnerComp);
}

/*
* Internal tick logic
*/

EABUtilityActionRunStatus UABUtilityActionBlueprintBase::Tick(
	UABUtilityComponent& OwnerComp,
	float DeltaSeconds,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	return TickBlueprintAction(&OwnerComp, DeltaSeconds);
}

/*
* Validation
*/

const bool UABUtilityActionBlueprintBase::ValidateAction(FString& InvalidationReason) const
{
	return Super::ValidateAction(InvalidationReason) && ValidateBlueprintAction(InvalidationReason, InvalidationReason);
}

/*
* Debugging
*/

#if WITH_GAMEPLAY_DEBUGGER_MENU
void UABUtilityActionBlueprintBase::DescribeSelfToGameplayDebugger(
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

	DebuggerCategory->AddTextLine(FString::Printf(TEXT("        {green}%s"), *DescribeBlueprintSelfToGameplayDebugger(&OwnerComp)));
}
#endif //WITH_GAMEPLAY_DEBUGGER_MENU