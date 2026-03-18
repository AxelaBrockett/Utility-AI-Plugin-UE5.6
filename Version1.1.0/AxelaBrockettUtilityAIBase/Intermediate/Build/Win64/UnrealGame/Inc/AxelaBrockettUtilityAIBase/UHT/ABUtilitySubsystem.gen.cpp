// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Subsystems/ABUtilitySubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeABUtilitySubsystem() {}

// ********** Begin Cross Module References ********************************************************
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionBase_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionInstanceMemoryBase_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityComponent_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilitySubsystem();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilitySubsystem_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UScriptStruct* Z_Construct_UScriptStruct_FInstanceMemoryWrapper();
ENGINE_API UClass* Z_Construct_UClass_UTickableWorldSubsystem();
UPackage* Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FInstanceMemoryWrapper ********************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FInstanceMemoryWrapper;
class UScriptStruct* FInstanceMemoryWrapper::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FInstanceMemoryWrapper.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FInstanceMemoryWrapper.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FInstanceMemoryWrapper, (UObject*)Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase(), TEXT("InstanceMemoryWrapper"));
	}
	return Z_Registration_Info_UScriptStruct_FInstanceMemoryWrapper.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FInstanceMemoryWrapper_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Subsystems/ABUtilitySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ComponentInstanceMemory_MetaData[] = {
		{ "ModuleRelativePath", "Public/Subsystems/ABUtilitySubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ComponentInstanceMemory_ValueProp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ComponentInstanceMemory_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ComponentInstanceMemory;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FInstanceMemoryWrapper>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FInstanceMemoryWrapper_Statics::NewProp_ComponentInstanceMemory_ValueProp = { "ComponentInstanceMemory", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UABUtilityActionInstanceMemoryBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FInstanceMemoryWrapper_Statics::NewProp_ComponentInstanceMemory_Key_KeyProp = { "ComponentInstanceMemory_Key", nullptr, (EPropertyFlags)0x0000000000080000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UABUtilityComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FInstanceMemoryWrapper_Statics::NewProp_ComponentInstanceMemory = { "ComponentInstanceMemory", nullptr, (EPropertyFlags)0x0010008000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInstanceMemoryWrapper, ComponentInstanceMemory), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ComponentInstanceMemory_MetaData), NewProp_ComponentInstanceMemory_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FInstanceMemoryWrapper_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInstanceMemoryWrapper_Statics::NewProp_ComponentInstanceMemory_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInstanceMemoryWrapper_Statics::NewProp_ComponentInstanceMemory_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInstanceMemoryWrapper_Statics::NewProp_ComponentInstanceMemory,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInstanceMemoryWrapper_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FInstanceMemoryWrapper_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
	nullptr,
	&NewStructOps,
	"InstanceMemoryWrapper",
	Z_Construct_UScriptStruct_FInstanceMemoryWrapper_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInstanceMemoryWrapper_Statics::PropPointers),
	sizeof(FInstanceMemoryWrapper),
	alignof(FInstanceMemoryWrapper),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000005),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInstanceMemoryWrapper_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FInstanceMemoryWrapper_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FInstanceMemoryWrapper()
{
	if (!Z_Registration_Info_UScriptStruct_FInstanceMemoryWrapper.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FInstanceMemoryWrapper.InnerSingleton, Z_Construct_UScriptStruct_FInstanceMemoryWrapper_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FInstanceMemoryWrapper.InnerSingleton;
}
// ********** End ScriptStruct FInstanceMemoryWrapper **********************************************

// ********** Begin Class UABUtilitySubsystem ******************************************************
void UABUtilitySubsystem::StaticRegisterNativesUABUtilitySubsystem()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilitySubsystem;
UClass* UABUtilitySubsystem::GetPrivateStaticClass()
{
	using TClass = UABUtilitySubsystem;
	if (!Z_Registration_Info_UClass_UABUtilitySubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilitySubsystem"),
			Z_Registration_Info_UClass_UABUtilitySubsystem.InnerSingleton,
			StaticRegisterNativesUABUtilitySubsystem,
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
	return Z_Registration_Info_UClass_UABUtilitySubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilitySubsystem_NoRegister()
{
	return UABUtilitySubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilitySubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Subsystems/ABUtilitySubsystem.h" },
		{ "ModuleRelativePath", "Public/Subsystems/ABUtilitySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActionComponentInstanceMemory_MetaData[] = {
		{ "Comment", "// Actions\n" },
		{ "ModuleRelativePath", "Public/Subsystems/ABUtilitySubsystem.h" },
		{ "ToolTip", "Actions" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActionComponentInstanceMemory_ValueProp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActionComponentInstanceMemory_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ActionComponentInstanceMemory;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilitySubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilitySubsystem_Statics::NewProp_ActionComponentInstanceMemory_ValueProp = { "ActionComponentInstanceMemory", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FInstanceMemoryWrapper, METADATA_PARAMS(0, nullptr) }; // 2871670694
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABUtilitySubsystem_Statics::NewProp_ActionComponentInstanceMemory_Key_KeyProp = { "ActionComponentInstanceMemory_Key", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UABUtilityActionBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UABUtilitySubsystem_Statics::NewProp_ActionComponentInstanceMemory = { "ActionComponentInstanceMemory", nullptr, (EPropertyFlags)0x0040008000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilitySubsystem, ActionComponentInstanceMemory), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActionComponentInstanceMemory_MetaData), NewProp_ActionComponentInstanceMemory_MetaData) }; // 2871670694
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABUtilitySubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilitySubsystem_Statics::NewProp_ActionComponentInstanceMemory_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilitySubsystem_Statics::NewProp_ActionComponentInstanceMemory_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilitySubsystem_Statics::NewProp_ActionComponentInstanceMemory,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilitySubsystem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UABUtilitySubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UTickableWorldSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilitySubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilitySubsystem_Statics::ClassParams = {
	&UABUtilitySubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UABUtilitySubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilitySubsystem_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilitySubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilitySubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilitySubsystem()
{
	if (!Z_Registration_Info_UClass_UABUtilitySubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilitySubsystem.OuterSingleton, Z_Construct_UClass_UABUtilitySubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilitySubsystem.OuterSingleton;
}
UABUtilitySubsystem::UABUtilitySubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilitySubsystem);
UABUtilitySubsystem::~UABUtilitySubsystem() {}
// ********** End Class UABUtilitySubsystem ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Subsystems_ABUtilitySubsystem_h__Script_AxelaBrockettUtilityAIBase_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FInstanceMemoryWrapper::StaticStruct, Z_Construct_UScriptStruct_FInstanceMemoryWrapper_Statics::NewStructOps, TEXT("InstanceMemoryWrapper"), &Z_Registration_Info_UScriptStruct_FInstanceMemoryWrapper, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FInstanceMemoryWrapper), 2871670694U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UABUtilitySubsystem, UABUtilitySubsystem::StaticClass, TEXT("UABUtilitySubsystem"), &Z_Registration_Info_UClass_UABUtilitySubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilitySubsystem), 2497221189U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Subsystems_ABUtilitySubsystem_h__Script_AxelaBrockettUtilityAIBase_1651833044(TEXT("/Script/AxelaBrockettUtilityAIBase"),
	Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Subsystems_ABUtilitySubsystem_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Subsystems_ABUtilitySubsystem_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Subsystems_ABUtilitySubsystem_h__Script_AxelaBrockettUtilityAIBase_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Subsystems_ABUtilitySubsystem_h__Script_AxelaBrockettUtilityAIBase_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
