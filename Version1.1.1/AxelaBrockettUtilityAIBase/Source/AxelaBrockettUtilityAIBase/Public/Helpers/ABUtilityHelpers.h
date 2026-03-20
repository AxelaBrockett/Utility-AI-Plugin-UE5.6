// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "AITypes.h"
#include "Components/ABUtilityComponent.h"
#include "Helpers/ABUtilityTypes.h"
#include "StateTreeExecutionTypes.h"
#include "Subsystems/ABUtilitySubsystem.h"
#include "UObject/NoExportTypes.h"

class UABUtilityActionBase;
class UObject;

namespace ABUtility::Helpers
{
	// Compare a left value to a right value using a comparison type
	bool CompareValues(const float Left, const float Right, const EGenericAICheck& ComparisonType);

	// Utility Subsystem getters
	const UABUtilitySubsystem* GetUtilitySubsystem(const UObject* WorldContextObject);
	const UABUtilitySubsystem& GetUtilitySubsystemChecked(const UObject* WorldContextObject);
	UABUtilitySubsystem* GetMutableUtilitySubsystem(const UObject* WorldContextObject);
	UABUtilitySubsystem& GetMutableUtilitySubsystemChecked(const UObject* WorldContextObject);

	template <typename T>
	const T* GetActionInstanceMemoryOfType(const UABUtilityActionBase& Action, const UABUtilityComponent& Component)
	{
		const UABUtilitySubsystem& UtilitySubsystem = GetUtilitySubsystemChecked(&Component);
		const UABUtilityActionInstanceMemoryBase* const InstanceMemory =
			UtilitySubsystem.GetActionInstanceMemoryForComponent(Action, Component);
		if (!IsValid(InstanceMemory)) return nullptr;
		return Cast<T>(InstanceMemory);
	}

	template <typename T>
	T* GetMutableActionInstanceMemoryOfType(const UABUtilityActionBase& Action, const UABUtilityComponent& Component)
	{
		UABUtilitySubsystem& UtilitySubsystem = GetMutableUtilitySubsystemChecked(&Component);
		UABUtilityActionInstanceMemoryBase* const InstanceMemory =
			UtilitySubsystem.GetMutableActionInstanceMemoryForComponent(Action, Component);
		if (!IsValid(InstanceMemory)) return nullptr;
		return Cast<T>(InstanceMemory);
	}

	const FString GetDebugCallstackString(int32 IgnoreCount);

	void UtilityVLOG(const ELogVerbosity::Type Verbosity, const FString& Message, const UObject* LogOwner);

	EABUtilityActionRunStatus StateTreeRunStatusToUtilityActionRunStatus(EStateTreeRunStatus StateTreeRunStatus);

	const FVector::FReal CalculateAngleDifferenceDot(const FVector& A, const FVector& B);
}