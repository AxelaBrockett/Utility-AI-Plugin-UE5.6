// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Actions/Requirements/ABUtilityRequirementBase.h"

#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"
#include "Components/ABUtilityComponent.h"

#if WITH_GAMEPLAY_DEBUGGER_MENU
#include "GameplayDebuggerCategory.h"
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

void UABUtilityRequirementBase::AsyncCheckRequirement(const UABUtilityComponent& OwnerComp) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityRequirementBase::AsyncCheckRequirement"))

	const bool bRequirementHasPassed = CheckRequirement(OwnerComp);
	AsyncTask(ENamedThreads::GameThread, [this, &bRequirementHasPassed]()
		{
			OnAsyncRequirementCheckedDelegate.Broadcast(this, bRequirementHasPassed);
		}
	);
}

#if	WITH_GAMEPLAY_DEBUGGER_MENU
void UABUtilityRequirementBase::DescribeSelfToGameplayDebugger(const UABUtilityComponent& OwnerComp, FGameplayDebuggerCategory* DebuggerCategory) const
{
	if (DebuggerCategory == nullptr)
	{
		return;
	}

	DebuggerCategory->AddTextLine(FString::Printf(TEXT("            {blue}Requirement Name: %s"), *GetName()));
	DebuggerCategory->AddTextLine(
		FString::Printf(TEXT("                {blue}Current Result: %s"),
			CheckRequirement(OwnerComp) ? TEXT("Pass") : TEXT("Fail"))
	);
}
#endif //WITH_GAMEPLAY_DEBUGGER_MENU