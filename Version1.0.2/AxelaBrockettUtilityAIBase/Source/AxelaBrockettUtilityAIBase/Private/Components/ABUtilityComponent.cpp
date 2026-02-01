// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Components/ABUtilityComponent.h"

#include "Actions/Actions/ABUtilityActionBase.h"
#include "Algo/RandomShuffle.h"
#include "Async/ParallelFor.h"
#include "Engine/World.h"
#include "Net/UnrealNetwork.h"
#include "TimerManager.h"
#include "VisualLogger/VisualLogger.h"

#if WITH_GAMEPLAY_DEBUGGER_MENU
#include "GameplayDebuggerCategory.h"
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

UABUtilityComponent::UABUtilityComponent()
{
	// Disable all ticking, this component runs event-based only
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;
	PrimaryComponentTick.bTickEvenWhenPaused = false;
}

void UABUtilityComponent::SetComponentTickEnabled(bool bEnabled)
{
	UE_VLOG_UELOG(
		GetOwner(),
		LogABUtility,
		Warning,
		TEXT("%s - Utility Component does not have a tick. Forcing tick to false."),
		ANSI_TO_TCHAR(__FUNCTION__)
	);

	Super::SetComponentTickEnabled(false);
}

/*
* UBrainComponent overrides
*/

void UABUtilityComponent::StartLogic()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityComponent::StartLogic"))

	checkf(IsValid(UtilityDataAsset), TEXT("Utility Component should always have a valid Utility Data Asset."));

	// Cache action selection mode
	ActionSelectionMode = UtilityDataAsset->GetActionSelectionMode();

	// Set local array size
	const TArray<TObjectPtr<UABUtilityActionBase>>& ActionsFromDataAsset = UtilityDataAsset->GetActions();
	UtilityActions.Reserve(ActionsFromDataAsset.Num());

	// Bind to each actions delegates
	for (UABUtilityActionBase* const Action : ActionsFromDataAsset)
	{
		checkf(IsValid(Action), TEXT("Data Asset [ %s ] has an invalid action."), *UtilityDataAsset->GetName());

		// Cache the action locally
		UtilityActions.Add(Action);

		// Delegate bindings
		Action->OnActionCompletedDelegate.AddDynamic(this, &UABUtilityComponent::OnActionCompleted);
		Action->OnAsyncRequirementsCheckedDelegate.AddDynamic(this, &UABUtilityComponent::OnActionRequirementsChecked);

		// Bind action to its required delegates
		Action->BindToRequirementDelegates();

		// Cache world for action
		Action->CacheWorld(GetWorld());
	}

	// Try to start logic
	if (!PerformUtilityAction())
	{
		StopLogic(FString("Could not start logic."));
	}
}

void UABUtilityComponent::PauseLogic(const FString& Reason)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityComponent::PauseLogic"))

	UE_VLOG_UELOG(
		GetOwner(),
		LogABUtility,
		Log,
		TEXT("%s - Pausing logic for utility component [ %s ] due to: %s"),
		ANSI_TO_TCHAR(__FUNCTION__),
		*GetName(),
		*Reason
	);

	Super::PauseLogic(Reason);
}

EAILogicResuming::Type UABUtilityComponent::ResumeLogic(const FString& Reason)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityComponent::ResumeLogic"))

	if (ShouldRestartLogicWhenResumingComponentLogic())
	{
		// Restart the component
		RestartLogic();
		return EAILogicResuming::RestartedInstead;
	}

	if (IsValid(CurrentAction))
	{
		// Try to resume the action, find new action otherwise
		if (!CurrentAction->ResumeAction(this))
		{
			UE_VLOG_UELOG(
				GetOwner(),
				LogABUtility,
				Warning,
				TEXT("%s - Failed to resume action [ %s ]. Attempting to choose new action."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*CurrentAction->GetName()
			);

			AbortCurrentAction(EABUtilityAbortActionLogic::ChooseNewAction);
		}
	}
	else
	{
		// Find a new action
		if (!PerformUtilityAction())
		{
			StopLogic(FString(TEXT("Could not find new action.")));
		}
	}

	return EAILogicResuming::Continue;
}

