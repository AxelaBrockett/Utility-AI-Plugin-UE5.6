// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Settings/ABUtilitySettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeABUtilitySettings() {}

// ********** Begin Cross Module References ********************************************************
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityDataAsset_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilitySettings();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilitySettings_NoRegister();
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
UPackage* Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UABUtilitySettings *******************************************************
void UABUtilitySettings::StaticRegisterNativesUABUtilitySettings()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilitySettings;
UClass* UABUtilitySettings::GetPrivateStaticClass()
{
	using TClass = UABUtilitySettings;
	if (!Z_Registration_Info_UClass_UABUtilitySettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilitySettings"),
			Z_Registration_Info_UClass_UABUtilitySettings.InnerSingleton,
			StaticRegisterNativesUABUtilitySettings,
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
	return Z_Registration_Info_UClass_UABUtilitySettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilitySettings_NoRegister()
{
	return UABUtilitySettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilitySettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "DisplayName", "Utility AI Settings" },
		{ "IncludePath", "Settings/ABUtilitySettings.h" },
		{ "ModuleRelativePath", "Public/Settings/ABUtilitySettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UtilityDataAssets_MetaData[] = {
		{ "Category", "Data Assets" },
		{ "Comment", "// Data assets\n// The Utility Data Assets that will be loaded at runtime and available for use\n" },
		{ "ModuleRelativePath", "Public/Settings/ABUtilitySettings.h" },
		{ "ToolTip", "Data assets\nThe Utility Data Assets that will be loaded at runtime and available for use" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPrintCallstackInLogs_MetaData[] = {
		{ "Category", "Debugging" },
		{ "Comment", "// Debugging\n// Whether or not callstacks will be printed with warnings and errors\n// Gathering the callstack is time consuming - use carefully\n" },
		{ "ModuleRelativePath", "Public/Settings/ABUtilitySettings.h" },
		{ "ToolTip", "Debugging\nWhether or not callstacks will be printed with warnings and errors\nGathering the callstack is time consuming - use carefully" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_UtilityDataAssets_ElementProp;
	static const UECodeGen_Private::FSetPropertyParams NewProp_UtilityDataAssets;
	static void NewProp_bPrintCallstackInLogs_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPrintCallstackInLogs;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilitySettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UABUtilitySettings_Statics::NewProp_UtilityDataAssets_ElementProp = { "UtilityDataAssets", nullptr, (EPropertyFlags)0x0004000000004001, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UABUtilityDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FSetPropertyParams Z_Construct_UClass_UABUtilitySettings_Statics::NewProp_UtilityDataAssets = { "UtilityDataAssets", nullptr, (EPropertyFlags)0x0044000000004001, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilitySettings, UtilityDataAssets), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UtilityDataAssets_MetaData), NewProp_UtilityDataAssets_MetaData) };
void Z_Construct_UClass_UABUtilitySettings_Statics::NewProp_bPrintCallstackInLogs_SetBit(void* Obj)
{
	((UABUtilitySettings*)Obj)->bPrintCallstackInLogs = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UABUtilitySettings_Statics::NewProp_bPrintCallstackInLogs = { "bPrintCallstackInLogs", nullptr, (EPropertyFlags)0x0040000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UABUtilitySettings), &Z_Construct_UClass_UABUtilitySettings_Statics::NewProp_bPrintCallstackInLogs_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPrintCallstackInLogs_MetaData), NewProp_bPrintCallstackInLogs_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABUtilitySettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilitySettings_Statics::NewProp_UtilityDataAssets_ElementProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilitySettings_Statics::NewProp_UtilityDataAssets,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilitySettings_Statics::NewProp_bPrintCallstackInLogs,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilitySettings_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UABUtilitySettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilitySettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilitySettings_Statics::ClassParams = {
	&UABUtilitySettings::StaticClass,
	"Plugins",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UABUtilitySettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilitySettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilitySettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilitySettings_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilitySettings()
{
	if (!Z_Registration_Info_UClass_UABUtilitySettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilitySettings.OuterSingleton, Z_Construct_UClass_UABUtilitySettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilitySettings.OuterSingleton;
}
UABUtilitySettings::UABUtilitySettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilitySettings);
UABUtilitySettings::~UABUtilitySettings() {}
// ********** End Class UABUtilitySettings *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Settings_ABUtilitySettings_h__Script_AxelaBrockettUtilityAIBase_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UABUtilitySettings, UABUtilitySettings::StaticClass, TEXT("UABUtilitySettings"), &Z_Registration_Info_UClass_UABUtilitySettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilitySettings), 2523495788U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Settings_ABUtilitySettings_h__Script_AxelaBrockettUtilityAIBase_1180424373(TEXT("/Script/AxelaBrockettUtilityAIBase"),
	Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Settings_ABUtilitySettings_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Settings_ABUtilitySettings_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
