// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Actions/Actions/ABUtilityActionBase.h"
#include "Helpers/ABUtilityTypes.h"

#include "ABUtilityActionBlueprintBase.generated.h"

class FGameplayDebuggerCategory;
class UABUtilityComponent;

/**
 * Base for BP actions
 * Runs BP logic with available code
 */
UCLASS(Abstract, Blueprintable)
class AXELABROCKETTUTILITYAIBASE_API UABUtilityActionBlueprintBase : public UABUtilityActionBase
{
	GENERATED_BODY()

public:
	// Validation
	const bool ValidateAction(FString& InvalidationReason) const override;

	// Debugging
#if WITH_GAMEPLAY_DEBUGGER_MENU
	void DescribeSelfToGameplayDebugger(
		const UABUtilityComponent& OwnerComp,
		const bool bUseConsiderationFactor,
		const UABUtilityActionInstanceMemoryBase* InstanceMemory,
		FGameplayDebuggerCategory* DebuggerCategory
	) const override;
#endif //WITH_GAMEPLAY_DEBUGGER_MENU
	
protected:
	// Validation
	UFUNCTION(BlueprintNativeEvent)
	const bool ValidateBlueprintAction(const FString& InInvalidationReason, FString& OutInvalidationReason) const;
	virtual const bool ValidateBlueprintAction_Implementation(const FString& InInvalidationReason, FString& OutInvalidationReason) const { return true; }

	// Debugging
	// Return string to be added to debug
	UFUNCTION(BlueprintNativeEvent)
	const FString DescribeBlueprintSelfToGameplayDebugger(const UABUtilityComponent* const OwnerComp) const;
	virtual const FString DescribeBlueprintSelfToGameplayDebugger_Implementation(const UABUtilityComponent* const OwnerComp) const { return FString(); }

	// Internal action logic
	EABUtilityActionRunStatus DoAction(
		UABUtilityComponent& OwnerComp,
		UABUtilityActionInstanceMemoryBase* InstanceMemory
	) override;

	UFUNCTION(BlueprintNativeEvent)
	EABUtilityActionRunStatus DoBlueprintAction(UABUtilityComponent* OwnerComp);
	virtual EABUtilityActionRunStatus DoBlueprintAction_Implementation(UABUtilityComponent* OwnerComp)
	{
		return EABUtilityActionRunStatus::Succeeded;
	}

	// Internal tick logic
	EABUtilityActionRunStatus Tick(
		UABUtilityComponent& OwnerComp,
		float DeltaSeconds,
		UABUtilityActionInstanceMemoryBase* InstanceMemory
	) override;

	UFUNCTION(BlueprintNativeEvent)
	EABUtilityActionRunStatus TickBlueprintAction(UABUtilityComponent* OwnerComp, float DeltaSeconds);
	virtual EABUtilityActionRunStatus TickBlueprintAction_Implementation(UABUtilityComponent* OwnerComp, float DeltaSeconds)
	{
		return EABUtilityActionRunStatus::Succeeded;
	}
};