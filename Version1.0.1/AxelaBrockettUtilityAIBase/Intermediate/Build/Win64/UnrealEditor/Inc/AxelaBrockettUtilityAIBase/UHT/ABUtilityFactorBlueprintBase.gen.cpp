// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/Factors/ABUtilityFactorBlueprintBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeABUtilityFactorBlueprintBase() {}

// ********** Begin Cross Module References ********************************************************
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityComponent_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityFactorBase();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityFactorBlueprintBase();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityFactorBlueprintBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UABUtilityFactorBlueprintBase Function CalculateBlueprintFactorScore *****
struct ABUtilityFactorBlueprintBase_eventCalculateBlueprintFactorScore_Parms
{
	const UABUtilityComponent* OwnerComp;
	float ReturnValue;

	/** Constructor, initializes return property only **/
	ABUtilityFactorBlueprintBase_eventCalculateBlueprintFactorScore_Parms()
		: ReturnValue(0)
	{
	}
};
static FName NAME_UABUtilityFactorBlueprintBase_CalculateBlueprintFactorScore = FName(TEXT("CalculateBlueprintFactorScore"));
const float UABUtilityFactorBlueprintBase::CalculateBlueprintFactorScore(const UABUtilityComponent* OwnerComp) const
{
	UFunction* Func = FindFunctionChecked(NAME_UABUtilityFactorBlueprintBase_CalculateBlueprintFactorScore);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		ABUtilityFactorBlueprintBase_eventCalculateBlueprintFactorScore_Parms Parms;
		Parms.OwnerComp=OwnerComp;
		const_cast<UABUtilityFactorBlueprintBase*>(this)->ProcessEvent(Func,&Parms);
		return Parms.ReturnValue;
	}
	else
	{
		return const_cast<UABUtilityFactorBlueprintBase*>(this)->CalculateBlueprintFactorScore_Implementation(OwnerComp);
	}
}
struct Z_Construct_UFunction_UABUtilityFactorBlueprintBase_CalculateBlueprintFactorScore_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Actions/Factors/ABUtilityFactorBlueprintBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OwnerComp_MetaData[] = {
		{ "EditInline", "true" },
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OwnerComp;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UABUtilityFactorBlueprintBase_CalculateBlueprintFactorScore_Statics::NewProp_OwnerComp = { "OwnerComp", nullptr, (EPropertyFlags)0x0010000000080082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityFactorBlueprintBase_eventCalculateBlueprintFactorScore_Parms, OwnerComp), Z_Construct_UClass_UABUtilityComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OwnerComp_MetaData), NewProp_OwnerComp_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UABUtilityFactorBlueprintBase_CalculateBlueprintFactorScore_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000582, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityFactorBlueprintBase_eventCalculateBlueprintFactorScore_Parms, ReturnValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityFactorBlueprintBase_CalculateBlueprintFactorScore_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityFactorBlueprintBase_CalculateBlueprintFactorScore_Statics::NewProp_OwnerComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityFactorBlueprintBase_CalculateBlueprintFactorScore_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityFactorBlueprintBase_CalculateBlueprintFactorScore_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityFactorBlueprintBase_CalculateBlueprintFactorScore_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityFactorBlueprintBase, nullptr, "CalculateBlueprintFactorScore", Z_Construct_UFunction_UABUtilityFactorBlueprintBase_CalculateBlueprintFactorScore_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityFactorBlueprintBase_CalculateBlueprintFactorScore_Statics::PropPointers), sizeof(ABUtilityFactorBlueprintBase_eventCalculateBlueprintFactorScore_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityFactorBlueprintBase_CalculateBlueprintFactorScore_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityFactorBlueprintBase_CalculateBlueprintFactorScore_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ABUtilityFactorBlueprintBase_eventCalculateBlueprintFactorScore_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityFactorBlueprintBase_CalculateBlueprintFactorScore()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityFactorBlueprintBase_CalculateBlueprintFactorScore_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityFactorBlueprintBase::execCalculateBlueprintFactorScore)
{
	P_GET_OBJECT(UABUtilityComponent,Z_Param_OwnerComp);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->CalculateBlueprintFactorScore_Implementation(Z_Param_OwnerComp);
	P_NATIVE_END;
}
// ********** End Class UABUtilityFactorBlueprintBase Function CalculateBlueprintFactorScore *******

