// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Actions/Actions/ABUtilityActionBase.h"
#include "AITypes.h"
#include "DataProviders/AIDataProvider.h"
#include "Helpers/ABUtilityTypes.h"
#include "Templates/SubclassOf.h"

#include "ABUtilityAction_LookAt.generated.h"

class AActor;
class AAIController;
class FGameplayDebuggerCategory;
class UABUtilityComponent;

UCLASS()
class UABUtilityActionLookAtIM : public UABUtilityActionInstanceMemoryBase
{
	GENERATED_BODY()

public:
	void Reset() override
	{
		LookAtActor.Reset();
		LookAtVector = FAISystem::InvalidLocation;
		LookAtRotator = FAISystem::InvalidRotation;
	}

	friend UABUtilityAction_LookAt;

private:
	TWeakObjectPtr<AActor> LookAtActor = nullptr;
	FVector LookAtVector = FAISystem::InvalidLocation;
	FRotator LookAtRotator = FAISystem::InvalidRotation;
};

UENUM()
enum class EABUtilityLookAtType : uint8
{
	Actor,
	Vector,
	Rotator
};

/**
 * To set what the AI looks at, call UABUtilitySubsystem::GetMutableActionsAvailableToComponent()
 * passing in the relevent UABUtilityComponent, search for this Action in that array, then call
 * either SetLookAtActor(), SetLookAtVector() or SetLookAtRotator()
 */
UCLASS(meta = (DisplayName = "Utility Look At"))
class AXELABROCKETTUTILITYAIBASE_API UABUtilityAction_LookAt : public UABUtilityActionBase
{
	GENERATED_BODY()
	
public:
	const TSubclassOf<UABUtilityActionInstanceMemoryBase> GetInstanceMemoryType() const override
	{
		return UABUtilityActionLookAtIM::StaticClass();
	}

	void PauseAction(
		UABUtilityComponent* OwnerComp,
		const FString& Reason,
		UABUtilityActionInstanceMemoryBase* InstanceMemory = nullptr
	) override;
	void AbortAction(
		UABUtilityComponent* OwnerComp,
		const FString& Reason,
		UABUtilityActionInstanceMemoryBase* InstanceMemory = nullptr
	) override;

	bool SetLookAtActor(UABUtilityComponent& OwnerComp, AActor* const NewLookAtActor);
	bool SetLookAtVector(UABUtilityComponent& OwnerComp, const FVector NewLookAtVector);
	bool SetLookAtRotator(UABUtilityComponent& OwnerComp, const FRotator NewLookAtRotator);

	const bool ValidateAction(FString& InvalidationReason) const override;

#if WITH_GAMEPLAY_DEBUGGER_MENU
	void DescribeSelfToGameplayDebugger(
		const UABUtilityComponent& OwnerComp,
		const bool bUseConsiderationFactor,
		const UABUtilityActionInstanceMemoryBase* InstanceMemory,
		FGameplayDebuggerCategory* DebuggerCategory
	) const override;
#endif //WITH_GAMEPLAY_DEBUGGER_MENU

protected:
	EABUtilityActionRunStatus DoAction(
		UABUtilityComponent& OwnerComp,
		UABUtilityActionInstanceMemoryBase* InstanceMemory
	) override;

	EABUtilityActionRunStatus Tick(
		UABUtilityComponent& OwnerComp,
		float DeltaSeconds,
		UABUtilityActionInstanceMemoryBase* InstanceMemory
	) override;

private:
	const float GetPrecisionDot(const UObject* BindOwner) const;
	void CleanUp(UABUtilityActionLookAtIM& LookAtIM, AAIController& AIController, const FVector& AIPawnLocation);

	// If true, the AI Controller's focus will be cleared when the game is paused
	UPROPERTY(EditAnywhere, Category = "Utility Look At")
	FAIDataProviderBoolValue CleanUpOnPause;
	
	// Success condition precision in degrees
	UPROPERTY(EditAnywhere, Category = "Utility Look At")
	FAIDataProviderFloatValue Precision;

	// The type of focal point to look at
	UPROPERTY(EditAnywhere, Category = "Utility Look At")
	EABUtilityLookAtType LookAtType = EABUtilityLookAtType::Actor;

	// The displacement distance to use when looking in a rotation direction
	UPROPERTY(EditAnywhere, Category = "Utility Look At", meta = (EditCondition = "LookAtType==EABUtilityLookAtType::Rotator", EditConditionHides))
	float LookAtRotatorDisplacement = 10000.0f;

	// If true, the Action will fail if no actors are found, otherwise it will continue to tick
	UPROPERTY(EditAnywhere, Category = "Utility Look At")
	bool bFailOnNoViableActors = false;
};