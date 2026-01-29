// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/Actions/ABUtilityActionBase.h"
#include "DataProviders/AIDataProvider.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeABUtilityActionBase() {}

// ********** Begin Cross Module References ********************************************************
AIMODULE_API UScriptStruct* Z_Construct_UScriptStruct_FAIDataProviderFloatValue();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionBase();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionBase_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityFactorBase_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityRequirementBase_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABFactorScoreTotallingMethod();
AXELABROCKETTUTILITYAIBASE_API UFunction* Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnActionCompletedDelegate__DelegateSignature();
AXELABROCKETTUTILITYAIBASE_API UFunction* Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementsChecked__DelegateSignature();
AXELABROCKETTUTILITYAIBASE_API UScriptStruct* Z_Construct_UScriptStruct_FABUtilityActionTickFunction();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
ENGINE_API UClass* Z_Construct_UClass_UWorld_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTickFunction();
UPackage* Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EABFactorScoreTotallingMethod *********************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EABFactorScoreTotallingMethod;
static UEnum* EABFactorScoreTotallingMethod_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EABFactorScoreTotallingMethod.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EABFactorScoreTotallingMethod.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABFactorScoreTotallingMethod, (UObject*)Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase(), TEXT("EABFactorScoreTotallingMethod"));
	}
	return Z_Registration_Info_UEnum_EABFactorScoreTotallingMethod.OuterSingleton;
}
template<> AXELABROCKETTUTILITYAIBASE_API UEnum* StaticEnum<EABFactorScoreTotallingMethod>()
{
	return EABFactorScoreTotallingMethod_StaticEnum();
}
struct Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABFactorScoreTotallingMethod_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Average.Name", "EABFactorScoreTotallingMethod::Average" },
		{ "Comment", "// The method used for totalling the scores of the actions factors\n" },
		{ "Max.Name", "EABFactorScoreTotallingMethod::Max" },
		{ "Min.Name", "EABFactorScoreTotallingMethod::Min" },
		{ "ModuleRelativePath", "Public/Actions/Actions/ABUtilityActionBase.h" },
		{ "Multiply.Name", "EABFactorScoreTotallingMethod::Multiply" },
		{ "Sum.Name", "EABFactorScoreTotallingMethod::Sum" },
		{ "ToolTip", "The method used for totalling the scores of the actions factors" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EABFactorScoreTotallingMethod::Sum", (int64)EABFactorScoreTotallingMethod::Sum },
		{ "EABFactorScoreTotallingMethod::Multiply", (int64)EABFactorScoreTotallingMethod::Multiply },
		{ "EABFactorScoreTotallingMethod::Average", (int64)EABFactorScoreTotallingMethod::Average },
		{ "EABFactorScoreTotallingMethod::Min", (int64)EABFactorScoreTotallingMethod::Min },
		{ "EABFactorScoreTotallingMethod::Max", (int64)EABFactorScoreTotallingMethod::Max },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABFactorScoreTotallingMethod_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
	nullptr,
	"EABFactorScoreTotallingMethod",
	"EABFactorScoreTotallingMethod",
	Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABFactorScoreTotallingMethod_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABFactorScoreTotallingMethod_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABFactorScoreTotallingMethod_Statics::Enum_MetaDataParams), Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABFactorScoreTotallingMethod_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABFactorScoreTotallingMethod()
{
	if (!Z_Registration_Info_UEnum_EABFactorScoreTotallingMethod.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EABFactorScoreTotallingMethod.InnerSingleton, Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABFactorScoreTotallingMethod_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EABFactorScoreTotallingMethod.InnerSingleton;
}
// ********** End Enum EABFactorScoreTotallingMethod ***********************************************

// ********** Begin ScriptStruct FABUtilityActionTickFunction **************************************
static_assert(std::is_polymorphic<FABUtilityActionTickFunction>() == std::is_polymorphic<FTickFunction>(), "USTRUCT FABUtilityActionTickFunction cannot be polymorphic unless super FTickFunction is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FABUtilityActionTickFunction;
class UScriptStruct* FABUtilityActionTickFunction::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FABUtilityActionTickFunction.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FABUtilityActionTickFunction.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FABUtilityActionTickFunction, (UObject*)Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase(), TEXT("ABUtilityActionTickFunction"));
	}
	return Z_Registration_Info_UScriptStruct_FABUtilityActionTickFunction.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FABUtilityActionTickFunction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "Comment", "// Tick function for the utility action\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/ABUtilityActionBase.h" },
		{ "ToolTip", "Tick function for the utility action" },
	};
