// Copyright (c) 2026 Axela Brockett. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Subsystems/WorldSubsystem.h"
#include "Templates/SubclassOf.h"

#include "ABUtilitySubsystem.generated.h"

class FSubsystemCollectionBase;
class UABUtilityActionBase;
class UABUtilityActionInstanceMemoryBase;
class UABUtilityComponent;
class UABUtilityDataAsset;

USTRUCT()
struct FInstanceMemoryWrapper
{
	GENERATED_BODY()

	UPROPERTY()
	TMap<UABUtilityComponent*, UABUtilityActionInstanceMemoryBase*> ComponentInstanceMemory;
};

/**
 * 
 */
UCLASS()
class AXELABROCKETTUTILITYAIBASE_API UABUtilitySubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()

public:
	// USubsystem overrides
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;
	void Tick(float DeltaTime) override;
	TStatId GetStatId() const override;

	// Subscription
	const bool SubscribeToDataAsset(
		UABUtilityComponent& SubscribingComponent,
		const TSoftObjectPtr<UABUtilityDataAsset>& DataAssetClass
	);
	const bool Unsubscribe(const UABUtilityComponent& UnsubscribingComponent);

	// Actions
	const TArray<const UABUtilityActionBase*> GetActionsAvailableToComponent(const UABUtilityComponent& Component) const;
	TArray<UABUtilityActionBase*> GetMutableActionsAvailableToComponent(const UABUtilityComponent& Component) const;

	// Instance memory
	const UABUtilityActionInstanceMemoryBase* GetActionInstanceMemoryForComponent(
		const UABUtilityActionBase& Action,
		const UABUtilityComponent& Component
	) const;
	UABUtilityActionInstanceMemoryBase* GetMutableActionInstanceMemoryForComponent(
		const UABUtilityActionBase& Action,
		const UABUtilityComponent& Component
	);

	// Components
	const UABUtilityComponent* GetComponentForActionInstanceMemory(
		const UABUtilityActionBase& Action,
		const UABUtilityActionInstanceMemoryBase& InstanceMemory
	) const;
	UABUtilityComponent* GetMutableComponentForActionInstanceMemory(
		const UABUtilityActionBase& Action,
		const UABUtilityActionInstanceMemoryBase& InstanceMemory
	) const;

protected:
	// UWorldSubsystem overrides
	bool DoesSupportWorldType(const EWorldType::Type WorldType) const override;

private:
	// Instance memory
	UABUtilityActionInstanceMemoryBase* InternalGetMutableActionInstanceMemoryForComponent(
		const UABUtilityActionBase& Action,
		const UABUtilityComponent& Component
	) const;

	// Actions
	UPROPERTY()
	TMap<UABUtilityActionBase*, FInstanceMemoryWrapper> ActionComponentInstanceMemory;
};