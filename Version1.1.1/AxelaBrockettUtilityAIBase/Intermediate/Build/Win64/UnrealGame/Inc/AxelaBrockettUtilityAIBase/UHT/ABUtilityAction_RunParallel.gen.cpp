// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/Actions/Examples/ABUtilityAction_RunParallel.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeABUtilityAction_RunParallel() {}

// ********** Begin Cross Module References ********************************************************
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityAction_RunParallel();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityAction_RunParallel_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionBase();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionBase_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionInstanceMemoryBase();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionInstanceMemoryBase_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionRunParallelInstanceMemory();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionRunParallelInstanceMemory_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityFactorBase_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityRequirementBase_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABRunParallelFailureType();
AXELABROCKETTUTILITYAIBASE_API UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityActionRunStatus();
UPackage* Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UABUtilityActionRunParallelInstanceMemory ********************************
void UABUtilityActionRunParallelInstanceMemory::StaticRegisterNativesUABUtilityActionRunParallelInstanceMemory()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilityActionRunParallelInstanceMemory;
UClass* UABUtilityActionRunParallelInstanceMemory::GetPrivateStaticClass()
{
	using TClass = UABUtilityActionRunParallelInstanceMemory;
	if (!Z_Registration_Info_UClass_UABUtilityActionRunParallelInstanceMemory.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilityActionRunParallelInstanceMemory"),
			Z_Registration_Info_UClass_UABUtilityActionRunParallelInstanceMemory.InnerSingleton,
			StaticRegisterNativesUABUtilityActionRunParallelInstanceMemory,
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
	return Z_Registration_Info_UClass_UABUtilityActionRunParallelInstanceMemory.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilityActionRunParallelInstanceMemory_NoRegister()
{
	return UABUtilityActionRunParallelInstanceMemory::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilityActionRunParallelInstanceMemory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Actions/Actions/Examples/ABUtilityAction_RunParallel.h" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_RunParallel.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilityActionRunParallelInstanceMemory>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UABUtilityActionRunParallelInstanceMemory_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UABUtilityActionInstanceMemoryBase,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityActionRunParallelInstanceMemory_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilityActionRunParallelInstanceMemory_Statics::ClassParams = {
	&UABUtilityActionRunParallelInstanceMemory::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityActionRunParallelInstanceMemory_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilityActionRunParallelInstanceMemory_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilityActionRunParallelInstanceMemory()
{
	if (!Z_Registration_Info_UClass_UABUtilityActionRunParallelInstanceMemory.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilityActionRunParallelInstanceMemory.OuterSingleton, Z_Construct_UClass_UABUtilityActionRunParallelInstanceMemory_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilityActionRunParallelInstanceMemory.OuterSingleton;
}
UABUtilityActionRunParallelInstanceMemory::UABUtilityActionRunParallelInstanceMemory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilityActionRunParallelInstanceMemory);
UABUtilityActionRunParallelInstanceMemory::~UABUtilityActionRunParallelInstanceMemory() {}
// ********** End Class UABUtilityActionRunParallelInstanceMemory **********************************

// ********** Begin Enum EABRunParallelFailureType *************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EABRunParallelFailureType;
static UEnum* EABRunParallelFailureType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EABRunParallelFailureType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EABRunParallelFailureType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABRunParallelFailureType, (UObject*)Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase(), TEXT("EABRunParallelFailureType"));
	}
	return Z_Registration_Info_UEnum_EABRunParallelFailureType.OuterSingleton;
}
template<> AXELABROCKETTUTILITYAIBASE_API UEnum* StaticEnum<EABRunParallelFailureType>()
{
	return EABRunParallelFailureType_StaticEnum();
}
struct Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABRunParallelFailureType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AllFail.Name", "EABRunParallelFailureType::AllFail" },
		{ "AllFail.ToolTip", "This owning Action will only fail if all contained Actions fail" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_RunParallel.h" },
		{ "OneFails.Name", "EABRunParallelFailureType::OneFails" },
		{ "OneFails.ToolTip", "If one contained Action fails, this owning Action fails" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EABRunParallelFailureType::OneFails", (int64)EABRunParallelFailureType::OneFails },
		{ "EABRunParallelFailureType::AllFail", (int64)EABRunParallelFailureType::AllFail },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABRunParallelFailureType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
	nullptr,
	"EABRunParallelFailureType",
	"EABRunParallelFailureType",
	Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABRunParallelFailureType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABRunParallelFailureType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABRunParallelFailureType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABRunParallelFailureType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABRunParallelFailureType()
{
	if (!Z_Registration_Info_UEnum_EABRunParallelFailureType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EABRunParallelFailureType.InnerSingleton, Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABRunParallelFailureType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EABRunParallelFailureType.InnerSingleton;
}
// ********** End Enum EABRunParallelFailureType ***************************************************

// ********** Begin Class UABUtilityAction_RunParallel Function OnParallelActionCompleted **********
struct Z_Construct_UFunction_UABUtilityAction_RunParallel_OnParallelActionCompleted_Statics
{
	struct ABUtilityAction_RunParallel_eventOnParallelActionCompleted_Parms
	{
		UABUtilityActionBase* Action;
		EABUtilityActionRunStatus ActionStatus;
		const UABUtilityActionInstanceMemoryBase* ActionMemory;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_RunParallel.h" },
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
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UABUtilityAction_RunParallel_OnParallelActionCompleted_Statics::NewProp_Action = { "Action", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityAction_RunParallel_eventOnParallelActionCompleted_Parms, Action), Z_Construct_UClass_UABUtilityActionBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UABUtilityAction_RunParallel_OnParallelActionCompleted_Statics::NewProp_ActionStatus_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UABUtilityAction_RunParallel_OnParallelActionCompleted_Statics::NewProp_ActionStatus = { "ActionStatus", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityAction_RunParallel_eventOnParallelActionCompleted_Parms, ActionStatus), Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityActionRunStatus, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActionStatus_MetaData), NewProp_ActionStatus_MetaData) }; // 422754709
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UABUtilityAction_RunParallel_OnParallelActionCompleted_Statics::NewProp_ActionMemory = { "ActionMemory", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityAction_RunParallel_eventOnParallelActionCompleted_Parms, ActionMemory), Z_Construct_UClass_UABUtilityActionInstanceMemoryBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActionMemory_MetaData), NewProp_ActionMemory_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityAction_RunParallel_OnParallelActionCompleted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityAction_RunParallel_OnParallelActionCompleted_Statics::NewProp_Action,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityAction_RunParallel_OnParallelActionCompleted_Statics::NewProp_ActionStatus_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityAction_RunParallel_OnParallelActionCompleted_Statics::NewProp_ActionStatus,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityAction_RunParallel_OnParallelActionCompleted_Statics::NewProp_ActionMemory,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityAction_RunParallel_OnParallelActionCompleted_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityAction_RunParallel_OnParallelActionCompleted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityAction_RunParallel, nullptr, "OnParallelActionCompleted", Z_Construct_UFunction_UABUtilityAction_RunParallel_OnParallelActionCompleted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityAction_RunParallel_OnParallelActionCompleted_Statics::PropPointers), sizeof(Z_Construct_UFunction_UABUtilityAction_RunParallel_OnParallelActionCompleted_Statics::ABUtilityAction_RunParallel_eventOnParallelActionCompleted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityAction_RunParallel_OnParallelActionCompleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityAction_RunParallel_OnParallelActionCompleted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UABUtilityAction_RunParallel_OnParallelActionCompleted_Statics::ABUtilityAction_RunParallel_eventOnParallelActionCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityAction_RunParallel_OnParallelActionCompleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityAction_RunParallel_OnParallelActionCompleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityAction_RunParallel::execOnParallelActionCompleted)
{
	P_GET_OBJECT(UABUtilityActionBase,Z_Param_Action);
	P_GET_ENUM(EABUtilityActionRunStatus,Z_Param_ActionStatus);
	P_GET_OBJECT(UABUtilityActionInstanceMemoryBase,Z_Param_ActionMemory);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnParallelActionCompleted(Z_Param_Action,EABUtilityActionRunStatus(Z_Param_ActionStatus),Z_Param_ActionMemory);
	P_NATIVE_END;
}
// ********** End Class UABUtilityAction_RunParallel Function OnParallelActionCompleted ************

