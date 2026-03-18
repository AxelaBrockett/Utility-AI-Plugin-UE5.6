// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Subsystems/ABUtilitySubsystem.h"

#include "Actions/Actions/ABUtilityActionBase.h"
#include "AIController.h"
#include "Components/ABUtilityComponent.h"
#include "DataAssets/ABUtilityDataAsset.h"
#include "Helpers/ABUtilityHelpers.h"
#include "Helpers/ABUtilityTypes.h"
#include "Settings/ABUtilitySettings.h"
#include "Subsystems/SubsystemCollection.h"

void UABUtilitySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilitySubsystem::Initialize"))

	Super::Initialize(Collection);
	
	const UABUtilitySettings* const UtilitySettings = GetDefault<UABUtilitySettings>();
	checkf(IsValid(UtilitySettings), TEXT("Could not get valid Utility Settings. Failed to initialize Utility Subsystem."));

	const TSet<const TSoftObjectPtr<const UABUtilityDataAsset>>& AvailableDataAssets = UtilitySettings->GetUtilityDataAssets();
	TArray<UABUtilityActionBase*> AllFoundActions;

	for (const TSoftObjectPtr<const UABUtilityDataAsset>& AvailableDataAssetSoftPtr : AvailableDataAssets)
	{
		const UABUtilityDataAsset* const AvailableDataAsset = AvailableDataAssetSoftPtr.LoadSynchronous();
		
		if (!IsValid(AvailableDataAsset))
		{
			ABUtility::Helpers::UtilityVLOG(
				ELogVerbosity::Error,
				FString::Printf(TEXT("%s - Failed to load Utility Data Asset [ %s ]."),
					ANSI_TO_TCHAR(__FUNCTION__),
					*AvailableDataAssetSoftPtr->GetName()
				),
				this
			);

			continue;
		}

		AllFoundActions.Append(AvailableDataAsset->GetActions());
	}

	for (UABUtilityActionBase* const Action : AllFoundActions)
	{
		if (ActionComponentInstanceMemory.Contains(Action))
		{
			continue;
		}

		Action->Initialize(GetWorld());
		ActionComponentInstanceMemory.Add(Action);
	}
}

void UABUtilitySubsystem::Deinitialize()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilitySubsystem::Deinitialize"))

	for (const TPair<UABUtilityActionBase*, FInstanceMemoryWrapper>& ActionInstanceMemory : ActionComponentInstanceMemory)
	{
		ActionInstanceMemory.Key->Deinitialize();
	}

	ActionComponentInstanceMemory.Empty();

	Super::Deinitialize();
}

void UABUtilitySubsystem::Tick(float DeltaTime)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilitySubsystem::Tick"))

	for (const TPair<UABUtilityActionBase*, FInstanceMemoryWrapper>& ActionMemoryWrapper : ActionComponentInstanceMemory)
	{
		if (!IsValid(ActionMemoryWrapper.Key))
		{
			continue;
		}

		if (!ActionMemoryWrapper.Key->ShouldTick())
		{
			continue;
		}

		for (const TPair<UABUtilityComponent*, UABUtilityActionInstanceMemoryBase*>& ComponentMemory : ActionMemoryWrapper.Value.ComponentInstanceMemory)
		{
			if (!IsValid(ComponentMemory.Key) || !IsValid(ComponentMemory.Value))
			{
				continue;
			}

			if (!ComponentMemory.Value->NeedsTick())
			{
				continue;
			}

			ActionMemoryWrapper.Key->TickAction(DeltaTime, *ComponentMemory.Key, ComponentMemory.Value);
		}
	}
}

TStatId UABUtilitySubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UABUtilitySubsystem, STATGROUP_Tickables);
}

bool UABUtilitySubsystem::DoesSupportWorldType(const EWorldType::Type WorldType) const
{
	return WorldType == EWorldType::Game || WorldType == EWorldType::PIE;
}

