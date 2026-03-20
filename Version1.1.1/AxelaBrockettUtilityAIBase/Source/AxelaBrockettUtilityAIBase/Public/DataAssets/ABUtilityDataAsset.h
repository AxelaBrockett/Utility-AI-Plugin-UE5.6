// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataAsset.h"

#include "ABUtilityDataAsset.generated.h"

class UABUtilityActionBase;

/**
 * Data asset for Utility AI
 * Contains Utility Actions
 */
UCLASS()
class AXELABROCKETTUTILITYAIBASE_API UABUtilityDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	// Actions
	// Get the available actions for agents using this data asset
	const TArray<TObjectPtr<UABUtilityActionBase>>& GetActions() const { return UtilityActions; }
	
private:
	// Actions
	// Actions available to agents using this data asset
	UPROPERTY(EditAnywhere, Instanced, Category = "Utility Actions")
	TArray<TObjectPtr<UABUtilityActionBase>> UtilityActions;
};