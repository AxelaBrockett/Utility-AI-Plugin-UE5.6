// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/Requirements/Examples/ABUtilityRequirement_HasActor.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeABUtilityRequirement_HasActor() {}

// ********** Begin Cross Module References ********************************************************
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityRequirement_HasActor();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityRequirement_HasActor_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityRequirementBase();
UPackage* Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UABUtilityRequirement_HasActor *******************************************
void UABUtilityRequirement_HasActor::StaticRegisterNativesUABUtilityRequirement_HasActor()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilityRequirement_HasActor;
UClass* UABUtilityRequirement_HasActor::GetPrivateStaticClass()
{
	using TClass = UABUtilityRequirement_HasActor;
	if (!Z_Registration_Info_UClass_UABUtilityRequirement_HasActor.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilityRequirement_HasActor"),
			Z_Registration_Info_UClass_UABUtilityRequirement_HasActor.InnerSingleton,
			StaticRegisterNativesUABUtilityRequirement_HasActor,
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
	return Z_Registration_Info_UClass_UABUtilityRequirement_HasActor.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilityRequirement_HasActor_NoRegister()
{
	return UABUtilityRequirement_HasActor::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilityRequirement_HasActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Agent is required to have an actor\n */" },
		{ "IncludePath", "Actions/Requirements/Examples/ABUtilityRequirement_HasActor.h" },
		{ "ModuleRelativePath", "Public/Actions/Requirements/Examples/ABUtilityRequirement_HasActor.h" },
		{ "ToolTip", "Agent is required to have an actor" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilityRequirement_HasActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UABUtilityRequirement_HasActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UABUtilityRequirementBase,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityRequirement_HasActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilityRequirement_HasActor_Statics::ClassParams = {
	&UABUtilityRequirement_HasActor::StaticClass,
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
	0x001010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityRequirement_HasActor_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilityRequirement_HasActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilityRequirement_HasActor()
{
	if (!Z_Registration_Info_UClass_UABUtilityRequirement_HasActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilityRequirement_HasActor.OuterSingleton, Z_Construct_UClass_UABUtilityRequirement_HasActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilityRequirement_HasActor.OuterSingleton;
}
UABUtilityRequirement_HasActor::UABUtilityRequirement_HasActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilityRequirement_HasActor);
UABUtilityRequirement_HasActor::~UABUtilityRequirement_HasActor() {}
// ********** End Class UABUtilityRequirement_HasActor *********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_Examples_ABUtilityRequirement_HasActor_h__Script_AxelaBrockettUtilityAIBase_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UABUtilityRequirement_HasActor, UABUtilityRequirement_HasActor::StaticClass, TEXT("UABUtilityRequirement_HasActor"), &Z_Registration_Info_UClass_UABUtilityRequirement_HasActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilityRequirement_HasActor), 2619399619U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_Examples_ABUtilityRequirement_HasActor_h__Script_AxelaBrockettUtilityAIBase_535215619(TEXT("/Script/AxelaBrockettUtilityAIBase"),
	Z_CompiledInDeferFile_FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_Examples_ABUtilityRequirement_HasActor_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_Examples_ABUtilityRequirement_HasActor_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
