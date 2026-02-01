// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Actions/Factors/Examples/ABUtilityFactor_DistToPlayer.h"

#include "AIController.h"
#include "Components/ABUtilityComponent.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "Helpers/ABUtilityTypes.h"
#include "VisualLogger/VisualLogger.h"

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

	const UWorld* const World = OwnerComp.GetWorld();
	if (!IsValid(World))
	{
		UE_VLOG_UELOG(
			OwnerComp.GetOwner(),
			LogABUtility,
			Error,
			TEXT("%s - Could not get valid world from Owner Component [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*OwnerComp.GetName()
		);
		return 0.0f;
	}

	const APlayerController* const PlayerController = World->GetFirstPlayerController();
	if (!IsValid(PlayerController))
	{
		UE_VLOG_UELOG(
			OwnerComp.GetOwner(),
			LogABUtility,
			Error,
			TEXT("%s - Could not get valid first Player Controller from world [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*World->GetName()
		);
		return 0.0f;
	}

	const APawn* const PlayerPawn = PlayerController->GetPawn();
	if (!IsValid(PlayerPawn))
	{
		UE_VLOG_UELOG(
			OwnerComp.GetOwner(),
			LogABUtility,
			Error,
			TEXT("%s - Could not get valid pawn from Player Controller [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*PlayerController->GetName()
		);
		return 0.0f;
	}

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
		return 0.0f;
	}

	const APawn* const AIPawn = AIController->GetPawn();
	if (!IsValid(AIPawn))
	{
		UE_VLOG_UELOG(
			AIController,
			LogABUtility,
			Error,
			TEXT("%s - Could not get valid Pawn from AI Controller [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*AIController->GetName()
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