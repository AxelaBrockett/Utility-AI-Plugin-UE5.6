// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Actions/Factors/ABUtilityFactorBase.h"

#include "ABUtilityFactorBlueprintBase.generated.h"

class FGameplayDebuggerCategory;
class UABUtilityComponent;

/**
 * 
 */
UCLASS(Abstract, Blueprintable)
class AXELABROCKETTUTILITYAIBASE_API UABUtilityFactorBlueprintBase : public UABUtilityFactorBase
{
	GENERATED_BODY()

public:
	// Validation
	const bool ValidateFactor(FString& InvalidationReasons) const override;

	// Debugging
#if WITH_GAMEPLAY_DEBUGGER_MENU
	void DescribeSelfToGameplayDebugger(
		const UABUtilityComponent& OwnerComp,
		const float NumberOfFactors,
		const bool bUseConsiderationFactor,
		FGameplayDebuggerCategory* DebuggerCategory
	) const override;
#endif //WITH_GAMEPLAY_DEBUGGER_MENU
	
protected:
	// Validation
	UFUNCTION(BlueprintNativeEvent)
	const bool ValidateBlueprintFactor(const FString& InInvalidationReason, FString& OutInvalidationReason) const;
	virtual const bool ValidateBlueprintFactor_Implementation(const FString& InInvalidationReason, FString& OutInvalidationReason) const { return true; }

	// Debugging
	// Return string to be added to debug
	UFUNCTION(BlueprintNativeEvent)
	const FString DescribeBlueprintSelfToGameplayDebugger(const UABUtilityComponent* const OwnerComp, const float NumberOfFactors) const;
	virtual const FString DescribeBlueprintSelfToGameplayDebugger_Implementation(const UABUtilityComponent* const OwnerComp, const float NumberOfFactors) const { return FString(); }

	// Internal scoring
	const float CalculateFactorScore(const UABUtilityComponent& OwnerComp) const override;

	UFUNCTION(BlueprintNativeEvent)
	const float CalculateBlueprintFactorScore(const UABUtilityComponent* const OwnerComp) const;
	virtual const float CalculateBlueprintFactorScore_Implementation(const UABUtilityComponent* const OwnerComp) const { return 1.0f; }
};