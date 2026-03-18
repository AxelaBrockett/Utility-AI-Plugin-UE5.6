// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Actions/Actions/Examples/ABUtilityAction_RunGA.h"

#ifdef AXELABROCKETTUTILITYAIBASE_ABUtilityAction_RunGA_generated_h
#error "ABUtilityAction_RunGA.generated.h already included, missing '#pragma once' in ABUtilityAction_RunGA.h"
#endif
#define AXELABROCKETTUTILITYAIBASE_ABUtilityAction_RunGA_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UABUtilityAction_RunGameplayAbility **************************************
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_NoRegister();

#define FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_RunGA_h_31_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUABUtilityAction_RunGameplayAbility(); \
	friend struct Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_NoRegister(); \
public: \
	DECLARE_CLASS2(UABUtilityAction_RunGameplayAbility, UABUtilityActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AxelaBrockettUtilityAIBase"), Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_NoRegister) \
	DECLARE_SERIALIZER(UABUtilityAction_RunGameplayAbility)


#define FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_RunGA_h_31_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UABUtilityAction_RunGameplayAbility(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UABUtilityAction_RunGameplayAbility(UABUtilityAction_RunGameplayAbility&&) = delete; \
	UABUtilityAction_RunGameplayAbility(const UABUtilityAction_RunGameplayAbility&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UABUtilityAction_RunGameplayAbility); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UABUtilityAction_RunGameplayAbility); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UABUtilityAction_RunGameplayAbility) \
	NO_API virtual ~UABUtilityAction_RunGameplayAbility();


#define FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_RunGA_h_28_PROLOG
#define FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_RunGA_h_31_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_RunGA_h_31_INCLASS_NO_PURE_DECLS \
	FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_RunGA_h_31_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UABUtilityAction_RunGameplayAbility;

// ********** End Class UABUtilityAction_RunGameplayAbility ****************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_RunGA_h

// ********** Begin Enum EABUtilityRunGAFromType ***************************************************
#define FOREACH_ENUM_EABUTILITYRUNGAFROMTYPE(op) \
	op(EABUtilityRunGAFromType::Tag) \
	op(EABUtilityRunGAFromType::Class) 

enum class EABUtilityRunGAFromType : uint8;
template<> struct TIsUEnumClass<EABUtilityRunGAFromType> { enum { Value = true }; };
template<> AXELABROCKETTUTILITYAIBASE_API UEnum* StaticEnum<EABUtilityRunGAFromType>();
// ********** End Enum EABUtilityRunGAFromType *****************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
