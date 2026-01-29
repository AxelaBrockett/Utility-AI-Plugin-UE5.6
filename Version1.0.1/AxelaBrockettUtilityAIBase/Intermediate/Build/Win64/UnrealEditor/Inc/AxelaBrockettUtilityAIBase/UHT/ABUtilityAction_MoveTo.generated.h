// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Actions/Actions/Examples/ABUtilityAction_MoveTo.h"

#ifdef AXELABROCKETTUTILITYAIBASE_ABUtilityAction_MoveTo_generated_h
#error "ABUtilityAction_MoveTo.generated.h already included, missing '#pragma once' in ABUtilityAction_MoveTo.h"
#endif
#define AXELABROCKETTUTILITYAIBASE_ABUtilityAction_MoveTo_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UABUtilityAction_MoveTo **************************************************
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityAction_MoveTo_NoRegister();

#define FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_MoveTo_h_64_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUABUtilityAction_MoveTo(); \
	friend struct Z_Construct_UClass_UABUtilityAction_MoveTo_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityAction_MoveTo_NoRegister(); \
public: \
	DECLARE_CLASS2(UABUtilityAction_MoveTo, UABUtilityActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AxelaBrockettUtilityAIBase"), Z_Construct_UClass_UABUtilityAction_MoveTo_NoRegister) \
	DECLARE_SERIALIZER(UABUtilityAction_MoveTo)


#define FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_MoveTo_h_64_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UABUtilityAction_MoveTo(UABUtilityAction_MoveTo&&) = delete; \
	UABUtilityAction_MoveTo(const UABUtilityAction_MoveTo&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UABUtilityAction_MoveTo); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UABUtilityAction_MoveTo); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UABUtilityAction_MoveTo) \
	NO_API virtual ~UABUtilityAction_MoveTo();


#define FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_MoveTo_h_61_PROLOG
#define FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_MoveTo_h_64_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_MoveTo_h_64_INCLASS_NO_PURE_DECLS \
	FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_MoveTo_h_64_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UABUtilityAction_MoveTo;

// ********** End Class UABUtilityAction_MoveTo ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_MoveTo_h

// ********** Begin Enum EABUtilityAction_MoveToTypes **********************************************
#define FOREACH_ENUM_EABUTILITYACTION_MOVETOTYPES(op) \
	op(EABUtilityAction_MoveToTypes::EQSGeneratedPoint) \
	op(EABUtilityAction_MoveToTypes::EQSGeneratedActor) \
	op(EABUtilityAction_MoveToTypes::ActorOfType) 

enum class EABUtilityAction_MoveToTypes;
template<> struct TIsUEnumClass<EABUtilityAction_MoveToTypes> { enum { Value = true }; };
template<> AXELABROCKETTUTILITYAIBASE_API UEnum* StaticEnum<EABUtilityAction_MoveToTypes>();
// ********** End Enum EABUtilityAction_MoveToTypes ************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
