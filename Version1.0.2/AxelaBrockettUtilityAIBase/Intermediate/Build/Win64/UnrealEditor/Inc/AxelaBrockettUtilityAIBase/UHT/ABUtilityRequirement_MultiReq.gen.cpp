// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/Requirements/Examples/ABUtilityRequirement_MultiReq.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeABUtilityRequirement_MultiReq() {}

// ********** Begin Cross Module References ********************************************************
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityRequirement_MultiReq();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityRequirement_MultiReq_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityRequirementBase();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityRequirementBase_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityRequirementGroupingOperator();
UPackage* Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EABUtilityRequirementGroupingOperator *************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EABUtilityRequirementGroupingOperator;
static UEnum* EABUtilityRequirementGroupingOperator_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EABUtilityRequirementGroupingOperator.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EABUtilityRequirementGroupingOperator.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityRequirementGroupingOperator, (UObject*)Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase(), TEXT("EABUtilityRequirementGroupingOperator"));
	}
	return Z_Registration_Info_UEnum_EABUtilityRequirementGroupingOperator.OuterSingleton;
}
template<> AXELABROCKETTUTILITYAIBASE_API UEnum* StaticEnum<EABUtilityRequirementGroupingOperator>()
{
	return EABUtilityRequirementGroupingOperator_StaticEnum();
}
struct Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityRequirementGroupingOperator_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AND.Name", "EABUtilityRequirementGroupingOperator::AND" },
		{ "ModuleRelativePath", "Public/Actions/Requirements/Examples/ABUtilityRequirement_MultiReq.h" },
		{ "OR.Name", "EABUtilityRequirementGroupingOperator::OR" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EABUtilityRequirementGroupingOperator::AND", (int64)EABUtilityRequirementGroupingOperator::AND },
		{ "EABUtilityRequirementGroupingOperator::OR", (int64)EABUtilityRequirementGroupingOperator::OR },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityRequirementGroupingOperator_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
	nullptr,
	"EABUtilityRequirementGroupingOperator",
	"EABUtilityRequirementGroupingOperator",
	Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityRequirementGroupingOperator_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityRequirementGroupingOperator_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityRequirementGroupingOperator_Statics::Enum_MetaDataParams), Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityRequirementGroupingOperator_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityRequirementGroupingOperator()
{
	if (!Z_Registration_Info_UEnum_EABUtilityRequirementGroupingOperator.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EABUtilityRequirementGroupingOperator.InnerSingleton, Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityRequirementGroupingOperator_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EABUtilityRequirementGroupingOperator.InnerSingleton;
}
// ********** End Enum EABUtilityRequirementGroupingOperator ***************************************

// ********** Begin Class UABUtilityRequirement_MultiReq *******************************************
void UABUtilityRequirement_MultiReq::StaticRegisterNativesUABUtilityRequirement_MultiReq()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilityRequirement_MultiReq;
UClass* UABUtilityRequirement_MultiReq::GetPrivateStaticClass()
{
	using TClass = UABUtilityRequirement_MultiReq;
	if (!Z_Registration_Info_UClass_UABUtilityRequirement_MultiReq.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilityRequirement_MultiReq"),
			Z_Registration_Info_UClass_UABUtilityRequirement_MultiReq.InnerSingleton,
			StaticRegisterNativesUABUtilityRequirement_MultiReq,
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
	return Z_Registration_Info_UClass_UABUtilityRequirement_MultiReq.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilityRequirement_MultiReq_NoRegister()
{
	return UABUtilityRequirement_MultiReq::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilityRequirement_MultiReq_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Multiple requirements grouped together with an AND or OR operator\n */" },
		{ "DisplayName", "Multiple Requirements" },
		{ "IncludePath", "Actions/Requirements/Examples/ABUtilityRequirement_MultiReq.h" },
		{ "ModuleRelativePath", "Public/Actions/Requirements/Examples/ABUtilityRequirement_MultiReq.h" },
		{ "ToolTip", "Multiple requirements grouped together with an AND or OR operator" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GroupingOperator_MetaData[] = {
		{ "Category", "Utility AI Multi Requirement" },
		{ "Comment", "// Operator this Multi-Requirement uses to group requirements together\n" },
		{ "ModuleRelativePath", "Public/Actions/Requirements/Examples/ABUtilityRequirement_MultiReq.h" },
		{ "ToolTip", "Operator this Multi-Requirement uses to group requirements together" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Requirements_Inner_MetaData[] = {
		{ "Category", "Utility AI Multi Requirement" },
		{ "Comment", "// Requirements grouped together\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actions/Requirements/Examples/ABUtilityRequirement_MultiReq.h" },
		{ "ToolTip", "Requirements grouped together" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Requirements_MetaData[] = {
		{ "Category", "Utility AI Multi Requirement" },
		{ "Comment", "// Requirements grouped together\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actions/Requirements/Examples/ABUtilityRequirement_MultiReq.h" },
		{ "ToolTip", "Requirements grouped together" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_GroupingOperator_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_GroupingOperator;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Requirements_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Requirements;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilityRequirement_MultiReq>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UABUtilityRequirement_MultiReq_Statics::NewProp_GroupingOperator_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UABUtilityRequirement_MultiReq_Statics::NewProp_GroupingOperator = { "GroupingOperator", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityRequirement_MultiReq, GroupingOperator), Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityRequirementGroupingOperator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GroupingOperator_MetaData), NewProp_GroupingOperator_MetaData) }; // 428640579
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABUtilityRequirement_MultiReq_Statics::NewProp_Requirements_Inner = { "Requirements", nullptr, (EPropertyFlags)0x0106000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UABUtilityRequirementBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Requirements_Inner_MetaData), NewProp_Requirements_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UABUtilityRequirement_MultiReq_Statics::NewProp_Requirements = { "Requirements", nullptr, (EPropertyFlags)0x0144008000000009, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityRequirement_MultiReq, Requirements), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Requirements_MetaData), NewProp_Requirements_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABUtilityRequirement_MultiReq_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityRequirement_MultiReq_Statics::NewProp_GroupingOperator_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityRequirement_MultiReq_Statics::NewProp_GroupingOperator,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityRequirement_MultiReq_Statics::NewProp_Requirements_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityRequirement_MultiReq_Statics::NewProp_Requirements,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityRequirement_MultiReq_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UABUtilityRequirement_MultiReq_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UABUtilityRequirementBase,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityRequirement_MultiReq_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilityRequirement_MultiReq_Statics::ClassParams = {
	&UABUtilityRequirement_MultiReq::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UABUtilityRequirement_MultiReq_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityRequirement_MultiReq_Statics::PropPointers),
	0,
	0x009010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityRequirement_MultiReq_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilityRequirement_MultiReq_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilityRequirement_MultiReq()
{
	if (!Z_Registration_Info_UClass_UABUtilityRequirement_MultiReq.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilityRequirement_MultiReq.OuterSingleton, Z_Construct_UClass_UABUtilityRequirement_MultiReq_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilityRequirement_MultiReq.OuterSingleton;
}
UABUtilityRequirement_MultiReq::UABUtilityRequirement_MultiReq(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilityRequirement_MultiReq);
UABUtilityRequirement_MultiReq::~UABUtilityRequirement_MultiReq() {}
// ********** End Class UABUtilityRequirement_MultiReq *********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_Examples_ABUtilityRequirement_MultiReq_h__Script_AxelaBrockettUtilityAIBase_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EABUtilityRequirementGroupingOperator_StaticEnum, TEXT("EABUtilityRequirementGroupingOperator"), &Z_Registration_Info_UEnum_EABUtilityRequirementGroupingOperator, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 428640579U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UABUtilityRequirement_MultiReq, UABUtilityRequirement_MultiReq::StaticClass, TEXT("UABUtilityRequirement_MultiReq"), &Z_Registration_Info_UClass_UABUtilityRequirement_MultiReq, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilityRequirement_MultiReq), 4255476961U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_Examples_ABUtilityRequirement_MultiReq_h__Script_AxelaBrockettUtilityAIBase_235301058(TEXT("/Script/AxelaBrockettUtilityAIBase"),
	Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_Examples_ABUtilityRequirement_MultiReq_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_Examples_ABUtilityRequirement_MultiReq_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_Examples_ABUtilityRequirement_MultiReq_h__Script_AxelaBrockettUtilityAIBase_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_Examples_ABUtilityRequirement_MultiReq_h__Script_AxelaBrockettUtilityAIBase_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