void UABUtilityComponent::RestartLogic()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityComponent::RestartLogic"))
	StopLogic(FString(TEXT("Restarting logic.")));
	StartLogic();
}

void UABUtilityComponent::StopLogic(const FString& Reason)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityComponent::StopLogic"))
	UE_VLOG_UELOG(
		GetOwner(),
		LogABUtility,
		Log,
		TEXT("%s - Stopping logic for utility component [ %s ] due to: %s"),
		ANSI_TO_TCHAR(__FUNCTION__),
		*GetName(),
		*Reason
	);

	// Abort and invalidate current action
	if (IsValid(CurrentAction))
	{
		CurrentAction->AbortAction(this, FString(TEXT("Stopping component logic.")));
		CurrentAction = nullptr;
	}

	// Unbind from all action delegates
	for (UABUtilityActionBase* const Action : UtilityActions)
	{
		if (!IsValid(Action))
		{
			continue;
		}

		// Delegate unbindings
		Action->OnActionCompletedDelegate.RemoveDynamic(this, &UABUtilityComponent::OnActionCompleted);
		Action->OnAsyncRequirementsCheckedDelegate.RemoveDynamic(this, &UABUtilityComponent::OnActionRequirementsChecked);

		// Unbind action from its required delegates
		Action->UnbindFromRequirementDelegates();
	}

	UtilityActions.Empty();

	Super::StopLogic(Reason);
}

void UABUtilityComponent::Cleanup()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityComponent::Cleanup"))
	StopLogic(FString(TEXT("Clean up brain component.")));
}

/*
* Pause and abort logic
*/

void UABUtilityComponent::AbortCurrentAction(const EABUtilityAbortActionLogic& AbortLogic)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityComponent::AbortCurrentAction"))

	switch (AbortLogic)
	{
		case (EABUtilityAbortActionLogic::StopComponent):
		{
			// Stop the component
			StopLogic(
				FString(
					TEXT("Aborting action with [ EUtilityAbortActionLogic::StopComponent ].")
				)
			);
			break;
		}
		case (EABUtilityAbortActionLogic::PauseLogicPauseAction):
		{
			// Pause the action as well as the component
			PauseLogicWithActionDecision(
				FString(
					TEXT("Pausing component logic and current action.")
				),
				EABUtilityComponentPauseActionLogic::PauseAction
			);
			break;
		}
		case (EABUtilityAbortActionLogic::PauseLogicAbortAction):
		{
			// Abort the action when pausing the component
			PauseLogicWithActionDecision(
				FString(
					TEXT("Aborting current action with choice to pause logic.")
				),
				EABUtilityComponentPauseActionLogic::AbortAction
			);
			break;
		}
		case (EABUtilityAbortActionLogic::ChooseNewAction):
		{
			// Abort the action to choose a new action
			if (IsValid(CurrentAction))
			{
				CurrentAction->AbortAction(this, FString(TEXT("Aborting to choose new action.")));
				CurrentAction = nullptr;
			}

			if (!PerformUtilityAction())
			{
				StopLogic(FString(TEXT("Could not find new action.")));
			}
			break;
		}
		default:
		{
			UE_VLOG_UELOG(
				GetOwner(),
				LogABUtility,
				Error,
				TEXT("%s - No valid abort logic passed in."),
				ANSI_TO_TCHAR(__FUNCTION__)
			);
			break;
		}
	}
}

void UABUtilityComponent::PauseLogicWithActionDecision(
	const FString& Reason,
	const EABUtilityComponentPauseActionLogic& ActionDecision
)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityComponent::PauseLogicWithActionDecision"))

	if (IsValid(CurrentAction))
	{
		switch (ActionDecision)
		{
			case (EABUtilityComponentPauseActionLogic::PauseAction):
			{
				// Pause the action ready for resuming later
				CurrentAction->PauseAction(
					this,
					FString(
						TEXT("Pausing component logic with Action Decision to pause action.")
					)
				);
				break;
			}
			case (EABUtilityComponentPauseActionLogic::AbortAction):
			default:
			{
				// Abort and invalidate the current action
				CurrentAction->AbortAction(
					this,
					FString(
						TEXT("Pausing component logic with Action Decision to abort action.")
					)
				);
				CurrentAction = nullptr;
				break;
			}
		}
	}

	PauseLogic(Reason);
}

