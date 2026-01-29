// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataAsset.h"

#include "ABUtilityDataAsset.generated.h"

class UABUtilityActionBase;

// The possible methods for selecting actions
UENUM()
enum class EABActionSelectionMode
{
	HighestScore UMETA(ToolTip = "Will attempt to run actions starting from the highest scoring", DisplayName = "Highest Scoring"),
	RandomFromTop10Pct UMETA(ToolTip = "Will get the top 10% scoring actions, randomly sort them, then attempt to run them", DisplayName = "Random From Top 10%"),
	RandomFromTop25Pct UMETA(ToolTip = "Will get the top 25% scoring actions, randomly sort them, then attempt to run them", DisplayName = "Random From Top 25%")
};

/**
 * Data asset for Utility AI
 * Contains Utility Actions
 */
UCLASS()
class AXELABROCKETTUTILITYAIBASE_API UABUtilityDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	// Get the available actions for agents using this data asset
	const TArray<TObjectPtr<UABUtilityActionBase>>& GetActions() const { return UtilityActions; }

	// Get the method for selecting actions
	const EABActionSelectionMode& GetActionSelectionMode() const { return ActionSelectionMode; }

	// Get whether or not the Factors are using the Consideration Factor score modifier
	const bool IsUsingConsiderationFactor() const { return bUseConsiderationFactor; }
	
private:
	// The method for selecting actions
	UPROPERTY(EditAnywhere, Category = "Utility Actions")
	EABActionSelectionMode ActionSelectionMode = EABActionSelectionMode::HighestScore;

	// Actions available to agents using this data asset
	UPROPERTY(EditAnywhere, Instanced, Category = "Utility Actions")
	TArray<TObjectPtr<UABUtilityActionBase>> UtilityActions;

	// Enabling this will make all Factors within all Actions use the Consideration Factor score modifier
	UPROPERTY(EditAnywhere, Category = "Scoring")
	bool bUseConsiderationFactor = true;
};