// ********** Begin Class UABUtilityFactorBlueprintBase Function DescribeBlueprintSelfToGameplayDebugger 
struct ABUtilityFactorBlueprintBase_eventDescribeBlueprintSelfToGameplayDebugger_Parms
{
	const UABUtilityComponent* OwnerComp;
	float NumberOfFactors;
	FString ReturnValue;
};
static FName NAME_UABUtilityFactorBlueprintBase_DescribeBlueprintSelfToGameplayDebugger = FName(TEXT("DescribeBlueprintSelfToGameplayDebugger"));
const FString UABUtilityFactorBlueprintBase::DescribeBlueprintSelfToGameplayDebugger(const UABUtilityComponent* OwnerComp, const float NumberOfFactors) const
{
	UFunction* Func = FindFunctionChecked(NAME_UABUtilityFactorBlueprintBase_DescribeBlueprintSelfToGameplayDebugger);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		ABUtilityFactorBlueprintBase_eventDescribeBlueprintSelfToGameplayDebugger_Parms Parms;
		Parms.OwnerComp=OwnerComp;
		Parms.NumberOfFactors=NumberOfFactors;
		const_cast<UABUtilityFactorBlueprintBase*>(this)->ProcessEvent(Func,&Parms);
		return Parms.ReturnValue;
	}
	else
	{
		return const_cast<UABUtilityFactorBlueprintBase*>(this)->DescribeBlueprintSelfToGameplayDebugger_Implementation(OwnerComp, NumberOfFactors);
	}
}
struct Z_Construct_UFunction_UABUtilityFactorBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Comment", "// Return string to be added to debug\n" },
		{ "ModuleRelativePath", "Public/Actions/Factors/ABUtilityFactorBlueprintBase.h" },
		{ "ToolTip", "Return string to be added to debug" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OwnerComp_MetaData[] = {
		{ "EditInline", "true" },
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NumberOfFactors_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OwnerComp;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NumberOfFactors;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UABUtilityFactorBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::NewProp_OwnerComp = { "OwnerComp", nullptr, (EPropertyFlags)0x0010000000080082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityFactorBlueprintBase_eventDescribeBlueprintSelfToGameplayDebugger_Parms, OwnerComp), Z_Construct_UClass_UABUtilityComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OwnerComp_MetaData), NewProp_OwnerComp_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UABUtilityFactorBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::NewProp_NumberOfFactors = { "NumberOfFactors", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityFactorBlueprintBase_eventDescribeBlueprintSelfToGameplayDebugger_Parms, NumberOfFactors), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NumberOfFactors_MetaData), NewProp_NumberOfFactors_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UABUtilityFactorBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000582, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityFactorBlueprintBase_eventDescribeBlueprintSelfToGameplayDebugger_Parms, ReturnValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityFactorBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityFactorBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::NewProp_OwnerComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityFactorBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::NewProp_NumberOfFactors,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityFactorBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityFactorBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityFactorBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityFactorBlueprintBase, nullptr, "DescribeBlueprintSelfToGameplayDebugger", Z_Construct_UFunction_UABUtilityFactorBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityFactorBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::PropPointers), sizeof(ABUtilityFactorBlueprintBase_eventDescribeBlueprintSelfToGameplayDebugger_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityFactorBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityFactorBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ABUtilityFactorBlueprintBase_eventDescribeBlueprintSelfToGameplayDebugger_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityFactorBlueprintBase_DescribeBlueprintSelfToGameplayDebugger()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityFactorBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityFactorBlueprintBase::execDescribeBlueprintSelfToGameplayDebugger)
{
	P_GET_OBJECT(UABUtilityComponent,Z_Param_OwnerComp);
	P_GET_PROPERTY(FFloatProperty,Z_Param_NumberOfFactors);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->DescribeBlueprintSelfToGameplayDebugger_Implementation(Z_Param_OwnerComp,Z_Param_NumberOfFactors);
	P_NATIVE_END;
}
// ********** End Class UABUtilityFactorBlueprintBase Function DescribeBlueprintSelfToGameplayDebugger 

