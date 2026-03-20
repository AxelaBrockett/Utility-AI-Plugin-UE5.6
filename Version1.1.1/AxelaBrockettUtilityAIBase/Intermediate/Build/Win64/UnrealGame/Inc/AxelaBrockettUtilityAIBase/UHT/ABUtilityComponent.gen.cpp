// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/ABUtilityComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeABUtilityComponent() {}

// ********** Begin Cross Module References ********************************************************
AIMODULE_API UClass* Z_Construct_UClass_UBrainComponent();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionBase_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionInstanceMemoryBase_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityComponent();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityComponent_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityDataAsset_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABActionSelectionMode();
AXELABROCKETTUTILITYAIBASE_API UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityAbortActionLogic();
AXELABROCKETTUTILITYAIBASE_API UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityActionRunStatus();
AXELABROCKETTUTILITYAIBASE_API UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityComponentPauseActionLogic();
UPackage* Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EABUtilityComponentPauseActionLogic ***************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EABUtilityComponentPauseActionLogic;
static UEnum* EABUtilityComponentPauseActionLogic_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EABUtilityComponentPauseActionLogic.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EABUtilityComponentPauseActionLogic.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityComponentPauseActionLogic, (UObject*)Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase(), TEXT("EABUtilityComponentPauseActionLogic"));
	}
	return Z_Registration_Info_UEnum_EABUtilityComponentPauseActionLogic.OuterSingleton;
}
template<> AXELABROCKETTUTILITYAIBASE_API UEnum* StaticEnum<EABUtilityComponentPauseActionLogic>()
{
	return EABUtilityComponentPauseActionLogic_StaticEnum();
}
struct Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityComponentPauseActionLogic_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AbortAction.Name", "EABUtilityComponentPauseActionLogic::AbortAction" },
		{ "Comment", "// Pause logic for the utility component\n" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "PauseAction.Name", "EABUtilityComponentPauseActionLogic::PauseAction" },
		{ "ToolTip", "Pause logic for the utility component" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EABUtilityComponentPauseActionLogic::PauseAction", (int64)EABUtilityComponentPauseActionLogic::PauseAction },
		{ "EABUtilityComponentPauseActionLogic::AbortAction", (int64)EABUtilityComponentPauseActionLogic::AbortAction },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityComponentPauseActionLogic_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
	nullptr,
	"EABUtilityComponentPauseActionLogic",
	"EABUtilityComponentPauseActionLogic",
	Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityComponentPauseActionLogic_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityComponentPauseActionLogic_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityComponentPauseActionLogic_Statics::Enum_MetaDataParams), Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityComponentPauseActionLogic_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityComponentPauseActionLogic()
{
	if (!Z_Registration_Info_UEnum_EABUtilityComponentPauseActionLogic.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EABUtilityComponentPauseActionLogic.InnerSingleton, Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityComponentPauseActionLogic_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EABUtilityComponentPauseActionLogic.InnerSingleton;
}
// ********** End Enum EABUtilityComponentPauseActionLogic *****************************************

// ********** Begin Class UABUtilityComponent Function AbortCurrentAction **************************
struct Z_Construct_UFunction_UABUtilityComponent_AbortCurrentAction_Statics
{
	struct ABUtilityComponent_eventAbortCurrentAction_Parms
	{
		EABUtilityAbortActionLogic AbortLogic;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Utility Component" },
		{ "Comment", "// Pause and abort functions\n" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "Pause and abort functions" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbortLogic_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_AbortLogic_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_AbortLogic;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UABUtilityComponent_AbortCurrentAction_Statics::NewProp_AbortLogic_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UABUtilityComponent_AbortCurrentAction_Statics::NewProp_AbortLogic = { "AbortLogic", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityComponent_eventAbortCurrentAction_Parms, AbortLogic), Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityAbortActionLogic, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbortLogic_MetaData), NewProp_AbortLogic_MetaData) }; // 2635248477
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityComponent_AbortCurrentAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityComponent_AbortCurrentAction_Statics::NewProp_AbortLogic_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityComponent_AbortCurrentAction_Statics::NewProp_AbortLogic,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_AbortCurrentAction_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityComponent_AbortCurrentAction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityComponent, nullptr, "AbortCurrentAction", Z_Construct_UFunction_UABUtilityComponent_AbortCurrentAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_AbortCurrentAction_Statics::PropPointers), sizeof(Z_Construct_UFunction_UABUtilityComponent_AbortCurrentAction_Statics::ABUtilityComponent_eventAbortCurrentAction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_AbortCurrentAction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityComponent_AbortCurrentAction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UABUtilityComponent_AbortCurrentAction_Statics::ABUtilityComponent_eventAbortCurrentAction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityComponent_AbortCurrentAction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityComponent_AbortCurrentAction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityComponent::execAbortCurrentAction)
{
	P_GET_ENUM_REF(EABUtilityAbortActionLogic,Z_Param_Out_AbortLogic);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AbortCurrentAction((EABUtilityAbortActionLogic&)(Z_Param_Out_AbortLogic));
	P_NATIVE_END;
}
// ********** End Class UABUtilityComponent Function AbortCurrentAction ****************************

