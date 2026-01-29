// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Validators/ABUtilityDataAssetValidator.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeABUtilityDataAssetValidator() {}

// ********** Begin Cross Module References ********************************************************
AXELABROCKETTUTILITYAIEDITORBASE_API UClass* Z_Construct_UClass_UABUtilityDataAssetValidator();
AXELABROCKETTUTILITYAIEDITORBASE_API UClass* Z_Construct_UClass_UABUtilityDataAssetValidator_NoRegister();
DATAVALIDATION_API UClass* Z_Construct_UClass_UEditorValidatorBase();
UPackage* Z_Construct_UPackage__Script_AxelaBrockettUtilityAIEditorBase();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UABUtilityDataAssetValidator *********************************************
void UABUtilityDataAssetValidator::StaticRegisterNativesUABUtilityDataAssetValidator()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilityDataAssetValidator;
UClass* UABUtilityDataAssetValidator::GetPrivateStaticClass()
{
	using TClass = UABUtilityDataAssetValidator;
	if (!Z_Registration_Info_UClass_UABUtilityDataAssetValidator.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilityDataAssetValidator"),
			Z_Registration_Info_UClass_UABUtilityDataAssetValidator.InnerSingleton,
			StaticRegisterNativesUABUtilityDataAssetValidator,
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
	return Z_Registration_Info_UClass_UABUtilityDataAssetValidator.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilityDataAssetValidator_NoRegister()
{
	return UABUtilityDataAssetValidator::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilityDataAssetValidator_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Editor Validator for the Utility Data Asset\n * Validates every action in the data asset, along with its Requirements and Factors\n */" },
		{ "IncludePath", "Validators/ABUtilityDataAssetValidator.h" },
		{ "ModuleRelativePath", "Public/Validators/ABUtilityDataAssetValidator.h" },
		{ "ToolTip", "Editor Validator for the Utility Data Asset\nValidates every action in the data asset, along with its Requirements and Factors" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilityDataAssetValidator>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UABUtilityDataAssetValidator_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEditorValidatorBase,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIEditorBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityDataAssetValidator_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilityDataAssetValidator_Statics::ClassParams = {
	&UABUtilityDataAssetValidator::StaticClass,
	"Editor",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityDataAssetValidator_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilityDataAssetValidator_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilityDataAssetValidator()
{
	if (!Z_Registration_Info_UClass_UABUtilityDataAssetValidator.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilityDataAssetValidator.OuterSingleton, Z_Construct_UClass_UABUtilityDataAssetValidator_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilityDataAssetValidator.OuterSingleton;
}
UABUtilityDataAssetValidator::UABUtilityDataAssetValidator() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilityDataAssetValidator);
UABUtilityDataAssetValidator::~UABUtilityDataAssetValidator() {}
// ********** End Class UABUtilityDataAssetValidator ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIEditorBase_Public_Validators_ABUtilityDataAssetValidator_h__Script_AxelaBrockettUtilityAIEditorBase_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UABUtilityDataAssetValidator, UABUtilityDataAssetValidator::StaticClass, TEXT("UABUtilityDataAssetValidator"), &Z_Registration_Info_UClass_UABUtilityDataAssetValidator, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilityDataAssetValidator), 2224278389U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIEditorBase_Public_Validators_ABUtilityDataAssetValidator_h__Script_AxelaBrockettUtilityAIEditorBase_3531834546(TEXT("/Script/AxelaBrockettUtilityAIEditorBase"),
	Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIEditorBase_Public_Validators_ABUtilityDataAssetValidator_h__Script_AxelaBrockettUtilityAIEditorBase_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIEditorBase_Public_Validators_ABUtilityDataAssetValidator_h__Script_AxelaBrockettUtilityAIEditorBase_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
