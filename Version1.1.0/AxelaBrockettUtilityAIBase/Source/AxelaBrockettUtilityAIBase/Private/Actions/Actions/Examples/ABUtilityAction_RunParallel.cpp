// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Actions/Actions/Examples/ABUtilityAction_RunParallel.h"

#include "Components/ABUtilityComponent.h"
#include "Engine/World.h"
#include "Helpers/ABUtilityHelpers.h"
#include "Subsystems/ABUtilitySubsystem.h"

#if WITH_GAMEPLAY_DEBUGGER_MENU
#include "GameplayDebuggerCategory.h"
#endif // WITH_GAMEPLAY_DEBUGGER_MENU

void UABUtilityAction_RunParallel::Initialize(UWorld* InWorld)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_RunParallel::Initialize"))
	
	Super::Initialize(InWorld);

	OwnFactors = Factors;
	OwnRequirements = Requirements;

	for (UABUtilityActionBase* const ParallelAction : ParallelActions)
	{
		checkf(IsValid(ParallelAction), TEXT("Run Parallel contains invalid Action."));
		ParallelAction->Initialize(InWorld);
		ParallelAction->OnActionCompletedDelegate.AddDynamic(this, &UABUtilityAction_RunParallel::OnParallelActionCompleted);

		Factors.Append(ParallelAction->GetFactors());
		Requirements.Append(ParallelAction->GetRequirements());

		const TSubclassOf<UABUtilityActionInstanceMemoryBase>& InstanceMemoryClass = ParallelAction->GetInstanceMemoryType();
		const FName InstanceMemoryName =
			FName(
				FString::Printf(
					TEXT("%s_InstanceMemory_%s"),
					*ParallelAction->GetName(),
					*GetName()
				)
			);
		UABUtilityActionInstanceMemoryBase* const InstanceMemory =
			NewObject<UABUtilityActionInstanceMemoryBase>(
				this,
				InstanceMemoryClass,
				InstanceMemoryName
			);
		ActionInstanceMemory.Add(ParallelAction, InstanceMemory);
	}
}

void UABUtilityAction_RunParallel::Deinitialize()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_RunParallel::Deinitialize"))

	for (UABUtilityActionBase* const ParallelAction : ParallelActions)
	{
		ParallelAction->OnActionCompletedDelegate.RemoveDynamic(this, &UABUtilityAction_RunParallel::OnParallelActionCompleted);
		ParallelAction->Deinitialize();
	}

	ActionInstanceMemory.Empty();

	Factors = OwnFactors;
	Requirements = OwnRequirements;
	OwnFactors.Empty();
	OwnRequirements.Empty();

	Super::Deinitialize();
}

EABUtilityActionRunStatus UABUtilityAction_RunParallel::DoAction(
	UABUtilityComponent& OwnerComp,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_RunParallel::DoAction"))

	checkf(!ParallelActions.IsEmpty(), TEXT("Run Parallel has no Actions."));
	
	TArray<EABUtilityActionRunStatus> ParallelActionRunStatuses;
	ParallelActionRunStatuses.Reserve(ParallelActions.Num());

	for (UABUtilityActionBase* const ParallelAction : ParallelActions)
	{
		checkf(IsValid(ParallelAction), TEXT("Run Parallel contains invalid Action."));

		UABUtilityActionInstanceMemoryBase** const ParallelActionInstanceMemoryPtr = ActionInstanceMemory.Find(ParallelAction);
		if (ParallelActionInstanceMemoryPtr == nullptr)
		{
			ABUtility::Helpers::UtilityVLOG(
				ELogVerbosity::Warning,
				FString::Printf(TEXT("%s - No Instance Memory available for Action [ %s ] inside Run Parallel."),
					ANSI_TO_TCHAR(__FUNCTION__),
					*ParallelAction->GetName()
				),
				OwnerComp.GetOwner()
			);
			continue;
		}

		UABUtilityActionInstanceMemoryBase* const ParallelActionInstanceMemory = *ParallelActionInstanceMemoryPtr;
		if (!IsValid(ParallelActionInstanceMemory))
		{
			ABUtility::Helpers::UtilityVLOG(
				ELogVerbosity::Warning,
				FString::Printf(TEXT("%s - Instance Memory for Action [ %s ] inside Run Parallel is invalid."),
					ANSI_TO_TCHAR(__FUNCTION__),
					*ParallelAction->GetName()
				),
				OwnerComp.GetOwner()
			);
			continue;
		}

		ParallelActionRunStatuses.Add(ParallelAction->PerformAction(OwnerComp, ParallelActionInstanceMemory));
	}

	if (ParallelActionRunStatuses.IsEmpty())
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - No successful Action."),
				ANSI_TO_TCHAR(__FUNCTION__)
			),
			this
		);
		return EABUtilityActionRunStatus::Failed;
	}

	return !CheckActionFailure(ParallelActionRunStatuses) ?
		EABUtilityActionRunStatus::Failed :
		ParallelActionRunStatuses.Contains(EABUtilityActionRunStatus::Running) ?
		EABUtilityActionRunStatus::Running :
		EABUtilityActionRunStatus::Succeeded;
}