// ********** Begin Class UABUtilityComponent Function AttemptRetry ********************************
struct Z_Construct_UFunction_UABUtilityComponent_AttemptRetry_Statics
{
	struct ABUtilityComponent_eventAttemptRetry_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Utility Component" },
		{ "Comment", "// Retry logic\n" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "Retry logic" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UABUtilityComponent_AttemptRetry_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ABUtilityComponent_eventAttemptRetry_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UABUtilityComponent_AttemptRetry_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ABUtilityComponent_eventAttemptRetry_Parms), &Z_Construct_UFunction_UABUtilityComponent_AttemptRetry_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityComponent_AttemptRetry_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityComponent_AttemptRetry_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_AttemptRetry_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityComponent_AttemptRetry_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityComponent, nullptr, "AttemptRetry", Z_Construct_UFunction_UABUtilityComponent_AttemptRetry_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_AttemptRetry_Statics::PropPointers), sizeof(Z_Construct_UFunction_UABUtilityComponent_AttemptRetry_Statics::ABUtilityComponent_eventAttemptRetry_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_AttemptRetry_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityComponent_AttemptRetry_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UABUtilityComponent_AttemptRetry_Statics::ABUtilityComponent_eventAttemptRetry_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityComponent_AttemptRetry()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityComponent_AttemptRetry_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityComponent::execAttemptRetry)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->AttemptRetry();
	P_NATIVE_END;
}
// ********** End Class UABUtilityComponent Function AttemptRetry **********************************

// ********** Begin Class UABUtilityComponent Function GetActionSelectionMode **********************
struct Z_Construct_UFunction_UABUtilityComponent_GetActionSelectionMode_Statics
{
	struct ABUtilityComponent_eventGetActionSelectionMode_Parms
	{
		EABActionSelectionMode ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Utility Component" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UABUtilityComponent_GetActionSelectionMode_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UABUtilityComponent_GetActionSelectionMode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityComponent_eventGetActionSelectionMode_Parms, ReturnValue), Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABActionSelectionMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) }; // 1120867461
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityComponent_GetActionSelectionMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityComponent_GetActionSelectionMode_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityComponent_GetActionSelectionMode_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_GetActionSelectionMode_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityComponent_GetActionSelectionMode_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityComponent, nullptr, "GetActionSelectionMode", Z_Construct_UFunction_UABUtilityComponent_GetActionSelectionMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_GetActionSelectionMode_Statics::PropPointers), sizeof(Z_Construct_UFunction_UABUtilityComponent_GetActionSelectionMode_Statics::ABUtilityComponent_eventGetActionSelectionMode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_GetActionSelectionMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityComponent_GetActionSelectionMode_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UABUtilityComponent_GetActionSelectionMode_Statics::ABUtilityComponent_eventGetActionSelectionMode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityComponent_GetActionSelectionMode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityComponent_GetActionSelectionMode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityComponent::execGetActionSelectionMode)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EABActionSelectionMode*)Z_Param__Result=P_THIS->GetActionSelectionMode();
	P_NATIVE_END;
}
// ********** End Class UABUtilityComponent Function GetActionSelectionMode ************************

// ********** Begin Class UABUtilityComponent Function GetCurrentAction ****************************
struct Z_Construct_UFunction_UABUtilityComponent_GetCurrentAction_Statics
{
	struct ABUtilityComponent_eventGetCurrentAction_Parms
	{
		const UABUtilityActionBase* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Utility Component" },
		{ "Comment", "// Getters\n" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "Getters" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UABUtilityComponent_GetCurrentAction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000582, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityComponent_eventGetCurrentAction_Parms, ReturnValue), Z_Construct_UClass_UABUtilityActionBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityComponent_GetCurrentAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityComponent_GetCurrentAction_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_GetCurrentAction_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityComponent_GetCurrentAction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityComponent, nullptr, "GetCurrentAction", Z_Construct_UFunction_UABUtilityComponent_GetCurrentAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_GetCurrentAction_Statics::PropPointers), sizeof(Z_Construct_UFunction_UABUtilityComponent_GetCurrentAction_Statics::ABUtilityComponent_eventGetCurrentAction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_GetCurrentAction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityComponent_GetCurrentAction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UABUtilityComponent_GetCurrentAction_Statics::ABUtilityComponent_eventGetCurrentAction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityComponent_GetCurrentAction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityComponent_GetCurrentAction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityComponent::execGetCurrentAction)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(const UABUtilityActionBase**)Z_Param__Result=P_THIS->GetCurrentAction();
	P_NATIVE_END;
}
// ********** End Class UABUtilityComponent Function GetCurrentAction ******************************

