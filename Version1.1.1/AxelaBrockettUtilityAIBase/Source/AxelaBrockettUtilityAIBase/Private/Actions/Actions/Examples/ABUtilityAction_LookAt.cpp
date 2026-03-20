// Copyright (c) 2026 Axela Brockett. All rights reserved.

#include "Actions/Actions/Examples/ABUtilityAction_LookAt.h"

#include "AIController.h"
#include "Components/ABUtilityComponent.h"
#include "GameFramework/Pawn.h"
#include "Helpers/ABUtilityHelpers.h"
#include "Kismet/GameplayStatics.h"

#if WITH_GAMEPLAY_DEBUGGER_MENU
#include "GameplayDebuggerCategory.h"
#include "GameplayDebuggerTypes.h"
#endif // WITH_GAMEPLAY_DEBUGGER_MENU

EABUtilityActionRunStatus UABUtilityAction_LookAt::DoAction(
	UABUtilityComponent& OwnerComp,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_RunParallel::DoAction"))

	AAIController* const AIController = OwnerComp.GetAIOwner();
	if (!IsValid(AIController))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(
				TEXT("%s - Utility Component [ %s ] does not have a valid AI owner."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp.GetName()
			),
			OwnerComp.GetOwner()
		);
		return EABUtilityActionRunStatus::Failed;
	}

	const APawn* const AIPawn = AIController->GetPawn();
	if (!IsValid(AIPawn))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Warning,
			FString::Printf(
				TEXT("%s - AI Controller [ %s ] does not have a valid pawn."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*AIController->GetName()
			),
			AIController
		);
		return EABUtilityActionRunStatus::Failed;
	}

	UABUtilityActionLookAtIM* const LookAtIM = Cast<UABUtilityActionLookAtIM>(InstanceMemory);
	if (!IsValid(LookAtIM))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(
				TEXT("%s - Instance Memory [ %s ] is not for Look At Action."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*InstanceMemory->GetName()
			),
			AIController
		);
		return EABUtilityActionRunStatus::Failed;
	}

	const FVector& AIPawnLocation = AIPawn->GetActorLocation();
	const FVector& AIPawnForwardVector = AIPawn->GetActorForwardVector();
	EABUtilityActionRunStatus ActionStatus = EABUtilityActionRunStatus::Failed;

	switch (LookAtType)
	{
		case (EABUtilityLookAtType::Actor):
		{
			AActor* const LookAtSpecificActor = LookAtIM->LookAtActor.Get();

			if (IsValid(LookAtSpecificActor))
			{
				const FVector PawnToTarget = LookAtSpecificActor->GetActorLocation() - AIPawnLocation;
				const FVector::FReal AngleDifference =
					ABUtility::Helpers::CalculateAngleDifferenceDot(AIPawnForwardVector, PawnToTarget);

				if (AngleDifference >= GetPrecisionDot(AIPawn))
				{
					ActionStatus = EABUtilityActionRunStatus::Succeeded;
					break;
				}

				AIController->SetFocus(LookAtSpecificActor, EAIFocusPriority::Gameplay);
				ActionStatus = EABUtilityActionRunStatus::Running;
			}
			break;
		}
		case (EABUtilityLookAtType::Vector):
		{
			if (FAISystem::IsValidLocation(LookAtIM->LookAtVector))
			{
				const FVector PawnToTarget = LookAtIM->LookAtVector - AIPawnLocation;
				const FVector::FReal AngleDifference =
					ABUtility::Helpers::CalculateAngleDifferenceDot(AIPawnForwardVector, PawnToTarget);

				if (AngleDifference >= GetPrecisionDot(AIPawn))
				{
					ActionStatus = EABUtilityActionRunStatus::Succeeded;
					break;
				}

				AIController->SetFocalPoint(LookAtIM->LookAtVector, EAIFocusPriority::Gameplay);
				ActionStatus = EABUtilityActionRunStatus::Running;
			}
			break;
		}
		case (EABUtilityLookAtType::Rotator):
		{
			if (FAISystem::IsValidRotation(LookAtIM->LookAtRotator))
			{
				const FVector::FReal AngleDifference =
					ABUtility::Helpers::CalculateAngleDifferenceDot(AIPawnForwardVector, LookAtIM->LookAtRotator.Vector());

				if (AngleDifference >= GetPrecisionDot(AIPawn))
				{
					ActionStatus = EABUtilityActionRunStatus::Succeeded;
					break;
				}

				const FVector FocalPoint = AIPawnLocation + (LookAtIM->LookAtRotator.Vector() * LookAtRotatorDisplacement);
				AIController->SetFocalPoint(FocalPoint, EAIFocusPriority::Gameplay);
				LookAtIM->LookAtVector = FocalPoint;
				ActionStatus = EABUtilityActionRunStatus::Running;
			}
			break;
		}
		default:
		{
			break;
		}
	}
	
	return !bFailOnNoViableActors ? EABUtilityActionRunStatus::Running : ActionStatus;
}