/*
* Replication functions
*/

void UABUtilityComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UABUtilityComponent, CurrentAction);
	DOREPLIFETIME(UABUtilityComponent, LastSuccessfulAction);
}

void UABUtilityComponent::OnRep_CurrentAction_Implementation()
{

}

void UABUtilityComponent::OnRep_LastSuccessfulAction_Implementation()
{

}

/*
* Debugging
*/

#if WITH_GAMEPLAY_DEBUGGER_MENU
void UABUtilityComponent::DescribeSelfToGameplayDebugger(FGameplayDebuggerCategory* DebuggerCategory) const
{
	if (DebuggerCategory == nullptr || !IsValid(UtilityDataAsset))
	{
		return;
	}

	DebuggerCategory->AddTextLine(FString::Printf(TEXT("Utility Component: %s"), *GetName()));
	DebuggerCategory->AddTextLine(
		FString::Printf(TEXT("Current Action: %s / Last Successful Action: %s / Action Selection mode: %s"),
			*GetNameSafe(CurrentAction),
			*GetNameSafe(LastSuccessfulAction),
			ActionSelectionMode == EABActionSelectionMode::HighestScore ? TEXT("Highest Score") :
			ActionSelectionMode == EABActionSelectionMode::RandomFromTop25Pct ? TEXT("Random From Top 25 Percent") :
			ActionSelectionMode == EABActionSelectionMode::RandomFromTop10Pct ? TEXT("Random From Top 10 Percent") :
			TEXT("None"))
	);
	DebuggerCategory->AddTextLine(
		FString::Printf(TEXT("Restart Logic When Resuming Component Logic: %s / Run Component Asynchronously: %s / Use Parallel Requirement Checking: %s / Retry On Failure: %s"),
			ShouldRestartLogicWhenResumingComponentLogic() ? TEXT("true") : TEXT("false"),
			IsComponentRunningAsynchronously() ? TEXT("true") : TEXT("false"),
			IsUsingParallelRequirementChecking() ? TEXT("true") : TEXT("false"),
			ShouldRetryOnFailure() ? TEXT("true") : TEXT("false"))
	);

	DebuggerCategory->AddTextLine(FString::Printf(TEXT("Possible actions:")));
	for (const UABUtilityActionBase* const Action : UtilityActions)
	{
		Action->DescribeSelfToGameplayDebugger(*this, UtilityDataAsset->IsUsingConsiderationFactor(), DebuggerCategory);
	}
}
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

/*
* Delegate binding functions
*/

void UABUtilityComponent::OnActionCompleted(UABUtilityActionBase* Action)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityComponent::OnActionCompleted"))

	checkf(IsValid(Action), TEXT("Delegate received from invalid action."));

	bool bSuccessful = false;

	// End-status logic
	switch (Action->GetCurrentRunStatus())
	{
		case (EABUtilityActionRunStatus::Running):
		{
			checkf(false, TEXT("Utility Component has received an Action Completed notification while the Action [ %s ] is still running."), *Action->GetName());
			break;
		}
		case (EABUtilityActionRunStatus::Succeeded):
		{
			LastSuccessfulAction = Action;
			bSuccessful = true;
			break;
		}
		case (EABUtilityActionRunStatus::Failed):
		{
			UE_VLOG_UELOG(
				GetOwner(),
				LogABUtility,
				Warning,
				TEXT("%s - Action [ %s ] has failed."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*Action->GetName()
			);
			break;
		}
		case (EABUtilityActionRunStatus::NotRunning):
		default:
		{
			break;
		}
	}

	// Reset the action and the current action
	const float ActionCooldown = Action->GetOnSuccessCooldownValue(*this);
	Action->ResetCurrentRunStatus();
	CurrentAction = nullptr;

	// Use Timer Manager to trigger PerformUtilityAction after cooldown
	const UWorld* const World = GetWorld();
	if (!IsValid(World))
	{
		UE_VLOG_UELOG(
			GetOwner(),
			LogABUtility,
			Error,
			TEXT("%s - Could not find a valid world."),
			ANSI_TO_TCHAR(__FUNCTION__)
		);
		StopLogic(FString(TEXT("Could not find a valid world.")));
		return;
	}

	FTimerManager& TimerManager = World->GetTimerManager();

	if (bSuccessful)
	{
		TimerManager.SetTimer(
			SuccessfulActionCooldownHandle,
			[this]()
			{
				if (!PerformUtilityAction())
				{
					StopLogic(FString(TEXT("Could not find a new action.")));
				}
			},
			ActionCooldown,
			false
		);

		return;
	}

	TimerManager.SetTimerForNextTick([this]()
		{
			if (!PerformUtilityAction())
			{
				StopLogic(FString(TEXT("Could not find a new action.")));
			}
		}
	);
}