// ********** Begin Class UABUtilityComponent Function GetLastSuccessfulAction *********************
struct Z_Construct_UFunction_UABUtilityComponent_GetLastSuccessfulAction_Statics
{
	struct ABUtilityComponent_eventGetLastSuccessfulAction_Parms
	{
		const UABUtilityActionBase* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Utility Component" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UABUtilityComponent_GetLastSuccessfulAction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000582, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityComponent_eventGetLastSuccessfulAction_Parms, ReturnValue), Z_Construct_UClass_UABUtilityActionBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityComponent_GetLastSuccessfulAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityComponent_GetLastSuccessfulAction_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_GetLastSuccessfulAction_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityComponent_GetLastSuccessfulAction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityComponent, nullptr, "GetLastSuccessfulAction", Z_Construct_UFunction_UABUtilityComponent_GetLastSuccessfulAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_GetLastSuccessfulAction_Statics::PropPointers), sizeof(Z_Construct_UFunction_UABUtilityComponent_GetLastSuccessfulAction_Statics::ABUtilityComponent_eventGetLastSuccessfulAction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_GetLastSuccessfulAction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityComponent_GetLastSuccessfulAction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UABUtilityComponent_GetLastSuccessfulAction_Statics::ABUtilityComponent_eventGetLastSuccessfulAction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityComponent_GetLastSuccessfulAction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityComponent_GetLastSuccessfulAction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityComponent::execGetLastSuccessfulAction)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(const UABUtilityActionBase**)Z_Param__Result=P_THIS->GetLastSuccessfulAction();
	P_NATIVE_END;
}
// ********** End Class UABUtilityComponent Function GetLastSuccessfulAction ***********************

// ********** Begin Class UABUtilityComponent Function IsComponentRunningAsynchronously ************
struct Z_Construct_UFunction_UABUtilityComponent_IsComponentRunningAsynchronously_Statics
{
	struct ABUtilityComponent_eventIsComponentRunningAsynchronously_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Utility Component" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UABUtilityComponent_IsComponentRunningAsynchronously_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ABUtilityComponent_eventIsComponentRunningAsynchronously_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UABUtilityComponent_IsComponentRunningAsynchronously_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000582, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ABUtilityComponent_eventIsComponentRunningAsynchronously_Parms), &Z_Construct_UFunction_UABUtilityComponent_IsComponentRunningAsynchronously_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityComponent_IsComponentRunningAsynchronously_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityComponent_IsComponentRunningAsynchronously_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_IsComponentRunningAsynchronously_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityComponent_IsComponentRunningAsynchronously_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityComponent, nullptr, "IsComponentRunningAsynchronously", Z_Construct_UFunction_UABUtilityComponent_IsComponentRunningAsynchronously_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_IsComponentRunningAsynchronously_Statics::PropPointers), sizeof(Z_Construct_UFunction_UABUtilityComponent_IsComponentRunningAsynchronously_Statics::ABUtilityComponent_eventIsComponentRunningAsynchronously_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_IsComponentRunningAsynchronously_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityComponent_IsComponentRunningAsynchronously_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UABUtilityComponent_IsComponentRunningAsynchronously_Statics::ABUtilityComponent_eventIsComponentRunningAsynchronously_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityComponent_IsComponentRunningAsynchronously()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityComponent_IsComponentRunningAsynchronously_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityComponent::execIsComponentRunningAsynchronously)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsComponentRunningAsynchronously();
	P_NATIVE_END;
}
// ********** End Class UABUtilityComponent Function IsComponentRunningAsynchronously **************

// ********** Begin Class UABUtilityComponent Function IsUsingConsiderationFactor ******************
struct Z_Construct_UFunction_UABUtilityComponent_IsUsingConsiderationFactor_Statics
{
	struct ABUtilityComponent_eventIsUsingConsiderationFactor_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Utility Component" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UABUtilityComponent_IsUsingConsiderationFactor_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ABUtilityComponent_eventIsUsingConsiderationFactor_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UABUtilityComponent_IsUsingConsiderationFactor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000582, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ABUtilityComponent_eventIsUsingConsiderationFactor_Parms), &Z_Construct_UFunction_UABUtilityComponent_IsUsingConsiderationFactor_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityComponent_IsUsingConsiderationFactor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityComponent_IsUsingConsiderationFactor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_IsUsingConsiderationFactor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityComponent_IsUsingConsiderationFactor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityComponent, nullptr, "IsUsingConsiderationFactor", Z_Construct_UFunction_UABUtilityComponent_IsUsingConsiderationFactor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_IsUsingConsiderationFactor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UABUtilityComponent_IsUsingConsiderationFactor_Statics::ABUtilityComponent_eventIsUsingConsiderationFactor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_IsUsingConsiderationFactor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityComponent_IsUsingConsiderationFactor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UABUtilityComponent_IsUsingConsiderationFactor_Statics::ABUtilityComponent_eventIsUsingConsiderationFactor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityComponent_IsUsingConsiderationFactor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityComponent_IsUsingConsiderationFactor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityComponent::execIsUsingConsiderationFactor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsUsingConsiderationFactor();
	P_NATIVE_END;
}
// ********** End Class UABUtilityComponent Function IsUsingConsiderationFactor ********************

// ********** Begin Class UABUtilityComponent Function IsUsingParallelRequirementChecking **********
struct Z_Construct_UFunction_UABUtilityComponent_IsUsingParallelRequirementChecking_Statics
{
	struct ABUtilityComponent_eventIsUsingParallelRequirementChecking_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Utility Component" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UABUtilityComponent_IsUsingParallelRequirementChecking_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ABUtilityComponent_eventIsUsingParallelRequirementChecking_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UABUtilityComponent_IsUsingParallelRequirementChecking_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000582, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ABUtilityComponent_eventIsUsingParallelRequirementChecking_Parms), &Z_Construct_UFunction_UABUtilityComponent_IsUsingParallelRequirementChecking_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityComponent_IsUsingParallelRequirementChecking_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityComponent_IsUsingParallelRequirementChecking_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_IsUsingParallelRequirementChecking_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityComponent_IsUsingParallelRequirementChecking_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityComponent, nullptr, "IsUsingParallelRequirementChecking", Z_Construct_UFunction_UABUtilityComponent_IsUsingParallelRequirementChecking_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_IsUsingParallelRequirementChecking_Statics::PropPointers), sizeof(Z_Construct_UFunction_UABUtilityComponent_IsUsingParallelRequirementChecking_Statics::ABUtilityComponent_eventIsUsingParallelRequirementChecking_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_IsUsingParallelRequirementChecking_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityComponent_IsUsingParallelRequirementChecking_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UABUtilityComponent_IsUsingParallelRequirementChecking_Statics::ABUtilityComponent_eventIsUsingParallelRequirementChecking_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityComponent_IsUsingParallelRequirementChecking()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityComponent_IsUsingParallelRequirementChecking_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityComponent::execIsUsingParallelRequirementChecking)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsUsingParallelRequirementChecking();
	P_NATIVE_END;
}
// ********** End Class UABUtilityComponent Function IsUsingParallelRequirementChecking ************

// ********** Begin Class UABUtilityComponent Function OnActionCompleted ***************************
struct Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics
{
	struct ABUtilityComponent_eventOnActionCompleted_Parms
	{
		UABUtilityActionBase* Action;
		EABUtilityActionRunStatus ActionStatus;
		const UABUtilityActionInstanceMemoryBase* ActionMemory;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Comment", "// Delegate binding functions\n" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "Delegate binding functions" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActionStatus_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActionMemory_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Action;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ActionStatus_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ActionStatus;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActionMemory;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::NewProp_Action = { "Action", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityComponent_eventOnActionCompleted_Parms, Action), Z_Construct_UClass_UABUtilityActionBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::NewProp_ActionStatus_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::NewProp_ActionStatus = { "ActionStatus", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityComponent_eventOnActionCompleted_Parms, ActionStatus), Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityActionRunStatus, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActionStatus_MetaData), NewProp_ActionStatus_MetaData) }; // 422754709
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::NewProp_ActionMemory = { "ActionMemory", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityComponent_eventOnActionCompleted_Parms, ActionMemory), Z_Construct_UClass_UABUtilityActionInstanceMemoryBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActionMemory_MetaData), NewProp_ActionMemory_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::NewProp_Action,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::NewProp_ActionStatus_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::NewProp_ActionStatus,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::NewProp_ActionMemory,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityComponent, nullptr, "OnActionCompleted", Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::PropPointers), sizeof(Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::ABUtilityComponent_eventOnActionCompleted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::ABUtilityComponent_eventOnActionCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityComponent::execOnActionCompleted)
{
	P_GET_OBJECT(UABUtilityActionBase,Z_Param_Action);
	P_GET_ENUM(EABUtilityActionRunStatus,Z_Param_ActionStatus);
	P_GET_OBJECT(UABUtilityActionInstanceMemoryBase,Z_Param_ActionMemory);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnActionCompleted(Z_Param_Action,EABUtilityActionRunStatus(Z_Param_ActionStatus),Z_Param_ActionMemory);
	P_NATIVE_END;
}
// ********** End Class UABUtilityComponent Function OnActionCompleted *****************************

// ********** Begin Class UABUtilityComponent Function OnActionRequirementsChecked *****************
struct Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics
{
	struct ABUtilityComponent_eventOnActionRequirementsChecked_Parms
	{
		UABUtilityActionBase* Action;
		bool bRequirementsPassed;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Comment", "// Delegate binding functions\n" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "Delegate binding functions" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRequirementsPassed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Action;
	static void NewProp_bRequirementsPassed_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRequirementsPassed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::NewProp_Action = { "Action", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityComponent_eventOnActionRequirementsChecked_Parms, Action), Z_Construct_UClass_UABUtilityActionBase_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::NewProp_bRequirementsPassed_SetBit(void* Obj)
{
	((ABUtilityComponent_eventOnActionRequirementsChecked_Parms*)Obj)->bRequirementsPassed = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::NewProp_bRequirementsPassed = { "bRequirementsPassed", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ABUtilityComponent_eventOnActionRequirementsChecked_Parms), &Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::NewProp_bRequirementsPassed_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRequirementsPassed_MetaData), NewProp_bRequirementsPassed_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::NewProp_Action,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::NewProp_bRequirementsPassed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityComponent, nullptr, "OnActionRequirementsChecked", Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::PropPointers), sizeof(Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::ABUtilityComponent_eventOnActionRequirementsChecked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::ABUtilityComponent_eventOnActionRequirementsChecked_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityComponent::execOnActionRequirementsChecked)
{
	P_GET_OBJECT(UABUtilityActionBase,Z_Param_Action);
	P_GET_UBOOL(Z_Param_bRequirementsPassed);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnActionRequirementsChecked(Z_Param_Action,Z_Param_bRequirementsPassed);
	P_NATIVE_END;
}
// ********** End Class UABUtilityComponent Function OnActionRequirementsChecked *******************

// ********** Begin Class UABUtilityComponent Function OnRep_CurrentAction *************************
static FName NAME_UABUtilityComponent_OnRep_CurrentAction = FName(TEXT("OnRep_CurrentAction"));
void UABUtilityComponent::OnRep_CurrentAction()
{
	UFunction* Func = FindFunctionChecked(NAME_UABUtilityComponent_OnRep_CurrentAction);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
	ProcessEvent(Func,NULL);
	}
	else
	{
		OnRep_CurrentAction_Implementation();
	}
}
struct Z_Construct_UFunction_UABUtilityComponent_OnRep_CurrentAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Comment", "// Replication functions\n" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "Replication functions" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityComponent_OnRep_CurrentAction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityComponent, nullptr, "OnRep_CurrentAction", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_OnRep_CurrentAction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityComponent_OnRep_CurrentAction_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UABUtilityComponent_OnRep_CurrentAction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityComponent_OnRep_CurrentAction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityComponent::execOnRep_CurrentAction)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_CurrentAction_Implementation();
	P_NATIVE_END;
}
// ********** End Class UABUtilityComponent Function OnRep_CurrentAction ***************************

