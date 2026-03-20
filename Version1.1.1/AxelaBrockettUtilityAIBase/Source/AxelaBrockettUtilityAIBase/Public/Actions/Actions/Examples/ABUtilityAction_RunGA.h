// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Abilities/GameplayAbility.h"
#include "Actions/Actions/ABUtilityActionBase.h"
#include "GameplayTagContainer.h"
#include "Helpers/ABUtilityTypes.h"
#include "Templates/SubclassOf.h"

#include "ABUtilityAction_RunGA.generated.h"

class FGameplayDebuggerCategory;
class UABUtilityComponent;

UENUM()
enum class EABUtilityRunGAFromType : uint8
{
	Tag,
	Class
};

/**
 * 
 */
UCLASS()
class AXELABROCKETTUTILITYAIBASE_API UABUtilityAction_RunGameplayAbility : public UABUtilityActionBase
{
	GENERATED_BODY()

public:
	const bool ValidateAction(FString& InvalidationReason) const override;

#if WITH_GAMEPLAY_DEBUGGER_MENU
	virtual void DescribeSelfToGameplayDebugger(
		const UABUtilityComponent& OwnerComp,
		const bool bUseConsiderationFactor,
		const UABUtilityActionInstanceMemoryBase* InstanceMemory,
		FGameplayDebuggerCategory* DebuggerCategory
	) const;
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

protected:
	EABUtilityActionRunStatus DoAction(
		UABUtilityComponent& OwnerComp,
		UABUtilityActionInstanceMemoryBase* InstanceMemory
	) override;
	
private:
	// The method to use to try and run a Gameplay Ability
	UPROPERTY(EditAnywhere, Category = "Utility Run Gameplay Ability")
	EABUtilityRunGAFromType RunGameplayAbilityFrom = EABUtilityRunGAFromType::Class;

	// The class of Gameplay Ability to run
	UPROPERTY(EditAnywhere, Category = "Utility Run Gameplay Ability", meta = (EditCondition = "RunGameplayAbilityFrom==EABUtilityRunGAFromType::Class", EditConditionHides))
	TSubclassOf<UGameplayAbility> ClassOfGameplayAbilityToRun;

	// The Gameplay Tags to match and find Gameplay Abilities to run
	UPROPERTY(EditAnywhere, Category = "Utility Run Gameplay Ability", meta = (EditCondition = "RunGameplayAbilityFrom==EABUtilityRunGAFromType::Tag", EditConditionHides))
	FGameplayTagContainer TagsOfGameplayAbilitiesToRun;

	// If the Actor does not own the chosen Gameplay Ability, give them the Ability
	UPROPERTY(EditAnywhere, Category = "Utility Run Gameplay Ability", meta = (EditCondition = "RunGameplayAbilityFrom==EABUtilityRunGAFromType::Class", EditConditionHides))
	bool bGiveAbilityIfNotOwned = false;
};