#endif // WITH_METADATA
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FABUtilityActionTickFunction>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FABUtilityActionTickFunction_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
	Z_Construct_UScriptStruct_FTickFunction,
	&NewStructOps,
	"ABUtilityActionTickFunction",
	nullptr,
	0,
	sizeof(FABUtilityActionTickFunction),
	alignof(FABUtilityActionTickFunction),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FABUtilityActionTickFunction_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FABUtilityActionTickFunction_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FABUtilityActionTickFunction()
{
	if (!Z_Registration_Info_UScriptStruct_FABUtilityActionTickFunction.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FABUtilityActionTickFunction.InnerSingleton, Z_Construct_UScriptStruct_FABUtilityActionTickFunction_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FABUtilityActionTickFunction.InnerSingleton;
}
// ********** End ScriptStruct FABUtilityActionTickFunction ****************************************

// ********** Begin Delegate FOnActionCompletedDelegate ********************************************
struct Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnActionCompletedDelegate__DelegateSignature_Statics
{
	struct _Script_AxelaBrockettUtilityAIBase_eventOnActionCompletedDelegate_Parms
	{
		UABUtilityActionBase* Action;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Actions/Actions/ABUtilityActionBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Action;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnActionCompletedDelegate__DelegateSignature_Statics::NewProp_Action = { "Action", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_AxelaBrockettUtilityAIBase_eventOnActionCompletedDelegate_Parms, Action), Z_Construct_UClass_UABUtilityActionBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnActionCompletedDelegate__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnActionCompletedDelegate__DelegateSignature_Statics::NewProp_Action,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnActionCompletedDelegate__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnActionCompletedDelegate__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase, nullptr, "OnActionCompletedDelegate__DelegateSignature", Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnActionCompletedDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnActionCompletedDelegate__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnActionCompletedDelegate__DelegateSignature_Statics::_Script_AxelaBrockettUtilityAIBase_eventOnActionCompletedDelegate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnActionCompletedDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnActionCompletedDelegate__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnActionCompletedDelegate__DelegateSignature_Statics::_Script_AxelaBrockettUtilityAIBase_eventOnActionCompletedDelegate_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnActionCompletedDelegate__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnActionCompletedDelegate__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnActionCompletedDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnActionCompletedDelegate, UABUtilityActionBase* Action)
{
	struct _Script_AxelaBrockettUtilityAIBase_eventOnActionCompletedDelegate_Parms
	{
		UABUtilityActionBase* Action;
	};
	_Script_AxelaBrockettUtilityAIBase_eventOnActionCompletedDelegate_Parms Parms;
	Parms.Action=Action;
	OnActionCompletedDelegate.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnActionCompletedDelegate **********************************************

// ********** Begin Delegate FOnAsyncRequirementsChecked *******************************************
struct Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementsChecked__DelegateSignature_Statics
{
	struct _Script_AxelaBrockettUtilityAIBase_eventOnAsyncRequirementsChecked_Parms
	{
		UABUtilityActionBase* Action;
		bool bRequirementsPassed;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Actions/Actions/ABUtilityActionBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRequirementsPassed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Action;
	static void NewProp_bRequirementsPassed_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRequirementsPassed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementsChecked__DelegateSignature_Statics::NewProp_Action = { "Action", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_AxelaBrockettUtilityAIBase_eventOnAsyncRequirementsChecked_Parms, Action), Z_Construct_UClass_UABUtilityActionBase_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementsChecked__DelegateSignature_Statics::NewProp_bRequirementsPassed_SetBit(void* Obj)
{
	((_Script_AxelaBrockettUtilityAIBase_eventOnAsyncRequirementsChecked_Parms*)Obj)->bRequirementsPassed = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementsChecked__DelegateSignature_Statics::NewProp_bRequirementsPassed = { "bRequirementsPassed", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_AxelaBrockettUtilityAIBase_eventOnAsyncRequirementsChecked_Parms), &Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementsChecked__DelegateSignature_Statics::NewProp_bRequirementsPassed_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRequirementsPassed_MetaData), NewProp_bRequirementsPassed_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementsChecked__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementsChecked__DelegateSignature_Statics::NewProp_Action,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementsChecked__DelegateSignature_Statics::NewProp_bRequirementsPassed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementsChecked__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementsChecked__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase, nullptr, "OnAsyncRequirementsChecked__DelegateSignature", Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementsChecked__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementsChecked__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementsChecked__DelegateSignature_Statics::_Script_AxelaBrockettUtilityAIBase_eventOnAsyncRequirementsChecked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementsChecked__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementsChecked__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementsChecked__DelegateSignature_Statics::_Script_AxelaBrockettUtilityAIBase_eventOnAsyncRequirementsChecked_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementsChecked__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementsChecked__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnAsyncRequirementsChecked_DelegateWrapper(const FMulticastScriptDelegate& OnAsyncRequirementsChecked, UABUtilityActionBase* Action, bool bRequirementsPassed)
{
	struct _Script_AxelaBrockettUtilityAIBase_eventOnAsyncRequirementsChecked_Parms
	{
		UABUtilityActionBase* Action;
		bool bRequirementsPassed;
	};
	_Script_AxelaBrockettUtilityAIBase_eventOnAsyncRequirementsChecked_Parms Parms;
	Parms.Action=Action;
	Parms.bRequirementsPassed=bRequirementsPassed ? true : false;
	OnAsyncRequirementsChecked.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnAsyncRequirementsChecked *********************************************

// ********** Begin Class UABUtilityActionBase Function OnAsyncRequirementChecked ******************
struct Z_Construct_UFunction_UABUtilityActionBase_OnAsyncRequirementChecked_Statics
{
	struct ABUtilityActionBase_eventOnAsyncRequirementChecked_Parms
	{
		const UABUtilityRequirementBase* Requirement;
		bool bRequirementPassed;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Actions/Actions/ABUtilityActionBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Requirement_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRequirementPassed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Requirement;
	static void NewProp_bRequirementPassed_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRequirementPassed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UABUtilityActionBase_OnAsyncRequirementChecked_Statics::NewProp_Requirement = { "Requirement", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityActionBase_eventOnAsyncRequirementChecked_Parms, Requirement), Z_Construct_UClass_UABUtilityRequirementBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Requirement_MetaData), NewProp_Requirement_MetaData) };
void Z_Construct_UFunction_UABUtilityActionBase_OnAsyncRequirementChecked_Statics::NewProp_bRequirementPassed_SetBit(void* Obj)
{
	((ABUtilityActionBase_eventOnAsyncRequirementChecked_Parms*)Obj)->bRequirementPassed = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UABUtilityActionBase_OnAsyncRequirementChecked_Statics::NewProp_bRequirementPassed = { "bRequirementPassed", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ABUtilityActionBase_eventOnAsyncRequirementChecked_Parms), &Z_Construct_UFunction_UABUtilityActionBase_OnAsyncRequirementChecked_Statics::NewProp_bRequirementPassed_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRequirementPassed_MetaData), NewProp_bRequirementPassed_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityActionBase_OnAsyncRequirementChecked_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityActionBase_OnAsyncRequirementChecked_Statics::NewProp_Requirement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityActionBase_OnAsyncRequirementChecked_Statics::NewProp_bRequirementPassed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityActionBase_OnAsyncRequirementChecked_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityActionBase_OnAsyncRequirementChecked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityActionBase, nullptr, "OnAsyncRequirementChecked", Z_Construct_UFunction_UABUtilityActionBase_OnAsyncRequirementChecked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityActionBase_OnAsyncRequirementChecked_Statics::PropPointers), sizeof(Z_Construct_UFunction_UABUtilityActionBase_OnAsyncRequirementChecked_Statics::ABUtilityActionBase_eventOnAsyncRequirementChecked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityActionBase_OnAsyncRequirementChecked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityActionBase_OnAsyncRequirementChecked_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UABUtilityActionBase_OnAsyncRequirementChecked_Statics::ABUtilityActionBase_eventOnAsyncRequirementChecked_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityActionBase_OnAsyncRequirementChecked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityActionBase_OnAsyncRequirementChecked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityActionBase::execOnAsyncRequirementChecked)
{
	P_GET_OBJECT(UABUtilityRequirementBase,Z_Param_Requirement);
	P_GET_UBOOL(Z_Param_bRequirementPassed);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnAsyncRequirementChecked(Z_Param_Requirement,Z_Param_bRequirementPassed);
	P_NATIVE_END;
}
// ********** End Class UABUtilityActionBase Function OnAsyncRequirementChecked ********************

// ********** Begin Class UABUtilityActionBase *****************************************************
void UABUtilityActionBase::StaticRegisterNativesUABUtilityActionBase()
{
	UClass* Class = UABUtilityActionBase::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnAsyncRequirementChecked", &UABUtilityActionBase::execOnAsyncRequirementChecked },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilityActionBase;
UClass* UABUtilityActionBase::GetPrivateStaticClass()
{
	using TClass = UABUtilityActionBase;
	if (!Z_Registration_Info_UClass_UABUtilityActionBase.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilityActionBase"),
			Z_Registration_Info_UClass_UABUtilityActionBase.InnerSingleton,
			StaticRegisterNativesUABUtilityActionBase,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UABUtilityActionBase.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilityActionBase_NoRegister()
{
	return UABUtilityActionBase::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilityActionBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Utility AI action\n * Contains Requirements that determine whether the action can run\n * Contains factors that determine the score of the action\n */" },
		{ "IncludePath", "Actions/Actions/ABUtilityActionBase.h" },
		{ "ModuleRelativePath", "Public/Actions/Actions/ABUtilityActionBase.h" },
		{ "ToolTip", "Utility AI action\nContains Requirements that determine whether the action can run\nContains factors that determine the score of the action" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PrimaryUtilityActionTick_MetaData[] = {
		{ "Category", "Tick" },
		{ "Comment", "// Tick function\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/ABUtilityActionBase.h" },
		{ "ToolTip", "Tick function" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShouldTickIfViewportsOnly_MetaData[] = {
		{ "Category", "Utility AI Action Base" },
		{ "Comment", "// If true, action is ticked even if TickType == LEVELTICK_ViewportsOnly\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/ABUtilityActionBase.h" },
		{ "ToolTip", "If true, action is ticked even if TickType == LEVELTICK_ViewportsOnly" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedWorld_MetaData[] = {
		{ "Comment", "// Cached instance of the world\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/ABUtilityActionBase.h" },
		{ "ToolTip", "Cached instance of the world" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UtilityWeight_MetaData[] = {
		{ "Category", "Utility AI Action Base" },
		{ "ClampMin", "0.000000" },
		{ "Comment", "// Weight multiplier that gets multiplied in at the end of scoring all factors\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/ABUtilityActionBase.h" },
		{ "ToolTip", "Weight multiplier that gets multiplied in at the end of scoring all factors" },
		{ "UIMin", "0.000000" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSuccessCooldown_MetaData[] = {
		{ "Category", "Utility AI Action Base" },
		{ "ClampMin", "0.000000" },
		{ "Comment", "// Cooldown time after the action has been successful\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/ABUtilityActionBase.h" },
		{ "ToolTip", "Cooldown time after the action has been successful" },
		{ "UIMin", "0.000000" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScoreAggregationMethod_MetaData[] = {
		{ "Category", "Utility AI Action Base" },
		{ "Comment", "// Method for working out the total score\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/ABUtilityActionBase.h" },
		{ "ToolTip", "Method for working out the total score" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Requirements_Inner_MetaData[] = {
		{ "Category", "Utility AI Action Base" },
		{ "Comment", "// The list of requirements for the action to be possible, will run through an AND operator\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actions/Actions/ABUtilityActionBase.h" },
		{ "ToolTip", "The list of requirements for the action to be possible, will run through an AND operator" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Requirements_MetaData[] = {
		{ "Category", "Utility AI Action Base" },
		{ "Comment", "// The list of requirements for the action to be possible, will run through an AND operator\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actions/Actions/ABUtilityActionBase.h" },
		{ "ToolTip", "The list of requirements for the action to be possible, will run through an AND operator" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Factors_Inner_MetaData[] = {
		{ "Category", "Utility AI Action Base" },
		{ "Comment", "// The list of factors affecting the utility score of the action\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actions/Actions/ABUtilityActionBase.h" },
		{ "ToolTip", "The list of factors affecting the utility score of the action" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Factors_MetaData[] = {
		{ "Category", "Utility AI Action Base" },
		{ "Comment", "// The list of factors affecting the utility score of the action\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actions/Actions/ABUtilityActionBase.h" },
		{ "ToolTip", "The list of factors affecting the utility score of the action" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseParallelRequirementChecking_MetaData[] = {
		{ "Category", "Utility AI Action Base" },
		{ "Comment", "// Use ParallelFor to check action requirements\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/ABUtilityActionBase.h" },
		{ "ToolTip", "Use ParallelFor to check action requirements" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bConsiderFactorScoreZero_MetaData[] = {
		{ "Category", "Utility AI Action Base" },
		{ "Comment", "// Consider a factors score even if it's 0\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/ABUtilityActionBase.h" },
		{ "ToolTip", "Consider a factors score even if it's 0" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_PrimaryUtilityActionTick;
	static void NewProp_bShouldTickIfViewportsOnly_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShouldTickIfViewportsOnly;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CachedWorld;
	static const UECodeGen_Private::FStructPropertyParams NewProp_UtilityWeight;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OnSuccessCooldown;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ScoreAggregationMethod_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ScoreAggregationMethod;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Requirements_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Requirements;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Factors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Factors;
	static void NewProp_bUseParallelRequirementChecking_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseParallelRequirementChecking;
	static void NewProp_bConsiderFactorScoreZero_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bConsiderFactorScoreZero;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UABUtilityActionBase_OnAsyncRequirementChecked, "OnAsyncRequirementChecked" }, // 413416270
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilityActionBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_PrimaryUtilityActionTick = { "PrimaryUtilityActionTick", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityActionBase, PrimaryUtilityActionTick), Z_Construct_UScriptStruct_FABUtilityActionTickFunction, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PrimaryUtilityActionTick_MetaData), NewProp_PrimaryUtilityActionTick_MetaData) }; // 3980420712
void Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_bShouldTickIfViewportsOnly_SetBit(void* Obj)
{
	((UABUtilityActionBase*)Obj)->bShouldTickIfViewportsOnly = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_bShouldTickIfViewportsOnly = { "bShouldTickIfViewportsOnly", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UABUtilityActionBase), &Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_bShouldTickIfViewportsOnly_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShouldTickIfViewportsOnly_MetaData), NewProp_bShouldTickIfViewportsOnly_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_CachedWorld = { "CachedWorld", nullptr, (EPropertyFlags)0x0124080000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityActionBase, CachedWorld), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedWorld_MetaData), NewProp_CachedWorld_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_UtilityWeight = { "UtilityWeight", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityActionBase, UtilityWeight), Z_Construct_UScriptStruct_FAIDataProviderFloatValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UtilityWeight_MetaData), NewProp_UtilityWeight_MetaData) }; // 2793119070
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_OnSuccessCooldown = { "OnSuccessCooldown", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityActionBase, OnSuccessCooldown), Z_Construct_UScriptStruct_FAIDataProviderFloatValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSuccessCooldown_MetaData), NewProp_OnSuccessCooldown_MetaData) }; // 2793119070
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_ScoreAggregationMethod_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_ScoreAggregationMethod = { "ScoreAggregationMethod", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityActionBase, ScoreAggregationMethod), Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABFactorScoreTotallingMethod, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScoreAggregationMethod_MetaData), NewProp_ScoreAggregationMethod_MetaData) }; // 3505111290
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_Requirements_Inner = { "Requirements", nullptr, (EPropertyFlags)0x0106000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UABUtilityRequirementBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Requirements_Inner_MetaData), NewProp_Requirements_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_Requirements = { "Requirements", nullptr, (EPropertyFlags)0x0144008000000009, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityActionBase, Requirements), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Requirements_MetaData), NewProp_Requirements_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_Factors_Inner = { "Factors", nullptr, (EPropertyFlags)0x0106000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UABUtilityFactorBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Factors_Inner_MetaData), NewProp_Factors_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_Factors = { "Factors", nullptr, (EPropertyFlags)0x0144008000000009, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityActionBase, Factors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Factors_MetaData), NewProp_Factors_MetaData) };
void Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_bUseParallelRequirementChecking_SetBit(void* Obj)
{
	((UABUtilityActionBase*)Obj)->bUseParallelRequirementChecking = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_bUseParallelRequirementChecking = { "bUseParallelRequirementChecking", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(uint8), sizeof(UABUtilityActionBase), &Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_bUseParallelRequirementChecking_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseParallelRequirementChecking_MetaData), NewProp_bUseParallelRequirementChecking_MetaData) };
void Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_bConsiderFactorScoreZero_SetBit(void* Obj)
{
	((UABUtilityActionBase*)Obj)->bConsiderFactorScoreZero = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_bConsiderFactorScoreZero = { "bConsiderFactorScoreZero", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(uint8), sizeof(UABUtilityActionBase), &Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_bConsiderFactorScoreZero_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bConsiderFactorScoreZero_MetaData), NewProp_bConsiderFactorScoreZero_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABUtilityActionBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_PrimaryUtilityActionTick,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_bShouldTickIfViewportsOnly,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_CachedWorld,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_UtilityWeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_OnSuccessCooldown,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_ScoreAggregationMethod_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_ScoreAggregationMethod,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_Requirements_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_Requirements,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_Factors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_Factors,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_bUseParallelRequirementChecking,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityActionBase_Statics::NewProp_bConsiderFactorScoreZero,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityActionBase_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UABUtilityActionBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityActionBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilityActionBase_Statics::ClassParams = {
	&UABUtilityActionBase::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UABUtilityActionBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityActionBase_Statics::PropPointers),
	0,
	0x009010A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityActionBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilityActionBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilityActionBase()
{
	if (!Z_Registration_Info_UClass_UABUtilityActionBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilityActionBase.OuterSingleton, Z_Construct_UClass_UABUtilityActionBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilityActionBase.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilityActionBase);
UABUtilityActionBase::~UABUtilityActionBase() {}
// ********** End Class UABUtilityActionBase *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_ABUtilityActionBase_h__Script_AxelaBrockettUtilityAIBase_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EABFactorScoreTotallingMethod_StaticEnum, TEXT("EABFactorScoreTotallingMethod"), &Z_Registration_Info_UEnum_EABFactorScoreTotallingMethod, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3505111290U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FABUtilityActionTickFunction::StaticStruct, Z_Construct_UScriptStruct_FABUtilityActionTickFunction_Statics::NewStructOps, TEXT("ABUtilityActionTickFunction"), &Z_Registration_Info_UScriptStruct_FABUtilityActionTickFunction, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FABUtilityActionTickFunction), 3980420712U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UABUtilityActionBase, UABUtilityActionBase::StaticClass, TEXT("UABUtilityActionBase"), &Z_Registration_Info_UClass_UABUtilityActionBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilityActionBase), 1022464538U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_ABUtilityActionBase_h__Script_AxelaBrockettUtilityAIBase_2366480926(TEXT("/Script/AxelaBrockettUtilityAIBase"),
	Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_ABUtilityActionBase_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_ABUtilityActionBase_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_ABUtilityActionBase_h__Script_AxelaBrockettUtilityAIBase_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_ABUtilityActionBase_h__Script_AxelaBrockettUtilityAIBase_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_ABUtilityActionBase_h__Script_AxelaBrockettUtilityAIBase_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_ABUtilityActionBase_h__Script_AxelaBrockettUtilityAIBase_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
