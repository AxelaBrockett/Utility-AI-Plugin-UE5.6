// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Actions/Factors/ABUtilityFactorBase.h"
#include "DataProviders/AIDataProvider.h"

#include "ABUtilityFactor_HostileActorDist.generated.h"

class FGameplayDebuggerCategory;
class UABUtilityComponent;

/**
 * Factor that scores based on distance to the closest hostile actor
 */
UCLASS()
class AXELABROCKETTUTILITYAIBASE_API UABUtilityFactor_HostileActorDist : public UABUtilityFactorBase
{
	GENERATED_BODY()

public:
	UABUtilityFactor_HostileActorDist();

	const bool ValidateFactor(FString& InvalidationReasons) const override;

	// Debugging
#if WITH_GAMEPLAY_DEBUGGER_MENU
	void DescribeSelfToGameplayDebugger(
		const UABUtilityComponent& OwnerComp,
		const float NumberOfFactors,
		const bool bUseConsiderationFactor,
		FGameplayDebuggerCategory* DebuggerCategory
	) const override;
#endif //WITH_GAMEPLAY_DEBUGGER_MENU
	
protected:
	const float CalculateFactorScore(const UABUtilityComponent& OwnerComp) const override;

private:
	UPROPERTY(EditAnywhere, Category = "Utility AI Factor Hostile Actor Distance")
	FAIDataProviderFloatValue MaxDist;
};