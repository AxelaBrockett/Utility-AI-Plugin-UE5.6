// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Actions/Requirements/ABUtilityRequirementBase.h"

#ifdef AXELABROCKETTUTILITYAIBASE_ABUtilityRequirementBase_generated_h
#error "ABUtilityRequirementBase.generated.h already included, missing '#pragma once' in ABUtilityRequirementBase.h"
#endif
#define AXELABROCKETTUTILITYAIBASE_ABUtilityRequirementBase_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UABUtilityRequirementBase;

// ********** Begin Delegate FOnAsyncRequirementChecked ********************************************
#define FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_ABUtilityRequirementBase_h_14_DELEGATE \
AXELABROCKETTUTILITYAIBASE_API void FOnAsyncRequirementChecked_DelegateWrapper(const FMulticastScriptDelegate& OnAsyncRequirementChecked, const UABUtilityRequirementBase* Requirement, bool bRequirementPassed);


// ********** End Delegate FOnAsyncRequirementChecked **********************************************

// ********** Begin Class UABUtilityRequirementBase ************************************************
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityRequirementBase_NoRegister();

#define FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_ABUtilityRequirementBase_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUABUtilityRequirementBase(); \
	friend struct Z_Construct_UClass_UABUtilityRequirementBase_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityRequirementBase_NoRegister(); \
public: \
	DECLARE_CLASS2(UABUtilityRequirementBase, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/AxelaBrockettUtilityAIBase"), Z_Construct_UClass_UABUtilityRequirementBase_NoRegister) \
	DECLARE_SERIALIZER(UABUtilityRequirementBase)


#define FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_ABUtilityRequirementBase_h_22_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UABUtilityRequirementBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UABUtilityRequirementBase(UABUtilityRequirementBase&&) = delete; \
	UABUtilityRequirementBase(const UABUtilityRequirementBase&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UABUtilityRequirementBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UABUtilityRequirementBase); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UABUtilityRequirementBase) \
	NO_API virtual ~UABUtilityRequirementBase();


#define FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_ABUtilityRequirementBase_h_19_PROLOG
#define FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_ABUtilityRequirementBase_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_ABUtilityRequirementBase_h_22_INCLASS_NO_PURE_DECLS \
	FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_ABUtilityRequirementBase_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UABUtilityRequirementBase;

// ********** End Class UABUtilityRequirementBase **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_ABUtilityRequirementBase_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