void UABUtilityComponent::OnActionRequirementsChecked(UABUtilityActionBase* Action, const bool bRequirementsPassed)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityComponent::OnActionRequirementsChecked"))

	checkf(IsValid(Action), TEXT("Delegate received from invalid action."));
	checkf(IsValid(UtilityDataAsset), TEXT("Utility Data Asset is no longer valid"));

	AsyncData.AsyncActionsChecked++;

	// Check the action score and consider the action if score is valid
	if (bRequirementsPassed)
	{
		const float ActionScore = Action->GetActionScore(*this, UtilityDataAsset->IsUsingConsiderationFactor());
		if (ActionScore > 0.0f)
		{
			AsyncData.AsyncPossibleActionsToScores.Add(Action, ActionScore);
		}
	}

	// Only continue if all actions have been checked
	if (AsyncData.AsyncActionsChecked != AsyncData.AsyncActionsToCheck)
	{
		return;
	}

	if (AsyncData.AsyncPossibleActionsToScores.IsEmpty())
	{
		if (!AttemptRetry())
		{
			// No possible actions, failing here
			StopLogic(FString(TEXT("Could not find appropriate action. Aborting.")));
		}

		return;
	}

	// Sort the actions by score
	AsyncData.AsyncPossibleActionsToScores.ValueStableSort([](const float& First, const float& Second) -> bool
		{
			return First > Second;
		}
	);

	TArray<UABUtilityActionBase*> AllActions;
	AsyncData.AsyncPossibleActionsToScores.GetKeys(AllActions);
	EABUtilityActionRunStatus ActionStatus = EABUtilityActionRunStatus::Failed;

	switch (ActionSelectionMode)
	{
		case (EABActionSelectionMode::HighestScore):
		{
			for (UABUtilityActionBase* const ThisAction : AllActions)
			{
				ActionStatus = ThisAction->PerformAction(*this);

				if (ActionStatus != EABUtilityActionRunStatus::Failed)
				{
					CurrentAction = ThisAction;
					break;
				}
			}
			break;
		}
		case (EABActionSelectionMode::RandomFromTop10Pct):
		{
			const int32 TenPctActionNum = (int32)((float)AllActions.Num() / 10.0f);
			TArray<UABUtilityActionBase*> TopActions;
			TopActions.Reserve(TenPctActionNum);
			for (int32 Index = 0; Index < TenPctActionNum; Index++)
			{
				TopActions.Add(AllActions[Index]);
			}
			Algo::RandomShuffle(TopActions);
			for (UABUtilityActionBase* const ThisAction : TopActions)
			{
				ActionStatus = ThisAction->PerformAction(*this);

				if (ActionStatus != EABUtilityActionRunStatus::Failed)
				{
					CurrentAction = ThisAction;
					break;
				}
			}
			break;
		}
		case (EABActionSelectionMode::RandomFromTop25Pct):
		{
			const int32 TwentyFivePctActionNum = (int32)((float)AllActions.Num() / 4.0f);
			TArray<UABUtilityActionBase*> TopActions;
			TopActions.Reserve(TwentyFivePctActionNum);
			for (int32 Index = 0; Index < TwentyFivePctActionNum; Index++)
			{
				TopActions.Add(AllActions[Index]);
			}
			Algo::RandomShuffle(TopActions);
			for (UABUtilityActionBase* const ThisAction : TopActions)
			{
				ActionStatus = ThisAction->PerformAction(*this);

				if (ActionStatus != EABUtilityActionRunStatus::Failed)
				{
					CurrentAction = ThisAction;
					break;
				}
			}
			break;
		}
	}
}

/*
* Action logic functions
*/

