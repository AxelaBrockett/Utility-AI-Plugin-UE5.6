// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Actions/Requirements/ABUtilityRequirementBPBase.h"

#include "Components/ABUtilityComponent.h"

#if WITH_GAMEPLAY_DEBUGGER_MENU
#include "GameplayDebuggerCategory.h"
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

const bool UABUtilityRequirementBlueprintBase::CheckRequirement(const UABUtilityComponent& OwnerComp) const
{
	return CheckBlueprintRequirement(&OwnerComp);
}

const bool UABUtilityRequirementBlueprintBase::ValidateRequirement(FString& InvalidationReason) const
{
	return Super::ValidateRequirement(InvalidationReason) && ValidateBlueprintRequirement(InvalidationReason, InvalidationReason);
}

#if WITH_GAMEPLAY_DEBUGGER_MENU
void UABUtilityRequirementBlueprintBase::DescribeSelfToGameplayDebugger(const UABUtilityComponent& OwnerComp, FGameplayDebuggerCategory* DebuggerCategory) const
{
	if (DebuggerCategory == nullptr)
	{
		return;
	}

	Super::DescribeSelfToGameplayDebugger(OwnerComp, DebuggerCategory);

	DebuggerCategory->AddTextLine(FString::Printf(TEXT("                {blue}%s"), *DescribeBlueprintSelfToGameplayDebugger(&OwnerComp)));
}
#endif //WITH_GAMEPLAY_DEBUGGER_MENU