const bool UABUtilitySubsystem::SubscribeToDataAsset(
	UABUtilityComponent& SubscribingComponent,
	const TSoftObjectPtr<UABUtilityDataAsset>& DataAssetClass
)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilitySubsystem::SubscribeToDataAsset"))

	if (!DataAssetClass.IsValid())
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Failed to subscribe Utility Component [ %s ] to invalid asset."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*SubscribingComponent.GetName()
			),
			this
		);

		return false;
	}

	// Load asset
	const UABUtilityDataAsset* const LoadedAsset = DataAssetClass.LoadSynchronous();
	if (!IsValid(LoadedAsset))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Failed to load Data Asset [ %s ] for Component [ %s ]"),
				ANSI_TO_TCHAR(__FUNCTION__),
				*DataAssetClass->GetName(),
				*SubscribingComponent.GetName()
			),
			this
		);
	}

	// Set up instance memory for actions
	const TArray<UABUtilityActionBase*>& Actions = LoadedAsset->GetActions();

	for (UABUtilityActionBase* Action : Actions)
	{
		FInstanceMemoryWrapper* InstanceMemoryWrapper = ActionComponentInstanceMemory.Find(Action);
		if (InstanceMemoryWrapper == nullptr)
		{
			continue;
		}

		const TSubclassOf<UABUtilityActionInstanceMemoryBase>& InstanceMemoryClass = Action->GetInstanceMemoryType();
		const FName InstanceMemoryName =
			FName(
				FString::Printf(
					TEXT("%s_InstanceMemory_%s_%s"),
					*Action->GetName(),
					*SubscribingComponent.GetName(),
					IsValid(SubscribingComponent.GetAIOwner()) ? *SubscribingComponent.GetAIOwner()->GetName() : TEXT("None")
				)
			);
		UABUtilityActionInstanceMemoryBase* const InstanceMemory =
			NewObject<UABUtilityActionInstanceMemoryBase>(
				this,
				InstanceMemoryClass,
				InstanceMemoryName
			);
		InstanceMemoryWrapper->ComponentInstanceMemory.Add(&SubscribingComponent, InstanceMemory);
	}

	return true;
}

const bool UABUtilitySubsystem::Unsubscribe(const UABUtilityComponent& UnsubscribingComponent)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilitySubsystem::Unsubscribe"))

	for (TPair<UABUtilityActionBase*, FInstanceMemoryWrapper>& ComponentInstanceMemory : ActionComponentInstanceMemory)
	{
		if (!ComponentInstanceMemory.Value.ComponentInstanceMemory.Contains(&UnsubscribingComponent))
		{
			continue;
		}

		ComponentInstanceMemory.Value.ComponentInstanceMemory.Remove(&UnsubscribingComponent);
	}

	return true;
}

const TArray<const UABUtilityActionBase*> UABUtilitySubsystem::GetActionsAvailableToComponent(const UABUtilityComponent& Component) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilitySubsystem::GetActionsAvailableToComponent"))

	TArray<const UABUtilityActionBase*> Actions;

	for (const TPair<UABUtilityActionBase*, FInstanceMemoryWrapper>& ActionInstanceMemory : ActionComponentInstanceMemory)
	{
		if (!IsValid(ActionInstanceMemory.Key))
		{
			continue;
		}

		if (!ActionInstanceMemory.Value.ComponentInstanceMemory.Contains(&Component))
		{
			continue;
		}

		Actions.Add(ActionInstanceMemory.Key);
	}

	return Actions;
}

TArray<UABUtilityActionBase*> UABUtilitySubsystem::GetMutableActionsAvailableToComponent(const UABUtilityComponent& Component) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilitySubsystem::GetMutableActionsAvailableToComponent"))

	TArray<UABUtilityActionBase*> Actions;

	for (const TPair<UABUtilityActionBase*, FInstanceMemoryWrapper>& ActionInstanceMemory : ActionComponentInstanceMemory)
	{
		if (!IsValid(ActionInstanceMemory.Key))
		{
			continue;
		}

		if (!ActionInstanceMemory.Value.ComponentInstanceMemory.Contains(&Component))
		{
			continue;
		}

		Actions.Add(ActionInstanceMemory.Key);
	}

	return Actions;
}