EABUtilityActionRunStatus UABUtilityAction_LookAt::Tick(
	UABUtilityComponent& OwnerComp,
	float DeltaSeconds,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(TEXT("UABUtilityAction_RunParallel::Tick"))

	AAIController* const AIController = OwnerComp.GetAIOwner();
	if (!IsValid(AIController))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(
				TEXT("%s - Utility Component [ %s ] does not have a valid AI owner."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp.GetName()
			),
			OwnerComp.GetOwner()
		);
		return EABUtilityActionRunStatus::Failed;
	}

	const APawn* const AIPawn = AIController->GetPawn();
	if (!IsValid(AIPawn))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Warning,
			FString::Printf(
				TEXT("%s - AI Controller [ %s ] does not have a valid pawn."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*AIController->GetName()
			),
			AIController
		);
		return EABUtilityActionRunStatus::Failed;
	}

	UABUtilityActionLookAtIM* const LookAtIM = Cast<UABUtilityActionLookAtIM>(InstanceMemory);
	if (!IsValid(LookAtIM))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(
				TEXT("%s - Instance Memory [ %s ] is not for Look At Action."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*InstanceMemory->GetName()
			),
			AIController
		);
		return EABUtilityActionRunStatus::Failed;
	}

	const FVector& AIPawnLocation = AIPawn->GetActorLocation();
	const FVector& AIPawnForwardVector = AIPawn->GetActorForwardVector();
	const FVector& AIFocalPoint = AIController->GetFocalPointForPriority(EAIFocusPriority::Gameplay);

	bool bClearFocus = false;

	if (AIFocalPoint == FAISystem::InvalidLocation)
	{
		CleanUp(*LookAtIM, *AIController, AIPawnLocation);
		return EABUtilityActionRunStatus::Failed;
	}

	const FVector LookAtDirection = AIFocalPoint - AIPawnLocation;
	const FVector::FReal AngleDifference =
		ABUtility::Helpers::CalculateAngleDifferenceDot(AIPawnForwardVector, LookAtDirection);

	if (AngleDifference >= GetPrecisionDot(AIPawn))
	{
		CleanUp(*LookAtIM, *AIController, AIPawnLocation);
		return EABUtilityActionRunStatus::Succeeded;
	}

	return EABUtilityActionRunStatus::Running;
}

void UABUtilityAction_LookAt::PauseAction(
	UABUtilityComponent* OwnerComp,
	const FString& Reason,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	if (!IsValid(OwnerComp))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(
				TEXT("%s - Look At Action has been passed an invalid Utility Component."),
				ANSI_TO_TCHAR(__FUNCTION__)
			),
			this
		);
		return;
	}

	AAIController* const AIController = OwnerComp->GetAIOwner();
	if (!IsValid(AIController))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(
				TEXT("%s - Utility Component [ %s ] does not have a valid AI owner."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp->GetName()
			),
			OwnerComp->GetOwner()
		);
		return;
	}

	CleanUpOnPause.BindData(AIController->GetPawn(), INDEX_NONE);
	const bool bCleanUpOnPauseValue = CleanUpOnPause.GetValue();

	if (!bCleanUpOnPauseValue)
	{
		Super::PauseAction(OwnerComp, Reason, InstanceMemory);
		return;
	}

	UABUtilityActionLookAtIM* const LookAtIM =
		IsValid(InstanceMemory) ?
		Cast<UABUtilityActionLookAtIM>(InstanceMemory) :
		ABUtility::Helpers::GetMutableActionInstanceMemoryOfType<UABUtilityActionLookAtIM>(*this, *OwnerComp);
	if (!IsValid(LookAtIM))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Instance Memory for component [ %s ] is not for Look At Action."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp->GetName()
			),
			AIController
		);
		return;
	}

	const APawn* const AIPawn = AIController->GetPawn();
	if (!IsValid(AIPawn))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Warning,
			FString::Printf(
				TEXT("%s - AI Controller [ %s ] does not have a valid pawn."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*AIController->GetName()
			),
			AIController
		);
		return;
	}

	CleanUp(*LookAtIM, *AIController, AIPawn->GetActorLocation());
	Super::PauseAction(OwnerComp, Reason, InstanceMemory);
}

