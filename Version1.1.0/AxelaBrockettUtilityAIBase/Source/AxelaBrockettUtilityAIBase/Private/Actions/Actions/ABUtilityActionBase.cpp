// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Actions/Actions/ABUtilityActionBase.h"

#include "Actions/Factors/ABUtilityFactorBase.h"
#include "Actions/Requirements/ABUtilityRequirementBase.h"
#include "AIController.h"
#include "Async/ParallelFor.h"
#include "Components/ABUtilityComponent.h"
#include "Engine/Level.h"
#include "Engine/World.h"
#include "Helpers/ABUtilityHelpers.h"

#if WITH_GAMEPLAY_DEBUGGER_MENU
#include "GameplayDebuggerCategory.h"
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

/*
* UABUtilityActionBase
*/

UABUtilityActionBase::UABUtilityActionBase()
{
	
}

/*
* Initialization
*/
void UABUtilityActionBase::Initialize(UWorld* InWorld)
{
	for (UABUtilityRequirementBase* const Requirement : Requirements)
	{
		checkf(IsValid(Requirement), TEXT("Action has invalid requirement."));
		Requirement->OnAsyncRequirementCheckedDelegate.AddDynamic(this, &UABUtilityActionBase::OnAsyncRequirementChecked);
	}

	CachedWorld = InWorld;
}

void UABUtilityActionBase::Deinitialize()
{
	for (UABUtilityRequirementBase* const Requirement : Requirements)
	{
		checkf(IsValid(Requirement), TEXT("Action has invalid requirement."));
		Requirement->OnAsyncRequirementCheckedDelegate.RemoveDynamic(this, &UABUtilityActionBase::OnAsyncRequirementChecked);
	}

	CachedWorld = nullptr;
}

/*
* Action requirement checking
*/

const bool UABUtilityActionBase::CheckAllRequirements(const UABUtilityComponent& OwnerComp) const
{
	return IsUsingParallelRequirementChecking() ?
		InternalParallelCheckAllRequirements(OwnerComp) :
		InternalCheckAllRequirements(OwnerComp);
}

void UABUtilityActionBase::AsyncCheckAllRequirements(const UABUtilityComponent& OwnerComp)
{
	if (IsUsingParallelRequirementChecking())
	{
		InternalParallelAsyncCheckAllRequirements(OwnerComp);
		return;
	}

	InternalAsyncCheckAllRequirements(OwnerComp);
}

/*
* Internal action requirement checking
*/

const bool UABUtilityActionBase::InternalCheckAllRequirements(const UABUtilityComponent& OwnerComp) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityActionBase::InternalCheckAllRequirements"))

	bool bRequirementsPassed = true;
	for (const UABUtilityRequirementBase* const Requirement : Requirements)
	{
		checkf(IsValid(Requirement), TEXT("Action has invalid requirement."));

		if (!Requirement->CheckRequirement(OwnerComp))
		{
			bRequirementsPassed = false;
			break;
		}
	}

	return bRequirementsPassed;
}

const bool UABUtilityActionBase::InternalParallelCheckAllRequirements(const UABUtilityComponent& OwnerComp) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityActionBase::InternalParallelCheckAllRequirements"))

	FCriticalSection Mutex;
	bool bRequirementsPassed = true;

	ParallelFor(Requirements.Num(), [this, &Mutex, &bRequirementsPassed, &OwnerComp](int32 Index)
		{
			FScopeLock Lock(&Mutex);

			const UABUtilityRequirementBase* const Requirement = Requirements[Index];

			// Ensure not check so we don't crash during multi-threaded processes
			if (!ensureAlwaysMsgf(IsValid(Requirement), TEXT("Action has an invalid requirement.")))
			{
				return;
			}

			// Check requirements
			if (!Requirement->CheckRequirement(OwnerComp))
			{
				bRequirementsPassed = false;
			}
		}
	);

	return bRequirementsPassed;
}

void UABUtilityActionBase::InternalAsyncCheckAllRequirements(const UABUtilityComponent& OwnerComp)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityActionBase::InternalAsyncCheckAllRequirements"))

	AsyncData.Reset();

	if (Requirements.IsEmpty())
	{
		AsyncTask(ENamedThreads::GameThread, [this]()
			{
				OnAsyncRequirementsCheckedDelegate.Broadcast(this, true);
			}
		);
	}

	for (const UABUtilityRequirementBase* const Requirement : Requirements)
	{
		checkf(IsValid(Requirement), TEXT("Action has an invalid requirement."));

		// Async check requirements
		AsyncTask(ENamedThreads::AnyThread, [Requirement, &OwnerComp]()
			{
				Requirement->AsyncCheckRequirement(OwnerComp);
			}
		);

		AsyncData.AsyncRequirementsToCheck++;
	}
}

