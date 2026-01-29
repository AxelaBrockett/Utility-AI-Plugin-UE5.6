// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/Actions/ABUtilityActionBlueprintBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeABUtilityActionBlueprintBase() {}

// ********** Begin Cross Module References ********************************************************
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionBase();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionBlueprintBase();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionBlueprintBase_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UABUtilityActionBlueprintBase Function DescribeBlueprintSelfToGameplayDebugger 
struct ABUtilityActionBlueprintBase_eventDescribeBlueprintSelfToGameplayDebugger_Parms
{
	const UABUtilityComponent* OwnerComp;
	FString ReturnValue;
};
static FName NAME_UABUtilityActionBlueprintBase_DescribeBlueprintSelfToGameplayDebugger = FName(TEXT("DescribeBlueprintSelfToGameplayDebugger"));
const FString UABUtilityActionBlueprintBase::DescribeBlueprintSelfToGameplayDebugger(const UABUtilityComponent* OwnerComp) const
{
	UFunction* Func = FindFunctionChecked(NAME_UABUtilityActionBlueprintBase_DescribeBlueprintSelfToGameplayDebugger);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		ABUtilityActionBlueprintBase_eventDescribeBlueprintSelfToGameplayDebugger_Parms Parms;
		Parms.OwnerComp=OwnerComp;
		const_cast<UABUtilityActionBlueprintBase*>(this)->ProcessEvent(Func,&Parms);
		return Parms.ReturnValue;
	}
	else
	{
		return const_cast<UABUtilityActionBlueprintBase*>(this)->DescribeBlueprintSelfToGameplayDebugger_Implementation(OwnerComp);
	}
}
struct Z_Construct_UFunction_UABUtilityActionBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Comment", "// Debugging\n// Return string to be added to debug\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/ABUtilityActionBlueprintBase.h" },
		{ "ToolTip", "Debugging\nReturn string to be added to debug" },
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
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UABUtilityActionBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::NewProp_OwnerComp = { "OwnerComp", nullptr, (EPropertyFlags)0x0010000000080082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityActionBlueprintBase_eventDescribeBlueprintSelfToGameplayDebugger_Parms, OwnerComp), Z_Construct_UClass_UABUtilityComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OwnerComp_MetaData), NewProp_OwnerComp_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UABUtilityActionBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000582, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityActionBlueprintBase_eventDescribeBlueprintSelfToGameplayDebugger_Parms, ReturnValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityActionBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityActionBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::NewProp_OwnerComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityActionBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityActionBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityActionBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityActionBlueprintBase, nullptr, "DescribeBlueprintSelfToGameplayDebugger", Z_Construct_UFunction_UABUtilityActionBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityActionBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::PropPointers), sizeof(ABUtilityActionBlueprintBase_eventDescribeBlueprintSelfToGameplayDebugger_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityActionBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityActionBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ABUtilityActionBlueprintBase_eventDescribeBlueprintSelfToGameplayDebugger_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityActionBlueprintBase_DescribeBlueprintSelfToGameplayDebugger()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityActionBlueprintBase_DescribeBlueprintSelfToGameplayDebugger_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityActionBlueprintBase::execDescribeBlueprintSelfToGameplayDebugger)
{
	P_GET_OBJECT(UABUtilityComponent,Z_Param_OwnerComp);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->DescribeBlueprintSelfToGameplayDebugger_Implementation(Z_Param_OwnerComp);
	P_NATIVE_END;
}
// ********** End Class UABUtilityActionBlueprintBase Function DescribeBlueprintSelfToGameplayDebugger 