void UABUtilityAction_LookAt::AbortAction(
	UABUtilityComponent* OwnerComp,
	const FString& Reason,
	UABUtilityActionInstanceMemoryBase* InstanceMemory
)
{
	if (!IsValid(OwnerComp))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(
				TEXT("%s - Look At Action has been passed an invalid Utility Component"),
				ANSI_TO_TCHAR(__FUNCTION__)
			),
			this
		);
		return;
	}

	AAIController* const AIController = OwnerComp->GetAIOwner();
	if (!IsValid(AIController))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(
				TEXT("%s - Utility Component [ %s ] does not have a valid AI owner."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp->GetName()
			),
			OwnerComp->GetOwner()
		);
		return;
	}

	const APawn* const AIPawn = AIController->GetPawn();
	if (!IsValid(AIPawn))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Warning,
			FString::Printf(
				TEXT("%s - AI Controller [ %s ] does not have a valid Pawn."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*AIController->GetName()
			),
			AIController
		);
		return;
	}

	UABUtilityActionLookAtIM* const LookAtIM =
		IsValid(InstanceMemory) ?
		Cast<UABUtilityActionLookAtIM>(InstanceMemory) :
		ABUtility::Helpers::GetMutableActionInstanceMemoryOfType<UABUtilityActionLookAtIM>(*this, *OwnerComp);
	if (!IsValid(LookAtIM))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(TEXT("%s - Instance Memory for component [ %s ] is not for Look At Action."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp->GetName()
			),
			AIController
		);
		return;
	}

	CleanUp(*LookAtIM, *AIController, AIPawn->GetActorLocation());
	Super::AbortAction(OwnerComp, Reason, InstanceMemory);
}

const float UABUtilityAction_LookAt::GetPrecisionDot(const UObject* BindOwner) const
{
	Precision.BindData(BindOwner, INDEX_NONE);
	return FMath::Cos(FMath::DegreesToRadians(Precision.GetValue()));
}

void UABUtilityAction_LookAt::CleanUp(
	UABUtilityActionLookAtIM& LookAtIM,
	AAIController& AIController,
	const FVector& AIPawnLocation
)
{
	bool bClearFocus = false;

	switch (LookAtType)
	{
		case (EABUtilityLookAtType::Actor):
		{
			bClearFocus = (LookAtIM.LookAtActor == AIController.GetFocusActorForPriority(EAIFocusPriority::Gameplay));
			break;
		}
		case (EABUtilityLookAtType::Vector):
		case (EABUtilityLookAtType::Rotator):
		{
			bClearFocus = (LookAtIM.LookAtVector == AIController.GetFocalPointForPriority(EAIFocusPriority::Gameplay));
			break;
		}
		default:
		{
			break;
		}
	}

	if (bClearFocus)
	{
		AIController.ClearFocus(EAIFocusPriority::Gameplay);
	}
}

bool UABUtilityAction_LookAt::SetLookAtActor(UABUtilityComponent& OwnerComp, AActor* const NewLookAtActor)
{
	UABUtilityActionLookAtIM* const LookAtIM =
		ABUtility::Helpers::GetMutableActionInstanceMemoryOfType<UABUtilityActionLookAtIM>(*this, OwnerComp);
	if (!IsValid(LookAtIM))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(
				TEXT("%s - Could not get Instance Memory for Look At Action for Utility Component [ %s ]."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp.GetName()
			),
			OwnerComp.GetOwner()
		);
		return false;
	}

	LookAtIM->LookAtActor = NewLookAtActor;
	return true;
}

bool UABUtilityAction_LookAt::SetLookAtVector(UABUtilityComponent& OwnerComp, const FVector NewLookAtVector)
{
	UABUtilityActionLookAtIM* const LookAtIM =
		ABUtility::Helpers::GetMutableActionInstanceMemoryOfType<UABUtilityActionLookAtIM>(*this, OwnerComp);
	if (!IsValid(LookAtIM))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(
				TEXT("%s - Could not get Instance Memory for Look At Action for Utility Component [ %s ]."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp.GetName()
			),
			OwnerComp.GetOwner()
		);
		return false;
	}

	LookAtIM->LookAtVector = NewLookAtVector;
	return true;
}

