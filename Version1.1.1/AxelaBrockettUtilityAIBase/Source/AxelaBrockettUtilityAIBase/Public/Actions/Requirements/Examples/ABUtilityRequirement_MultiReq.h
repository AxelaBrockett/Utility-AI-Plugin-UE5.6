// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Actions/Requirements/ABUtilityRequirementBase.h"

#include "ABUtilityRequirement_MultiReq.generated.h"

class FGameplayDebuggerCategory;
class UABUtilityComponent;

UENUM()
enum class EABUtilityRequirementGroupingOperator
{
	AND,
	OR
};

/**
 * Multiple requirements grouped together with an AND or OR operator
 */
UCLASS(meta = (DisplayName = "Multiple Requirements"))
class AXELABROCKETTUTILITYAIBASE_API UABUtilityRequirement_MultiReq : public UABUtilityRequirementBase
{
	GENERATED_BODY()
	
public:
	const bool CheckRequirement(const UABUtilityComponent& OwnerComp) const override;
	const bool ValidateRequirement(FString& InvalidationReason) const override;

#if WITH_GAMEPLAY_DEBUGGER_MENU
	void DescribeSelfToGameplayDebugger(const UABUtilityComponent& OwnerComp, FGameplayDebuggerCategory* DebuggerCategory) const override;
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

private:
	// Operator this Multi-Requirement uses to group requirements together
	UPROPERTY(EditAnywhere, Category = "Utility AI Multi Requirement")
	EABUtilityRequirementGroupingOperator GroupingOperator = EABUtilityRequirementGroupingOperator::AND;

	// Requirements grouped together
	UPROPERTY(EditAnywhere, Instanced, Category = "Utility AI Multi Requirement")
	TArray<TObjectPtr<UABUtilityRequirementBase>> Requirements;
};