// ********** Begin Class UABUtilityActionBlueprintBase Function DoBlueprintAction *****************
struct ABUtilityActionBlueprintBase_eventDoBlueprintAction_Parms
{
	UABUtilityComponent* OwnerComp;
};
static FName NAME_UABUtilityActionBlueprintBase_DoBlueprintAction = FName(TEXT("DoBlueprintAction"));
void UABUtilityActionBlueprintBase::DoBlueprintAction(UABUtilityComponent* OwnerComp)
{
	UFunction* Func = FindFunctionChecked(NAME_UABUtilityActionBlueprintBase_DoBlueprintAction);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		ABUtilityActionBlueprintBase_eventDoBlueprintAction_Parms Parms;
		Parms.OwnerComp=OwnerComp;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		DoBlueprintAction_Implementation(OwnerComp);
	}
}
struct Z_Construct_UFunction_UABUtilityActionBlueprintBase_DoBlueprintAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Actions/Actions/ABUtilityActionBlueprintBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OwnerComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OwnerComp;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UABUtilityActionBlueprintBase_DoBlueprintAction_Statics::NewProp_OwnerComp = { "OwnerComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityActionBlueprintBase_eventDoBlueprintAction_Parms, OwnerComp), Z_Construct_UClass_UABUtilityComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OwnerComp_MetaData), NewProp_OwnerComp_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityActionBlueprintBase_DoBlueprintAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityActionBlueprintBase_DoBlueprintAction_Statics::NewProp_OwnerComp,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityActionBlueprintBase_DoBlueprintAction_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityActionBlueprintBase_DoBlueprintAction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityActionBlueprintBase, nullptr, "DoBlueprintAction", Z_Construct_UFunction_UABUtilityActionBlueprintBase_DoBlueprintAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityActionBlueprintBase_DoBlueprintAction_Statics::PropPointers), sizeof(ABUtilityActionBlueprintBase_eventDoBlueprintAction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityActionBlueprintBase_DoBlueprintAction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityActionBlueprintBase_DoBlueprintAction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ABUtilityActionBlueprintBase_eventDoBlueprintAction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityActionBlueprintBase_DoBlueprintAction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityActionBlueprintBase_DoBlueprintAction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityActionBlueprintBase::execDoBlueprintAction)
{
	P_GET_OBJECT(UABUtilityComponent,Z_Param_OwnerComp);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoBlueprintAction_Implementation(Z_Param_OwnerComp);
	P_NATIVE_END;
}
// ********** End Class UABUtilityActionBlueprintBase Function DoBlueprintAction *******************

// ********** Begin Class UABUtilityActionBlueprintBase Function FinishAction **********************
struct Z_Construct_UFunction_UABUtilityActionBlueprintBase_FinishAction_Statics
{
	struct ABUtilityActionBlueprintBase_eventFinishAction_Parms
	{
		bool bSuccess;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Utility AI Blueprint Action" },
		{ "Comment", "// Completion function\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/ABUtilityActionBlueprintBase.h" },
		{ "ToolTip", "Completion function" },
	};
#endif // WITH_METADATA
	static void NewProp_bSuccess_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UABUtilityActionBlueprintBase_FinishAction_Statics::NewProp_bSuccess_SetBit(void* Obj)
{
	((ABUtilityActionBlueprintBase_eventFinishAction_Parms*)Obj)->bSuccess = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UABUtilityActionBlueprintBase_FinishAction_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ABUtilityActionBlueprintBase_eventFinishAction_Parms), &Z_Construct_UFunction_UABUtilityActionBlueprintBase_FinishAction_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityActionBlueprintBase_FinishAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityActionBlueprintBase_FinishAction_Statics::NewProp_bSuccess,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityActionBlueprintBase_FinishAction_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityActionBlueprintBase_FinishAction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityActionBlueprintBase, nullptr, "FinishAction", Z_Construct_UFunction_UABUtilityActionBlueprintBase_FinishAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityActionBlueprintBase_FinishAction_Statics::PropPointers), sizeof(Z_Construct_UFunction_UABUtilityActionBlueprintBase_FinishAction_Statics::ABUtilityActionBlueprintBase_eventFinishAction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityActionBlueprintBase_FinishAction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityActionBlueprintBase_FinishAction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UABUtilityActionBlueprintBase_FinishAction_Statics::ABUtilityActionBlueprintBase_eventFinishAction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityActionBlueprintBase_FinishAction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityActionBlueprintBase_FinishAction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityActionBlueprintBase::execFinishAction)
{
	P_GET_UBOOL(Z_Param_bSuccess);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FinishAction(Z_Param_bSuccess);
	P_NATIVE_END;
}
// ********** End Class UABUtilityActionBlueprintBase Function FinishAction ************************

// ********** Begin Class UABUtilityActionBlueprintBase Function TickBlueprintAction ***************
struct ABUtilityActionBlueprintBase_eventTickBlueprintAction_Parms
{
	UABUtilityComponent* OwnerComp;
	float DeltaSeconds;
};
static FName NAME_UABUtilityActionBlueprintBase_TickBlueprintAction = FName(TEXT("TickBlueprintAction"));
void UABUtilityActionBlueprintBase::TickBlueprintAction(UABUtilityComponent* OwnerComp, float DeltaSeconds)
{
	UFunction* Func = FindFunctionChecked(NAME_UABUtilityActionBlueprintBase_TickBlueprintAction);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		ABUtilityActionBlueprintBase_eventTickBlueprintAction_Parms Parms;
		Parms.OwnerComp=OwnerComp;
		Parms.DeltaSeconds=DeltaSeconds;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		TickBlueprintAction_Implementation(OwnerComp, DeltaSeconds);
	}
}
struct Z_Construct_UFunction_UABUtilityActionBlueprintBase_TickBlueprintAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Actions/Actions/ABUtilityActionBlueprintBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OwnerComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OwnerComp;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DeltaSeconds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UABUtilityActionBlueprintBase_TickBlueprintAction_Statics::NewProp_OwnerComp = { "OwnerComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityActionBlueprintBase_eventTickBlueprintAction_Parms, OwnerComp), Z_Construct_UClass_UABUtilityComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OwnerComp_MetaData), NewProp_OwnerComp_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UABUtilityActionBlueprintBase_TickBlueprintAction_Statics::NewProp_DeltaSeconds = { "DeltaSeconds", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityActionBlueprintBase_eventTickBlueprintAction_Parms, DeltaSeconds), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityActionBlueprintBase_TickBlueprintAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityActionBlueprintBase_TickBlueprintAction_Statics::NewProp_OwnerComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityActionBlueprintBase_TickBlueprintAction_Statics::NewProp_DeltaSeconds,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityActionBlueprintBase_TickBlueprintAction_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityActionBlueprintBase_TickBlueprintAction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityActionBlueprintBase, nullptr, "TickBlueprintAction", Z_Construct_UFunction_UABUtilityActionBlueprintBase_TickBlueprintAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityActionBlueprintBase_TickBlueprintAction_Statics::PropPointers), sizeof(ABUtilityActionBlueprintBase_eventTickBlueprintAction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityActionBlueprintBase_TickBlueprintAction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityActionBlueprintBase_TickBlueprintAction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ABUtilityActionBlueprintBase_eventTickBlueprintAction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityActionBlueprintBase_TickBlueprintAction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityActionBlueprintBase_TickBlueprintAction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityActionBlueprintBase::execTickBlueprintAction)
{
	P_GET_OBJECT(UABUtilityComponent,Z_Param_OwnerComp);
	P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaSeconds);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TickBlueprintAction_Implementation(Z_Param_OwnerComp,Z_Param_DeltaSeconds);
	P_NATIVE_END;
}
// ********** End Class UABUtilityActionBlueprintBase Function TickBlueprintAction *****************

