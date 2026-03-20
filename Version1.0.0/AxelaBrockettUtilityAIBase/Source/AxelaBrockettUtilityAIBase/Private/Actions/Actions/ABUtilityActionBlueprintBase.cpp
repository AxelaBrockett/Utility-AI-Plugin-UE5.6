// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Actions/Actions/ABUtilityActionBlueprintBase.h"

#include "Components/ABUtilityComponent.h"

#if WITH_GAMEPLAY_DEBUGGER_MENU
#include "GameplayDebuggerCategory.h"
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

/*
* Internal action logic
*/

EABUtilityActionRunStatus UABUtilityActionBlueprintBase::DoAction(UABUtilityComponent& OwnerComp)
{
	CurrentRunStatus = EABUtilityActionRunStatus::Running;
	DoBlueprintAction(&OwnerComp);
	return CurrentRunStatus;
}

/*
* Internal tick logic
*/

void UABUtilityActionBlueprintBase::Tick(UABUtilityComponent& OwnerComp, float DeltaSeconds)
{
	TickBlueprintAction(&OwnerComp, DeltaSeconds);
}

/*
* Completion function
*/

void UABUtilityActionBlueprintBase::FinishAction(bool bSuccess)
{
	CurrentRunStatus = bSuccess ? EABUtilityActionRunStatus::Succeeded : EABUtilityActionRunStatus::Failed;
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
void UABUtilityActionBlueprintBase::DescribeSelfToGameplayDebugger(const UABUtilityComponent& OwnerComp, FGameplayDebuggerCategory* DebuggerCategory) const
{
	if (DebuggerCategory == nullptr)
	{
		return;
	}

	Super::DescribeSelfToGameplayDebugger(OwnerComp, DebuggerCategory);

	DebuggerCategory->AddTextLine(FString::Printf(TEXT("        {green}%s"), *DescribeBlueprintSelfToGameplayDebugger(&OwnerComp)));
}
#endif //WITH_GAMEPLAY_DEBUGGER_MENU