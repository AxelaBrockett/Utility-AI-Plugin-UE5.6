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
AXELABROCKETTUTILITYAIBASE_API UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABActionSelectionMode();
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
UPackage* Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EABActionSelectionMode ****************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EABActionSelectionMode;
static UEnum* EABActionSelectionMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EABActionSelectionMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EABActionSelectionMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABActionSelectionMode, (UObject*)Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase(), TEXT("EABActionSelectionMode"));
	}
	return Z_Registration_Info_UEnum_EABActionSelectionMode.OuterSingleton;
}
template<> AXELABROCKETTUTILITYAIBASE_API UEnum* StaticEnum<EABActionSelectionMode>()
{
	return EABActionSelectionMode_StaticEnum();
}
struct Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABActionSelectionMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Comment", "// The possible methods for selecting actions\n" },
		{ "HighestScore.DisplayName", "Highest Scoring" },
		{ "HighestScore.Name", "EABActionSelectionMode::HighestScore" },
		{ "HighestScore.ToolTip", "Will attempt to run actions starting from the highest scoring" },
		{ "ModuleRelativePath", "Public/DataAssets/ABUtilityDataAsset.h" },
		{ "RandomFromTop10Pct.DisplayName", "Random From Top 10%" },
		{ "RandomFromTop10Pct.Name", "EABActionSelectionMode::RandomFromTop10Pct" },
		{ "RandomFromTop10Pct.ToolTip", "Will get the top 10% scoring actions, randomly sort them, then attempt to run them" },
		{ "RandomFromTop25Pct.DisplayName", "Random From Top 25%" },
		{ "RandomFromTop25Pct.Name", "EABActionSelectionMode::RandomFromTop25Pct" },
		{ "RandomFromTop25Pct.ToolTip", "Will get the top 25% scoring actions, randomly sort them, then attempt to run them" },
		{ "ToolTip", "The possible methods for selecting actions" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EABActionSelectionMode::HighestScore", (int64)EABActionSelectionMode::HighestScore },
		{ "EABActionSelectionMode::RandomFromTop10Pct", (int64)EABActionSelectionMode::RandomFromTop10Pct },
		{ "EABActionSelectionMode::RandomFromTop25Pct", (int64)EABActionSelectionMode::RandomFromTop25Pct },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABActionSelectionMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
	nullptr,
	"EABActionSelectionMode",
	"EABActionSelectionMode",
	Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABActionSelectionMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABActionSelectionMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABActionSelectionMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABActionSelectionMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABActionSelectionMode()
{
	if (!Z_Registration_Info_UEnum_EABActionSelectionMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EABActionSelectionMode.InnerSingleton, Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABActionSelectionMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EABActionSelectionMode.InnerSingleton;
}
// ********** End Enum EABActionSelectionMode ******************************************************

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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActionSelectionMode_MetaData[] = {
		{ "Category", "Utility Actions" },
		{ "Comment", "// The method for selecting actions\n" },
		{ "ModuleRelativePath", "Public/DataAssets/ABUtilityDataAsset.h" },
		{ "ToolTip", "The method for selecting actions" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UtilityActions_Inner_MetaData[] = {
		{ "Category", "Utility Actions" },
		{ "Comment", "// Actions available to agents using this data asset\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DataAssets/ABUtilityDataAsset.h" },
		{ "ToolTip", "Actions available to agents using this data asset" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UtilityActions_MetaData[] = {
		{ "Category", "Utility Actions" },
		{ "Comment", "// Actions available to agents using this data asset\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DataAssets/ABUtilityDataAsset.h" },
		{ "ToolTip", "Actions available to agents using this data asset" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseConsiderationFactor_MetaData[] = {
		{ "Category", "Scoring" },
		{ "Comment", "// Enabling this will make all Factors within all Actions use the Consideration Factor score modifier\n" },
		{ "ModuleRelativePath", "Public/DataAssets/ABUtilityDataAsset.h" },
		{ "ToolTip", "Enabling this will make all Factors within all Actions use the Consideration Factor score modifier" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ActionSelectionMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ActionSelectionMode;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UtilityActions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_UtilityActions;
	static void NewProp_bUseConsiderationFactor_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseConsiderationFactor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilityDataAsset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UABUtilityDataAsset_Statics::NewProp_ActionSelectionMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UABUtilityDataAsset_Statics::NewProp_ActionSelectionMode = { "ActionSelectionMode", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityDataAsset, ActionSelectionMode), Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABActionSelectionMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActionSelectionMode_MetaData), NewProp_ActionSelectionMode_MetaData) }; // 1396463637
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABUtilityDataAsset_Statics::NewProp_UtilityActions_Inner = { "UtilityActions", nullptr, (EPropertyFlags)0x0106000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UABUtilityActionBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UtilityActions_Inner_MetaData), NewProp_UtilityActions_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UABUtilityDataAsset_Statics::NewProp_UtilityActions = { "UtilityActions", nullptr, (EPropertyFlags)0x0144008000000009, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityDataAsset, UtilityActions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UtilityActions_MetaData), NewProp_UtilityActions_MetaData) };
void Z_Construct_UClass_UABUtilityDataAsset_Statics::NewProp_bUseConsiderationFactor_SetBit(void* Obj)
{
	((UABUtilityDataAsset*)Obj)->bUseConsiderationFactor = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UABUtilityDataAsset_Statics::NewProp_bUseConsiderationFactor = { "bUseConsiderationFactor", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UABUtilityDataAsset), &Z_Construct_UClass_UABUtilityDataAsset_Statics::NewProp_bUseConsiderationFactor_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseConsiderationFactor_MetaData), NewProp_bUseConsiderationFactor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABUtilityDataAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityDataAsset_Statics::NewProp_ActionSelectionMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityDataAsset_Statics::NewProp_ActionSelectionMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityDataAsset_Statics::NewProp_UtilityActions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityDataAsset_Statics::NewProp_UtilityActions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityDataAsset_Statics::NewProp_bUseConsiderationFactor,
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
struct Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_DataAssets_ABUtilityDataAsset_h__Script_AxelaBrockettUtilityAIBase_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EABActionSelectionMode_StaticEnum, TEXT("EABActionSelectionMode"), &Z_Registration_Info_UEnum_EABActionSelectionMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1396463637U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UABUtilityDataAsset, UABUtilityDataAsset::StaticClass, TEXT("UABUtilityDataAsset"), &Z_Registration_Info_UClass_UABUtilityDataAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilityDataAsset), 2668675380U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_DataAssets_ABUtilityDataAsset_h__Script_AxelaBrockettUtilityAIBase_847000119(TEXT("/Script/AxelaBrockettUtilityAIBase"),
	Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_DataAssets_ABUtilityDataAsset_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_DataAssets_ABUtilityDataAsset_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_DataAssets_ABUtilityDataAsset_h__Script_AxelaBrockettUtilityAIBase_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_DataAssets_ABUtilityDataAsset_h__Script_AxelaBrockettUtilityAIBase_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