// ********** Begin Class UABUtilityActionBlueprintBase Function ValidateBlueprintAction ***********
struct ABUtilityActionBlueprintBase_eventValidateBlueprintAction_Parms
{
	FString InInvalidationReason;
	FString OutInvalidationReason;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	ABUtilityActionBlueprintBase_eventValidateBlueprintAction_Parms()
		: ReturnValue(false)
	{
	}
};
static FName NAME_UABUtilityActionBlueprintBase_ValidateBlueprintAction = FName(TEXT("ValidateBlueprintAction"));
const bool UABUtilityActionBlueprintBase::ValidateBlueprintAction(const FString& InInvalidationReason, FString& OutInvalidationReason) const
{
	UFunction* Func = FindFunctionChecked(NAME_UABUtilityActionBlueprintBase_ValidateBlueprintAction);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		ABUtilityActionBlueprintBase_eventValidateBlueprintAction_Parms Parms;
		Parms.InInvalidationReason=InInvalidationReason;
		Parms.OutInvalidationReason=OutInvalidationReason;
		const_cast<UABUtilityActionBlueprintBase*>(this)->ProcessEvent(Func,&Parms);
		OutInvalidationReason=Parms.OutInvalidationReason;
		return !!Parms.ReturnValue;
	}
	else
	{
		return const_cast<UABUtilityActionBlueprintBase*>(this)->ValidateBlueprintAction_Implementation(InInvalidationReason, OutInvalidationReason);
	}
}
struct Z_Construct_UFunction_UABUtilityActionBlueprintBase_ValidateBlueprintAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Comment", "// Validation\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/ABUtilityActionBlueprintBase.h" },
		{ "ToolTip", "Validation" },
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
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UABUtilityActionBlueprintBase_ValidateBlueprintAction_Statics::NewProp_InInvalidationReason = { "InInvalidationReason", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityActionBlueprintBase_eventValidateBlueprintAction_Parms, InInvalidationReason), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InInvalidationReason_MetaData), NewProp_InInvalidationReason_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UABUtilityActionBlueprintBase_ValidateBlueprintAction_Statics::NewProp_OutInvalidationReason = { "OutInvalidationReason", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityActionBlueprintBase_eventValidateBlueprintAction_Parms, OutInvalidationReason), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UABUtilityActionBlueprintBase_ValidateBlueprintAction_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ABUtilityActionBlueprintBase_eventValidateBlueprintAction_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UABUtilityActionBlueprintBase_ValidateBlueprintAction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000582, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ABUtilityActionBlueprintBase_eventValidateBlueprintAction_Parms), &Z_Construct_UFunction_UABUtilityActionBlueprintBase_ValidateBlueprintAction_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityActionBlueprintBase_ValidateBlueprintAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityActionBlueprintBase_ValidateBlueprintAction_Statics::NewProp_InInvalidationReason,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityActionBlueprintBase_ValidateBlueprintAction_Statics::NewProp_OutInvalidationReason,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityActionBlueprintBase_ValidateBlueprintAction_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityActionBlueprintBase_ValidateBlueprintAction_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityActionBlueprintBase_ValidateBlueprintAction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityActionBlueprintBase, nullptr, "ValidateBlueprintAction", Z_Construct_UFunction_UABUtilityActionBlueprintBase_ValidateBlueprintAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityActionBlueprintBase_ValidateBlueprintAction_Statics::PropPointers), sizeof(ABUtilityActionBlueprintBase_eventValidateBlueprintAction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48480C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityActionBlueprintBase_ValidateBlueprintAction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityActionBlueprintBase_ValidateBlueprintAction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ABUtilityActionBlueprintBase_eventValidateBlueprintAction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityActionBlueprintBase_ValidateBlueprintAction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityActionBlueprintBase_ValidateBlueprintAction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityActionBlueprintBase::execValidateBlueprintAction)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InInvalidationReason);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_OutInvalidationReason);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ValidateBlueprintAction_Implementation(Z_Param_InInvalidationReason,Z_Param_Out_OutInvalidationReason);
	P_NATIVE_END;
}
// ********** End Class UABUtilityActionBlueprintBase Function ValidateBlueprintAction *************

