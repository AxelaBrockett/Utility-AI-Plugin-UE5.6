// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/Factors/ABUtilityFactorBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeABUtilityFactorBase() {}

// ********** Begin Cross Module References ********************************************************
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityFactorBase();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityFactorBase_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
UPackage* Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UABUtilityFactorBase *****************************************************
void UABUtilityFactorBase::StaticRegisterNativesUABUtilityFactorBase()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilityFactorBase;
UClass* UABUtilityFactorBase::GetPrivateStaticClass()
{
	using TClass = UABUtilityFactorBase;
	if (!Z_Registration_Info_UClass_UABUtilityFactorBase.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilityFactorBase"),
			Z_Registration_Info_UClass_UABUtilityFactorBase.InnerSingleton,
			StaticRegisterNativesUABUtilityFactorBase,
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
	return Z_Registration_Info_UClass_UABUtilityFactorBase.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilityFactorBase_NoRegister()
{
	return UABUtilityFactorBase::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilityFactorBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Factor for determining the score of an action\n */" },
		{ "IncludePath", "Actions/Factors/ABUtilityFactorBase.h" },
		{ "ModuleRelativePath", "Public/Actions/Factors/ABUtilityFactorBase.h" },
		{ "ToolTip", "Factor for determining the score of an action" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bInverseScore_MetaData[] = {
		{ "Category", "Scoring" },
		{ "Comment", "// Inlines\n" },
		{ "ModuleRelativePath", "Public/Actions/Factors/ABUtilityFactorBase.h" },
		{ "ToolTip", "Inlines" },
	};
#endif // WITH_METADATA
	static void NewProp_bInverseScore_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInverseScore;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilityFactorBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UABUtilityFactorBase_Statics::NewProp_bInverseScore_SetBit(void* Obj)
{
	((UABUtilityFactorBase*)Obj)->bInverseScore = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UABUtilityFactorBase_Statics::NewProp_bInverseScore = { "bInverseScore", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(uint8), sizeof(UABUtilityFactorBase), &Z_Construct_UClass_UABUtilityFactorBase_Statics::NewProp_bInverseScore_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bInverseScore_MetaData), NewProp_bInverseScore_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABUtilityFactorBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityFactorBase_Statics::NewProp_bInverseScore,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityFactorBase_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UABUtilityFactorBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityFactorBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilityFactorBase_Statics::ClassParams = {
	&UABUtilityFactorBase::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UABUtilityFactorBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityFactorBase_Statics::PropPointers),
	0,
	0x001010A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityFactorBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilityFactorBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilityFactorBase()
{
	if (!Z_Registration_Info_UClass_UABUtilityFactorBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilityFactorBase.OuterSingleton, Z_Construct_UClass_UABUtilityFactorBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilityFactorBase.OuterSingleton;
}
UABUtilityFactorBase::UABUtilityFactorBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilityFactorBase);
UABUtilityFactorBase::~UABUtilityFactorBase() {}
// ********** End Class UABUtilityFactorBase *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Factors_ABUtilityFactorBase_h__Script_AxelaBrockettUtilityAIBase_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UABUtilityFactorBase, UABUtilityFactorBase::StaticClass, TEXT("UABUtilityFactorBase"), &Z_Registration_Info_UClass_UABUtilityFactorBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilityFactorBase), 3839878289U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Factors_ABUtilityFactorBase_h__Script_AxelaBrockettUtilityAIBase_3731072198(TEXT("/Script/AxelaBrockettUtilityAIBase"),
	Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Factors_ABUtilityFactorBase_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Factors_ABUtilityFactorBase_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
