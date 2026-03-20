// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMEPLAY_DEBUGGER_MENU
#include "GameplayDebuggerCategory.h"

class AActor;
class APlayerController;

/**
 * Gameplay Debugger Category for Utility AI
 */
class AXELABROCKETTUTILITYAIBASE_API FGameplayDebuggerCategory_Utility : public FGameplayDebuggerCategory
{
public:
	// Debugging
	FGameplayDebuggerCategory_Utility();

	void CollectData(APlayerController* OwnerPC, AActor* DebugActor) override;

	static TSharedRef<FGameplayDebuggerCategory> MakeInstance();

protected:
	void OnChangeActionIndex();

	int32 ActionIndex = 0;
};
#endif //WITH_GAMEPLAY_DEBUGGER_MENU