// ********** Begin Class UABUtilityActionBlueprintBase ********************************************
void UABUtilityActionBlueprintBase::StaticRegisterNativesUABUtilityActionBlueprintBase()
{
	UClass* Class = UABUtilityActionBlueprintBase::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "DescribeBlueprintSelfToGameplayDebugger", &UABUtilityActionBlueprintBase::execDescribeBlueprintSelfToGameplayDebugger },
		{ "DoBlueprintAction", &UABUtilityActionBlueprintBase::execDoBlueprintAction },
		{ "FinishAction", &UABUtilityActionBlueprintBase::execFinishAction },
		{ "TickBlueprintAction", &UABUtilityActionBlueprintBase::execTickBlueprintAction },
		{ "ValidateBlueprintAction", &UABUtilityActionBlueprintBase::execValidateBlueprintAction },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilityActionBlueprintBase;
UClass* UABUtilityActionBlueprintBase::GetPrivateStaticClass()
{
	using TClass = UABUtilityActionBlueprintBase;
	if (!Z_Registration_Info_UClass_UABUtilityActionBlueprintBase.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilityActionBlueprintBase"),
			Z_Registration_Info_UClass_UABUtilityActionBlueprintBase.InnerSingleton,
			StaticRegisterNativesUABUtilityActionBlueprintBase,
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
	return Z_Registration_Info_UClass_UABUtilityActionBlueprintBase.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilityActionBlueprintBase_NoRegister()
{
	return UABUtilityActionBlueprintBase::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilityActionBlueprintBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Base for BP actions\n * Runs BP logic with available code\n */" },
		{ "IncludePath", "Actions/Actions/ABUtilityActionBlueprintBase.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Actions/Actions/ABUtilityActionBlueprintBase.h" },
		{ "ToolTip", "Base for BP actions\nRuns BP logic with available code" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UABUtilityActionBlueprintBase_DescribeBlueprintSelfToGameplayDebugger, "DescribeBlueprintSelfToGameplayDebugger" }, // 3563330033
		{ &Z_Construct_UFunction_UABUtilityActionBlueprintBase_DoBlueprintAction, "DoBlueprintAction" }, // 541974318
		{ &Z_Construct_UFunction_UABUtilityActionBlueprintBase_FinishAction, "FinishAction" }, // 26523956
		{ &Z_Construct_UFunction_UABUtilityActionBlueprintBase_TickBlueprintAction, "TickBlueprintAction" }, // 1138251070
		{ &Z_Construct_UFunction_UABUtilityActionBlueprintBase_ValidateBlueprintAction, "ValidateBlueprintAction" }, // 1944943853
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilityActionBlueprintBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UABUtilityActionBlueprintBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UABUtilityActionBase,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityActionBlueprintBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilityActionBlueprintBase_Statics::ClassParams = {
	&UABUtilityActionBlueprintBase::StaticClass,
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
	0x009010A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityActionBlueprintBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilityActionBlueprintBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilityActionBlueprintBase()
{
	if (!Z_Registration_Info_UClass_UABUtilityActionBlueprintBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilityActionBlueprintBase.OuterSingleton, Z_Construct_UClass_UABUtilityActionBlueprintBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilityActionBlueprintBase.OuterSingleton;
}
UABUtilityActionBlueprintBase::UABUtilityActionBlueprintBase() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilityActionBlueprintBase);
UABUtilityActionBlueprintBase::~UABUtilityActionBlueprintBase() {}
// ********** End Class UABUtilityActionBlueprintBase **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_ABUtilityActionBlueprintBase_h__Script_AxelaBrockettUtilityAIBase_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UABUtilityActionBlueprintBase, UABUtilityActionBlueprintBase::StaticClass, TEXT("UABUtilityActionBlueprintBase"), &Z_Registration_Info_UClass_UABUtilityActionBlueprintBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilityActionBlueprintBase), 95051888U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_ABUtilityActionBlueprintBase_h__Script_AxelaBrockettUtilityAIBase_551995229(TEXT("/Script/AxelaBrockettUtilityAIBase"),
	Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_ABUtilityActionBlueprintBase_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_ABUtilityActionBlueprintBase_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
