// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Actions/Requirements/ABUtilityRequirementBase.h"

#include "ABUtilityRequirementBPBase.generated.h"

class FGameplayDebuggerCategory;
class UABUtilityComponent;

/**
 * 
 */
UCLASS(Abstract, Blueprintable)
class AXELABROCKETTUTILITYAIBASE_API UABUtilityRequirementBlueprintBase : public UABUtilityRequirementBase
{
	GENERATED_BODY()
	
public:
	// Requirement checking
	const bool CheckRequirement(const UABUtilityComponent& OwnerComp) const override;

	// Validation
	const bool ValidateRequirement(FString& InvalidationReason) const override;

	// Debugging
#if WITH_GAMEPLAY_DEBUGGER_MENU
	void DescribeSelfToGameplayDebugger(const UABUtilityComponent& OwnerComp, FGameplayDebuggerCategory* DebuggerCategory) const override;
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

protected:
	// Validation
	UFUNCTION(BlueprintNativeEvent)
	const bool ValidateBlueprintRequirement(const FString& InInvalidationReason, FString& OutInvalidationReason) const;
	virtual const bool ValidateBlueprintRequirement_Implementation(const FString& InInvalidationReason, FString& OutInValidationReason) const { return true; }

	// Debugging
	// Return string to be added to debug
	UFUNCTION(BlueprintNativeEvent)
	const FString DescribeBlueprintSelfToGameplayDebugger(const UABUtilityComponent* const OwnerComp) const;
	virtual const FString DescribeBlueprintSelfToGameplayDebugger_Implementation(const UABUtilityComponent* const OwnerComp) const { return FString(); }

	// Internal requirement checking
	UFUNCTION(BlueprintNativeEvent)
	const bool CheckBlueprintRequirement(const UABUtilityComponent* const OwnerComp) const;
	virtual const bool CheckBlueprintRequirement_Implementation(const UABUtilityComponent* const OwnerComp) const { return true; }
};