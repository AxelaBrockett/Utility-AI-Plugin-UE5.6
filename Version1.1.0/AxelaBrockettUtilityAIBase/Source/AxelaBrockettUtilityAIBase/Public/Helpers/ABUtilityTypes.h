// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "Logging/LogMacros.h"
#include "UObject/NoExportTypes.h"
#include "UObject/ObjectMacros.h"

#include "ABUtilityTypes.generated.h"

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

UENUM(BlueprintType)
enum class EABActionSelectionMode : uint8
{
	HighestScore UMETA(ToolTip = "Will attempt to run actions starting from the highest scoring", DisplayName = "Highest Scoring"),
	RandomFromTop10Pct UMETA(ToolTip = "Will get the top 10% scoring actions, randomly sort them, then attempt to run them", DisplayName = "Random From Top 10%"),
	RandomFromTop25Pct UMETA(ToolTip = "Will get the top 25% scoring actions, randomly sort them, then attempt to run them", DisplayName = "Random From Top 25%")
};

/*
* Classes
*/

UCLASS()
class UABUtilityActionInstanceMemoryBase : public UObject
{
	GENERATED_BODY()

public:
	const bool NeedsTick() const { return bNeedsTick; }
	const bool IsTickableActionComplete() const { return bTickableActionComplete; }
	const bool WasSuccessful() const { return bSuccess; }
	void SetNeedsTick(const bool bInNeedsTick = false) { bNeedsTick = bInNeedsTick; }
	void SetTickableActionComplete(const bool bInTickableActionComplete = false, const bool bInSuccess = false)
	{
		bTickableActionComplete = bInTickableActionComplete;
		bSuccess = bInSuccess;
	}
	virtual void Reset() {}

protected:
	bool bNeedsTick = false;
	bool bTickableActionComplete = false;
	bool bSuccess = false;
};