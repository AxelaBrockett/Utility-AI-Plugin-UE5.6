// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Actions/Requirements/ABUtilityRequirementBase.h"
#include "AITypes.h"
#include "DataProviders/AIDataProvider.h"
#include "Templates/SubclassOf.h"

#include "ABUtilityRequirement_SenseValue.generated.h"

class FGameplayDebuggerCategory;
class UAISense;
struct FAIStimulus;

/**
 * Compare a perception sense value to a given value
 */
UCLASS(meta = (DisplayName = "Sense Value Comparison"))
class AXELABROCKETTUTILITYAIBASE_API UABUtilityRequirement_SenseValue : public UABUtilityRequirementBase
{
	GENERATED_BODY()
	
public:
	UABUtilityRequirement_SenseValue();

	const bool CheckRequirement(const UABUtilityComponent& OwnerComp) const override;
	const bool ValidateRequirement(FString& InvalidationReason) const override;

#if WITH_GAMEPLAY_DEBUGGER_MENU
	void DescribeSelfToGameplayDebugger(const UABUtilityComponent& OwnerComp, FGameplayDebuggerCategory* DebuggerCategory) const override;
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

private:
	const float GetHighestStrengthFromStimuli(const TArray<FAIStimulus>& Stimuli) const;

	// The sense to check the value of.
	// If left blank or the agent does not use this sense, a general highest value will be used
	UPROPERTY(EditAnywhere, Category = "Utility AI Sense Value Requirement")
	TSubclassOf<UAISense> SenseToCheck;

	// The goal value to compare against
	UPROPERTY(EditAnywhere, Category = "Utility AI Sense Value Requirement")
	FAIDataProviderFloatValue GoalValue;

	// The type of comparison being made against the two values
	UPROPERTY(EditAnywhere, Category = "Utility AI Sense Value Requirement")
	EGenericAICheck ValueComparison = EGenericAICheck::Equal;
};