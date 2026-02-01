// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "UObject/NoExportTypes.h"

#include "ABUtilityRequirementBase.generated.h"

class FGameplayDebuggerCategory;
class UABUtilityComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAsyncRequirementChecked, const UABUtilityRequirementBase*, Requirement, const bool, bRequirementPassed);

/**
 * Requirement for determining if a utility action can run
 */
UCLASS(EditInlineNew, Abstract)
class AXELABROCKETTUTILITYAIBASE_API UABUtilityRequirementBase : public UObject
{
	GENERATED_BODY()
	
public:
	// Requirement checking
	virtual const bool CheckRequirement(const UABUtilityComponent& OwnerComp) const { return true; }
	void AsyncCheckRequirement(const UABUtilityComponent& OwnerComp) const;

	// Validation
	virtual const bool ValidateRequirement(FString& InvalidationReason) const { return true; }

	// Debugging
#if WITH_GAMEPLAY_DEBUGGER_MENU
	virtual void DescribeSelfToGameplayDebugger(const UABUtilityComponent& OwnerComp, FGameplayDebuggerCategory* DebuggerCategory) const;
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

	// Delegate broadcasts
	FOnAsyncRequirementChecked OnAsyncRequirementCheckedDelegate;
};