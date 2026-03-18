// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Actions/Factors/Examples/ABUtilityFactor_DistToPlayer.h"

#include "AIController.h"
#include "Components/ABUtilityComponent.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "Helpers/ABUtilityHelpers.h"
#include "Helpers/ABUtilityTypes.h"

#if WITH_GAMEPLAY_DEBUGGER_MENU
#include "GameplayDebuggerCategory.h"
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

UABUtilityFactor_DistToPlayer::UABUtilityFactor_DistToPlayer()
{
	MaxDist.DefaultValue = 1000.0f;
}

const bool UABUtilityFactor_DistToPlayer::ValidateFactor(FString& InvalidationReason) const
{
	bool bIsValid = Super::ValidateFactor(InvalidationReason);

	MaxDist.BindData(this, INDEX_NONE);
	if (MaxDist.GetValue() <= 0.0f)
	{
		InvalidationReason += FString::Printf(TEXT("Max Dist is less than or equal to 0.0\n"));
		bIsValid = false;
	}

	return bIsValid;
}

const float UABUtilityFactor_DistToPlayer::CalculateFactorScore(const UABUtilityComponent& OwnerComp) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityFactor_DistToPlayer::CalculateFactorScore"))

	const UWorld* const World = GetWorld();
	if (!IsValid(World))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Could not get valid world."),
				ANSI_TO_TCHAR(__FUNCTION__)
			),
			OwnerComp.GetOwner()
		);
		return 0.0f;
	}

	const APlayerController* const PlayerController = World->GetFirstPlayerController();
	if (!IsValid(PlayerController))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Could not get valid First Player Controller from World [ %s ]."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*World->GetName()
			),
			OwnerComp.GetOwner()
		);
		return 0.0f;
	}

	const APawn* const PlayerPawn = PlayerController->GetPawn();
	if (!IsValid(PlayerPawn))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Could not get valid Pawn from Player Controller [ %s ]."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*PlayerController->GetName()
			),
			OwnerComp.GetOwner()
		);
		return 0.0f;
	}

	const AAIController* const AIController = OwnerComp.GetAIOwner();
	if (!IsValid(AIController))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Could not get valid AI Controller from Component [ %s ]."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp.GetName()
			),
			OwnerComp.GetOwner()
		);
		return 0.0f;
	}

	const APawn* const AIPawn = AIController->GetPawn();
	if (!IsValid(AIPawn))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Could not get valid Pawn from AI Controller [ %s ]."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*AIController->GetName()
			),
			AIController
		);
		return 0.0f;
	}

	MaxDist.BindData(AIPawn, INDEX_NONE);
	const float MaxDistValue = MaxDist.GetValue();
	const float MaxDistSqr = MaxDistValue * MaxDistValue;
	const float DistanceToPlayerSqr = FVector::DistSquared(AIPawn->GetActorLocation(), PlayerPawn->GetActorLocation());
	
	if (DistanceToPlayerSqr > MaxDistSqr)
	{
		return 0.0f;
	}

	// Square root so we're working with more accurate values, for example (7-3)/7 (0.5 ish) instead of (49-9)/49 (0.8 ish)
	const float DistanceToPlayer = FMath::Sqrt(DistanceToPlayerSqr);

	return (MaxDistValue - DistanceToPlayer) / MaxDistValue;
}

#if WITH_GAMEPLAY_DEBUGGER_MENU
void UABUtilityFactor_DistToPlayer::DescribeSelfToGameplayDebugger(
	const UABUtilityComponent& OwnerComp,
	const float NumberOfFactors,
	const bool bUseConsiderationFactor,
	FGameplayDebuggerCategory* DebuggerCategory
) const
{
	if (DebuggerCategory == nullptr)
	{
		return;
	}
	
	Super::DescribeSelfToGameplayDebugger(OwnerComp, NumberOfFactors, bUseConsiderationFactor, DebuggerCategory);

	const AAIController* const AIController = OwnerComp.GetAIOwner();
	if (IsValid(AIController))
	{
		MaxDist.BindData(AIController->GetPawn(), INDEX_NONE);
	}

	DebuggerCategory->AddTextLine(FString::Printf(TEXT("                {red}Max Dist: %f"), MaxDist.GetValue()));
}
#endif //WITH_GAMEPLAY_DEBUGGER_MENU