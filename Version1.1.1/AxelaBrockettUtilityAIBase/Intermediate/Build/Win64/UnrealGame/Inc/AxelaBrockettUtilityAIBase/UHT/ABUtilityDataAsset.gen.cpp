// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DataAssets/ABUtilityDataAsset.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeABUtilityDataAsset() {}

// ********** Begin Cross Module References ********************************************************
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionBase_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityDataAsset();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityDataAsset_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
UPackage* Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UABUtilityDataAsset ******************************************************
void UABUtilityDataAsset::StaticRegisterNativesUABUtilityDataAsset()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilityDataAsset;
UClass* UABUtilityDataAsset::GetPrivateStaticClass()
{
	using TClass = UABUtilityDataAsset;
	if (!Z_Registration_Info_UClass_UABUtilityDataAsset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilityDataAsset"),
			Z_Registration_Info_UClass_UABUtilityDataAsset.InnerSingleton,
			StaticRegisterNativesUABUtilityDataAsset,
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
	return Z_Registration_Info_UClass_UABUtilityDataAsset.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilityDataAsset_NoRegister()
{
	return UABUtilityDataAsset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilityDataAsset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Data asset for Utility AI\n * Contains Utility Actions\n */" },
		{ "IncludePath", "DataAssets/ABUtilityDataAsset.h" },
		{ "ModuleRelativePath", "Public/DataAssets/ABUtilityDataAsset.h" },
		{ "ToolTip", "Data asset for Utility AI\nContains Utility Actions" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UtilityActions_Inner_MetaData[] = {
		{ "Category", "Utility Actions" },
		{ "Comment", "// Actions\n// Actions available to agents using this data asset\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DataAssets/ABUtilityDataAsset.h" },
		{ "ToolTip", "Actions\nActions available to agents using this data asset" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UtilityActions_MetaData[] = {
		{ "Category", "Utility Actions" },
		{ "Comment", "// Actions\n// Actions available to agents using this data asset\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DataAssets/ABUtilityDataAsset.h" },
		{ "ToolTip", "Actions\nActions available to agents using this data asset" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UtilityActions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_UtilityActions;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilityDataAsset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABUtilityDataAsset_Statics::NewProp_UtilityActions_Inner = { "UtilityActions", nullptr, (EPropertyFlags)0x0106000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UABUtilityActionBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UtilityActions_Inner_MetaData), NewProp_UtilityActions_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UABUtilityDataAsset_Statics::NewProp_UtilityActions = { "UtilityActions", nullptr, (EPropertyFlags)0x0144008000000009, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityDataAsset, UtilityActions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UtilityActions_MetaData), NewProp_UtilityActions_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABUtilityDataAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityDataAsset_Statics::NewProp_UtilityActions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityDataAsset_Statics::NewProp_UtilityActions,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityDataAsset_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UABUtilityDataAsset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityDataAsset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilityDataAsset_Statics::ClassParams = {
	&UABUtilityDataAsset::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UABUtilityDataAsset_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityDataAsset_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityDataAsset_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilityDataAsset_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilityDataAsset()
{
	if (!Z_Registration_Info_UClass_UABUtilityDataAsset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilityDataAsset.OuterSingleton, Z_Construct_UClass_UABUtilityDataAsset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilityDataAsset.OuterSingleton;
}
UABUtilityDataAsset::UABUtilityDataAsset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilityDataAsset);
UABUtilityDataAsset::~UABUtilityDataAsset() {}
// ********** End Class UABUtilityDataAsset ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_DataAssets_ABUtilityDataAsset_h__Script_AxelaBrockettUtilityAIBase_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UABUtilityDataAsset, UABUtilityDataAsset::StaticClass, TEXT("UABUtilityDataAsset"), &Z_Registration_Info_UClass_UABUtilityDataAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilityDataAsset), 2128213748U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_DataAssets_ABUtilityDataAsset_h__Script_AxelaBrockettUtilityAIBase_1779618446(TEXT("/Script/AxelaBrockettUtilityAIBase"),
	Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_DataAssets_ABUtilityDataAsset_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_DataAssets_ABUtilityDataAsset_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
