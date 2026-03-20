// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Engine/DeveloperSettings.h"

#include "ABUtilitySettings.generated.h"

class UABUtilityDataAsset;

/**
 * 
 */
UCLASS(Config = Plugins, DefaultConfig, meta = (DisplayName = "Utility AI Settings"))
class AXELABROCKETTUTILITYAIBASE_API UABUtilitySettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	const TSet<const TSoftObjectPtr<const UABUtilityDataAsset>>& GetUtilityDataAssets() const { return UtilityDataAssets; }
	const bool ShouldPrintCallstackInLogs() const { return bPrintCallstackInLogs; }
	
private:
	// Data assets
	// The Utility Data Assets that will be loaded at runtime and available for use
	UPROPERTY(EditAnywhere, Config, Category = "Data Assets")
	TSet<const TSoftObjectPtr<const UABUtilityDataAsset>> UtilityDataAssets;

	// Debugging
	// Whether or not callstacks will be printed with warnings and errors
	// Gathering the callstack is time consuming - use carefully
	UPROPERTY(EditAnywhere, Config, Category = "Debugging")
	bool bPrintCallstackInLogs = true;
};