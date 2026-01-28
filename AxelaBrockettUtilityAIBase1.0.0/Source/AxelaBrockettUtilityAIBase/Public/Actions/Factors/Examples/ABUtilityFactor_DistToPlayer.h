// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Actions/Factors/ABUtilityFactorBase.h"
#include "DataProviders/AIDataProvider.h"

#include "ABUtilityFactor_DistToPlayer.generated.h"

class FGameplayDebuggerCategory;
class UABUtilityComponent;

/**
 * Factor that scores based on distance to the player
 */
UCLASS()
class AXELABROCKETTUTILITYAIBASE_API UABUtilityFactor_DistToPlayer : public UABUtilityFactorBase
{
	GENERATED_BODY()
	
public:
	UABUtilityFactor_DistToPlayer();

	const bool ValidateFactor(FString& InvalidationReasons) const override;

	// Debugging
#if WITH_GAMEPLAY_DEBUGGER_MENU
	void DescribeSelfToGameplayDebugger(
		const UABUtilityComponent& OwnerComp,
		const float NumberOfFactors,
		FGameplayDebuggerCategory* DebuggerCategory
	) const override;
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

protected:
	const float CalculateFactorScore(const UABUtilityComponent& OwnerComp) const override;

private:
	UPROPERTY(EditAnywhere, Category = "Utility AI Factor Distance To Player")
	FAIDataProviderFloatValue MaxDist;
};