EABUtilityActionRunStatus UABUtilityAction_RunParallel::Tick(
	UABUtilityComponent& OwnerComp,
	float DeltaSeconds,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_RunParallel::Tick"))

	checkf(!ParallelActions.IsEmpty(), TEXT("Run Parallel has no Actions."));

	TArray<EABUtilityActionRunStatus> ParallelActionRunStatuses;
	ParallelActionRunStatuses.Reserve(ParallelActions.Num());

	for (UABUtilityActionBase* const ParallelAction : ParallelActions)
	{
		checkf(IsValid(ParallelAction), TEXT("Run Parallel contains invalid Action"));

		if (!ParallelAction->ShouldTick())
		{
			continue;
		}

		UABUtilityActionInstanceMemoryBase** const ParallelActionInstanceMemoryPtr = ActionInstanceMemory.Find(ParallelAction);
		if (ParallelActionInstanceMemoryPtr == nullptr)
		{
			ABUtility::Helpers::UtilityVLOG(
				ELogVerbosity::Warning,
				FString::Printf(TEXT("%s - No Instance Memory available for Action [ %s ] inside Run Parallel."),
					ANSI_TO_TCHAR(__FUNCTION__),
					*ParallelAction->GetName()
				),
				OwnerComp.GetOwner()
			);
			continue;
		}

		UABUtilityActionInstanceMemoryBase* const ParallelActionInstanceMemory = *ParallelActionInstanceMemoryPtr;
		if (!IsValid(ParallelActionInstanceMemory))
		{
			ABUtility::Helpers::UtilityVLOG(
				ELogVerbosity::Warning,
				FString::Printf(TEXT("%s - Instance Memory for Action [ %s ] inside Run Parallel is invalid."),
					ANSI_TO_TCHAR(__FUNCTION__),
					*ParallelAction->GetName()
				),
				OwnerComp.GetOwner()
			);
			continue;
		}

		if (!ParallelActionInstanceMemory->NeedsTick())
		{
			continue;
		}

		ParallelActionRunStatuses.Add(ParallelAction->TickAction(DeltaSeconds, OwnerComp, ParallelActionInstanceMemory));
	}

	if (ParallelActionRunStatuses.IsEmpty())
	{
		// If no ticking is done, we have finished all ticks, return
		return EABUtilityActionRunStatus::Succeeded;
	}

	return !CheckActionFailure(ParallelActionRunStatuses) ?
		EABUtilityActionRunStatus::Failed :
		ParallelActionRunStatuses.Contains(EABUtilityActionRunStatus::Running) ?
		EABUtilityActionRunStatus::Running :
		EABUtilityActionRunStatus::Succeeded;
}