void UABUtilityActionBase::InternalParallelAsyncCheckAllRequirements(const UABUtilityComponent& OwnerComp)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityActionBase::InternalParallelAsyncCheckAllRequirements"))

	AsyncData.Reset();

	if (Requirements.IsEmpty())
	{
		AsyncTask(ENamedThreads::GameThread, [this]()
			{
				OnAsyncRequirementsCheckedDelegate.Broadcast(this, true);
			}
		);
	}

	FCriticalSection Mutex;

	ParallelFor(Requirements.Num(), [this, &Mutex, &OwnerComp](int32 Index)
		{
			FScopeLock Lock(&Mutex);

			const UABUtilityRequirementBase* const Requirement = Requirements[Index];

			// Ensure not check so we don't crash during multi-threaded processes
			if (!ensureAlwaysMsgf(IsValid(Requirement), TEXT("Action has an invalid requirement.")))
			{
				return;
			}

			// Async check requirements
			AsyncTask(ENamedThreads::AnyThread, [Requirement, &OwnerComp]()
				{
					Requirement->AsyncCheckRequirement(OwnerComp);
				}
			);

			AsyncData.AsyncRequirementsToCheck++;
		}
	);
}

void UABUtilityActionBase::OnAsyncRequirementChecked(
	const UABUtilityRequirementBase* const Requirement,
	const bool bRequirementPassed
)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityActionBase::OnAsyncRequirementChecked"))

	checkf(IsValid(Requirement), TEXT("Delegate received from invalid requirement."));

	// If any requirement does not pass, the action cannot be taken
	AsyncData.bAsyncRequirementsPassed = AsyncData.bAsyncRequirementsPassed && bRequirementPassed;
	AsyncData.AsyncRequirementsChecked++;

	if (AsyncData.AsyncRequirementsChecked == AsyncData.AsyncRequirementsToCheck)
	{
		// All requirements have been checked
		AsyncTask(ENamedThreads::GameThread, [this]()
			{
				OnAsyncRequirementsCheckedDelegate.Broadcast(this, AsyncData.bAsyncRequirementsPassed);
			}
		);
	}
}

/*
* Getters
*/

const float UABUtilityActionBase::GetOnSuccessCooldownValue(UABUtilityComponent& OwnerComp) const
{
	const AAIController* const AIController = OwnerComp.GetAIOwner();
	if (!IsValid(AIController))
	{
		return FLT_MAX;
	}

	const APawn* const AIPawn = AIController->GetPawn();
	if (!IsValid(AIPawn))
	{
		return FLT_MAX;
	}

	OnSuccessCooldown.BindData(AIPawn, INDEX_NONE);
	return OnSuccessCooldown.GetValue();
}

const float UABUtilityActionBase::GetUtilityWeightValue(const UABUtilityComponent& OwnerComp) const
{
	const AAIController* const AIController = OwnerComp.GetAIOwner();
	if (!IsValid(AIController))
	{
		return 0.0f;
	}

	UtilityWeight.BindData(AIController->GetPawn(), INDEX_NONE);
	return UtilityWeight.GetValue();
}

/*
* Action scoring
*/

const float UABUtilityActionBase::GetActionScore(const UABUtilityComponent& OwnerComp, const bool bUseConsiderationFactor) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityActionBase::GetActionScore"))

	float TotalScore = 1.0f;

	// Cast the int number of factors to a float
	const float NumFactors = static_cast<float>(Factors.Num());
	for (int32 Index = 0; Index < Factors.Num(); Index++)
	{
		const UABUtilityFactorBase* const Factor = Factors[Index];
		checkf(IsValid(Factor), TEXT("Action has an invalid factor."));
		// Multiply the current score by the factor score
		const float FactorScore = Factor->GetFactorScore(OwnerComp, NumFactors, bUseConsiderationFactor);
		if (FactorScore != 0.0f || IsConsideringFactorScoreZero())
		{
			ModifyTotalScore(FactorScore, NumFactors, Index, TotalScore);
		}
	}

	// Multiply the total score by the utility weight
	return TotalScore * GetUtilityWeightValue(OwnerComp);
}

/*
* Action logic
*/

