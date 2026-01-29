// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Actions/Requirements/Examples/ABUtilityRequirement_HasActor.h"

#include "AIController.h"
#include "Components/ABUtilityComponent.h"
#include "GameFramework/Pawn.h"
#include "Helpers/ABUtilityTypes.h"
#include "VisualLogger/VisualLogger.h"

const bool UABUtilityRequirement_HasActor::CheckRequirement(const UABUtilityComponent& OwnerComp) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityRequirement_HasActor::CheckRequirement"))

	const AAIController* const AIController = OwnerComp.GetAIOwner();
	if (!IsValid(AIController))
	{
		UE_VLOG_UELOG(
			OwnerComp.GetOwner(),
			LogABUtility,
			Error,
			TEXT("%s - Could not get valid AI Controller owner from owner comp [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*OwnerComp.GetName()
		);
		return false;
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
		return false;
	}
	
	// A Pawn is an Actor so we're good to confirm here
	return true;
}