void UABUtilityAction_RunParallel::OnParallelActionCompleted(
	UABUtilityActionBase* Action,
	const EABUtilityActionRunStatus ActionStatus,
	const UABUtilityActionInstanceMemoryBase* ActionMemory
)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityComponent::OnActionCompleted"))

	checkf(IsValid(Action), TEXT("Delegate received from invalid action."));

	switch (ActionStatus)
	{
		case (EABUtilityActionRunStatus::Running):
		{
			ABUtility::Helpers::UtilityVLOG(
				ELogVerbosity::Error,
				FString::Printf(TEXT("%s - Received Action Completed notification with Action status Running."),
					ANSI_TO_TCHAR(__FUNCTION__)
				),
				this
			);
			break;
		}
		case (EABUtilityActionRunStatus::Succeeded):
		{
			break;
		}
		case (EABUtilityActionRunStatus::Failed):
		{
			ABUtility::Helpers::UtilityVLOG(
				ELogVerbosity::Warning,
				FString::Printf(TEXT("%s - Action [ %s ] has failed."),
					ANSI_TO_TCHAR(__FUNCTION__),
					*Action->GetName()
				),
				this
			);
			break;
		}
		case (EABUtilityActionRunStatus::NotRunning):
		default:
		{
			break;
		}
	}
}

const bool UABUtilityAction_RunParallel::CheckActionFailure(const TArray<EABUtilityActionRunStatus>& ParallelActionRunStatuses) const
{
	switch (FailureType)
	{
		default:
		case (EABRunParallelFailureType::OneFails):
		{
			if (ParallelActionRunStatuses.Contains(EABUtilityActionRunStatus::Failed))
				return false;
			break;
		}
		case (EABRunParallelFailureType::AllFail):
		{
			bool bAllFailed = true;
			for (const EABUtilityActionRunStatus& ParallelActionRunStatus : ParallelActionRunStatuses)
			{
				if (ParallelActionRunStatus != EABUtilityActionRunStatus::Failed &&
					ParallelActionRunStatus != EABUtilityActionRunStatus::NotRunning)
				{
					bAllFailed = false;
					break;
				}
			}

			if (bAllFailed)
			{
				return false;
			}
			break;
		}
	}

	return true;
}

void UABUtilityAction_RunParallel::OnActionCompleted(
	UABUtilityActionInstanceMemoryBase* InstanceMemory,
	const EABUtilityActionRunStatus ActionStatus
)
{
	const UABUtilitySubsystem& UtilitySubsystem = ABUtility::Helpers::GetUtilitySubsystemChecked(this);
	UABUtilityComponent* const OwnerComp =
		UtilitySubsystem.GetMutableComponentForActionInstanceMemory(*this, *InstanceMemory);
	if (!IsValid(OwnerComp))
	{
		Super::OnActionCompleted(InstanceMemory, ActionStatus);
		return;
	}
	
	for (UABUtilityActionBase* const ParallelAction : ParallelActions)
	{
		checkf(IsValid(ParallelAction), TEXT("Run Parallel contains invalid Action"));
		
		UABUtilityActionInstanceMemoryBase** const ParallelActionInstanceMemoryPtr = ActionInstanceMemory.Find(ParallelAction);
		if (ParallelActionInstanceMemoryPtr == nullptr)
		{
			ABUtility::Helpers::UtilityVLOG(
				ELogVerbosity::Warning,
				FString::Printf(TEXT("%s - No Instance Memory available for Action [ %s ] inside Run Parallel."),
					ANSI_TO_TCHAR(__FUNCTION__),
					*ParallelAction->GetName()
				),
				OwnerComp->GetOwner()
			);
			continue;
		}

		UABUtilityActionInstanceMemoryBase* const ParallelActionInstanceMemory = *ParallelActionInstanceMemoryPtr;
		if (!IsValid(ParallelActionInstanceMemory))
		{
			ABUtility::Helpers::UtilityVLOG(
				ELogVerbosity::Warning,
				FString::Printf(TEXT("%s - Instance Memory for Action [ %s ] inside Run Parallel is invalid."),
					ANSI_TO_TCHAR(__FUNCTION__),
					*ParallelAction->GetName()
				),
				OwnerComp->GetOwner()
			);
			continue;
		}

		ParallelAction->OnActionCompleted(ParallelActionInstanceMemory, ActionStatus);
	}
	
	Super::OnActionCompleted(InstanceMemory, ActionStatus);
}