bool UABUtilityComponent::PerformUtilityAction()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityComponent::PerformUtilityAction"))

	if (IsComponentRunningAsynchronously())
	{
		AsyncRequestUtilityAction();
		return true;
	}

	// Attempt to run a utility action
	if (!RequestUtilityAction())
	{
		UE_VLOG_UELOG(
			GetOwner(),
			LogABUtility,
			Error,
			TEXT("%s - Utility Component [ %s ] could not perform a valid action."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*GetName()
		);

		return AttemptRetry();
	}

	return true;
}

bool UABUtilityComponent::RequestUtilityAction()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityComponent::RequestUtilityAction"))

	if (UtilityActions.IsEmpty())
	{
		// No actions to choose from, failing here
		return false;
	}

	TMap<UABUtilityActionBase*, const float> PossibleActionsToScores;

	// Get the possible actions
	if (IsUsingParallelRequirementChecking())
	{
		ParallelGetPossibleActions(PossibleActionsToScores);
	}
	else
	{
		GetPossibleActions(PossibleActionsToScores);
	}

	if (PossibleActionsToScores.IsEmpty())
	{
		// No possible actions as all requirements failed, failing here.
		return false;
	}

	// Sort the actions by score
	PossibleActionsToScores.ValueStableSort([](const float& First, const float& Second) -> bool
		{
			return First > Second;
		}
	);

	// Try choosing the action based on the Action Selection Mode
	EABUtilityActionRunStatus ActionStatus = EABUtilityActionRunStatus::Failed;

	TArray<UABUtilityActionBase*> AllActions;
	PossibleActionsToScores.GetKeys(AllActions);

	switch (ActionSelectionMode)
	{
		case (EABActionSelectionMode::HighestScore):
		{
			for (UABUtilityActionBase* const Action : AllActions)
			{
				ActionStatus = Action->PerformAction(*this);

				if (ActionStatus != EABUtilityActionRunStatus::Failed)
				{
					CurrentAction = Action;
					break;
				}
			}
			break;
		}
		case (EABActionSelectionMode::RandomFromTop10Pct):
		{
			const int32 TenPctActionNum = (int32)((float)AllActions.Num() / 10.0f);
			TArray<UABUtilityActionBase*> TopActions;
			TopActions.Reserve(TenPctActionNum);
			for (int32 Index = 0; Index < TenPctActionNum; Index++)
			{
				TopActions.Add(AllActions[Index]);
			}
			Algo::RandomShuffle(TopActions);
			for (UABUtilityActionBase* const Action : TopActions)
			{
				ActionStatus = Action->PerformAction(*this);

				if (ActionStatus != EABUtilityActionRunStatus::Failed)
				{
					CurrentAction = Action;
					break;
				}
			}
			break;
		}
		case (EABActionSelectionMode::RandomFromTop25Pct):
		{
			const int32 TwentyFivePctActionNum = (int32)((float)AllActions.Num() / 4.0f);
			TArray<UABUtilityActionBase*> TopActions;
			TopActions.Reserve(TwentyFivePctActionNum);
			for (int32 Index = 0; Index < TwentyFivePctActionNum; Index++)
			{
				TopActions.Add(AllActions[Index]);
			}
			Algo::RandomShuffle(TopActions);
			for (UABUtilityActionBase* const Action : TopActions)
			{
				ActionStatus = Action->PerformAction(*this);

				if (ActionStatus != EABUtilityActionRunStatus::Failed)
				{
					CurrentAction = Action;
					break;
				}
			}
			break;
		}
	}

	return ActionStatus != EABUtilityActionRunStatus::Failed;
}

void UABUtilityComponent::AsyncRequestUtilityAction()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityComponent::AsyncRequestUtilityAction"))

	if (UtilityActions.IsEmpty())
	{
		UE_VLOG_UELOG(
			GetOwner(),
			LogABUtility,
			Warning,
			TEXT("%s - Utility Component [ %s ] has no actions."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*GetName()
		);
		StopLogic(FString(TEXT("Could not find new action.")));
		return;
	}

	// Get possible actions
	if (IsUsingParallelRequirementChecking())
	{
		ParallelAsyncGetPossibleActions();
	}
	else
	{
		AsyncGetPossibleActions();
	}
}

