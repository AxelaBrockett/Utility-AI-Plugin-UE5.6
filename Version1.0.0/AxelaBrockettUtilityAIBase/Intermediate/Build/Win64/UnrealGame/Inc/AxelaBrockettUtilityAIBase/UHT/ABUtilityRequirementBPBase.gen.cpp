// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/Requirements/ABUtilityRequirementBPBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeABUtilityRequirementBPBase() {}

// ********** Begin Cross Module References ********************************************************
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityComponent_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityRequirementBase();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityRequirementBlueprintBase();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityRequirementBlueprintBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UABUtilityRequirementBlueprintBase Function CheckBlueprintRequirement ****
struct ABUtilityRequirementBlueprintBase_eventCheckBlueprintRequirement_Parms
{
	const UABUtilityComponent* OwnerComp;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	ABUtilityRequirementBlueprintBase_eventCheckBlueprintRequirement_Parms()
		: ReturnValue(false)
	{
	}
};
static FName NAME_UABUtilityRequirementBlueprintBase_CheckBlueprintRequirement = FName(TEXT("CheckBlueprintRequirement"));
const bool UABUtilityRequirementBlueprintBase::CheckBlueprintRequirement(const UABUtilityComponent* OwnerComp) const
{
	UFunction* Func = FindFunctionChecked(NAME_UABUtilityRequirementBlueprintBase_CheckBlueprintRequirement);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		ABUtilityRequirementBlueprintBase_eventCheckBlueprintRequirement_Parms Parms;
		Parms.OwnerComp=OwnerComp;
		const_cast<UABUtilityRequirementBlueprintBase*>(this)->ProcessEvent(Func,&Parms);
		return !!Parms.ReturnValue;
	}
	else
	{
		return const_cast<UABUtilityRequirementBlueprintBase*>(this)->CheckBlueprintRequirement_Implementation(OwnerComp);
	}
}
struct Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_CheckBlueprintRequirement_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Actions/Requirements/ABUtilityRequirementBPBase.h" },
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
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_CheckBlueprintRequirement_Statics::NewProp_OwnerComp = { "OwnerComp", nullptr, (EPropertyFlags)0x0010000000080082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityRequirementBlueprintBase_eventCheckBlueprintRequirement_Parms, OwnerComp), Z_Construct_UClass_UABUtilityComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OwnerComp_MetaData), NewProp_OwnerComp_MetaData) };
void Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_CheckBlueprintRequirement_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ABUtilityRequirementBlueprintBase_eventCheckBlueprintRequirement_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_CheckBlueprintRequirement_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000582, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ABUtilityRequirementBlueprintBase_eventCheckBlueprintRequirement_Parms), &Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_CheckBlueprintRequirement_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_CheckBlueprintRequirement_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_CheckBlueprintRequirement_Statics::NewProp_OwnerComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_CheckBlueprintRequirement_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_CheckBlueprintRequirement_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_CheckBlueprintRequirement_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityRequirementBlueprintBase, nullptr, "CheckBlueprintRequirement", Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_CheckBlueprintRequirement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_CheckBlueprintRequirement_Statics::PropPointers), sizeof(ABUtilityRequirementBlueprintBase_eventCheckBlueprintRequirement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_CheckBlueprintRequirement_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_CheckBlueprintRequirement_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ABUtilityRequirementBlueprintBase_eventCheckBlueprintRequirement_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_CheckBlueprintRequirement()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_CheckBlueprintRequirement_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityRequirementBlueprintBase::execCheckBlueprintRequirement)
{
	P_GET_OBJECT(UABUtilityComponent,Z_Param_OwnerComp);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CheckBlueprintRequirement_Implementation(Z_Param_OwnerComp);
	P_NATIVE_END;
}
// ********** End Class UABUtilityRequirementBlueprintBase Function CheckBlueprintRequirement ******

