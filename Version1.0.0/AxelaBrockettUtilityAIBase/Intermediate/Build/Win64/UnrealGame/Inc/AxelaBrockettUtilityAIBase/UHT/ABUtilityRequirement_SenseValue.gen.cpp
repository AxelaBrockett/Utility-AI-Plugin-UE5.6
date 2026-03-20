// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/Requirements/Examples/ABUtilityRequirement_SenseValue.h"
#include "DataProviders/AIDataProvider.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeABUtilityRequirement_SenseValue() {}

// ********** Begin Cross Module References ********************************************************
AIMODULE_API UClass* Z_Construct_UClass_UAISense_NoRegister();
AIMODULE_API UEnum* Z_Construct_UEnum_AIModule_EGenericAICheck();
AIMODULE_API UScriptStruct* Z_Construct_UScriptStruct_FAIDataProviderFloatValue();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityRequirement_SenseValue();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityRequirement_SenseValue_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityRequirementBase();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
UPackage* Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UABUtilityRequirement_SenseValue *****************************************
void UABUtilityRequirement_SenseValue::StaticRegisterNativesUABUtilityRequirement_SenseValue()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilityRequirement_SenseValue;
UClass* UABUtilityRequirement_SenseValue::GetPrivateStaticClass()
{
	using TClass = UABUtilityRequirement_SenseValue;
	if (!Z_Registration_Info_UClass_UABUtilityRequirement_SenseValue.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilityRequirement_SenseValue"),
			Z_Registration_Info_UClass_UABUtilityRequirement_SenseValue.InnerSingleton,
			StaticRegisterNativesUABUtilityRequirement_SenseValue,
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
	return Z_Registration_Info_UClass_UABUtilityRequirement_SenseValue.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilityRequirement_SenseValue_NoRegister()
{
	return UABUtilityRequirement_SenseValue::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilityRequirement_SenseValue_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Compare a perception sense value to a given value\n */" },
		{ "DisplayName", "Sense Value Comparison" },
		{ "IncludePath", "Actions/Requirements/Examples/ABUtilityRequirement_SenseValue.h" },
		{ "ModuleRelativePath", "Public/Actions/Requirements/Examples/ABUtilityRequirement_SenseValue.h" },
		{ "ToolTip", "Compare a perception sense value to a given value" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SenseToCheck_MetaData[] = {
		{ "Category", "Utility AI Sense Value Requirement" },
		{ "Comment", "// The sense to check the value of.\n// If left blank or the agent does not use this sense, a general highest value will be used\n" },
		{ "ModuleRelativePath", "Public/Actions/Requirements/Examples/ABUtilityRequirement_SenseValue.h" },
		{ "ToolTip", "The sense to check the value of.\nIf left blank or the agent does not use this sense, a general highest value will be used" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GoalValue_MetaData[] = {
		{ "Category", "Utility AI Sense Value Requirement" },
		{ "Comment", "// The goal value to compare against\n" },
		{ "ModuleRelativePath", "Public/Actions/Requirements/Examples/ABUtilityRequirement_SenseValue.h" },
		{ "ToolTip", "The goal value to compare against" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ValueComparison_MetaData[] = {
		{ "Category", "Utility AI Sense Value Requirement" },
		{ "Comment", "// The type of comparison being made against the two values\n" },
		{ "ModuleRelativePath", "Public/Actions/Requirements/Examples/ABUtilityRequirement_SenseValue.h" },
		{ "ToolTip", "The type of comparison being made against the two values" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_SenseToCheck;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GoalValue;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ValueComparison_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ValueComparison;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilityRequirement_SenseValue>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UABUtilityRequirement_SenseValue_Statics::NewProp_SenseToCheck = { "SenseToCheck", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityRequirement_SenseValue, SenseToCheck), Z_Construct_UClass_UClass, Z_Construct_UClass_UAISense_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SenseToCheck_MetaData), NewProp_SenseToCheck_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityRequirement_SenseValue_Statics::NewProp_GoalValue = { "GoalValue", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityRequirement_SenseValue, GoalValue), Z_Construct_UScriptStruct_FAIDataProviderFloatValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GoalValue_MetaData), NewProp_GoalValue_MetaData) }; // 2793119070
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UABUtilityRequirement_SenseValue_Statics::NewProp_ValueComparison_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UABUtilityRequirement_SenseValue_Statics::NewProp_ValueComparison = { "ValueComparison", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityRequirement_SenseValue, ValueComparison), Z_Construct_UEnum_AIModule_EGenericAICheck, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ValueComparison_MetaData), NewProp_ValueComparison_MetaData) }; // 1286505699
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABUtilityRequirement_SenseValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityRequirement_SenseValue_Statics::NewProp_SenseToCheck,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityRequirement_SenseValue_Statics::NewProp_GoalValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityRequirement_SenseValue_Statics::NewProp_ValueComparison_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityRequirement_SenseValue_Statics::NewProp_ValueComparison,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityRequirement_SenseValue_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UABUtilityRequirement_SenseValue_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UABUtilityRequirementBase,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityRequirement_SenseValue_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilityRequirement_SenseValue_Statics::ClassParams = {
	&UABUtilityRequirement_SenseValue::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UABUtilityRequirement_SenseValue_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityRequirement_SenseValue_Statics::PropPointers),
	0,
	0x009010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityRequirement_SenseValue_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilityRequirement_SenseValue_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilityRequirement_SenseValue()
{
	if (!Z_Registration_Info_UClass_UABUtilityRequirement_SenseValue.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilityRequirement_SenseValue.OuterSingleton, Z_Construct_UClass_UABUtilityRequirement_SenseValue_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilityRequirement_SenseValue.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilityRequirement_SenseValue);
UABUtilityRequirement_SenseValue::~UABUtilityRequirement_SenseValue() {}
// ********** End Class UABUtilityRequirement_SenseValue *******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_Examples_ABUtilityRequirement_SenseValue_h__Script_AxelaBrockettUtilityAIBase_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UABUtilityRequirement_SenseValue, UABUtilityRequirement_SenseValue::StaticClass, TEXT("UABUtilityRequirement_SenseValue"), &Z_Registration_Info_UClass_UABUtilityRequirement_SenseValue, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilityRequirement_SenseValue), 2143373749U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_Examples_ABUtilityRequirement_SenseValue_h__Script_AxelaBrockettUtilityAIBase_867102512(TEXT("/Script/AxelaBrockettUtilityAIBase"),
	Z_CompiledInDeferFile_FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_Examples_ABUtilityRequirement_SenseValue_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_Examples_ABUtilityRequirement_SenseValue_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
