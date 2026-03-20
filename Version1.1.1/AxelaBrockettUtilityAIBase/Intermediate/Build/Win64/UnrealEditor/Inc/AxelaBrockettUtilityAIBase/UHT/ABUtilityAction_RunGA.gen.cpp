// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/Actions/Examples/ABUtilityAction_RunGA.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeABUtilityAction_RunGA() {}

// ********** Begin Cross Module References ********************************************************
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityAction_RunGameplayAbility();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionBase();
AXELABROCKETTUTILITYAIBASE_API UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityRunGAFromType();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayAbility_NoRegister();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
UPackage* Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EABUtilityRunGAFromType ***************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EABUtilityRunGAFromType;
static UEnum* EABUtilityRunGAFromType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EABUtilityRunGAFromType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EABUtilityRunGAFromType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityRunGAFromType, (UObject*)Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase(), TEXT("EABUtilityRunGAFromType"));
	}
	return Z_Registration_Info_UEnum_EABUtilityRunGAFromType.OuterSingleton;
}
template<> AXELABROCKETTUTILITYAIBASE_API UEnum* StaticEnum<EABUtilityRunGAFromType>()
{
	return EABUtilityRunGAFromType_StaticEnum();
}
struct Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityRunGAFromType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Class.Name", "EABUtilityRunGAFromType::Class" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_RunGA.h" },
		{ "Tag.Name", "EABUtilityRunGAFromType::Tag" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EABUtilityRunGAFromType::Tag", (int64)EABUtilityRunGAFromType::Tag },
		{ "EABUtilityRunGAFromType::Class", (int64)EABUtilityRunGAFromType::Class },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityRunGAFromType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
	nullptr,
	"EABUtilityRunGAFromType",
	"EABUtilityRunGAFromType",
	Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityRunGAFromType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityRunGAFromType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityRunGAFromType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityRunGAFromType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityRunGAFromType()
{
	if (!Z_Registration_Info_UEnum_EABUtilityRunGAFromType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EABUtilityRunGAFromType.InnerSingleton, Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityRunGAFromType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EABUtilityRunGAFromType.InnerSingleton;
}
// ********** End Enum EABUtilityRunGAFromType *****************************************************

// ********** Begin Class UABUtilityAction_RunGameplayAbility **************************************
void UABUtilityAction_RunGameplayAbility::StaticRegisterNativesUABUtilityAction_RunGameplayAbility()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilityAction_RunGameplayAbility;
UClass* UABUtilityAction_RunGameplayAbility::GetPrivateStaticClass()
{
	using TClass = UABUtilityAction_RunGameplayAbility;
	if (!Z_Registration_Info_UClass_UABUtilityAction_RunGameplayAbility.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilityAction_RunGameplayAbility"),
			Z_Registration_Info_UClass_UABUtilityAction_RunGameplayAbility.InnerSingleton,
			StaticRegisterNativesUABUtilityAction_RunGameplayAbility,
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
	return Z_Registration_Info_UClass_UABUtilityAction_RunGameplayAbility.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_NoRegister()
{
	return UABUtilityAction_RunGameplayAbility::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Actions/Actions/Examples/ABUtilityAction_RunGA.h" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_RunGA.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RunGameplayAbilityFrom_MetaData[] = {
		{ "Category", "Utility Run Gameplay Ability" },
		{ "Comment", "// The method to use to try and run a Gameplay Ability\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_RunGA.h" },
		{ "ToolTip", "The method to use to try and run a Gameplay Ability" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClassOfGameplayAbilityToRun_MetaData[] = {
		{ "Category", "Utility Run Gameplay Ability" },
		{ "Comment", "// The class of Gameplay Ability to run\n" },
		{ "EditCondition", "RunGameplayAbilityFrom==EABUtilityRunGAFromType::Class" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_RunGA.h" },
		{ "ToolTip", "The class of Gameplay Ability to run" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TagsOfGameplayAbilitiesToRun_MetaData[] = {
		{ "Category", "Utility Run Gameplay Ability" },
		{ "Comment", "// The Gameplay Tags to match and find Gameplay Abilities to run\n" },
		{ "EditCondition", "RunGameplayAbilityFrom==EABUtilityRunGAFromType::Tag" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_RunGA.h" },
		{ "ToolTip", "The Gameplay Tags to match and find Gameplay Abilities to run" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bGiveAbilityIfNotOwned_MetaData[] = {
		{ "Category", "Utility Run Gameplay Ability" },
		{ "Comment", "// If the Actor does not own the chosen Gameplay Ability, give them the Ability\n" },
		{ "EditCondition", "RunGameplayAbilityFrom==EABUtilityRunGAFromType::Class" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_RunGA.h" },
		{ "ToolTip", "If the Actor does not own the chosen Gameplay Ability, give them the Ability" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_RunGameplayAbilityFrom_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_RunGameplayAbilityFrom;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ClassOfGameplayAbilityToRun;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TagsOfGameplayAbilitiesToRun;
	static void NewProp_bGiveAbilityIfNotOwned_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bGiveAbilityIfNotOwned;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilityAction_RunGameplayAbility>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_Statics::NewProp_RunGameplayAbilityFrom_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_Statics::NewProp_RunGameplayAbilityFrom = { "RunGameplayAbilityFrom", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_RunGameplayAbility, RunGameplayAbilityFrom), Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityRunGAFromType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RunGameplayAbilityFrom_MetaData), NewProp_RunGameplayAbilityFrom_MetaData) }; // 1627522169
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_Statics::NewProp_ClassOfGameplayAbilityToRun = { "ClassOfGameplayAbilityToRun", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_RunGameplayAbility, ClassOfGameplayAbilityToRun), Z_Construct_UClass_UClass, Z_Construct_UClass_UGameplayAbility_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClassOfGameplayAbilityToRun_MetaData), NewProp_ClassOfGameplayAbilityToRun_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_Statics::NewProp_TagsOfGameplayAbilitiesToRun = { "TagsOfGameplayAbilitiesToRun", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_RunGameplayAbility, TagsOfGameplayAbilitiesToRun), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TagsOfGameplayAbilitiesToRun_MetaData), NewProp_TagsOfGameplayAbilitiesToRun_MetaData) }; // 2104890724
void Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_Statics::NewProp_bGiveAbilityIfNotOwned_SetBit(void* Obj)
{
	((UABUtilityAction_RunGameplayAbility*)Obj)->bGiveAbilityIfNotOwned = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_Statics::NewProp_bGiveAbilityIfNotOwned = { "bGiveAbilityIfNotOwned", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UABUtilityAction_RunGameplayAbility), &Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_Statics::NewProp_bGiveAbilityIfNotOwned_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bGiveAbilityIfNotOwned_MetaData), NewProp_bGiveAbilityIfNotOwned_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_Statics::NewProp_RunGameplayAbilityFrom_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_Statics::NewProp_RunGameplayAbilityFrom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_Statics::NewProp_ClassOfGameplayAbilityToRun,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_Statics::NewProp_TagsOfGameplayAbilitiesToRun,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_Statics::NewProp_bGiveAbilityIfNotOwned,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UABUtilityActionBase,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_Statics::ClassParams = {
	&UABUtilityAction_RunGameplayAbility::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_Statics::PropPointers),
	0,
	0x009010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilityAction_RunGameplayAbility()
{
	if (!Z_Registration_Info_UClass_UABUtilityAction_RunGameplayAbility.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilityAction_RunGameplayAbility.OuterSingleton, Z_Construct_UClass_UABUtilityAction_RunGameplayAbility_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilityAction_RunGameplayAbility.OuterSingleton;
}
UABUtilityAction_RunGameplayAbility::UABUtilityAction_RunGameplayAbility() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilityAction_RunGameplayAbility);
UABUtilityAction_RunGameplayAbility::~UABUtilityAction_RunGameplayAbility() {}
// ********** End Class UABUtilityAction_RunGameplayAbility ****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_RunGA_h__Script_AxelaBrockettUtilityAIBase_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EABUtilityRunGAFromType_StaticEnum, TEXT("EABUtilityRunGAFromType"), &Z_Registration_Info_UEnum_EABUtilityRunGAFromType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1627522169U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UABUtilityAction_RunGameplayAbility, UABUtilityAction_RunGameplayAbility::StaticClass, TEXT("UABUtilityAction_RunGameplayAbility"), &Z_Registration_Info_UClass_UABUtilityAction_RunGameplayAbility, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilityAction_RunGameplayAbility), 3117239823U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_RunGA_h__Script_AxelaBrockettUtilityAIBase_2180363313(TEXT("/Script/AxelaBrockettUtilityAIBase"),
	Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_RunGA_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_RunGA_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_RunGA_h__Script_AxelaBrockettUtilityAIBase_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_RunGA_h__Script_AxelaBrockettUtilityAIBase_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