// ********** Begin Class UABUtilityRequirementBlueprintBase Function DescribeBlueprintSelfToGameplayDebugger 
struct ABUtilityRequirementBlueprintBase_eventDescribeBlueprintSelfToGameplayDebugger_Parms
{
	const UABUtilityComponent* OwnerComp;
	FString ReturnValue;
};
static FName NAME_UABUtilityRequirementBlueprintBase_DescribeBlueprintSelfToGameplayDebugger = FName(TEXT("DescribeBlueprintSelfToGameplayDebugger"));
const FString UABUtilityRequirementBlueprintBase::DescribeBlueprintSelfToGameplayDebugger(const UABUtilityComponent* OwnerComp) const
{
	UFunction* Func = FindFunctionChecked(NAME_UABUtilityRequirementBlueprintBase_DescribeBlueprintSelfToGameplayDebugger);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		ABUtilityRequirementBlueprintBase_eventDescribeBlueprintSelfToGameplayDebugger_Parms Parms;
		Parms.OwnerComp=OwnerComp;
		const_cast<UABUtilityRequirementBlueprintBase*>(this)->ProcessEvent(Func,&Parms);
		return Parms.ReturnValue;
	}
	else
	{
		return const_cast<UABUtilityRequirementBlueprintBase*>(this)->DescribeBlueprintSelfToGameplayDebugger_Implementation(OwnerComp);
	}
}
struct Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Comment", "// Return string to be added to debug\n" },
		{ "ModuleRelativePath", "Public/Actions/Requirements/ABUtilityRequirementBPBase.h" },
		{ "ToolTip", "Return string to be added to debug" },
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
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::NewProp_OwnerComp = { "OwnerComp", nullptr, (EPropertyFlags)0x0010000000080082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityRequirementBlueprintBase_eventDescribeBlueprintSelfToGameplayDebugger_Parms, OwnerComp), Z_Construct_UClass_UABUtilityComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OwnerComp_MetaData), NewProp_OwnerComp_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000582, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityRequirementBlueprintBase_eventDescribeBlueprintSelfToGameplayDebugger_Parms, ReturnValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::NewProp_OwnerComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityRequirementBlueprintBase, nullptr, "DescribeBlueprintSelfToGameplayDebugger", Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::PropPointers), sizeof(ABUtilityRequirementBlueprintBase_eventDescribeBlueprintSelfToGameplayDebugger_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ABUtilityRequirementBlueprintBase_eventDescribeBlueprintSelfToGameplayDebugger_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_DescribeBlueprintSelfToGameplayDebugger()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityRequirementBlueprintBase::execDescribeBlueprintSelfToGameplayDebugger)
{
	P_GET_OBJECT(UABUtilityComponent,Z_Param_OwnerComp);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->DescribeBlueprintSelfToGameplayDebugger_Implementation(Z_Param_OwnerComp);
	P_NATIVE_END;
}
// ********** End Class UABUtilityRequirementBlueprintBase Function DescribeBlueprintSelfToGameplayDebugger 

// ********** Begin Class UABUtilityRequirementBlueprintBase Function ValidateBlueprintRequirement *
struct ABUtilityRequirementBlueprintBase_eventValidateBlueprintRequirement_Parms
{
	FString InInvalidationReason;
	FString OutInvalidationReason;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	ABUtilityRequirementBlueprintBase_eventValidateBlueprintRequirement_Parms()
		: ReturnValue(false)
	{
	}
};
static FName NAME_UABUtilityRequirementBlueprintBase_ValidateBlueprintRequirement = FName(TEXT("ValidateBlueprintRequirement"));
const bool UABUtilityRequirementBlueprintBase::ValidateBlueprintRequirement(const FString& InInvalidationReason, FString& OutInvalidationReason) const
{
	UFunction* Func = FindFunctionChecked(NAME_UABUtilityRequirementBlueprintBase_ValidateBlueprintRequirement);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		ABUtilityRequirementBlueprintBase_eventValidateBlueprintRequirement_Parms Parms;
		Parms.InInvalidationReason=InInvalidationReason;
		Parms.OutInvalidationReason=OutInvalidationReason;
		const_cast<UABUtilityRequirementBlueprintBase*>(this)->ProcessEvent(Func,&Parms);
		OutInvalidationReason=Parms.OutInvalidationReason;
		return !!Parms.ReturnValue;
	}
	else
	{
		return const_cast<UABUtilityRequirementBlueprintBase*>(this)->ValidateBlueprintRequirement_Implementation(InInvalidationReason, OutInvalidationReason);
	}
}
struct Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_ValidateBlueprintRequirement_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Actions/Requirements/ABUtilityRequirementBPBase.h" },
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
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_ValidateBlueprintRequirement_Statics::NewProp_InInvalidationReason = { "InInvalidationReason", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityRequirementBlueprintBase_eventValidateBlueprintRequirement_Parms, InInvalidationReason), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InInvalidationReason_MetaData), NewProp_InInvalidationReason_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_ValidateBlueprintRequirement_Statics::NewProp_OutInvalidationReason = { "OutInvalidationReason", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityRequirementBlueprintBase_eventValidateBlueprintRequirement_Parms, OutInvalidationReason), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_ValidateBlueprintRequirement_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ABUtilityRequirementBlueprintBase_eventValidateBlueprintRequirement_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_ValidateBlueprintRequirement_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000582, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ABUtilityRequirementBlueprintBase_eventValidateBlueprintRequirement_Parms), &Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_ValidateBlueprintRequirement_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_ValidateBlueprintRequirement_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_ValidateBlueprintRequirement_Statics::NewProp_InInvalidationReason,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_ValidateBlueprintRequirement_Statics::NewProp_OutInvalidationReason,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_ValidateBlueprintRequirement_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_ValidateBlueprintRequirement_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_ValidateBlueprintRequirement_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityRequirementBlueprintBase, nullptr, "ValidateBlueprintRequirement", Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_ValidateBlueprintRequirement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_ValidateBlueprintRequirement_Statics::PropPointers), sizeof(ABUtilityRequirementBlueprintBase_eventValidateBlueprintRequirement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48480C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_ValidateBlueprintRequirement_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_ValidateBlueprintRequirement_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ABUtilityRequirementBlueprintBase_eventValidateBlueprintRequirement_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_ValidateBlueprintRequirement()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_ValidateBlueprintRequirement_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityRequirementBlueprintBase::execValidateBlueprintRequirement)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InInvalidationReason);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_OutInvalidationReason);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ValidateBlueprintRequirement_Implementation(Z_Param_InInvalidationReason,Z_Param_Out_OutInvalidationReason);
	P_NATIVE_END;
}
// ********** End Class UABUtilityRequirementBlueprintBase Function ValidateBlueprintRequirement ***