bool UABUtilityAction_LookAt::SetLookAtRotator(UABUtilityComponent& OwnerComp, const FRotator NewLookAtRotator)
{
	UABUtilityActionLookAtIM* const LookAtIM =
		ABUtility::Helpers::GetMutableActionInstanceMemoryOfType<UABUtilityActionLookAtIM>(*this, OwnerComp);
	if (!IsValid(LookAtIM))
	{
		ABUtility::Helpers::UtilityVLOG(
			ELogVerbosity::Error,
			FString::Printf(
				TEXT("%s - Could not get Instance Memory for Look At Action for Utility Component [ %s ]."),
				ANSI_TO_TCHAR(__FUNCTION__),
				*OwnerComp.GetName()
			),
			OwnerComp.GetOwner()
		);
		return false;
	}

	LookAtIM->LookAtRotator = NewLookAtRotator;
	return true;
}

const bool UABUtilityAction_LookAt::ValidateAction(FString& InvalidationReason) const
{
	bool bIsValid = Super::ValidateAction(InvalidationReason);

	Precision.BindData(this, INDEX_NONE);
	if (Precision.GetValue() < 0.0f)
	{
		InvalidationReason += FString::Printf(TEXT("Precision value is less than 0."));
		bIsValid = false;
	}

	return bIsValid;
}

#if WITH_GAMEPLAY_DEBUGGER_MENU
void UABUtilityAction_LookAt::DescribeSelfToGameplayDebugger(
	const UABUtilityComponent& OwnerComp,
	const bool bUseConsiderationFactor,
	const UABUtilityActionInstanceMemoryBase* InstanceMemory,
	FGameplayDebuggerCategory* DebuggerCategory
) const
{
	if (DebuggerCategory == nullptr)
	{
		return;
	}

	Super::DescribeSelfToGameplayDebugger(
		OwnerComp,
		bUseConsiderationFactor,
		InstanceMemory,
		DebuggerCategory
	);

	const AAIController* const AIController = OwnerComp.GetAIOwner();
	if (IsValid(AIController))
	{
		Precision.BindData(AIController->GetPawn(), INDEX_NONE);
	}

	DebuggerCategory->AddTextLine(
		FString::Printf(TEXT("        {green}Precision: %f / Look At Type: %s / Look At Rotator Displacement: %f / Fail On No Viable Actors: %s"),
			Precision.GetValue(),
			LookAtType == EABUtilityLookAtType::Actor ? TEXT("Actor") :
			LookAtType == EABUtilityLookAtType::Vector ? TEXT("Vector") :
			LookAtType == EABUtilityLookAtType::Rotator ? TEXT("Rotator") :
			TEXT("None"),
			LookAtRotatorDisplacement,
			bFailOnNoViableActors ? TEXT("true") : TEXT("false")
		)
	);

	const UABUtilityActionLookAtIM* const LookAtIM = Cast<UABUtilityActionLookAtIM>(InstanceMemory);
	if (IsValid(LookAtIM) && LookAtIM->NeedsTick())
	{
		switch (LookAtType)
		{
			case (EABUtilityLookAtType::Actor):
			{
				if (LookAtIM->LookAtActor.IsValid())
				{
					DebuggerCategory->AddShape(
						FGameplayDebuggerShape::MakePoint(
							LookAtIM->LookAtActor.Get()->GetActorLocation(),
							10.0f,
							FColor::Green,
							FString::Printf(TEXT("%s"),
								*LookAtIM->LookAtActor.Get()->GetName()
							)
						)
					);
				}
				break;
			}
			case (EABUtilityLookAtType::Vector):
			{
				DebuggerCategory->AddShape(
					FGameplayDebuggerShape::MakePoint(
						LookAtIM->LookAtVector,
						10.0f,
						FColor::Green,
						FString::Printf(TEXT("%s"),
							*LookAtIM->LookAtVector.ToString()
						)
					)
				);
				break;
			}
			case (EABUtilityLookAtType::Rotator):
			{
				const APawn* const AIPawn = AIController->GetPawn();
				if (IsValid(AIPawn))
				{
					const FVector& AIPawnLocation = AIPawn->GetActorLocation();
					DebuggerCategory->AddShape(
						FGameplayDebuggerShape::MakeArrow(
							AIPawnLocation,
							AIPawnLocation + (LookAtIM->LookAtRotator.Vector() * 50.0f),
							10.0f,
							10.0f,
							FColor::Green,
							FString::Printf(TEXT("%s"),
								*LookAtIM->LookAtRotator.ToString()
							)
						)
					);
				}
				break;
			}
			default:
			{
				break;
			}
		}
	}
}
#endif // WITH_GAMEPLAY_DEBUGGER_MENU