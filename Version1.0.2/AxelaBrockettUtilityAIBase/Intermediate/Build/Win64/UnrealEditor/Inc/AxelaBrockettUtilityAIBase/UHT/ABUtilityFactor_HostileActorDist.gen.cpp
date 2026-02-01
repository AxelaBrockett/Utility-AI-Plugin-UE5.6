// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/Factors/Examples/ABUtilityFactor_HostileActorDist.h"
#include "DataProviders/AIDataProvider.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeABUtilityFactor_HostileActorDist() {}

// ********** Begin Cross Module References ********************************************************
AIMODULE_API UScriptStruct* Z_Construct_UScriptStruct_FAIDataProviderFloatValue();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityFactor_HostileActorDist();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityFactor_HostileActorDist_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityFactorBase();
UPackage* Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UABUtilityFactor_HostileActorDist ****************************************
void UABUtilityFactor_HostileActorDist::StaticRegisterNativesUABUtilityFactor_HostileActorDist()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilityFactor_HostileActorDist;
UClass* UABUtilityFactor_HostileActorDist::GetPrivateStaticClass()
{
	using TClass = UABUtilityFactor_HostileActorDist;
	if (!Z_Registration_Info_UClass_UABUtilityFactor_HostileActorDist.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilityFactor_HostileActorDist"),
			Z_Registration_Info_UClass_UABUtilityFactor_HostileActorDist.InnerSingleton,
			StaticRegisterNativesUABUtilityFactor_HostileActorDist,
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
	return Z_Registration_Info_UClass_UABUtilityFactor_HostileActorDist.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilityFactor_HostileActorDist_NoRegister()
{
	return UABUtilityFactor_HostileActorDist::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilityFactor_HostileActorDist_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Factor that scores based on distance to the closest hostile actor\n */" },
		{ "IncludePath", "Actions/Factors/Examples/ABUtilityFactor_HostileActorDist.h" },
		{ "ModuleRelativePath", "Public/Actions/Factors/Examples/ABUtilityFactor_HostileActorDist.h" },
		{ "ToolTip", "Factor that scores based on distance to the closest hostile actor" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxDist_MetaData[] = {
		{ "Category", "Utility AI Factor Hostile Actor Distance" },
		{ "ModuleRelativePath", "Public/Actions/Factors/Examples/ABUtilityFactor_HostileActorDist.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_MaxDist;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilityFactor_HostileActorDist>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityFactor_HostileActorDist_Statics::NewProp_MaxDist = { "MaxDist", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityFactor_HostileActorDist, MaxDist), Z_Construct_UScriptStruct_FAIDataProviderFloatValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxDist_MetaData), NewProp_MaxDist_MetaData) }; // 2793119070
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABUtilityFactor_HostileActorDist_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityFactor_HostileActorDist_Statics::NewProp_MaxDist,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityFactor_HostileActorDist_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UABUtilityFactor_HostileActorDist_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UABUtilityFactorBase,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityFactor_HostileActorDist_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilityFactor_HostileActorDist_Statics::ClassParams = {
	&UABUtilityFactor_HostileActorDist::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UABUtilityFactor_HostileActorDist_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityFactor_HostileActorDist_Statics::PropPointers),
	0,
	0x009010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityFactor_HostileActorDist_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilityFactor_HostileActorDist_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilityFactor_HostileActorDist()
{
	if (!Z_Registration_Info_UClass_UABUtilityFactor_HostileActorDist.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilityFactor_HostileActorDist.OuterSingleton, Z_Construct_UClass_UABUtilityFactor_HostileActorDist_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilityFactor_HostileActorDist.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilityFactor_HostileActorDist);
UABUtilityFactor_HostileActorDist::~UABUtilityFactor_HostileActorDist() {}
// ********** End Class UABUtilityFactor_HostileActorDist ******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Factors_Examples_ABUtilityFactor_HostileActorDist_h__Script_AxelaBrockettUtilityAIBase_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UABUtilityFactor_HostileActorDist, UABUtilityFactor_HostileActorDist::StaticClass, TEXT("UABUtilityFactor_HostileActorDist"), &Z_Registration_Info_UClass_UABUtilityFactor_HostileActorDist, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilityFactor_HostileActorDist), 2776719219U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Factors_Examples_ABUtilityFactor_HostileActorDist_h__Script_AxelaBrockettUtilityAIBase_307091449(TEXT("/Script/AxelaBrockettUtilityAIBase"),
	Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Factors_Examples_ABUtilityFactor_HostileActorDist_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Factors_Examples_ABUtilityFactor_HostileActorDist_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