// ********** Begin Class UABUtilityRequirementBlueprintBase ***************************************
void UABUtilityRequirementBlueprintBase::StaticRegisterNativesUABUtilityRequirementBlueprintBase()
{
	UClass* Class = UABUtilityRequirementBlueprintBase::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CheckBlueprintRequirement", &UABUtilityRequirementBlueprintBase::execCheckBlueprintRequirement },
		{ "DescribeBlueprintSelfToGameplayDebugger", &UABUtilityRequirementBlueprintBase::execDescribeBlueprintSelfToGameplayDebugger },
		{ "ValidateBlueprintRequirement", &UABUtilityRequirementBlueprintBase::execValidateBlueprintRequirement },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilityRequirementBlueprintBase;
UClass* UABUtilityRequirementBlueprintBase::GetPrivateStaticClass()
{
	using TClass = UABUtilityRequirementBlueprintBase;
	if (!Z_Registration_Info_UClass_UABUtilityRequirementBlueprintBase.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilityRequirementBlueprintBase"),
			Z_Registration_Info_UClass_UABUtilityRequirementBlueprintBase.InnerSingleton,
			StaticRegisterNativesUABUtilityRequirementBlueprintBase,
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
	return Z_Registration_Info_UClass_UABUtilityRequirementBlueprintBase.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilityRequirementBlueprintBase_NoRegister()
{
	return UABUtilityRequirementBlueprintBase::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilityRequirementBlueprintBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Actions/Requirements/ABUtilityRequirementBPBase.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Actions/Requirements/ABUtilityRequirementBPBase.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_CheckBlueprintRequirement, "CheckBlueprintRequirement" }, // 2975372904
		{ &Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_DescribeBlueprintSelfToGameplayDebugger, "DescribeBlueprintSelfToGameplayDebugger" }, // 334928629
		{ &Z_Construct_UFunction_UABUtilityRequirementBlueprintBase_ValidateBlueprintRequirement, "ValidateBlueprintRequirement" }, // 2739857009
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilityRequirementBlueprintBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UABUtilityRequirementBlueprintBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UABUtilityRequirementBase,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityRequirementBlueprintBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilityRequirementBlueprintBase_Statics::ClassParams = {
	&UABUtilityRequirementBlueprintBase::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityRequirementBlueprintBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilityRequirementBlueprintBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilityRequirementBlueprintBase()
{
	if (!Z_Registration_Info_UClass_UABUtilityRequirementBlueprintBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilityRequirementBlueprintBase.OuterSingleton, Z_Construct_UClass_UABUtilityRequirementBlueprintBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilityRequirementBlueprintBase.OuterSingleton;
}
UABUtilityRequirementBlueprintBase::UABUtilityRequirementBlueprintBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilityRequirementBlueprintBase);
UABUtilityRequirementBlueprintBase::~UABUtilityRequirementBlueprintBase() {}
// ********** End Class UABUtilityRequirementBlueprintBase *****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_ABUtilityRequirementBPBase_h__Script_AxelaBrockettUtilityAIBase_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UABUtilityRequirementBlueprintBase, UABUtilityRequirementBlueprintBase::StaticClass, TEXT("UABUtilityRequirementBlueprintBase"), &Z_Registration_Info_UClass_UABUtilityRequirementBlueprintBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilityRequirementBlueprintBase), 3410638224U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_ABUtilityRequirementBPBase_h__Script_AxelaBrockettUtilityAIBase_1930865976(TEXT("/Script/AxelaBrockettUtilityAIBase"),
	Z_CompiledInDeferFile_FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_ABUtilityRequirementBPBase_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_ABUtilityRequirementBPBase_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
