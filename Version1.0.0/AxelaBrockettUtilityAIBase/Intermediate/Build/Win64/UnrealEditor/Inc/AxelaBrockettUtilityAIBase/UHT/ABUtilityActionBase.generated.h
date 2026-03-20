// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Actions/Actions/ABUtilityActionBase.h"

#ifdef AXELABROCKETTUTILITYAIBASE_ABUtilityActionBase_generated_h
#error "ABUtilityActionBase.generated.h already included, missing '#pragma once' in ABUtilityActionBase.h"
#endif
#define AXELABROCKETTUTILITYAIBASE_ABUtilityActionBase_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UABUtilityActionBase;
class UABUtilityRequirementBase;

// ********** Begin ScriptStruct FABUtilityActionTickFunction **************************************
#define FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_ABUtilityActionBase_h_35_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FABUtilityActionTickFunction_Statics; \
	AXELABROCKETTUTILITYAIBASE_API static class UScriptStruct* StaticStruct(); \
	typedef FTickFunction Super;


struct FABUtilityActionTickFunction;
// ********** End ScriptStruct FABUtilityActionTickFunction ****************************************

// ********** Begin Delegate FOnActionCompletedDelegate ********************************************
#define FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_ABUtilityActionBase_h_61_DELEGATE \
AXELABROCKETTUTILITYAIBASE_API void FOnActionCompletedDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnActionCompletedDelegate, UABUtilityActionBase* Action);


// ********** End Delegate FOnActionCompletedDelegate **********************************************

// ********** Begin Delegate FOnAsyncRequirementsChecked *******************************************
#define FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_ABUtilityActionBase_h_62_DELEGATE \
AXELABROCKETTUTILITYAIBASE_API void FOnAsyncRequirementsChecked_DelegateWrapper(const FMulticastScriptDelegate& OnAsyncRequirementsChecked, UABUtilityActionBase* Action, bool bRequirementsPassed);


// ********** End Delegate FOnAsyncRequirementsChecked *********************************************

// ********** Begin Class UABUtilityActionBase *****************************************************
#define FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_ABUtilityActionBase_h_72_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnAsyncRequirementChecked);


AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionBase_NoRegister();

#define FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_ABUtilityActionBase_h_72_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUABUtilityActionBase(); \
	friend struct Z_Construct_UClass_UABUtilityActionBase_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionBase_NoRegister(); \
public: \
	DECLARE_CLASS2(UABUtilityActionBase, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/AxelaBrockettUtilityAIBase"), Z_Construct_UClass_UABUtilityActionBase_NoRegister) \
	DECLARE_SERIALIZER(UABUtilityActionBase)


#define FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_ABUtilityActionBase_h_72_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UABUtilityActionBase(UABUtilityActionBase&&) = delete; \
	UABUtilityActionBase(const UABUtilityActionBase&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UABUtilityActionBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UABUtilityActionBase); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(UABUtilityActionBase) \
	NO_API virtual ~UABUtilityActionBase();


#define FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_ABUtilityActionBase_h_69_PROLOG
#define FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_ABUtilityActionBase_h_72_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_ABUtilityActionBase_h_72_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_ABUtilityActionBase_h_72_INCLASS_NO_PURE_DECLS \
	FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_ABUtilityActionBase_h_72_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UABUtilityActionBase;

// ********** End Class UABUtilityActionBase *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_ABUtilityActionBase_h

// ********** Begin Enum EABFactorScoreTotallingMethod *********************************************
#define FOREACH_ENUM_EABFACTORSCORETOTALLINGMETHOD(op) \
	op(EABFactorScoreTotallingMethod::Sum) \
	op(EABFactorScoreTotallingMethod::Multiply) \
	op(EABFactorScoreTotallingMethod::Average) \
	op(EABFactorScoreTotallingMethod::Min) \
	op(EABFactorScoreTotallingMethod::Max) 

enum class EABFactorScoreTotallingMethod : uint8;
template<> struct TIsUEnumClass<EABFactorScoreTotallingMethod> { enum { Value = true }; };
template<> AXELABROCKETTUTILITYAIBASE_API UEnum* StaticEnum<EABFactorScoreTotallingMethod>();
// ********** End Enum EABFactorScoreTotallingMethod ***********************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
