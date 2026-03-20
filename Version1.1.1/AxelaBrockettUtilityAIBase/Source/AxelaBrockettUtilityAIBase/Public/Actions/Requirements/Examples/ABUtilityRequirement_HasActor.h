// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Actions/Requirements/ABUtilityRequirementBase.h"

#include "ABUtilityRequirement_HasActor.generated.h"

class UABUtilityComponent;

/**
 * Agent is required to have an actor
 */
UCLASS()
class AXELABROCKETTUTILITYAIBASE_API UABUtilityRequirement_HasActor : public UABUtilityRequirementBase
{
	GENERATED_BODY()
	
public:
	const bool CheckRequirement(const UABUtilityComponent& OwnerComp) const override;
};