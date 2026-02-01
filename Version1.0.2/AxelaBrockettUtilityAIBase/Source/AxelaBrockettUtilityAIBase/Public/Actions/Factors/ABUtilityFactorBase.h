// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "UObject/NoExportTypes.h"

#include "ABUtilityFactorBase.generated.h"

class FGameplayDebuggerCategory;
class UABUtilityComponent;

/**
 * Factor for determining the score of an action
 */
UCLASS(EditInlineNew, Abstract)
class AXELABROCKETTUTILITYAIBASE_API UABUtilityFactorBase : public UObject
{
	GENERATED_BODY()
	
public:
	// Scoring
	const float GetFactorScore(const UABUtilityComponent& OwnerComp, const float NumberOfFactors, const bool bUseConsiderationFactor) const;

	// Inlines
	const bool IsInversed() const;

	// Validation
	virtual const bool ValidateFactor(FString& InvalidationReasons) const { return true; }

	// Debugging
#if WITH_GAMEPLAY_DEBUGGER_MENU
	virtual void DescribeSelfToGameplayDebugger(
		const UABUtilityComponent& OwnerComp,
		const float NumberOfFactors,
		const bool bUseConsiderationFactor,
		FGameplayDebuggerCategory* DebuggerCategory
	) const;
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

protected:
	// Internal scoring
	virtual const float CalculateFactorScore(const UABUtilityComponent& OwnerComp) const { return 1.0f; }
	void AddConsiderationFactor(const float NumberOfFactors, float& OutFloat) const;

private:
	// Inlines
	UPROPERTY(EditAnywhere, Category = "Scoring")
	uint32 bInverseScore : 1;
};

FORCEINLINE const bool UABUtilityFactorBase::IsInversed() const
{
	return bInverseScore;
}