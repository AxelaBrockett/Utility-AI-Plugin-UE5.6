// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/ABUtilityComponent.h"

#ifdef AXELABROCKETTUTILITYAIBASE_ABUtilityComponent_generated_h
#error "ABUtilityComponent.generated.h already included, missing '#pragma once' in ABUtilityComponent.h"
#endif
#define AXELABROCKETTUTILITYAIBASE_ABUtilityComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UABUtilityActionBase;

// ********** Begin Class UABUtilityComponent ******************************************************
#define FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnActionRequirementsChecked); \
	DECLARE_FUNCTION(execOnActionCompleted); \
	DECLARE_FUNCTION(execOnRep_LastSuccessfulAction); \
	DECLARE_FUNCTION(execOnRep_CurrentAction);


#define FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h_30_CALLBACK_WRAPPERS
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityComponent_NoRegister();

#define FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h_30_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUABUtilityComponent(); \
	friend struct Z_Construct_UClass_UABUtilityComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UABUtilityComponent, UBrainComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/AxelaBrockettUtilityAIBase"), Z_Construct_UClass_UABUtilityComponent_NoRegister) \
	DECLARE_SERIALIZER(UABUtilityComponent) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		CurrentAction=NETFIELD_REP_START, \
		LastSuccessfulAction, \
		NETFIELD_REP_END=LastSuccessfulAction	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h_30_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UABUtilityComponent(UABUtilityComponent&&) = delete; \
	UABUtilityComponent(const UABUtilityComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UABUtilityComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UABUtilityComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UABUtilityComponent) \
	NO_API virtual ~UABUtilityComponent();


#define FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h_27_PROLOG
#define FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h_30_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h_30_CALLBACK_WRAPPERS \
	FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h_30_INCLASS_NO_PURE_DECLS \
	FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h_30_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UABUtilityComponent;

// ********** End Class UABUtilityComponent ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
