// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Actions/Requirements/Examples/ABUtilityRequirement_SenseValue.h"

#include "AIController.h"
#include "Components/ABUtilityComponent.h"
#include "Helpers/ABUtilityHelpers.h"
#include "Helpers/ABUtilityTypes.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AIPerceptionTypes.h"
#include "Perception/AISense.h"
#include "VisualLogger/VisualLogger.h"

#if WITH_GAMEPLAY_DEBUGGER_MENU
#include "GameplayDebuggerCategory.h"
#endif // WITH_GAMEPLAY_DEBUGGER_MENU

UABUtilityRequirement_SenseValue::UABUtilityRequirement_SenseValue()
{
	GoalValue.DefaultValue = 0.0f;
}

const bool UABUtilityRequirement_SenseValue::CheckRequirement(const UABUtilityComponent& OwnerComp) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityRequirement_SenseValue::CheckRequirement"))

	const AAIController* const AIController = OwnerComp.GetAIOwner();
	if (!IsValid(AIController))
	{
		UE_VLOG_UELOG(
			OwnerComp.GetOwner(),
			LogABUtility,
			Error,
			TEXT("%s - Could not get valid AI Controller from Owner Component [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*OwnerComp.GetName()
		);
		return false;
	}

	GoalValue.BindData(AIController, INDEX_NONE);

	const UAIPerceptionComponent* const PerceptionComponent = AIController->FindComponentByClass<UAIPerceptionComponent>();
	if (!IsValid(PerceptionComponent))
	{
		UE_VLOG_UELOG(
			AIController,
			LogABUtility,
			Error,
			TEXT("%s - Could not get valid Perception Component from AI Controller [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*AIController->GetName()
		);
		return false;
	}

	const FAISenseID SenseID = UAISense::GetSenseID(SenseToCheck);
	if (!SenseID.IsValid())
	{
		UE_VLOG_UELOG(
			AIController,
			LogABUtility,
			Error,
			TEXT("%s - Could not get valid sense ID. Result will be generic."),
			ANSI_TO_TCHAR(__FUNCTION__)
		);
	}

	float HighestStrengthValue = 0.0f;
	for (UAIPerceptionComponent::FActorPerceptionContainer::TConstIterator DataIt = PerceptionComponent->GetPerceptualDataConstIterator(); DataIt; ++DataIt)
	{
		const FActorPerceptionInfo* const ActorInfo = &DataIt->Value;
		if (ActorInfo == nullptr)
		{
			continue;
		}

		const float SenseValue = SenseID.IsValid() ? ActorInfo->LastSensedStimuli[SenseID].Strength : GetHighestStrengthFromStimuli(ActorInfo->LastSensedStimuli);
		HighestStrengthValue = SenseValue > HighestStrengthValue ? SenseValue : HighestStrengthValue;
	}

	const float GVValue = GoalValue.GetValue();
	const bool bComparison = ABUtility::Helpers::Requirements::CompareValues(HighestStrengthValue, GVValue, ValueComparison);
	return bComparison;
}

const bool UABUtilityRequirement_SenseValue::ValidateRequirement(FString& InvalidationReason) const
{
	bool bIsValid = Super::ValidateRequirement(InvalidationReason);

	GoalValue.BindData(this, INDEX_NONE);
	if (GoalValue.GetValue() < 0.0f)
	{
		InvalidationReason += FString::Printf(TEXT("Goal Value less than 0.0\n"));
		bIsValid = false;
	}

	return bIsValid;
}

const float UABUtilityRequirement_SenseValue::GetHighestStrengthFromStimuli(const TArray<FAIStimulus>& Stimuli) const
{
	float HighestStrength = 0.0f;
	for (const FAIStimulus& Stimulus : Stimuli)
	{
		const float StimulusStrength = Stimulus.Strength;
		HighestStrength = StimulusStrength > HighestStrength ? StimulusStrength : HighestStrength;
	}
	return HighestStrength;
}

#if WITH_GAMEPLAY_DEBUGGER_MENU
void UABUtilityRequirement_SenseValue::DescribeSelfToGameplayDebugger(const UABUtilityComponent& OwnerComp, FGameplayDebuggerCategory* DebuggerCategory) const
{
	if (DebuggerCategory == nullptr)
	{
		return;
	}

	Super::DescribeSelfToGameplayDebugger(OwnerComp, DebuggerCategory);

	DebuggerCategory->AddTextLine(FString::Printf(TEXT("                {blue}Sense To Check: %s / Goal Value: %f / Value Comparison: %s"),
		*GetNameSafe(SenseToCheck),
		GoalValue.GetValue(),
		ValueComparison == EGenericAICheck::Equal ? TEXT("Equal") :
		ValueComparison == EGenericAICheck::Greater ? TEXT("Greater") :
		ValueComparison == EGenericAICheck::GreaterOrEqual ? TEXT("Greater Or Equal") :
		ValueComparison == EGenericAICheck::IsTrue ? TEXT("Is True") :
		ValueComparison == EGenericAICheck::Less ? TEXT("Less") :
		ValueComparison == EGenericAICheck::LessOrEqual ? TEXT("Less Or Equal") :
		ValueComparison == EGenericAICheck::NotEqual ? TEXT("Not Equal"):
		TEXT("None")
	));
}
#endif //WITH_GAMEPLAY_DEBUGGER_MENU