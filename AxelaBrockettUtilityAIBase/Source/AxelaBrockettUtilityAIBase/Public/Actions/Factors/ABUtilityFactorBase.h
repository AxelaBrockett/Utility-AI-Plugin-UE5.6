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
	const float GetFactorScore(const UABUtilityComponent& OwnerComp, const float NumberOfFactors) const;

	const bool IsInversed() const;
	const bool IsUsingConsiderationFactor() const;

	virtual const bool ValidateFactor(FString& InvalidationReasons) const { return true; }

	// Debugging
#if WITH_GAMEPLAY_DEBUGGER_MENU
	virtual void DescribeSelfToGameplayDebugger(
		const UABUtilityComponent& OwnerComp,
		const float NumberOfFactors,
		FGameplayDebuggerCategory* DebuggerCategory
	) const;
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

protected:
	virtual const float CalculateFactorScore(const UABUtilityComponent& OwnerComp) const { return 1.0f; }

	void AddConsiderationFactor(const float NumberOfFactors, float& OutFloat) const;

private:
	UPROPERTY(EditAnywhere, Category = "Scoring")
	uint32 bInverseScore : 1;

	UPROPERTY(EditAnywhere, Category = "Scoring")
	uint32 bUseConsiderationFactor : 1;
};

FORCEINLINE const bool UABUtilityFactorBase::IsInversed() const
{
	return bInverseScore;
}

FORCEINLINE const bool UABUtilityFactorBase::IsUsingConsiderationFactor() const
{
	return bUseConsiderationFactor;
}