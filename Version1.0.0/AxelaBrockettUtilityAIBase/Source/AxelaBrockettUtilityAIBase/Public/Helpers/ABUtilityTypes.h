// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "Logging/LogMacros.h"
#include "UObject/ObjectMacros.h"

DECLARE_LOG_CATEGORY_EXTERN(LogABUtility, Display, All);

/*
* Enums
*/

UENUM(BlueprintType)
enum class EABUtilityActionRunStatus : uint8
{
	NotRunning,
	Running,
	Succeeded,
	Failed
};

UENUM()
enum class EABUtilityAbortActionLogic : uint8
{
	StopComponent,
	PauseLogicPauseAction,
	PauseLogicAbortAction,
	ChooseNewAction
};