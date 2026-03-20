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

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UABUtilityActionInstanceMemoryBase ***************************************
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionInstanceMemoryBase_NoRegister();

#define FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Helpers_ABUtilityTypes_h_50_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUABUtilityActionInstanceMemoryBase(); \
	friend struct Z_Construct_UClass_UABUtilityActionInstanceMemoryBase_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionInstanceMemoryBase_NoRegister(); \
public: \
	DECLARE_CLASS2(UABUtilityActionInstanceMemoryBase, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AxelaBrockettUtilityAIBase"), Z_Construct_UClass_UABUtilityActionInstanceMemoryBase_NoRegister) \
	DECLARE_SERIALIZER(UABUtilityActionInstanceMemoryBase)


#define FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Helpers_ABUtilityTypes_h_50_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UABUtilityActionInstanceMemoryBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UABUtilityActionInstanceMemoryBase(UABUtilityActionInstanceMemoryBase&&) = delete; \
	UABUtilityActionInstanceMemoryBase(const UABUtilityActionInstanceMemoryBase&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UABUtilityActionInstanceMemoryBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UABUtilityActionInstanceMemoryBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UABUtilityActionInstanceMemoryBase) \
	NO_API virtual ~UABUtilityActionInstanceMemoryBase();


#define FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Helpers_ABUtilityTypes_h_47_PROLOG
#define FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Helpers_ABUtilityTypes_h_50_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Helpers_ABUtilityTypes_h_50_INCLASS_NO_PURE_DECLS \
	FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Helpers_ABUtilityTypes_h_50_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UABUtilityActionInstanceMemoryBase;

// ********** End Class UABUtilityActionInstanceMemoryBase *****************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Helpers_ABUtilityTypes_h

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

// ********** Begin Enum EABActionSelectionMode ****************************************************
#define FOREACH_ENUM_EABACTIONSELECTIONMODE(op) \
	op(EABActionSelectionMode::HighestScore) \
	op(EABActionSelectionMode::RandomFromTop10Pct) \
	op(EABActionSelectionMode::RandomFromTop25Pct) 

enum class EABActionSelectionMode : uint8;
template<> struct TIsUEnumClass<EABActionSelectionMode> { enum { Value = true }; };
template<> AXELABROCKETTUTILITYAIBASE_API UEnum* StaticEnum<EABActionSelectionMode>();
// ********** End Enum EABActionSelectionMode ******************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
