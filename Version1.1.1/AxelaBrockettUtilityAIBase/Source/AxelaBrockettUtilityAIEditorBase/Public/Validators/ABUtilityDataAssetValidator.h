// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "EditorValidatorBase.h"

#include "ABUtilityDataAssetValidator.generated.h"

class FDataValidationContext;
struct FAssetData;

/**
 * Editor Validator for the Utility Data Asset
 * Validates every action in the data asset, along with its Requirements and Factors
 */
UCLASS()
class AXELABROCKETTUTILITYAIEDITORBASE_API UABUtilityDataAssetValidator : public UEditorValidatorBase
{
	GENERATED_BODY()
	
public:
	// Validation
	bool CanValidateAsset_Implementation(
		const FAssetData& InAssetData,
		UObject* InObject,
		FDataValidationContext& InContext
	) const override;
	EDataValidationResult ValidateLoadedAsset_Implementation(
		const FAssetData& InAssetData,
		UObject* InAsset,
		FDataValidationContext& Context
	) override;
};