// ********** Begin Class UABUtilityComponent Function OnRep_CurrentRunStatus **********************
static FName NAME_UABUtilityComponent_OnRep_CurrentRunStatus = FName(TEXT("OnRep_CurrentRunStatus"));
void UABUtilityComponent::OnRep_CurrentRunStatus()
{
	UFunction* Func = FindFunctionChecked(NAME_UABUtilityComponent_OnRep_CurrentRunStatus);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
	ProcessEvent(Func,NULL);
	}
	else
	{
		OnRep_CurrentRunStatus_Implementation();
	}
}
struct Z_Construct_UFunction_UABUtilityComponent_OnRep_CurrentRunStatus_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityComponent_OnRep_CurrentRunStatus_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityComponent, nullptr, "OnRep_CurrentRunStatus", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_OnRep_CurrentRunStatus_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityComponent_OnRep_CurrentRunStatus_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UABUtilityComponent_OnRep_CurrentRunStatus()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityComponent_OnRep_CurrentRunStatus_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityComponent::execOnRep_CurrentRunStatus)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_CurrentRunStatus_Implementation();
	P_NATIVE_END;
}
// ********** End Class UABUtilityComponent Function OnRep_CurrentRunStatus ************************

// ********** Begin Class UABUtilityComponent Function OnRep_LastSuccessfulAction ******************
static FName NAME_UABUtilityComponent_OnRep_LastSuccessfulAction = FName(TEXT("OnRep_LastSuccessfulAction"));
void UABUtilityComponent::OnRep_LastSuccessfulAction()
{
	UFunction* Func = FindFunctionChecked(NAME_UABUtilityComponent_OnRep_LastSuccessfulAction);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
	ProcessEvent(Func,NULL);
	}
	else
	{
		OnRep_LastSuccessfulAction_Implementation();
	}
}
struct Z_Construct_UFunction_UABUtilityComponent_OnRep_LastSuccessfulAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityComponent_OnRep_LastSuccessfulAction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityComponent, nullptr, "OnRep_LastSuccessfulAction", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_OnRep_LastSuccessfulAction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityComponent_OnRep_LastSuccessfulAction_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UABUtilityComponent_OnRep_LastSuccessfulAction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityComponent_OnRep_LastSuccessfulAction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityComponent::execOnRep_LastSuccessfulAction)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_LastSuccessfulAction_Implementation();
	P_NATIVE_END;
}
// ********** End Class UABUtilityComponent Function OnRep_LastSuccessfulAction ********************

