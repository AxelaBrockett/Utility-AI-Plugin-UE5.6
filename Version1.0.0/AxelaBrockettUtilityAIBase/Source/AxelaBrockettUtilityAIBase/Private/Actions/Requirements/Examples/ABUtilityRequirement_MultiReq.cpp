// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Actions/Requirements/Examples/ABUtilityRequirement_MultiReq.h"

#include "Components/ABUtilityComponent.h"

#if WITH_GAMEPLAY_DEBUGGER_MENU
#include "GameplayDebuggerCategory.h"
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

const bool UABUtilityRequirement_MultiReq::CheckRequirement(const UABUtilityComponent& OwnerComp) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityRequirement_MultiReq::CheckRequirement"))

	switch (GroupingOperator)
	{
		case (EABUtilityRequirementGroupingOperator::AND):
		{
			bool bRequirementsPassed = true;

			for (const UABUtilityRequirementBase* const Requirement : Requirements)
			{
				checkf(IsValid(Requirement), TEXT("Multi Requirement has an invalid requirement."));

				if (!Requirement->CheckRequirement(OwnerComp))
				{
					bRequirementsPassed = false;
					break;
				}
			}

			return bRequirementsPassed;
			break;
		}
		case (EABUtilityRequirementGroupingOperator::OR):
		{
			for (const UABUtilityRequirementBase* const Requirement : Requirements)
			{
				checkf(IsValid(Requirement), TEXT("Multi Requirement has an invalid requirement."));

				if (Requirement->CheckRequirement(OwnerComp))
				{
					return true;
				}
			}
			
			return false;
			break;
		}
	}

	return false;
}

const bool UABUtilityRequirement_MultiReq::ValidateRequirement(FString& InvalidationReason) const
{
	bool bIsValid = Super::ValidateRequirement(InvalidationReason);
	uint32 RequirementIndex = 0;

	for (const UABUtilityRequirementBase* const Requirement : Requirements)
	{
		if (!IsValid(Requirement))
		{
			InvalidationReason += FString::Printf(TEXT("Requirement in multi req is invalid, index: %i\n"), RequirementIndex);
			bIsValid = false;
			RequirementIndex++;
			continue;
		}

		if (!Requirement->ValidateRequirement(InvalidationReason))
		{
			InvalidationReason += FString::Printf(TEXT("Requirement in multi req failed validation, index: %i\n"), RequirementIndex);
			bIsValid = false;
			RequirementIndex++;
			continue;
		}

		RequirementIndex++;
	}
	
	return bIsValid;
}

#if WITH_GAMEPLAY_DEBUGGER_MENU
void UABUtilityRequirement_MultiReq::DescribeSelfToGameplayDebugger(const UABUtilityComponent& OwnerComp, FGameplayDebuggerCategory* DebuggerCategory) const
{
	if (DebuggerCategory == nullptr)
	{
		return;
	}

	Super::DescribeSelfToGameplayDebugger(OwnerComp, DebuggerCategory);

	DebuggerCategory->AddTextLine(FString::Printf(TEXT("            {blue}Multi-Requrement, Requirements held: %i"), Requirements.Num()));
	DebuggerCategory->AddTextLine(FString::Printf(TEXT("{blue}MULTI REQ START")));
	for (const UABUtilityRequirementBase* const Requirement : Requirements)
	{
		Requirement->DescribeSelfToGameplayDebugger(OwnerComp, DebuggerCategory);
	}
	DebuggerCategory->AddTextLine(FString::Printf(TEXT("{blue}MULTI REQ END")));
}
#endif //WITH_GAMEPLAY_DEBUGGER_MENU