// ********** Begin Class UABUtilityAction_RunParallel *********************************************
void UABUtilityAction_RunParallel::StaticRegisterNativesUABUtilityAction_RunParallel()
{
	UClass* Class = UABUtilityAction_RunParallel::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnParallelActionCompleted", &UABUtilityAction_RunParallel::execOnParallelActionCompleted },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilityAction_RunParallel;
UClass* UABUtilityAction_RunParallel::GetPrivateStaticClass()
{
	using TClass = UABUtilityAction_RunParallel;
	if (!Z_Registration_Info_UClass_UABUtilityAction_RunParallel.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilityAction_RunParallel"),
			Z_Registration_Info_UClass_UABUtilityAction_RunParallel.InnerSingleton,
			StaticRegisterNativesUABUtilityAction_RunParallel,
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
	return Z_Registration_Info_UClass_UABUtilityAction_RunParallel.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilityAction_RunParallel_NoRegister()
{
	return UABUtilityAction_RunParallel::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilityAction_RunParallel_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Allows for multiple Actions to be run together at the same time\n * Requirements of all contained Actions must pass for this to run\n * Score will take into account score of all contained Actions\n */" },
		{ "DisplayName", "Utility Run Parallel Actions" },
		{ "IncludePath", "Actions/Actions/Examples/ABUtilityAction_RunParallel.h" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_RunParallel.h" },
		{ "ToolTip", "Allows for multiple Actions to be run together at the same time\nRequirements of all contained Actions must pass for this to run\nScore will take into account score of all contained Actions" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FailureType_MetaData[] = {
		{ "Category", "Utility Actions" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_RunParallel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParallelActions_Inner_MetaData[] = {
		{ "Category", "Utility Actions" },
		{ "Comment", "// List of Actions to be run at the same time\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_RunParallel.h" },
		{ "ToolTip", "List of Actions to be run at the same time" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParallelActions_MetaData[] = {
		{ "Category", "Utility Actions" },
		{ "Comment", "// List of Actions to be run at the same time\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_RunParallel.h" },
		{ "ToolTip", "List of Actions to be run at the same time" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActionInstanceMemory_MetaData[] = {
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_RunParallel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OwnFactors_MetaData[] = {
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_RunParallel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OwnRequirements_MetaData[] = {
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_RunParallel.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_FailureType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_FailureType;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ParallelActions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ParallelActions;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActionInstanceMemory_ValueProp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActionInstanceMemory_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ActionInstanceMemory;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OwnFactors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OwnFactors;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OwnRequirements_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OwnRequirements;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UABUtilityAction_RunParallel_OnParallelActionCompleted, "OnParallelActionCompleted" }, // 37075038
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilityAction_RunParallel>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::NewProp_FailureType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::NewProp_FailureType = { "FailureType", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_RunParallel, FailureType), Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABRunParallelFailureType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FailureType_MetaData), NewProp_FailureType_MetaData) }; // 3371035474
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::NewProp_ParallelActions_Inner = { "ParallelActions", nullptr, (EPropertyFlags)0x0002000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UABUtilityActionBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParallelActions_Inner_MetaData), NewProp_ParallelActions_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::NewProp_ParallelActions = { "ParallelActions", nullptr, (EPropertyFlags)0x0040008000000009, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_RunParallel, ParallelActions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParallelActions_MetaData), NewProp_ParallelActions_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::NewProp_ActionInstanceMemory_ValueProp = { "ActionInstanceMemory", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UABUtilityActionInstanceMemoryBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::NewProp_ActionInstanceMemory_Key_KeyProp = { "ActionInstanceMemory_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UABUtilityActionBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::NewProp_ActionInstanceMemory = { "ActionInstanceMemory", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_RunParallel, ActionInstanceMemory), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActionInstanceMemory_MetaData), NewProp_ActionInstanceMemory_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::NewProp_OwnFactors_Inner = { "OwnFactors", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UABUtilityFactorBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::NewProp_OwnFactors = { "OwnFactors", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_RunParallel, OwnFactors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OwnFactors_MetaData), NewProp_OwnFactors_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::NewProp_OwnRequirements_Inner = { "OwnRequirements", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UABUtilityRequirementBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::NewProp_OwnRequirements = { "OwnRequirements", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_RunParallel, OwnRequirements), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OwnRequirements_MetaData), NewProp_OwnRequirements_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::NewProp_FailureType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::NewProp_FailureType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::NewProp_ParallelActions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::NewProp_ParallelActions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::NewProp_ActionInstanceMemory_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::NewProp_ActionInstanceMemory_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::NewProp_ActionInstanceMemory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::NewProp_OwnFactors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::NewProp_OwnFactors,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::NewProp_OwnRequirements_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::NewProp_OwnRequirements,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UABUtilityActionBase,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::ClassParams = {
	&UABUtilityAction_RunParallel::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::PropPointers),
	0,
	0x009010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilityAction_RunParallel()
{
	if (!Z_Registration_Info_UClass_UABUtilityAction_RunParallel.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilityAction_RunParallel.OuterSingleton, Z_Construct_UClass_UABUtilityAction_RunParallel_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilityAction_RunParallel.OuterSingleton;
}
UABUtilityAction_RunParallel::UABUtilityAction_RunParallel() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilityAction_RunParallel);
UABUtilityAction_RunParallel::~UABUtilityAction_RunParallel() {}
// ********** End Class UABUtilityAction_RunParallel ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_RunParallel_h__Script_AxelaBrockettUtilityAIBase_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EABRunParallelFailureType_StaticEnum, TEXT("EABRunParallelFailureType"), &Z_Registration_Info_UEnum_EABRunParallelFailureType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3371035474U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UABUtilityActionRunParallelInstanceMemory, UABUtilityActionRunParallelInstanceMemory::StaticClass, TEXT("UABUtilityActionRunParallelInstanceMemory"), &Z_Registration_Info_UClass_UABUtilityActionRunParallelInstanceMemory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilityActionRunParallelInstanceMemory), 2266277256U) },
		{ Z_Construct_UClass_UABUtilityAction_RunParallel, UABUtilityAction_RunParallel::StaticClass, TEXT("UABUtilityAction_RunParallel"), &Z_Registration_Info_UClass_UABUtilityAction_RunParallel, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilityAction_RunParallel), 2888857078U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_RunParallel_h__Script_AxelaBrockettUtilityAIBase_3025659902(TEXT("/Script/AxelaBrockettUtilityAIBase"),
	Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_RunParallel_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_RunParallel_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_RunParallel_h__Script_AxelaBrockettUtilityAIBase_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_RunParallel_h__Script_AxelaBrockettUtilityAIBase_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