const bool UABUtilityAction_RunParallel::ValidateAction(FString& InvalidationReason) const
{
	bool bIsValid = Super::ValidateAction(InvalidationReason);

	if (ParallelActions.Num() <= 1)
	{
		InvalidationReason += FString::Printf(TEXT("Run Parallel requires at least 2 Actions.\n"));
		bIsValid = false;
	}

	uint32 ParallelActionIndex = 0;
	for (const UABUtilityActionBase* const ParallelAction : ParallelActions)
	{
		if (!IsValid(ParallelAction))
		{
			InvalidationReason += FString::Printf(TEXT("Run Parallel has invalid Action, index %i\n"), ParallelActionIndex);
			bIsValid = false;
			ParallelActionIndex++;
			continue;
		}

		if (!ParallelAction->ValidateAction(InvalidationReason))
		{
			InvalidationReason += FString::Printf(TEXT("Action owned by Run Parallel is invalid, index %i\n"), ParallelActionIndex);
			bIsValid = false;
			ParallelActionIndex++;
			continue;
		}

		ParallelActionIndex++;
	}

	return bIsValid;
}

#if WITH_GAMEPLAY_DEBUGGER_MENU
void UABUtilityAction_RunParallel::DescribeSelfToGameplayDebugger(
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

	Super::DescribeSelfToGameplayDebugger(OwnerComp, bUseConsiderationFactor, InstanceMemory, DebuggerCategory);

	DebuggerCategory->AddTextLine(FString::Printf(TEXT("        {green}Run Parallel, Actions held: %i"), ParallelActions.Num()));
	DebuggerCategory->AddTextLine(FString::Printf(TEXT("{green}RUN PARALLEL START")));
	for (const UABUtilityActionBase* const ParallelAction : ParallelActions)
	{
		const UABUtilityActionInstanceMemoryBase* const* ParallelActionIMPtr = ActionInstanceMemory.Find(ParallelAction);
		if (ParallelActionIMPtr == nullptr)
		{
			continue;
		}
		const UABUtilityActionInstanceMemoryBase* const ParallelActionIM = *ParallelActionIMPtr;
		if (!IsValid(ParallelActionIM))
		{
			continue;
		}
		ParallelAction->DescribeSelfToGameplayDebugger(OwnerComp, bUseConsiderationFactor, ParallelActionIM, DebuggerCategory);
	}
	DebuggerCategory->AddTextLine(FString::Printf(TEXT("{green}RUN PARALLEL END")));
}
#endif // WITH_GAMEPLAY_DEBUGGER_MENU

void UABUtilityAction_RunParallel::PauseAction(
	UABUtilityComponent* OwnerComp,
	const FString& Reason,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	for (UABUtilityActionBase* const ParallelAction : ParallelActions)
	{
		checkf(IsValid(ParallelAction), TEXT("Run Parallel contains invalid Action"));

		UABUtilityActionInstanceMemoryBase** const ParallelActionInstanceMemoryPtr = ActionInstanceMemory.Find(ParallelAction);
		if (ParallelActionInstanceMemoryPtr == nullptr)
		{
			ABUtility::Helpers::UtilityVLOG(
				ELogVerbosity::Warning,
				FString::Printf(TEXT("%s - No Instance Memory available for Action [ %s ] inside Run Parallel."),
					ANSI_TO_TCHAR(__FUNCTION__),
					*ParallelAction->GetName()
				),
				OwnerComp->GetOwner()
			);
			continue;
		}

		UABUtilityActionInstanceMemoryBase* const ParallelActionInstanceMemory = *ParallelActionInstanceMemoryPtr;
		if (!IsValid(ParallelActionInstanceMemory))
		{
			ABUtility::Helpers::UtilityVLOG(
				ELogVerbosity::Warning,
				FString::Printf(TEXT("%s - Instance Memory for Action [ %s ] inside Run Parallel is invalid."),
					ANSI_TO_TCHAR(__FUNCTION__),
					*ParallelAction->GetName()
				),
				OwnerComp->GetOwner()
			);
			continue;
		}

		ParallelAction->PauseAction(OwnerComp, Reason, ParallelActionInstanceMemory);
	}
	
	Super::PauseAction(OwnerComp, Reason, InstanceMemory);
}