// ********** Begin Class UABUtilityComponent Function PauseLogicWithActionDecision ****************
struct Z_Construct_UFunction_UABUtilityComponent_PauseLogicWithActionDecision_Statics
{
	struct ABUtilityComponent_eventPauseLogicWithActionDecision_Parms
	{
		FString Reason;
		EABUtilityComponentPauseActionLogic ActionDecision;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Utility Component" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Reason_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActionDecision_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Reason;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ActionDecision_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ActionDecision;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UABUtilityComponent_PauseLogicWithActionDecision_Statics::NewProp_Reason = { "Reason", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityComponent_eventPauseLogicWithActionDecision_Parms, Reason), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Reason_MetaData), NewProp_Reason_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UABUtilityComponent_PauseLogicWithActionDecision_Statics::NewProp_ActionDecision_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UABUtilityComponent_PauseLogicWithActionDecision_Statics::NewProp_ActionDecision = { "ActionDecision", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityComponent_eventPauseLogicWithActionDecision_Parms, ActionDecision), Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityComponentPauseActionLogic, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActionDecision_MetaData), NewProp_ActionDecision_MetaData) }; // 1445323107
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityComponent_PauseLogicWithActionDecision_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityComponent_PauseLogicWithActionDecision_Statics::NewProp_Reason,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityComponent_PauseLogicWithActionDecision_Statics::NewProp_ActionDecision_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityComponent_PauseLogicWithActionDecision_Statics::NewProp_ActionDecision,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_PauseLogicWithActionDecision_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityComponent_PauseLogicWithActionDecision_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityComponent, nullptr, "PauseLogicWithActionDecision", Z_Construct_UFunction_UABUtilityComponent_PauseLogicWithActionDecision_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_PauseLogicWithActionDecision_Statics::PropPointers), sizeof(Z_Construct_UFunction_UABUtilityComponent_PauseLogicWithActionDecision_Statics::ABUtilityComponent_eventPauseLogicWithActionDecision_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_PauseLogicWithActionDecision_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityComponent_PauseLogicWithActionDecision_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UABUtilityComponent_PauseLogicWithActionDecision_Statics::ABUtilityComponent_eventPauseLogicWithActionDecision_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityComponent_PauseLogicWithActionDecision()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityComponent_PauseLogicWithActionDecision_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityComponent::execPauseLogicWithActionDecision)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Reason);
	P_GET_ENUM_REF(EABUtilityComponentPauseActionLogic,Z_Param_Out_ActionDecision);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PauseLogicWithActionDecision(Z_Param_Reason,(EABUtilityComponentPauseActionLogic&)(Z_Param_Out_ActionDecision));
	P_NATIVE_END;
}
// ********** End Class UABUtilityComponent Function PauseLogicWithActionDecision ******************