void UABUtilityComponent::GetPossibleActions(TMap<UABUtilityActionBase*, const float>& PossibleActionsToScores)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityComponent::GetPossibleActions"))

	checkf(IsValid(UtilityDataAsset), TEXT("Utility Data Asset is no longer valid"));

	for (UABUtilityActionBase* const Action : UtilityActions)
	{
		checkf(IsValid(Action), TEXT("Utility Component [ %s ] has an invalid action."), *GetName());

		// Check requirements
		if (!Action->CheckAllRequirements(*this))
		{
			continue;
		}

		// Check action has a valid score
		const float ActionScore = Action->GetActionScore(*this, UtilityDataAsset->IsUsingConsiderationFactor());
		if (ActionScore > 0.0f)
		{
			// Consider action
			PossibleActionsToScores.Add(Action, ActionScore);
		}
	}
}

void UABUtilityComponent::ParallelGetPossibleActions(TMap<UABUtilityActionBase*, const float>& PossibleActionsToScores)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityComponent::ParallelGetPossibleActions"))

	checkf(IsValid(UtilityDataAsset), TEXT("Utility Data Asset is no longer valid"));

	// Mutex for multi-threading
	FCriticalSection Mutex;

	ParallelFor(UtilityActions.Num(), [this, &Mutex, &PossibleActionsToScores](int32 Index)
		{
			FScopeLock Loc(&Mutex);

			UABUtilityActionBase* const Action = UtilityActions[Index];

			// Ensure not check so we don't crash during multi-threaded processes
			if (!ensureAlwaysMsgf(IsValid(Action), TEXT("Utility Data Asset has invalid action.")))
			{
				return;
			}

			// Check requirements
			if (!Action->CheckAllRequirements(*this))
			{
				return;
			}

			// Check action has a valid score
			const float ActionScore = Action->GetActionScore(*this, UtilityDataAsset->IsUsingConsiderationFactor());
			if (ActionScore > 0.0f)
			{
				// Consider action
				PossibleActionsToScores.Add(Action, ActionScore);
			}
		}
	);
}

void UABUtilityComponent::AsyncGetPossibleActions()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityComponent::AsyncGetPossibleActions"))

	AsyncData.Reset();

	for (UABUtilityActionBase* const Action : UtilityActions)
	{
		checkf(IsValid(Action), TEXT("Utility Component [ %s ] has an invalid action."), *GetName());

		// Start async task on any thread
		AsyncTask(ENamedThreads::AnyThread, [this, Action]()
			{
				Action->AsyncCheckAllRequirements(*this);
			}
		);

		AsyncData.AsyncActionsToCheck++;
	}
}

void UABUtilityComponent::ParallelAsyncGetPossibleActions()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityComponent::ParallelAsyncGetPossibleActions"))

	AsyncData.Reset();

	FCriticalSection Mutex;

	ParallelFor(UtilityActions.Num(), [this, &Mutex](int32 Index)
		{
			FScopeLock Lock(&Mutex);

			UABUtilityActionBase* const Action = UtilityActions[Index];

			// Ensure not check so we don't crash during multi-threaded processes
			if (!ensureAlwaysMsgf(IsValid(Action), TEXT("Utility Data Asset has invalid action.")))
			{
				return;
			}

			// Start async task on any thread
			AsyncTask(ENamedThreads::AnyThread, [this, Action]()
				{
					Action->AsyncCheckAllRequirements(*this);
				}
			);

			AsyncData.AsyncActionsToCheck++;
		}
	);
}

bool UABUtilityComponent::AttemptRetry()
{
	if (!ShouldRetryOnFailure())
	{
		return false;
	}

	// Use Timer Manager to trigger PerformUtilityAction next tick
	const UWorld* const World = GetWorld();
	if (!IsValid(World))
	{
		UE_VLOG_UELOG(
			GetOwner(),
			LogABUtility,
			Error,
			TEXT("%s - Could not find a valid world."),
			ANSI_TO_TCHAR(__FUNCTION__)
		);
		return false;
	}

	FTimerManager& TimerManager = World->GetTimerManager();

	TimerManager.SetTimerForNextTick([this]()
		{
			PerformUtilityAction();
		}
	);

	return true;
}