// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Actions/Factors/ABUtilityFactorBase.h"

#include "Components/ABUtilityComponent.h"

#if WITH_GAMEPLAY_DEBUGGER_MENU
#include "GameplayDebuggerCategory.h"
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

const float UABUtilityFactorBase::GetFactorScore(const UABUtilityComponent& OwnerComp, const float NumberOfFactors, const bool bUseConsiderationFactor) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityFactorBase::GetFactorScore"))

	const float BaseScore = IsInversed() ? 1.0f - CalculateFactorScore(OwnerComp) : CalculateFactorScore(OwnerComp);

	float FinalScore = BaseScore;
	if (bUseConsiderationFactor)
	{
		AddConsiderationFactor(NumberOfFactors, FinalScore);
	}

	return FinalScore;
}

void UABUtilityFactorBase::AddConsiderationFactor(const float NumberOfFactors, float& OutFloat) const
{
	// Implement Consideration Factor described in this video:
	// https://gdcvault.com/play/1021848/Building-a-Better-Centaur-AI
	const float ModificationFactor = 1.0f - (1.0f / NumberOfFactors);
	const float MakeUpValue = (1.0f - OutFloat) * ModificationFactor;
	const float FinalScore = OutFloat + (MakeUpValue * OutFloat);
	OutFloat = FinalScore;
}

#if WITH_GAMEPLAY_DEBUGGER_MENU
void UABUtilityFactorBase::DescribeSelfToGameplayDebugger(
	const UABUtilityComponent& OwnerComp,
	const float NumberOfFactors,
	const bool bUseConsiderationFactor,
	FGameplayDebuggerCategory* DebuggerCategory
) const
{
	if (DebuggerCategory == nullptr)
	{
		return;
	}

	DebuggerCategory->AddTextLine(FString::Printf(TEXT("            {red}Factor Name: %s"), *GetName()));
	DebuggerCategory->AddTextLine(
		FString::Printf(TEXT("                {red}Inverse Score: %s / Use Consideration Factor: %s / Current Score: %f"),
			IsInversed() ? TEXT("true") : TEXT("false"),
			bUseConsiderationFactor ? TEXT("true") : TEXT("false"),
			GetFactorScore(OwnerComp, NumberOfFactors, bUseConsiderationFactor)
		)
	);
}
#endif //WITH_GAMEPLAY_DEBUGGER_MENU