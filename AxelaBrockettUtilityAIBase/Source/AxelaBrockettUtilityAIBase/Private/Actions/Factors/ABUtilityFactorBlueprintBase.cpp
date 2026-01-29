// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Actions/Factors/ABUtilityFactorBlueprintBase.h"

#include "Components/ABUtilityComponent.h"

#if WITH_GAMEPLAY_DEBUGGER_MENU
#include "GameplayDebuggerCategory.h"
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

const float UABUtilityFactorBlueprintBase::CalculateFactorScore(const UABUtilityComponent& OwnerComp) const
{
	return CalculateBlueprintFactorScore(&OwnerComp);
}

const bool UABUtilityFactorBlueprintBase::ValidateFactor(FString& InvalidationReason) const
{
	return Super::ValidateFactor(InvalidationReason) && ValidateBlueprintFactor(InvalidationReason, InvalidationReason);
}

#if WITH_GAMEPLAY_DEBUGGER_MENU
void UABUtilityFactorBlueprintBase::DescribeSelfToGameplayDebugger(
	const UABUtilityComponent& OwnerComp,
	const float NumberOfFactors,
	FGameplayDebuggerCategory* DebuggerCategory
) const
{
	if (DebuggerCategory == nullptr)
	{
		return;
	}

	Super::DescribeSelfToGameplayDebugger(OwnerComp, NumberOfFactors, DebuggerCategory);

	DebuggerCategory->AddTextLine(FString::Printf(TEXT("                {red}%s"), *DescribeBlueprintSelfToGameplayDebugger(&OwnerComp, NumberOfFactors)));
}
#endif //WITH_GAMPLAY_DEBUGGER_MENU