// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/Actions/Examples/ABUtilityAction_RunDynamicST.h"
#include "GameplayTagContainer.h"
#include "StateTreeInstanceData.h"
#include "StateTreeReference.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeABUtilityAction_RunDynamicST() {}

// ********** Begin Cross Module References ********************************************************
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityAction_RunDynamicStateTree();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityAction_RunDynamicStateTree_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionBase();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionInstanceMemoryBase();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionRunDynamicSTIM();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionRunDynamicSTIM_NoRegister();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
STATETREEMODULE_API UScriptStruct* Z_Construct_UScriptStruct_FStateTreeInstanceData();
STATETREEMODULE_API UScriptStruct* Z_Construct_UScriptStruct_FStateTreeReference();
UPackage* Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UABUtilityActionRunDynamicSTIM *******************************************
void UABUtilityActionRunDynamicSTIM::StaticRegisterNativesUABUtilityActionRunDynamicSTIM()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilityActionRunDynamicSTIM;
UClass* UABUtilityActionRunDynamicSTIM::GetPrivateStaticClass()
{
	using TClass = UABUtilityActionRunDynamicSTIM;
	if (!Z_Registration_Info_UClass_UABUtilityActionRunDynamicSTIM.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilityActionRunDynamicSTIM"),
			Z_Registration_Info_UClass_UABUtilityActionRunDynamicSTIM.InnerSingleton,
			StaticRegisterNativesUABUtilityActionRunDynamicSTIM,
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
	return Z_Registration_Info_UClass_UABUtilityActionRunDynamicSTIM.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilityActionRunDynamicSTIM_NoRegister()
{
	return UABUtilityActionRunDynamicSTIM::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilityActionRunDynamicSTIM_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Actions/Actions/Examples/ABUtilityAction_RunDynamicST.h" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_RunDynamicST.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstanceData_MetaData[] = {
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_RunDynamicST.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InstanceData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilityActionRunDynamicSTIM>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityActionRunDynamicSTIM_Statics::NewProp_InstanceData = { "InstanceData", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityActionRunDynamicSTIM, InstanceData), Z_Construct_UScriptStruct_FStateTreeInstanceData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstanceData_MetaData), NewProp_InstanceData_MetaData) }; // 300993340
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABUtilityActionRunDynamicSTIM_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityActionRunDynamicSTIM_Statics::NewProp_InstanceData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityActionRunDynamicSTIM_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UABUtilityActionRunDynamicSTIM_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UABUtilityActionInstanceMemoryBase,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityActionRunDynamicSTIM_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilityActionRunDynamicSTIM_Statics::ClassParams = {
	&UABUtilityActionRunDynamicSTIM::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UABUtilityActionRunDynamicSTIM_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityActionRunDynamicSTIM_Statics::PropPointers),
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityActionRunDynamicSTIM_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilityActionRunDynamicSTIM_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilityActionRunDynamicSTIM()
{
	if (!Z_Registration_Info_UClass_UABUtilityActionRunDynamicSTIM.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilityActionRunDynamicSTIM.OuterSingleton, Z_Construct_UClass_UABUtilityActionRunDynamicSTIM_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilityActionRunDynamicSTIM.OuterSingleton;
}
UABUtilityActionRunDynamicSTIM::UABUtilityActionRunDynamicSTIM(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilityActionRunDynamicSTIM);
UABUtilityActionRunDynamicSTIM::~UABUtilityActionRunDynamicSTIM() {}
// ********** End Class UABUtilityActionRunDynamicSTIM *********************************************

// ********** Begin Class UABUtilityAction_RunDynamicStateTree *************************************
void UABUtilityAction_RunDynamicStateTree::StaticRegisterNativesUABUtilityAction_RunDynamicStateTree()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilityAction_RunDynamicStateTree;
UClass* UABUtilityAction_RunDynamicStateTree::GetPrivateStaticClass()
{
	using TClass = UABUtilityAction_RunDynamicStateTree;
	if (!Z_Registration_Info_UClass_UABUtilityAction_RunDynamicStateTree.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilityAction_RunDynamicStateTree"),
			Z_Registration_Info_UClass_UABUtilityAction_RunDynamicStateTree.InnerSingleton,
			StaticRegisterNativesUABUtilityAction_RunDynamicStateTree,
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
	return Z_Registration_Info_UClass_UABUtilityAction_RunDynamicStateTree.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilityAction_RunDynamicStateTree_NoRegister()
{
	return UABUtilityAction_RunDynamicStateTree::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilityAction_RunDynamicStateTree_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Actions/Actions/Examples/ABUtilityAction_RunDynamicST.h" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_RunDynamicST.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InjectionTag_MetaData[] = {
		{ "Category", "Utility Run Dynamic ST" },
		{ "Comment", "// The tag to use to inject a State Tree at run time\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_RunDynamicST.h" },
		{ "ToolTip", "The tag to use to inject a State Tree at run time" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StateTreeRef_MetaData[] = {
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_RunDynamicST.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InjectionTag;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StateTreeRef;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilityAction_RunDynamicStateTree>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_RunDynamicStateTree_Statics::NewProp_InjectionTag = { "InjectionTag", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_RunDynamicStateTree, InjectionTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InjectionTag_MetaData), NewProp_InjectionTag_MetaData) }; // 133831994
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_RunDynamicStateTree_Statics::NewProp_StateTreeRef = { "StateTreeRef", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_RunDynamicStateTree, StateTreeRef), Z_Construct_UScriptStruct_FStateTreeReference, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StateTreeRef_MetaData), NewProp_StateTreeRef_MetaData) }; // 1846190055
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABUtilityAction_RunDynamicStateTree_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_RunDynamicStateTree_Statics::NewProp_InjectionTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_RunDynamicStateTree_Statics::NewProp_StateTreeRef,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityAction_RunDynamicStateTree_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UABUtilityAction_RunDynamicStateTree_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UABUtilityActionBase,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityAction_RunDynamicStateTree_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilityAction_RunDynamicStateTree_Statics::ClassParams = {
	&UABUtilityAction_RunDynamicStateTree::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UABUtilityAction_RunDynamicStateTree_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityAction_RunDynamicStateTree_Statics::PropPointers),
	0,
	0x009010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityAction_RunDynamicStateTree_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilityAction_RunDynamicStateTree_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilityAction_RunDynamicStateTree()
{
	if (!Z_Registration_Info_UClass_UABUtilityAction_RunDynamicStateTree.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilityAction_RunDynamicStateTree.OuterSingleton, Z_Construct_UClass_UABUtilityAction_RunDynamicStateTree_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilityAction_RunDynamicStateTree.OuterSingleton;
}
UABUtilityAction_RunDynamicStateTree::UABUtilityAction_RunDynamicStateTree() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilityAction_RunDynamicStateTree);
UABUtilityAction_RunDynamicStateTree::~UABUtilityAction_RunDynamicStateTree() {}
// ********** End Class UABUtilityAction_RunDynamicStateTree ***************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_RunDynamicST_h__Script_AxelaBrockettUtilityAIBase_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UABUtilityActionRunDynamicSTIM, UABUtilityActionRunDynamicSTIM::StaticClass, TEXT("UABUtilityActionRunDynamicSTIM"), &Z_Registration_Info_UClass_UABUtilityActionRunDynamicSTIM, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilityActionRunDynamicSTIM), 387680942U) },
		{ Z_Construct_UClass_UABUtilityAction_RunDynamicStateTree, UABUtilityAction_RunDynamicStateTree::StaticClass, TEXT("UABUtilityAction_RunDynamicStateTree"), &Z_Registration_Info_UClass_UABUtilityAction_RunDynamicStateTree, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilityAction_RunDynamicStateTree), 2888392659U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_RunDynamicST_h__Script_AxelaBrockettUtilityAIBase_398651009(TEXT("/Script/AxelaBrockettUtilityAIBase"),
	Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_RunDynamicST_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_RunDynamicST_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
