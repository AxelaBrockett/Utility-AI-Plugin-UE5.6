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
class UABUtilityActionInstanceMemoryBase;
enum class EABActionSelectionMode : uint8;
enum class EABUtilityAbortActionLogic : uint8;
enum class EABUtilityActionRunStatus : uint8;
enum class EABUtilityComponentPauseActionLogic : uint8;

// ********** Begin Class UABUtilityComponent ******************************************************
#define FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnActionRequirementsChecked); \
	DECLARE_FUNCTION(execAttemptRetry); \
	DECLARE_FUNCTION(execOnActionCompleted); \
	DECLARE_FUNCTION(execOnRep_CurrentRunStatus); \
	DECLARE_FUNCTION(execOnRep_LastSuccessfulAction); \
	DECLARE_FUNCTION(execOnRep_CurrentAction); \
	DECLARE_FUNCTION(execIsUsingConsiderationFactor); \
	DECLARE_FUNCTION(execShouldRetryOnFailure); \
	DECLARE_FUNCTION(execIsUsingParallelRequirementChecking); \
	DECLARE_FUNCTION(execIsComponentRunningAsynchronously); \
	DECLARE_FUNCTION(execShouldRestartLogicWhenResumingComponentLogic); \
	DECLARE_FUNCTION(execPauseLogicWithActionDecision); \
	DECLARE_FUNCTION(execAbortCurrentAction); \
	DECLARE_FUNCTION(execGetActionSelectionMode); \
	DECLARE_FUNCTION(execGetLastSuccessfulAction); \
	DECLARE_FUNCTION(execGetCurrentAction);


#define FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h_31_CALLBACK_WRAPPERS
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityComponent_NoRegister();

#define FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h_31_INCLASS_NO_PURE_DECLS \
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
		CurrentRunStatus, \
		NETFIELD_REP_END=CurrentRunStatus	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h_31_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UABUtilityComponent(UABUtilityComponent&&) = delete; \
	UABUtilityComponent(const UABUtilityComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UABUtilityComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UABUtilityComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UABUtilityComponent) \
	NO_API virtual ~UABUtilityComponent();


#define FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h_28_PROLOG
#define FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h_31_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h_31_CALLBACK_WRAPPERS \
	FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h_31_INCLASS_NO_PURE_DECLS \
	FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h_31_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UABUtilityComponent;

// ********** End Class UABUtilityComponent ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h

// ********** Begin Enum EABUtilityComponentPauseActionLogic ***************************************
#define FOREACH_ENUM_EABUTILITYCOMPONENTPAUSEACTIONLOGIC(op) \
	op(EABUtilityComponentPauseActionLogic::PauseAction) \
	op(EABUtilityComponentPauseActionLogic::AbortAction) 

enum class EABUtilityComponentPauseActionLogic : uint8;
template<> struct TIsUEnumClass<EABUtilityComponentPauseActionLogic> { enum { Value = true }; };
template<> AXELABROCKETTUTILITYAIBASE_API UEnum* StaticEnum<EABUtilityComponentPauseActionLogic>();
// ********** End Enum EABUtilityComponentPauseActionLogic *****************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
