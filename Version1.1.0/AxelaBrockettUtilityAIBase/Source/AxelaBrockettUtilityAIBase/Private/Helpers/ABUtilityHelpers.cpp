// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Helpers/ABUtilityHelpers.h"

#include "Engine/World.h"
#include "Settings/ABUtilitySettings.h"
#include "UObject/NoExportTypes.h"
#include "VisualLogger/VisualLogger.h"
#include "Windows/WindowsPlatformStackWalk.h"

namespace ABUtility::Helpers
{
	bool CompareValues(const float Left, const float Right, const EGenericAICheck& ComparisonType)
	{
		switch (ComparisonType)
		{
			case (EGenericAICheck::Equal):
			{
				return Left == Right;
				break;
			}
			case (EGenericAICheck::NotEqual):
			{
				return Left != Right;
				break;
			}
			case (EGenericAICheck::Less):
			{
				return Left < Right;
				break;
			}
			case (EGenericAICheck::LessOrEqual):
			{
				return Left <= Right;
				break;
			}
			case (EGenericAICheck::Greater):
			{
				return Left > Right;
				break;
			}
			case (EGenericAICheck::GreaterOrEqual):
			{
				return Left >= Right;
				break;
			}
			default:
			{
				ensureAlwaysMsgf(false, TEXT("Unhandled Comparison Type [ %d ]."), ComparisonType);
				return false;
				break;
			}
		}
	}

	const UABUtilitySubsystem* GetUtilitySubsystem(const UObject* WorldContextObject)
	{
		return GetMutableUtilitySubsystem(WorldContextObject);
	}

	const UABUtilitySubsystem& GetUtilitySubsystemChecked(const UObject* WorldContextObject)
	{
		const UABUtilitySubsystem* const UtilitySubsystem = GetUtilitySubsystem(WorldContextObject);
		check(IsValid(UtilitySubsystem));
		return *UtilitySubsystem;
	}

	UABUtilitySubsystem* GetMutableUtilitySubsystem(const UObject* WorldContextObject)
	{
		const UWorld* const World = WorldContextObject->GetWorld();
		checkf(IsValid(World), TEXT("Could not get valid world."));
		return World->GetSubsystem<UABUtilitySubsystem>();
	}

	UABUtilitySubsystem& GetMutableUtilitySubsystemChecked(const UObject* WorldContextObject)
	{
		UABUtilitySubsystem* const UtilitySubsystem = GetMutableUtilitySubsystem(WorldContextObject);
		check(IsValid(UtilitySubsystem));
		return *UtilitySubsystem;
	}

	const FString GetDebugCallstackString(int32 IgnoreCount)
	{
		const SIZE_T StackTraceSize = 65535;
		ANSICHAR StackTrace[StackTraceSize] = { 0 };
		FPlatformStackWalk::StackWalkAndDump(StackTrace, StackTraceSize, ++IgnoreCount);
		FString StackTraceText(StackTrace);
		return StackTraceText;
	}

	void UtilityVLOG(const ELogVerbosity::Type Verbosity, const FString& Message, const UObject* LogOwner)
	{
		if (!IsValid(LogOwner))
		{
			return;
		}

		const UABUtilitySettings* const UtilitySettings = GetDefault<UABUtilitySettings>();
		checkf(IsValid(UtilitySettings), TEXT("Could not get valid Utility Settings."));

		switch (Verbosity)
		{
			case (ELogVerbosity::All):
			{
				UE_VLOG_UELOG(
					LogOwner,
					LogABUtility,
					All,
					TEXT("Log Message: %s\nCallstack:\n%s"),
					*Message,
					UtilitySettings->ShouldPrintCallstackInLogs() ? *GetDebugCallstackString(1) : TEXT("NONE")
				);
				break;
			}
			case (ELogVerbosity::BreakOnLog):
			{
				UE_VLOG_UELOG(
					LogOwner,
					LogABUtility,
					Error,
					TEXT("Log Message: %s\nCallstack:\n%s"),
					*Message,
					UtilitySettings->ShouldPrintCallstackInLogs() ? *GetDebugCallstackString(1) : TEXT("NONE")
				);
				UE_DEBUG_BREAK();
				break;
			}
			case (ELogVerbosity::Display):
			default:
			{
				UE_VLOG_UELOG(
					LogOwner,
					LogABUtility,
					Display,
					TEXT("Log Message: %s\nCallstack:\n%s"),
					*Message,
					UtilitySettings->ShouldPrintCallstackInLogs() ? *GetDebugCallstackString(1) : TEXT("NONE")
				);
				break;
			}
			case (ELogVerbosity::Error):
			{
				UE_VLOG_UELOG(
					LogOwner,
					LogABUtility,
					Error,
					TEXT("Log Message: %s\nCallstack:\n%s"),
					*Message,
					UtilitySettings->ShouldPrintCallstackInLogs() ? *GetDebugCallstackString(1) : TEXT("NONE")
				);
				break;
			}
			case (ELogVerbosity::Fatal):
			{
				UE_VLOG_UELOG(
					LogOwner,
					LogABUtility,
					Fatal,
					TEXT("Log Message: %s\nCallstack:\n%s"),
					*Message,
					UtilitySettings->ShouldPrintCallstackInLogs() ? *GetDebugCallstackString(1) : TEXT("NONE")
				);
				break;
			}
			case (ELogVerbosity::Log):
			{
				UE_VLOG_UELOG(
					LogOwner,
					LogABUtility,
					Log,
					TEXT("Log Message: %s\nCallstack:\n%s"),
					*Message,
					UtilitySettings->ShouldPrintCallstackInLogs() ? *GetDebugCallstackString(1) : TEXT("NONE")
				);
				break;
			}
			case (ELogVerbosity::NoLogging):
			case (ELogVerbosity::NumVerbosity):
			case (ELogVerbosity::SetColor):
			case (ELogVerbosity::VerbosityMask):
			{
				break;
			}
			case (ELogVerbosity::Verbose):
			{
				UE_VLOG_UELOG(
					LogOwner,
					LogABUtility,
					Verbose,
					TEXT("Log Message: %s\nCallstack:\n%s"),
					*Message,
					UtilitySettings->ShouldPrintCallstackInLogs() ? *GetDebugCallstackString(1) : TEXT("NONE")
				);
				break;
			}
			case (ELogVerbosity::Warning):
			{
				UE_VLOG_UELOG(
					LogOwner,
					LogABUtility,
					Warning,
					TEXT("Log Message: %s\nCallstack:\n%s"),
					*Message,
					UtilitySettings->ShouldPrintCallstackInLogs() ? *GetDebugCallstackString(1) : TEXT("NONE")
				);
				break;
			}
		}
	}

	EABUtilityActionRunStatus StateTreeRunStatusToUtilityActionRunStatus(EStateTreeRunStatus StateTreeRunStatus)
	{
		switch (StateTreeRunStatus)
		{
			case (EStateTreeRunStatus::Failed):
			case (EStateTreeRunStatus::Stopped):
			case (EStateTreeRunStatus::Unset):
			default:
			{
				return EABUtilityActionRunStatus::Failed;
			}
			case (EStateTreeRunStatus::Running):
			{
				return EABUtilityActionRunStatus::Running;
			}
			case (EStateTreeRunStatus::Succeeded):
			{
				return EABUtilityActionRunStatus::Succeeded;
			}
		}
	}

	const FVector::FReal CalculateAngleDifferenceDot(const FVector& A, const FVector& B)
	{
		return (A.IsNearlyZero() || B.IsNearlyZero()) ? 1.0f : A.CosineAngle2D(B);
	}
}