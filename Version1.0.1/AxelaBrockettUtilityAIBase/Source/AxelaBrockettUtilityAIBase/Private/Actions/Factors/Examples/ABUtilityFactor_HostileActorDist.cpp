// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Actions/Factors/Examples/ABUtilityFactor_HostileActorDist.h"

#include "AIController.h"
#include "Components/ABUtilityComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "Helpers/ABUtilityTypes.h"
#include "Perception/AIPerceptionComponent.h"
#include "VisualLogger/VisualLogger.h"

#if WITH_GAMEPLAY_DEBUGGER_MENU
#include "GameplayDebuggerCategory.h"
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

UABUtilityFactor_HostileActorDist::UABUtilityFactor_HostileActorDist()
{
	MaxDist.DefaultValue = 1000.0f;
}

const bool UABUtilityFactor_HostileActorDist::ValidateFactor(FString& InvalidationReason) const
{
	bool bIsValid = Super::ValidateFactor(InvalidationReason);

	MaxDist.BindData(this, INDEX_NONE);
	const float MaxDistValue = MaxDist.GetValue();
	if (MaxDist.GetValue() <= 0.0f)
	{
		InvalidationReason += FString::Printf(TEXT("Max Dist is less than or equal to 0.0\n"));
		bIsValid = false;
	}

	return bIsValid;
}

const float UABUtilityFactor_HostileActorDist::CalculateFactorScore(const UABUtilityComponent& OwnerComp) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityFactor_HostileActorDist::CalculateFactorScore"))

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

	const UAIPerceptionComponent* const AIPerceptionComponent = AIController->FindComponentByClass<UAIPerceptionComponent>();
	if (!IsValid(AIPerceptionComponent))
	{
		UE_VLOG_UELOG(
			AIController,
			LogABUtility,
			Error,
			TEXT("%s - Could not get valid Perception Component from AI Controller [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*AIController->GetName()
		);
		return 0.0f;
	}

	const APawn* const Pawn = AIController->GetPawn();
	if (!IsValid(Pawn))
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

	MaxDist.BindData(Pawn, INDEX_NONE);
	const float MaxDistValue = MaxDist.GetValue();
	const float MaxDistSqr = MaxDistValue * MaxDistValue;

	TArray<AActor*> HostileActors;
	AIPerceptionComponent->GetHostileActors(HostileActors);

	float LowestDistance = FLT_MAX;
	for (const AActor* const HostileActor : HostileActors)
	{
		const float DistanceToActor = FVector::DistSquared(Pawn->GetActorLocation(), HostileActor->GetActorLocation());
		LowestDistance = DistanceToActor < LowestDistance ? DistanceToActor : LowestDistance;
	}

	if (LowestDistance > MaxDistSqr)
	{
		return 0.0f;
	}

	// Square root so we're working with more accurate values, for example (7-3)/7 (0.5 ish) instead of (49-9)/49 (0.8 ish)
	const float LowestDistanceRoot = FMath::Sqrt(LowestDistance);

	return (MaxDistValue - LowestDistanceRoot) / MaxDistValue;
}

#if WITH_GAMEPLAY_DEBUGGER_MENU
void UABUtilityFactor_HostileActorDist::DescribeSelfToGameplayDebugger(
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