// ********** Begin Class UABUtilityFactorBlueprintBase Function ValidateBlueprintFactor ***********
struct ABUtilityFactorBlueprintBase_eventValidateBlueprintFactor_Parms
{
	FString InInvalidationReason;
	FString OutInvalidationReason;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	ABUtilityFactorBlueprintBase_eventValidateBlueprintFactor_Parms()
		: ReturnValue(false)
	{
	}
};
static FName NAME_UABUtilityFactorBlueprintBase_ValidateBlueprintFactor = FName(TEXT("ValidateBlueprintFactor"));
const bool UABUtilityFactorBlueprintBase::ValidateBlueprintFactor(const FString& InInvalidationReason, FString& OutInvalidationReason) const
{
	UFunction* Func = FindFunctionChecked(NAME_UABUtilityFactorBlueprintBase_ValidateBlueprintFactor);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		ABUtilityFactorBlueprintBase_eventValidateBlueprintFactor_Parms Parms;
		Parms.InInvalidationReason=InInvalidationReason;
		Parms.OutInvalidationReason=OutInvalidationReason;
		const_cast<UABUtilityFactorBlueprintBase*>(this)->ProcessEvent(Func,&Parms);
		OutInvalidationReason=Parms.OutInvalidationReason;
		return !!Parms.ReturnValue;
	}
	else
	{
		return const_cast<UABUtilityFactorBlueprintBase*>(this)->ValidateBlueprintFactor_Implementation(InInvalidationReason, OutInvalidationReason);
	}
}
struct Z_Construct_UFunction_UABUtilityFactorBlueprintBase_ValidateBlueprintFactor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Actions/Factors/ABUtilityFactorBlueprintBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InInvalidationReason_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_InInvalidationReason;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutInvalidationReason;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UABUtilityFactorBlueprintBase_ValidateBlueprintFactor_Statics::NewProp_InInvalidationReason = { "InInvalidationReason", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityFactorBlueprintBase_eventValidateBlueprintFactor_Parms, InInvalidationReason), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InInvalidationReason_MetaData), NewProp_InInvalidationReason_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UABUtilityFactorBlueprintBase_ValidateBlueprintFactor_Statics::NewProp_OutInvalidationReason = { "OutInvalidationReason", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityFactorBlueprintBase_eventValidateBlueprintFactor_Parms, OutInvalidationReason), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UABUtilityFactorBlueprintBase_ValidateBlueprintFactor_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ABUtilityFactorBlueprintBase_eventValidateBlueprintFactor_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UABUtilityFactorBlueprintBase_ValidateBlueprintFactor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000582, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ABUtilityFactorBlueprintBase_eventValidateBlueprintFactor_Parms), &Z_Construct_UFunction_UABUtilityFactorBlueprintBase_ValidateBlueprintFactor_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityFactorBlueprintBase_ValidateBlueprintFactor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityFactorBlueprintBase_ValidateBlueprintFactor_Statics::NewProp_InInvalidationReason,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityFactorBlueprintBase_ValidateBlueprintFactor_Statics::NewProp_OutInvalidationReason,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityFactorBlueprintBase_ValidateBlueprintFactor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityFactorBlueprintBase_ValidateBlueprintFactor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityFactorBlueprintBase_ValidateBlueprintFactor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityFactorBlueprintBase, nullptr, "ValidateBlueprintFactor", Z_Construct_UFunction_UABUtilityFactorBlueprintBase_ValidateBlueprintFactor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityFactorBlueprintBase_ValidateBlueprintFactor_Statics::PropPointers), sizeof(ABUtilityFactorBlueprintBase_eventValidateBlueprintFactor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48480C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityFactorBlueprintBase_ValidateBlueprintFactor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityFactorBlueprintBase_ValidateBlueprintFactor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ABUtilityFactorBlueprintBase_eventValidateBlueprintFactor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityFactorBlueprintBase_ValidateBlueprintFactor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityFactorBlueprintBase_ValidateBlueprintFactor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityFactorBlueprintBase::execValidateBlueprintFactor)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InInvalidationReason);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_OutInvalidationReason);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ValidateBlueprintFactor_Implementation(Z_Param_InInvalidationReason,Z_Param_Out_OutInvalidationReason);
	P_NATIVE_END;
}
// ********** End Class UABUtilityFactorBlueprintBase Function ValidateBlueprintFactor *************

