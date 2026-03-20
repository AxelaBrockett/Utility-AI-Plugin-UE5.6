// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Actions/Requirements/Examples/ABUtilityRequirement_HasActor.h"

#include "AIController.h"
#include "Components/ABUtilityComponent.h"
#include "GameFramework/Pawn.h"
#include "Helpers/ABUtilityHelpers.h"
#include "Helpers/ABUtilityTypes.h"

const bool UABUtilityRequirement_HasActor::CheckRequirement(const UABUtilityComponent& OwnerComp) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityRequirement_HasActor::CheckRequirement"))

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
		return false;
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
		return false;
	}
	
	// A Pawn is an Actor so we're good to confirm here
	return true;
}