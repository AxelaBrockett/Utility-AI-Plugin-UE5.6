// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Validators/ABUtilityDataAssetValidator.h"

#include "Actions/Actions/ABUtilityActionBase.h"
#include "Actions/Factors/ABUtilityFactorBase.h"
#include "Actions/Requirements/ABUtilityRequirementBase.h"
#include "AssetRegistry/AssetData.h"
#include "DataAssets/ABUtilityDataAsset.h"
#include "Misc/DataValidation.h"

#define LOCTEXT_NAMESPACE "AssetValidation"

bool UABUtilityDataAssetValidator::CanValidateAsset_Implementation(
	const FAssetData& InAssetData,
	UObject* InObject,
	FDataValidationContext& InContext
) const
{
	// This validator only accepts UAJBUtilityDataAssets
	return InObject->IsA(UABUtilityDataAsset::StaticClass());
}

EDataValidationResult UABUtilityDataAssetValidator::ValidateLoadedAsset_Implementation(
	const FAssetData& InAssetData,
	UObject* InAsset,
	FDataValidationContext& Context
)
{
	UABUtilityDataAsset* const UtilityDataAsset = Cast<UABUtilityDataAsset>(InAsset);
	if (!IsValid(UtilityDataAsset))
	{
		// Object incorrectly passed CanValidateAsset
		AssetFails(
			InAsset,
			FText::Format(
				LOCTEXT(
					"UtilityDataAssetValidator_IsNotAJBUtilityDataAsset",
					"Asset {0} is not of type UAJBUtilityDataAsset yet it passed CanValidateAsset."
				),
				FText::FromName(InAsset->GetFName())
			)
		);
		return EDataValidationResult::Invalid;
	}

	// Prepare invalid index arrays
	const TArray<UABUtilityActionBase*>& UtilityActions = UtilityDataAsset->GetActions();
	TArray<int32> InvalidActionIndices;
	TArray<FString> InvalidActionReasons;
	struct FInvalidRequirementIndices
	{
		TArray<int32> RequirementIndices;
		TArray<FString> RequirementReasons;
	};
	struct FInvalidFactorIndices
	{
		TArray<int32> FactorIndices;
		TArray<FString> FactorReasons;
	};
	TArray<FInvalidRequirementIndices> InvalidRequirementIndices;
	TArray<FInvalidFactorIndices> InvalidFactorIndices;
	InvalidActionIndices.Reserve(UtilityActions.Num());
	InvalidActionReasons.Reserve(UtilityActions.Num());
	InvalidRequirementIndices.Reserve(UtilityActions.Num());
	InvalidFactorIndices.Reserve(UtilityActions.Num());

	bool bAssetFullyValid = true;

	for (int32 Index = 0; Index < UtilityActions.Num(); Index++)
	{
		// Keep on top of indices
		InvalidActionReasons.Add(FString());
		InvalidRequirementIndices.Add(FInvalidRequirementIndices());
		InvalidFactorIndices.Add(FInvalidFactorIndices());

		const UABUtilityActionBase* const Action = UtilityActions[Index];
		if (!IsValid(Action))
		{
			// Action is invalid
			InvalidActionIndices.Add(Index);
			bAssetFullyValid = false;
			continue;
		}

		if (!Action->ValidateAction(InvalidActionReasons[0]))
		{
			InvalidActionIndices.Add(Index);
			bAssetFullyValid = false;
			continue;
		}

		// Collect invalid requirements
		const TArray<UABUtilityRequirementBase*>& Requirements = Action->GetRequirements();
		for (int32 RequirementIndex = 0; RequirementIndex < Requirements.Num(); RequirementIndex++)
		{
			const UABUtilityRequirementBase* const Requirement = Requirements[RequirementIndex];
			if (!IsValid(Requirement))
			{
				InvalidRequirementIndices[Index].RequirementIndices.Add(RequirementIndex);
				InvalidRequirementIndices[Index].RequirementReasons.Add(FString::Printf(TEXT("Requirement is nullptr.\n")));
				bAssetFullyValid = false;
				continue;
			}

			FString RequirementInvalidationReasons;
			if (!Requirement->ValidateRequirement(RequirementInvalidationReasons))
			{
				InvalidRequirementIndices[Index].RequirementIndices.Add(RequirementIndex);
				InvalidRequirementIndices[Index].RequirementReasons.Add(RequirementInvalidationReasons);
				bAssetFullyValid = false;
			}
		}

		// Collect invalid factors
		const TArray<UABUtilityFactorBase*>& Factors = Action->GetFactors();
		for (int32 FactorIndex = 0; FactorIndex < Factors.Num(); FactorIndex++)
		{
			const UABUtilityFactorBase* const Factor = Factors[FactorIndex];
			if (!IsValid(Factor))
			{
				InvalidFactorIndices[Index].FactorIndices.Add(FactorIndex);
				InvalidFactorIndices[Index].FactorReasons.Add(FString::Printf(TEXT("Factor is nullptr.\n")));
				bAssetFullyValid = false;
				continue;
			}

			FString FactorInvalidationReasons;
			if (!Factor->ValidateFactor(FactorInvalidationReasons))
			{
				InvalidFactorIndices[Index].FactorIndices.Add(FactorIndex);
				InvalidFactorIndices[Index].FactorReasons.Add(FactorInvalidationReasons);
				bAssetFullyValid = false;
			}
		}
	}

	// If this is still true, asset passes
	if (bAssetFullyValid)
	{
		AssetPasses(InAsset);
		return EDataValidationResult::Valid;
	}

	// Add invalid actions to the error message
	FString ErrorMessage;
	if (!InvalidActionIndices.IsEmpty())
	{
		ErrorMessage += FString::Printf(TEXT("\nInvalid action indices:\n"));
		for (const int32& ActionIndex : InvalidActionIndices)
		{
			ErrorMessage += FString::Printf(TEXT("    %i\n"), ActionIndex);
			ErrorMessage += FString::Printf(TEXT("    - %s\n"), *InvalidActionReasons[ActionIndex]);
		}
	}

	// Add invalid requirements to the error message
	ErrorMessage += FString::Printf(TEXT("\nInvalid requirements:\n"));
	for (int32 ActionIndex = 0; ActionIndex < InvalidRequirementIndices.Num(); ActionIndex++)
	{
		const FInvalidRequirementIndices& SelectedRequirementIndices = InvalidRequirementIndices[ActionIndex];
		if (SelectedRequirementIndices.RequirementIndices.IsEmpty())
		{
			continue;
		}

		ErrorMessage += FString::Printf(TEXT("    Action: %s\n    Requirement indices:\n"), *UtilityActions[ActionIndex]->GetName());

		for (const int32& RequirementIndex : SelectedRequirementIndices.RequirementIndices)
		{
			ErrorMessage += FString::Printf(TEXT("        %i\n"), RequirementIndex);
			ErrorMessage += FString::Printf(TEXT("        - %s\n"),
				*SelectedRequirementIndices.RequirementReasons[RequirementIndex]
			);
		}
	}

	// Add invalid factors to the error message
	ErrorMessage += FString::Printf(TEXT("\nInvalid factors:\n"));
	for (int32 ActionIndex = 0; ActionIndex < InvalidFactorIndices.Num(); ActionIndex++)
	{
		const FInvalidFactorIndices& SelectedFactorIndices = InvalidFactorIndices[ActionIndex];
		if (SelectedFactorIndices.FactorIndices.IsEmpty())
		{
			continue;
		}

		ErrorMessage += FString::Printf(TEXT("    Action: %s\n    Factor indices:\n"), *UtilityActions[ActionIndex]->GetName());

		for (const int32& FactorIndex : SelectedFactorIndices.FactorIndices)
		{
			ErrorMessage += FString::Printf(TEXT("        %i\n"), FactorIndex);
			ErrorMessage += FString::Printf(TEXT("        - %s\n"),
				*SelectedFactorIndices.FactorReasons[FactorIndex]
			);
		}
	}

	AssetFails(InAsset, FText::FromString(ErrorMessage));
	return EDataValidationResult::Invalid;
}

#undef LOCTEXT_NAMESPACE