bool UABUtilityAction_RunParallel::ResumeAction(
	UABUtilityComponent* OwnerComp,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	bool bResumeSuccess = true;

	for (UABUtilityActionBase* const ParallelAction : ParallelActions)
	{
		checkf(IsValid(ParallelAction), TEXT("Run Parallel contains invalid Action"));

		if (!ParallelAction->ShouldTick())
		{
			continue;
		}

		UABUtilityActionInstanceMemoryBase** const ParallelActionInstanceMemoryPtr = ActionInstanceMemory.Find(ParallelAction);
		if (ParallelActionInstanceMemoryPtr == nullptr)
		{
			ABUtility::Helpers::UtilityVLOG(
				ELogVerbosity::Warning,
				FString::Printf(TEXT("%s - No Instance Memory available for Action [ %s ] inside Run Parallel."),
					ANSI_TO_TCHAR(__FUNCTION__),
					*ParallelAction->GetName()
				),
				OwnerComp->GetOwner()
			);
			bResumeSuccess = false;
			continue;
		}

		UABUtilityActionInstanceMemoryBase* const ParallelActionInstanceMemory = *ParallelActionInstanceMemoryPtr;
		if (!IsValid(ParallelActionInstanceMemory))
		{
			ABUtility::Helpers::UtilityVLOG(
				ELogVerbosity::Warning,
				FString::Printf(TEXT("%s - Instance Memory for Action [ %s ] inside Run Parallel is invalid."),
					ANSI_TO_TCHAR(__FUNCTION__),
					*ParallelAction->GetName()
				),
				OwnerComp->GetOwner()
			);
			bResumeSuccess = false;
			continue;
		}

		bResumeSuccess = ParallelAction->ResumeAction(OwnerComp, ParallelActionInstanceMemory) && bResumeSuccess;
	}

	return bResumeSuccess && Super::ResumeAction(OwnerComp, InstanceMemory);
}

void UABUtilityAction_RunParallel::AbortAction(
	UABUtilityComponent* OwnerComp,
	const FString& Reason,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	for (UABUtilityActionBase* const ParallelAction : ParallelActions)
	{
		checkf(IsValid(ParallelAction), TEXT("Run Parallel contains invalid Action"));

		UABUtilityActionInstanceMemoryBase** const ParallelActionInstanceMemoryPtr = ActionInstanceMemory.Find(ParallelAction);
		if (ParallelActionInstanceMemoryPtr == nullptr)
		{
			ABUtility::Helpers::UtilityVLOG(
				ELogVerbosity::Warning,
				FString::Printf(TEXT("%s - No Instance Memory available for Action [ %s ] inside Run Parallel."),
					ANSI_TO_TCHAR(__FUNCTION__),
					*ParallelAction->GetName()
				),
				OwnerComp->GetOwner()
			);
			continue;
		}

		UABUtilityActionInstanceMemoryBase* const ParallelActionInstanceMemory = *ParallelActionInstanceMemoryPtr;
		if (!IsValid(ParallelActionInstanceMemory))
		{
			ABUtility::Helpers::UtilityVLOG(
				ELogVerbosity::Warning,
				FString::Printf(TEXT("%s - Instance Memory for Action [ %s ] inside Run Parallel is invalid."),
					ANSI_TO_TCHAR(__FUNCTION__),
					*ParallelAction->GetName()
				),
				OwnerComp->GetOwner()
			);
			continue;
		}

		ParallelAction->AbortAction(OwnerComp, Reason, ParallelActionInstanceMemory);
	}

	Super::AbortAction(OwnerComp, Reason, InstanceMemory);
}