// ********** Begin Class UABUtilityComponent Function ShouldRestartLogicWhenResumingComponentLogic 
struct Z_Construct_UFunction_UABUtilityComponent_ShouldRestartLogicWhenResumingComponentLogic_Statics
{
	struct ABUtilityComponent_eventShouldRestartLogicWhenResumingComponentLogic_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Utility Component" },
		{ "Comment", "// Inlines\n" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "Inlines" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UABUtilityComponent_ShouldRestartLogicWhenResumingComponentLogic_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ABUtilityComponent_eventShouldRestartLogicWhenResumingComponentLogic_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UABUtilityComponent_ShouldRestartLogicWhenResumingComponentLogic_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000582, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ABUtilityComponent_eventShouldRestartLogicWhenResumingComponentLogic_Parms), &Z_Construct_UFunction_UABUtilityComponent_ShouldRestartLogicWhenResumingComponentLogic_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityComponent_ShouldRestartLogicWhenResumingComponentLogic_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityComponent_ShouldRestartLogicWhenResumingComponentLogic_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_ShouldRestartLogicWhenResumingComponentLogic_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityComponent_ShouldRestartLogicWhenResumingComponentLogic_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityComponent, nullptr, "ShouldRestartLogicWhenResumingComponentLogic", Z_Construct_UFunction_UABUtilityComponent_ShouldRestartLogicWhenResumingComponentLogic_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_ShouldRestartLogicWhenResumingComponentLogic_Statics::PropPointers), sizeof(Z_Construct_UFunction_UABUtilityComponent_ShouldRestartLogicWhenResumingComponentLogic_Statics::ABUtilityComponent_eventShouldRestartLogicWhenResumingComponentLogic_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_ShouldRestartLogicWhenResumingComponentLogic_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityComponent_ShouldRestartLogicWhenResumingComponentLogic_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UABUtilityComponent_ShouldRestartLogicWhenResumingComponentLogic_Statics::ABUtilityComponent_eventShouldRestartLogicWhenResumingComponentLogic_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityComponent_ShouldRestartLogicWhenResumingComponentLogic()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityComponent_ShouldRestartLogicWhenResumingComponentLogic_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityComponent::execShouldRestartLogicWhenResumingComponentLogic)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ShouldRestartLogicWhenResumingComponentLogic();
	P_NATIVE_END;
}
// ********** End Class UABUtilityComponent Function ShouldRestartLogicWhenResumingComponentLogic **

// ********** Begin Class UABUtilityComponent Function ShouldRetryOnFailure ************************
struct Z_Construct_UFunction_UABUtilityComponent_ShouldRetryOnFailure_Statics
{
	struct ABUtilityComponent_eventShouldRetryOnFailure_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Utility Component" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UABUtilityComponent_ShouldRetryOnFailure_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ABUtilityComponent_eventShouldRetryOnFailure_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UABUtilityComponent_ShouldRetryOnFailure_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000582, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ABUtilityComponent_eventShouldRetryOnFailure_Parms), &Z_Construct_UFunction_UABUtilityComponent_ShouldRetryOnFailure_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityComponent_ShouldRetryOnFailure_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityComponent_ShouldRetryOnFailure_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_ShouldRetryOnFailure_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityComponent_ShouldRetryOnFailure_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityComponent, nullptr, "ShouldRetryOnFailure", Z_Construct_UFunction_UABUtilityComponent_ShouldRetryOnFailure_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_ShouldRetryOnFailure_Statics::PropPointers), sizeof(Z_Construct_UFunction_UABUtilityComponent_ShouldRetryOnFailure_Statics::ABUtilityComponent_eventShouldRetryOnFailure_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_ShouldRetryOnFailure_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityComponent_ShouldRetryOnFailure_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UABUtilityComponent_ShouldRetryOnFailure_Statics::ABUtilityComponent_eventShouldRetryOnFailure_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityComponent_ShouldRetryOnFailure()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityComponent_ShouldRetryOnFailure_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityComponent::execShouldRetryOnFailure)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ShouldRetryOnFailure();
	P_NATIVE_END;
}
// ********** End Class UABUtilityComponent Function ShouldRetryOnFailure **************************