const UABUtilityActionInstanceMemoryBase* UABUtilitySubsystem::GetActionInstanceMemoryForComponent(
	const UABUtilityActionBase& Action,
	const UABUtilityComponent& Component
) const
{
	return InternalGetMutableActionInstanceMemoryForComponent(Action, Component);
}

UABUtilityActionInstanceMemoryBase* UABUtilitySubsystem::GetMutableActionInstanceMemoryForComponent(
	const UABUtilityActionBase& Action,
	const UABUtilityComponent& Component
)
{
	return InternalGetMutableActionInstanceMemoryForComponent(Action, Component);
}

UABUtilityActionInstanceMemoryBase* UABUtilitySubsystem::InternalGetMutableActionInstanceMemoryForComponent(
	const UABUtilityActionBase& Action,
	const UABUtilityComponent& Component
) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilitySubsystem::InternalGetMutableActionInstanceMemoryForComponent"))

	const FInstanceMemoryWrapper* const InstanceMemoryWrapper = ActionComponentInstanceMemory.Find(&Action);
	if (InstanceMemoryWrapper == nullptr)
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Instance Memory for Action [ %s ] does not exist."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*Action.GetName()
			),
			this
		);
		return nullptr;
	}

	UABUtilityActionInstanceMemoryBase* const* InstanceMemoryPtr = InstanceMemoryWrapper->ComponentInstanceMemory.Find(&Component);
	if (InstanceMemoryPtr == nullptr)
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Instance Memory for Action [ %s ] does not exist for Component [ %s ]."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*Action.GetName(),
				*Component.GetName()
			),
			this
		);
		return nullptr;
	}

	UABUtilityActionInstanceMemoryBase* const InstanceMemory = *InstanceMemoryPtr;
	if (!IsValid(InstanceMemory))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Could not get valid instance memory for Action [ %s ] for Component [ %s ]."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*Action.GetName(),
				*Component.GetName()
			),
			this
		);
		return nullptr;
	}

	return InstanceMemory;
}

const UABUtilityComponent* UABUtilitySubsystem::GetComponentForActionInstanceMemory(
	const UABUtilityActionBase& Action,
	const UABUtilityActionInstanceMemoryBase& InstanceMemory
) const
{
	return GetMutableComponentForActionInstanceMemory(Action, InstanceMemory);
}

UABUtilityComponent* UABUtilitySubsystem::GetMutableComponentForActionInstanceMemory(
	const UABUtilityActionBase& Action,
	const UABUtilityActionInstanceMemoryBase& InstanceMemory
) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilitySubsystem::GetMutableComponentForActionInstanceMemory"))

	const FInstanceMemoryWrapper* const InstanceMemoryWrapper = ActionComponentInstanceMemory.Find(&Action);
	if (InstanceMemoryWrapper == nullptr)
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Action [ %s ] does not exist within the subsystem."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*Action.GetName()
			),
			this
		);
		return nullptr;
	}

	for (const TPair<UABUtilityComponent*, UABUtilityActionInstanceMemoryBase*>& ComponentMemory : InstanceMemoryWrapper->ComponentInstanceMemory)
	{
		if (ComponentMemory.Value != &InstanceMemory)
		{
			continue;
		}

		return ComponentMemory.Key;
	}

	ABUtility::Helpers::UtilityVLOG(
		ELogVerbosity::Error,
		FString::Printf(TEXT("%s - No component subscribed to Action [ %s ]."),
			ANSI_TO_TCHAR(__FUNCTION__),
			*Action.GetName()
		),
		this
	);

	return nullptr;
}