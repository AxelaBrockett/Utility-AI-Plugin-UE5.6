// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Helpers/ABUtilityTypes.h"

#ifdef AXELABROCKETTUTILITYAIBASE_ABUtilityTypes_generated_h
#error "ABUtilityTypes.generated.h already included, missing '#pragma once' in ABUtilityTypes.h"
#endif
#define AXELABROCKETTUTILITYAIBASE_ABUtilityTypes_generated_h

#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Helpers_ABUtilityTypes_h

// ********** Begin Enum EABUtilityActionRunStatus *************************************************
#define FOREACH_ENUM_EABUTILITYACTIONRUNSTATUS(op) \
	op(EABUtilityActionRunStatus::NotRunning) \
	op(EABUtilityActionRunStatus::Running) \
	op(EABUtilityActionRunStatus::Succeeded) \
	op(EABUtilityActionRunStatus::Failed) 

enum class EABUtilityActionRunStatus : uint8;
template<> struct TIsUEnumClass<EABUtilityActionRunStatus> { enum { Value = true }; };
template<> AXELABROCKETTUTILITYAIBASE_API UEnum* StaticEnum<EABUtilityActionRunStatus>();
// ********** End Enum EABUtilityActionRunStatus ***************************************************

// ********** Begin Enum EABUtilityAbortActionLogic ************************************************
#define FOREACH_ENUM_EABUTILITYABORTACTIONLOGIC(op) \
	op(EABUtilityAbortActionLogic::StopComponent) \
	op(EABUtilityAbortActionLogic::PauseLogicPauseAction) \
	op(EABUtilityAbortActionLogic::PauseLogicAbortAction) \
	op(EABUtilityAbortActionLogic::ChooseNewAction) 

enum class EABUtilityAbortActionLogic : uint8;
template<> struct TIsUEnumClass<EABUtilityAbortActionLogic> { enum { Value = true }; };
template<> AXELABROCKETTUTILITYAIBASE_API UEnum* StaticEnum<EABUtilityAbortActionLogic>();
// ********** End Enum EABUtilityAbortActionLogic **************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