// ********** Begin Class UABUtilityComponent ******************************************************
void UABUtilityComponent::StaticRegisterNativesUABUtilityComponent()
{
	UClass* Class = UABUtilityComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AbortCurrentAction", &UABUtilityComponent::execAbortCurrentAction },
		{ "AttemptRetry", &UABUtilityComponent::execAttemptRetry },
		{ "GetActionSelectionMode", &UABUtilityComponent::execGetActionSelectionMode },
		{ "GetCurrentAction", &UABUtilityComponent::execGetCurrentAction },
		{ "GetLastSuccessfulAction", &UABUtilityComponent::execGetLastSuccessfulAction },
		{ "IsComponentRunningAsynchronously", &UABUtilityComponent::execIsComponentRunningAsynchronously },
		{ "IsUsingConsiderationFactor", &UABUtilityComponent::execIsUsingConsiderationFactor },
		{ "IsUsingParallelRequirementChecking", &UABUtilityComponent::execIsUsingParallelRequirementChecking },
		{ "OnActionCompleted", &UABUtilityComponent::execOnActionCompleted },
		{ "OnActionRequirementsChecked", &UABUtilityComponent::execOnActionRequirementsChecked },
		{ "OnRep_CurrentAction", &UABUtilityComponent::execOnRep_CurrentAction },
		{ "OnRep_CurrentRunStatus", &UABUtilityComponent::execOnRep_CurrentRunStatus },
		{ "OnRep_LastSuccessfulAction", &UABUtilityComponent::execOnRep_LastSuccessfulAction },
		{ "PauseLogicWithActionDecision", &UABUtilityComponent::execPauseLogicWithActionDecision },
		{ "ShouldRestartLogicWhenResumingComponentLogic", &UABUtilityComponent::execShouldRestartLogicWhenResumingComponentLogic },
		{ "ShouldRetryOnFailure", &UABUtilityComponent::execShouldRetryOnFailure },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilityComponent;
UClass* UABUtilityComponent::GetPrivateStaticClass()
{
	using TClass = UABUtilityComponent;
	if (!Z_Registration_Info_UClass_UABUtilityComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilityComponent"),
			Z_Registration_Info_UClass_UABUtilityComponent.InnerSingleton,
			StaticRegisterNativesUABUtilityComponent,
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
	return Z_Registration_Info_UClass_UABUtilityComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilityComponent_NoRegister()
{
	return UABUtilityComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilityComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "AI" },
		{ "Comment", "/**\n * Utility brain component\n */" },
		{ "HideCategories", "Sockets Collision" },
		{ "IncludePath", "Components/ABUtilityComponent.h" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "Utility brain component" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UtilityDataAssetClass_MetaData[] = {
		{ "Category", "Utility" },
		{ "Comment", "// Data assets\n// Data asset class of type UABUtilityDataAsset\n" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "Data assets\nData asset class of type UABUtilityDataAsset" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentAction_MetaData[] = {
		{ "Comment", "// Replicated properties\n" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "Replicated properties" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastSuccessfulAction_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentRunStatus_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRestartLogicWhenResumingComponentLogic_MetaData[] = {
		{ "Category", "Pausing" },
		{ "Comment", "// Inlines\n// Restart the component when resuming after pausing\n" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "Inlines\nRestart the component when resuming after pausing" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRunComponentAsynchronously_MetaData[] = {
		{ "Category", "Async" },
		{ "Comment", "// Use available async functions\n" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "Use available async functions" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseParallelRequirementChecking_MetaData[] = {
		{ "Category", "Async" },
		{ "Comment", "// Use ParallelFor to check action requirements\n" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "Use ParallelFor to check action requirements" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRetryOnFailure_MetaData[] = {
		{ "Category", "Utility" },
		{ "Comment", "// In the event of all actions failing, retry\n" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "In the event of all actions failing, retry" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseConsiderationFactorScoreModifier_MetaData[] = {
		{ "Category", "Scoring" },
		{ "Comment", "// Enabling this will make all Factors within all Actions use the Consideration Factor score modifier\n" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "Enabling this will make all Factors within all Actions use the Consideration Factor score modifier" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActionSelectionMode_MetaData[] = {
		{ "Category", "Actions" },
		{ "Comment", "// Actions\n" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "Actions" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_UtilityDataAssetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LastSuccessfulAction;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentRunStatus_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentRunStatus;
	static void NewProp_bRestartLogicWhenResumingComponentLogic_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRestartLogicWhenResumingComponentLogic;
	static void NewProp_bRunComponentAsynchronously_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRunComponentAsynchronously;
	static void NewProp_bUseParallelRequirementChecking_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseParallelRequirementChecking;
	static void NewProp_bRetryOnFailure_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRetryOnFailure;
	static void NewProp_bUseConsiderationFactorScoreModifier_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseConsiderationFactorScoreModifier;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ActionSelectionMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ActionSelectionMode;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UABUtilityComponent_AbortCurrentAction, "AbortCurrentAction" }, // 1079866598
		{ &Z_Construct_UFunction_UABUtilityComponent_AttemptRetry, "AttemptRetry" }, // 2851388830
		{ &Z_Construct_UFunction_UABUtilityComponent_GetActionSelectionMode, "GetActionSelectionMode" }, // 2982829651
		{ &Z_Construct_UFunction_UABUtilityComponent_GetCurrentAction, "GetCurrentAction" }, // 1547845077
		{ &Z_Construct_UFunction_UABUtilityComponent_GetLastSuccessfulAction, "GetLastSuccessfulAction" }, // 188964957
		{ &Z_Construct_UFunction_UABUtilityComponent_IsComponentRunningAsynchronously, "IsComponentRunningAsynchronously" }, // 459207785
		{ &Z_Construct_UFunction_UABUtilityComponent_IsUsingConsiderationFactor, "IsUsingConsiderationFactor" }, // 3090749913
		{ &Z_Construct_UFunction_UABUtilityComponent_IsUsingParallelRequirementChecking, "IsUsingParallelRequirementChecking" }, // 2447756976
		{ &Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted, "OnActionCompleted" }, // 3729720910
		{ &Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked, "OnActionRequirementsChecked" }, // 1225115453
		{ &Z_Construct_UFunction_UABUtilityComponent_OnRep_CurrentAction, "OnRep_CurrentAction" }, // 2100181586
		{ &Z_Construct_UFunction_UABUtilityComponent_OnRep_CurrentRunStatus, "OnRep_CurrentRunStatus" }, // 3517177700
		{ &Z_Construct_UFunction_UABUtilityComponent_OnRep_LastSuccessfulAction, "OnRep_LastSuccessfulAction" }, // 692858777
		{ &Z_Construct_UFunction_UABUtilityComponent_PauseLogicWithActionDecision, "PauseLogicWithActionDecision" }, // 944541402
		{ &Z_Construct_UFunction_UABUtilityComponent_ShouldRestartLogicWhenResumingComponentLogic, "ShouldRestartLogicWhenResumingComponentLogic" }, // 3061196674
		{ &Z_Construct_UFunction_UABUtilityComponent_ShouldRetryOnFailure, "ShouldRetryOnFailure" }, // 660543887
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilityComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_UtilityDataAssetClass = { "UtilityDataAssetClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityComponent, UtilityDataAssetClass), Z_Construct_UClass_UABUtilityDataAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UtilityDataAssetClass_MetaData), NewProp_UtilityDataAssetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_CurrentAction = { "CurrentAction", "OnRep_CurrentAction", (EPropertyFlags)0x0124080100000020, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityComponent, CurrentAction), Z_Construct_UClass_UABUtilityActionBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentAction_MetaData), NewProp_CurrentAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_LastSuccessfulAction = { "LastSuccessfulAction", "OnRep_LastSuccessfulAction", (EPropertyFlags)0x0124080100000020, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityComponent, LastSuccessfulAction), Z_Construct_UClass_UABUtilityActionBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastSuccessfulAction_MetaData), NewProp_LastSuccessfulAction_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_CurrentRunStatus_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_CurrentRunStatus = { "CurrentRunStatus", "OnRep_CurrentRunStatus", (EPropertyFlags)0x0020080100000020, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityComponent, CurrentRunStatus), Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityActionRunStatus, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentRunStatus_MetaData), NewProp_CurrentRunStatus_MetaData) }; // 422754709
void Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bRestartLogicWhenResumingComponentLogic_SetBit(void* Obj)
{
	((UABUtilityComponent*)Obj)->bRestartLogicWhenResumingComponentLogic = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bRestartLogicWhenResumingComponentLogic = { "bRestartLogicWhenResumingComponentLogic", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(uint8), sizeof(UABUtilityComponent), &Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bRestartLogicWhenResumingComponentLogic_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRestartLogicWhenResumingComponentLogic_MetaData), NewProp_bRestartLogicWhenResumingComponentLogic_MetaData) };
void Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bRunComponentAsynchronously_SetBit(void* Obj)
{
	((UABUtilityComponent*)Obj)->bRunComponentAsynchronously = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bRunComponentAsynchronously = { "bRunComponentAsynchronously", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(uint8), sizeof(UABUtilityComponent), &Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bRunComponentAsynchronously_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRunComponentAsynchronously_MetaData), NewProp_bRunComponentAsynchronously_MetaData) };
void Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bUseParallelRequirementChecking_SetBit(void* Obj)
{
	((UABUtilityComponent*)Obj)->bUseParallelRequirementChecking = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bUseParallelRequirementChecking = { "bUseParallelRequirementChecking", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(uint8), sizeof(UABUtilityComponent), &Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bUseParallelRequirementChecking_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseParallelRequirementChecking_MetaData), NewProp_bUseParallelRequirementChecking_MetaData) };
void Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bRetryOnFailure_SetBit(void* Obj)
{
	((UABUtilityComponent*)Obj)->bRetryOnFailure = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bRetryOnFailure = { "bRetryOnFailure", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(uint8), sizeof(UABUtilityComponent), &Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bRetryOnFailure_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRetryOnFailure_MetaData), NewProp_bRetryOnFailure_MetaData) };
void Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bUseConsiderationFactorScoreModifier_SetBit(void* Obj)
{
	((UABUtilityComponent*)Obj)->bUseConsiderationFactorScoreModifier = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bUseConsiderationFactorScoreModifier = { "bUseConsiderationFactorScoreModifier", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(uint8), sizeof(UABUtilityComponent), &Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bUseConsiderationFactorScoreModifier_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseConsiderationFactorScoreModifier_MetaData), NewProp_bUseConsiderationFactorScoreModifier_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_ActionSelectionMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_ActionSelectionMode = { "ActionSelectionMode", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityComponent, ActionSelectionMode), Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABActionSelectionMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActionSelectionMode_MetaData), NewProp_ActionSelectionMode_MetaData) }; // 1120867461
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABUtilityComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_UtilityDataAssetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_CurrentAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_LastSuccessfulAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_CurrentRunStatus_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_CurrentRunStatus,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bRestartLogicWhenResumingComponentLogic,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bRunComponentAsynchronously,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bUseParallelRequirementChecking,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bRetryOnFailure,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bUseConsiderationFactorScoreModifier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_ActionSelectionMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_ActionSelectionMode,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UABUtilityComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBrainComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilityComponent_Statics::ClassParams = {
	&UABUtilityComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UABUtilityComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilityComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilityComponent()
{
	if (!Z_Registration_Info_UClass_UABUtilityComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilityComponent.OuterSingleton, Z_Construct_UClass_UABUtilityComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilityComponent.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void UABUtilityComponent::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_CurrentAction(TEXT("CurrentAction"));
	static FName Name_LastSuccessfulAction(TEXT("LastSuccessfulAction"));
	static FName Name_CurrentRunStatus(TEXT("CurrentRunStatus"));
	const bool bIsValid = true
		&& Name_CurrentAction == ClassReps[(int32)ENetFields_Private::CurrentAction].Property->GetFName()
		&& Name_LastSuccessfulAction == ClassReps[(int32)ENetFields_Private::LastSuccessfulAction].Property->GetFName()
		&& Name_CurrentRunStatus == ClassReps[(int32)ENetFields_Private::CurrentRunStatus].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in UABUtilityComponent"));
}
#endif
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilityComponent);
UABUtilityComponent::~UABUtilityComponent() {}
// ********** End Class UABUtilityComponent ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h__Script_AxelaBrockettUtilityAIBase_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EABUtilityComponentPauseActionLogic_StaticEnum, TEXT("EABUtilityComponentPauseActionLogic"), &Z_Registration_Info_UEnum_EABUtilityComponentPauseActionLogic, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1445323107U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UABUtilityComponent, UABUtilityComponent::StaticClass, TEXT("UABUtilityComponent"), &Z_Registration_Info_UClass_UABUtilityComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilityComponent), 733903698U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h__Script_AxelaBrockettUtilityAIBase_2460069104(TEXT("/Script/AxelaBrockettUtilityAIBase"),
	Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h__Script_AxelaBrockettUtilityAIBase_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h__Script_AxelaBrockettUtilityAIBase_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
