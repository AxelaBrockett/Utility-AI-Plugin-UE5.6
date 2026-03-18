// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Actions/Actions/Examples/ABUtilityAction_RunGA.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "AIController.h"
#include "Components/ABUtilityComponent.h"
#include "GameFramework/Pawn.h"
#include "GameplayAbilitySpec.h"
#include "Helpers/ABUtilityHelpers.h"

#if WITH_GAMEPLAY_DEBUGGER_MENU
#include "GameplayDebuggerCategory.h"
#endif // WITH_GAMEPLAY_DEBUGGER_MENU

EABUtilityActionRunStatus UABUtilityAction_RunGameplayAbility::DoAction(
	UABUtilityComponent& OwnerComp,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	const AAIController* const AIController = OwnerComp.GetAIOwner();
	if (!IsValid(AIController))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(
				TEXT("%s - Utility Component [ %s ] does not have a valid AI Owner."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp.GetName()
			),
			OwnerComp.GetOwner()
		);
		return EABUtilityActionRunStatus::Failed;
	}

	const APawn* const AIPawn = AIController->GetPawn();
	if (!IsValid(AIPawn))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Warning,
			FString::Printf(
				TEXT("%s - AI Controller [ %s ] does not have a valid Pawn."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*AIController->GetName()
			),
			AIController
		);
		return EABUtilityActionRunStatus::Failed;
	}

	UAbilitySystemComponent* const ASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(AIPawn);
	if (!IsValid(ASC))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Warning,
			FString::Printf(
				TEXT("%s - Pawn [ %s ] does not have a valid Ability System Component, please add one and ensure the ")
				TEXT("Pawn class inherits from IAbilitySystemInterface."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*AIPawn->GetName()
			),
			AIController
		);
		return EABUtilityActionRunStatus::Failed;
	}

	switch (RunGameplayAbilityFrom)
	{
		default:
		{
			break;
		}
		case (EABUtilityRunGAFromType::Class):
		{
			if (ASC->TryActivateAbilityByClass(ClassOfGameplayAbilityToRun))
			{
				return EABUtilityActionRunStatus::Succeeded;
				break;
			}

			const FGameplayAbilitySpec* const AbilitySpec = ASC->FindAbilitySpecFromClass(ClassOfGameplayAbilityToRun);
			if (AbilitySpec == nullptr)
			{
				if (!bGiveAbilityIfNotOwned)
				{
					ABUtility::Helpers::UtilityVLOG(
						ELogVerbosity::Warning,
						FString::Printf(
							TEXT("%s - Ability Pawn [ %s ] does not have the Ability [ %s ]."),
							ANSI_TO_TCHAR(__FUNCTION__),
							*AIPawn->GetName(),
							*ClassOfGameplayAbilityToRun->GetName()
						),
						AIController
					);
					break;
				}

				const FGameplayAbilitySpec NewAbilitySpec(ClassOfGameplayAbilityToRun);
				const FGameplayAbilitySpecHandle AbilitySpecHandle = ASC->GiveAbility(NewAbilitySpec);
				if (!AbilitySpecHandle.IsValid())
				{
					ABUtility::Helpers::UtilityVLOG(
						ELogVerbosity::Warning,
						FString::Printf(
							TEXT("%s - Failed to give Ability Pawn [ %s ] Ability [ %s ]."),
							ANSI_TO_TCHAR(__FUNCTION__),
							*AIPawn->GetName(),
							*ClassOfGameplayAbilityToRun->GetName()
						),
						AIController
					);
					break;
				}
			}

			if (ASC->TryActivateAbilityByClass(ClassOfGameplayAbilityToRun))
			{
				return EABUtilityActionRunStatus::Succeeded;
				break;
			}

			break;
		}
		case (EABUtilityRunGAFromType::Tag):
		{
			if (ASC->TryActivateAbilitiesByTag(TagsOfGameplayAbilitiesToRun))
			{
				return EABUtilityActionRunStatus::Succeeded;
			}
			break;
		}
	}

	ABUtility::Helpers::UtilityVLOG(
		ELogVerbosity::Error,
		FString::Printf(
			TEXT("%s - Failed to run Gameplay Abilities."),
			ANSI_TO_TCHAR(__FUNCTION__)
		),
		AIController
	);
	return EABUtilityActionRunStatus::Failed;
}

const bool UABUtilityAction_RunGameplayAbility::ValidateAction(FString& InvalidationReason) const
{
	bool bIsValid = Super::ValidateAction(InvalidationReason);

	switch (RunGameplayAbilityFrom)
	{
		case (EABUtilityRunGAFromType::Class):
		{
			if (!IsValid(ClassOfGameplayAbilityToRun))
			{
				InvalidationReason += FString::Printf(TEXT("No valid Gameplay Ability class set."));
				bIsValid = false;
			}
			break;
		}
		case (EABUtilityRunGAFromType::Tag):
		{
			if (!TagsOfGameplayAbilitiesToRun.IsValid())
			{
				InvalidationReason += FString::Printf(TEXT("No tags added to Gameplay Ability tag list."));
				bIsValid = false;
			}
			break;
		}
		default:
		{
			InvalidationReason += FString::Printf(TEXT("Unexpected value for Run Gameplay Ability From."));
			bIsValid = false;
			break;
		}
	}

	return bIsValid;
}

#if WITH_GAMEPLAY_DEBUGGER_MENU
void UABUtilityAction_RunGameplayAbility::DescribeSelfToGameplayDebugger(
	const UABUtilityComponent& OwnerComp,
	const bool bUseConsiderationFactor,
	const UABUtilityActionInstanceMemoryBase* InstanceMemory,
	FGameplayDebuggerCategory* DebuggerCategory
) const
{
	if (DebuggerCategory == nullptr)
	{
		return;
	}

	Super::DescribeSelfToGameplayDebugger(
		OwnerComp,
		bUseConsiderationFactor,
		InstanceMemory,
		DebuggerCategory
	);

	DebuggerCategory->AddTextLine(
		FString::Printf(TEXT("        {green}Run Gameplay Ability From: %s / Class Of Gameplay Ability To Run: %s / Tags Of Gameplay Abilities To Run: %s / Give Ability If Not Owned: %s"),
			RunGameplayAbilityFrom == EABUtilityRunGAFromType::Class ? TEXT("Class") :
			RunGameplayAbilityFrom == EABUtilityRunGAFromType::Tag ? TEXT("Tag") :
			TEXT("None"),
			*GetNameSafe(ClassOfGameplayAbilityToRun),
			*TagsOfGameplayAbilitiesToRun.ToString(),
			bGiveAbilityIfNotOwned ? TEXT("true") : TEXT("false")
		)
	);
}
#endif // WITH_GAMEPLAY_DEBUGGER_MENU