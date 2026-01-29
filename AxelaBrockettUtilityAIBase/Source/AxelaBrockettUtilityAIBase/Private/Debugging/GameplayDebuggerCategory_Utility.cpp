// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Debugging/GameplayDebuggerCategory_Utility.h"

#if WITH_GAMEPLAY_DEBUGGER_MENU

#include "AIController.h"
#include "BrainComponent.h"
#include "Components/ABUtilityComponent.h"
#include "GameFramework/Pawn.h"

FGameplayDebuggerCategory_Utility::FGameplayDebuggerCategory_Utility()
{

}

TSharedRef<FGameplayDebuggerCategory> FGameplayDebuggerCategory_Utility::MakeInstance()
{
	return MakeShareable(new FGameplayDebuggerCategory_Utility());
}

void FGameplayDebuggerCategory_Utility::CollectData(APlayerController* OwnerPC, AActor* DebugActor)
{
	const APawn* const DebugPawn = Cast<APawn>(DebugActor);
	if (!IsValid(DebugPawn))
	{
		return;
	}

	const AAIController* const AIController = Cast<AAIController>(DebugPawn->GetController());
	if (!IsValid(AIController))
	{
		return;
	}

	const UBrainComponent* const BrainComponent = AIController->GetBrainComponent();
	if (!IsValid(BrainComponent))
	{
		return;
	}

	const UABUtilityComponent* const UtilityComponent = Cast<UABUtilityComponent>(BrainComponent);
	if (!IsValid(UtilityComponent))
	{
		return;
	}

	UtilityComponent->DescribeSelfToGameplayDebugger(this);
}

#endif //WITH_GAMEPLAY_DEBUGGER_MENU