// ********** Begin Class UABUtilityFactorBlueprintBase ********************************************
void UABUtilityFactorBlueprintBase::StaticRegisterNativesUABUtilityFactorBlueprintBase()
{
	UClass* Class = UABUtilityFactorBlueprintBase::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CalculateBlueprintFactorScore", &UABUtilityFactorBlueprintBase::execCalculateBlueprintFactorScore },
		{ "DescribeBlueprintSelfToGameplayDebugger", &UABUtilityFactorBlueprintBase::execDescribeBlueprintSelfToGameplayDebugger },
		{ "ValidateBlueprintFactor", &UABUtilityFactorBlueprintBase::execValidateBlueprintFactor },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilityFactorBlueprintBase;
UClass* UABUtilityFactorBlueprintBase::GetPrivateStaticClass()
{
	using TClass = UABUtilityFactorBlueprintBase;
	if (!Z_Registration_Info_UClass_UABUtilityFactorBlueprintBase.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilityFactorBlueprintBase"),
			Z_Registration_Info_UClass_UABUtilityFactorBlueprintBase.InnerSingleton,
			StaticRegisterNativesUABUtilityFactorBlueprintBase,
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
	return Z_Registration_Info_UClass_UABUtilityFactorBlueprintBase.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilityFactorBlueprintBase_NoRegister()
{
	return UABUtilityFactorBlueprintBase::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilityFactorBlueprintBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Actions/Factors/ABUtilityFactorBlueprintBase.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Actions/Factors/ABUtilityFactorBlueprintBase.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UABUtilityFactorBlueprintBase_CalculateBlueprintFactorScore, "CalculateBlueprintFactorScore" }, // 1560504109
		{ &Z_Construct_UFunction_UABUtilityFactorBlueprintBase_DescribeBlueprintSelfToGameplayDebugger, "DescribeBlueprintSelfToGameplayDebugger" }, // 1831877266
		{ &Z_Construct_UFunction_UABUtilityFactorBlueprintBase_ValidateBlueprintFactor, "ValidateBlueprintFactor" }, // 3690975575
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilityFactorBlueprintBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UABUtilityFactorBlueprintBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UABUtilityFactorBase,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityFactorBlueprintBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilityFactorBlueprintBase_Statics::ClassParams = {
	&UABUtilityFactorBlueprintBase::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001010A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityFactorBlueprintBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilityFactorBlueprintBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilityFactorBlueprintBase()
{
	if (!Z_Registration_Info_UClass_UABUtilityFactorBlueprintBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilityFactorBlueprintBase.OuterSingleton, Z_Construct_UClass_UABUtilityFactorBlueprintBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilityFactorBlueprintBase.OuterSingleton;
}
UABUtilityFactorBlueprintBase::UABUtilityFactorBlueprintBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilityFactorBlueprintBase);
UABUtilityFactorBlueprintBase::~UABUtilityFactorBlueprintBase() {}
// ********** End Class UABUtilityFactorBlueprintBase **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Factors_ABUtilityFactorBlueprintBase_h__Script_AxelaBrockettUtilityAIBase_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UABUtilityFactorBlueprintBase, UABUtilityFactorBlueprintBase::StaticClass, TEXT("UABUtilityFactorBlueprintBase"), &Z_Registration_Info_UClass_UABUtilityFactorBlueprintBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilityFactorBlueprintBase), 576559682U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Factors_ABUtilityFactorBlueprintBase_h__Script_AxelaBrockettUtilityAIBase_555311893(TEXT("/Script/AxelaBrockettUtilityAIBase"),
	Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Factors_ABUtilityFactorBlueprintBase_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Factors_ABUtilityFactorBlueprintBase_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