const EABUtilityActionRunStatus UABUtilityActionBase::PerformAction(
	UABUtilityComponent& OwnerComp,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityActionBase::PerformAction"))

	const EABUtilityActionRunStatus CurrentRunStatus = DoAction(OwnerComp, InstanceMemory);

	if (CurrentRunStatus != EABUtilityActionRunStatus::Running)
	{
		// If the action completes, immediately complete
		OnActionCompleted(InstanceMemory, CurrentRunStatus);
		return CurrentRunStatus;
	}

	// Register tick function
	if (ShouldTick())
	{
		InstanceMemory->SetNeedsTick(true);
	}

	return CurrentRunStatus;
}

/*
* Pause, resume and abort logic
*/

void UABUtilityActionBase::PauseAction(
	UABUtilityComponent* OwnerComp,
	const FString& Reason,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityActionBase::PauseAction"))

	ABUtility::Helpers::UtilityVLOG(
		ELogVerbosity::Log,
		FString::Printf(TEXT("%s - Pausing Action [ %s ] due to [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*GetName(),
			*Reason
		),
		this
	);

	UABUtilityActionInstanceMemoryBase* const PauseInstanceMemory =
		IsValid(InstanceMemory) ?
		InstanceMemory :
		ABUtility::Helpers::GetMutableActionInstanceMemoryOfType<UABUtilityActionInstanceMemoryBase>(*this, *OwnerComp);
	if (IsValid(PauseInstanceMemory))
	{
		PauseInstanceMemory->SetNeedsTick(false);
	}
}

bool UABUtilityActionBase::ResumeAction(
	UABUtilityComponent* OwnerComp,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityActionBase::ResumeAction"))

	ABUtility::Helpers::UtilityVLOG(
		ELogVerbosity::Log,
		FString::Printf(TEXT("%s - Resuming action [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*GetName()
		),
		this
	);

	UABUtilityActionInstanceMemoryBase* const ResumeInstanceMemory =
		IsValid(InstanceMemory) ?
		InstanceMemory :
		ABUtility::Helpers::GetMutableActionInstanceMemoryOfType<UABUtilityActionInstanceMemoryBase>(*this, *OwnerComp);
	if (IsValid(ResumeInstanceMemory) && ShouldTick())
	{
		ResumeInstanceMemory->SetNeedsTick(true);
	}

	return true;
}

void UABUtilityActionBase::AbortAction(
	UABUtilityComponent* OwnerComp,
	const FString& Reason,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityActionBase::AbortAction"))

	ABUtility::Helpers::UtilityVLOG(
		ELogVerbosity::Log,
		FString::Printf(TEXT("%s - Aborting action [ %s ] due to [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*GetName(),
			*Reason
		),
		this
	);

	UABUtilityActionInstanceMemoryBase* const AbortInstanceMemory =
		IsValid(InstanceMemory) ?
		InstanceMemory :
		ABUtility::Helpers::GetMutableActionInstanceMemoryOfType<UABUtilityActionInstanceMemoryBase>(*this, *OwnerComp);

	// Reset the run status and complete the action
	OnActionCompleted(AbortInstanceMemory, EABUtilityActionRunStatus::NotRunning);
}

/*
* Tick logic
*/

EABUtilityActionRunStatus UABUtilityActionBase::TickAction(
	float DeltaTime,
	UABUtilityComponent& OwnerComp,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityActionBase::TickAction"))
	
	if (!ShouldTick() || !InstanceMemory->NeedsTick())
	{
		return EABUtilityActionRunStatus::NotRunning;
	}
	
	// Tick with owning component
	const EABUtilityActionRunStatus CurrentRunStatus = Tick(OwnerComp, DeltaTime, InstanceMemory);

	if (CurrentRunStatus != EABUtilityActionRunStatus::Running || InstanceMemory->IsTickableActionComplete())
	{
		// If we're not running, we've completed
		OnActionCompleted(InstanceMemory, CurrentRunStatus);
	}

	return CurrentRunStatus;
}

/*
* Validation
*/

const bool UABUtilityActionBase::ValidateAction(FString& InvalidationReason) const
{
	bool bIsValid = true;

	// Validate the Utility Weight data provider
	UtilityWeight.BindData(this, INDEX_NONE);
	if (UtilityWeight.GetValue() < 0.0f)
	{
		InvalidationReason += FString::Printf(TEXT("Utility Weight less than 0.0\n"));
		bIsValid = false;
	}

	// Validate the On Success Cooldown data provider
	OnSuccessCooldown.BindData(this, INDEX_NONE);
	if (OnSuccessCooldown.GetValue() < 0.0f)
	{
		InvalidationReason += FString::Printf(TEXT("On Success Cooldown value less than 0.0\n"));
		bIsValid = false;
	}

	return bIsValid;
}

/*
* Debugging
*/

#if WITH_GAMEPLAY_DEBUGGER_MENU
void UABUtilityActionBase::DescribeSelfToGameplayDebugger(
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

	const AAIController* const AIController = OwnerComp.GetAIOwner();
	if (IsValid(AIController))
	{
		const APawn* const AIPawn = AIController->GetPawn();
		UtilityWeight.BindData(AIPawn, INDEX_NONE);
		OnSuccessCooldown.BindData(AIPawn, INDEX_NONE);
	}

	const float NumFactors = static_cast<float>(Factors.Num());

	DebuggerCategory->AddTextLine(FString::Printf(TEXT("    {green}Action: %s"), *GetName()));

	DebuggerCategory->AddTextLine(
		FString::Printf(TEXT("        {green}Utility Weight: %f / On Success Cooldown: %f / Score Aggregation Method: %s / Current Score: %f"),
			UtilityWeight.GetValue(),
			OnSuccessCooldown.GetValue(),
			ScoreAggregationMethod == EABFactorScoreTotallingMethod::Max ? TEXT("Max") :
			ScoreAggregationMethod == EABFactorScoreTotallingMethod::Sum ? TEXT("Sum") :
			ScoreAggregationMethod == EABFactorScoreTotallingMethod::Multiply ? TEXT("Multiply") :
			ScoreAggregationMethod == EABFactorScoreTotallingMethod::Average ? TEXT("Average") :
			ScoreAggregationMethod == EABFactorScoreTotallingMethod::Min ? TEXT("Min") :
			TEXT("None"),
			GetActionScore(OwnerComp, bUseConsiderationFactor)
		)
	);

	DebuggerCategory->AddTextLine(
		FString::Printf(TEXT("        {green}Use Parallel Requirement Checking: %s / Consider Factor Score Zero: %s"),
			IsUsingParallelRequirementChecking() ? TEXT("true") : TEXT("false"),
			IsConsideringFactorScoreZero() ? TEXT("true") : TEXT("false"))
	);

	DebuggerCategory->AddTextLine(FString::Printf(TEXT("        {green}Requirements:")));
	for (const UABUtilityRequirementBase* const Requirement : Requirements)
	{
		Requirement->DescribeSelfToGameplayDebugger(OwnerComp, DebuggerCategory);
	}

	DebuggerCategory->AddTextLine(FString::Printf(TEXT("        {green}Factors:")));
	for (const UABUtilityFactorBase* const Factor : Factors)
	{
		Factor->DescribeSelfToGameplayDebugger(OwnerComp, NumFactors, bUseConsiderationFactor, DebuggerCategory);
	}
}
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

/*
* Internal action logic
*/

void UABUtilityActionBase::OnActionCompleted(UABUtilityActionInstanceMemoryBase* InstanceMemory, const EABUtilityActionRunStatus ActionStatus)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityActionBase::OnActionCompleted"))

	// Reset instance memory
	if (IsValid(InstanceMemory))
	{
		InstanceMemory->Reset();
		InstanceMemory->SetNeedsTick(false);
		InstanceMemory->SetTickableActionComplete(false, false);
	}

	// Broadcast this actions complete delegate
	OnActionCompletedDelegate.Broadcast(this, ActionStatus, InstanceMemory);
}

/*
* Internal action scoring
*/

void UABUtilityActionBase::ModifyTotalScore(
	const float& ModifyingScore,
	const float& NumFactors,
	const int32& CurrentIndex,
	float& OutTotalScore
) const
{
	switch (ScoreAggregationMethod)
	{
		case (EABFactorScoreTotallingMethod::Sum):
		{
			OutTotalScore += ModifyingScore;
			break;
		}
		case (EABFactorScoreTotallingMethod::Multiply):
		{
			OutTotalScore *= ModifyingScore;
			break;
		}
		case (EABFactorScoreTotallingMethod::Average):
		{
			OutTotalScore += ModifyingScore;
			if (static_cast<float>(CurrentIndex) == NumFactors - 1.0f)
			{
				OutTotalScore /= NumFactors;
			}
			break;
		}
		case (EABFactorScoreTotallingMethod::Min):
		{
			OutTotalScore = ((ModifyingScore < OutTotalScore) || (OutTotalScore == 0.0f)) ? ModifyingScore : OutTotalScore;
			break;
		}
		case (EABFactorScoreTotallingMethod::Max):
		{
			OutTotalScore = ModifyingScore > OutTotalScore ? ModifyingScore : OutTotalScore;
			break;
		}
		default:
		{
			break;
		}
	}
}