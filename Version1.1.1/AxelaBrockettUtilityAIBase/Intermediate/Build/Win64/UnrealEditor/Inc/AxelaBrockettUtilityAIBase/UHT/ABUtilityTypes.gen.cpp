// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Helpers/ABUtilityTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeABUtilityTypes() {}

// ********** Begin Cross Module References ********************************************************
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionInstanceMemoryBase();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionInstanceMemoryBase_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABActionSelectionMode();
AXELABROCKETTUTILITYAIBASE_API UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityAbortActionLogic();
AXELABROCKETTUTILITYAIBASE_API UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityActionRunStatus();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
UPackage* Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EABUtilityActionRunStatus *************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EABUtilityActionRunStatus;
static UEnum* EABUtilityActionRunStatus_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EABUtilityActionRunStatus.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EABUtilityActionRunStatus.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityActionRunStatus, (UObject*)Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase(), TEXT("EABUtilityActionRunStatus"));
	}
	return Z_Registration_Info_UEnum_EABUtilityActionRunStatus.OuterSingleton;
}
template<> AXELABROCKETTUTILITYAIBASE_API UEnum* StaticEnum<EABUtilityActionRunStatus>()
{
	return EABUtilityActionRunStatus_StaticEnum();
}
struct Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityActionRunStatus_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/*\n* Enums\n*/" },
		{ "Failed.Name", "EABUtilityActionRunStatus::Failed" },
		{ "ModuleRelativePath", "Public/Helpers/ABUtilityTypes.h" },
		{ "NotRunning.Name", "EABUtilityActionRunStatus::NotRunning" },
		{ "Running.Name", "EABUtilityActionRunStatus::Running" },
		{ "Succeeded.Name", "EABUtilityActionRunStatus::Succeeded" },
		{ "ToolTip", "* Enums" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EABUtilityActionRunStatus::NotRunning", (int64)EABUtilityActionRunStatus::NotRunning },
		{ "EABUtilityActionRunStatus::Running", (int64)EABUtilityActionRunStatus::Running },
		{ "EABUtilityActionRunStatus::Succeeded", (int64)EABUtilityActionRunStatus::Succeeded },
		{ "EABUtilityActionRunStatus::Failed", (int64)EABUtilityActionRunStatus::Failed },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityActionRunStatus_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
	nullptr,
	"EABUtilityActionRunStatus",
	"EABUtilityActionRunStatus",
	Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityActionRunStatus_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityActionRunStatus_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityActionRunStatus_Statics::Enum_MetaDataParams), Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityActionRunStatus_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityActionRunStatus()
{
	if (!Z_Registration_Info_UEnum_EABUtilityActionRunStatus.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EABUtilityActionRunStatus.InnerSingleton, Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityActionRunStatus_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EABUtilityActionRunStatus.InnerSingleton;
}
// ********** End Enum EABUtilityActionRunStatus ***************************************************

// ********** Begin Enum EABUtilityAbortActionLogic ************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EABUtilityAbortActionLogic;
static UEnum* EABUtilityAbortActionLogic_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EABUtilityAbortActionLogic.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EABUtilityAbortActionLogic.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityAbortActionLogic, (UObject*)Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase(), TEXT("EABUtilityAbortActionLogic"));
	}
	return Z_Registration_Info_UEnum_EABUtilityAbortActionLogic.OuterSingleton;
}
template<> AXELABROCKETTUTILITYAIBASE_API UEnum* StaticEnum<EABUtilityAbortActionLogic>()
{
	return EABUtilityAbortActionLogic_StaticEnum();
}
struct Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityAbortActionLogic_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "ChooseNewAction.Name", "EABUtilityAbortActionLogic::ChooseNewAction" },
		{ "ModuleRelativePath", "Public/Helpers/ABUtilityTypes.h" },
		{ "PauseLogicAbortAction.Name", "EABUtilityAbortActionLogic::PauseLogicAbortAction" },
		{ "PauseLogicPauseAction.Name", "EABUtilityAbortActionLogic::PauseLogicPauseAction" },
		{ "StopComponent.Name", "EABUtilityAbortActionLogic::StopComponent" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EABUtilityAbortActionLogic::StopComponent", (int64)EABUtilityAbortActionLogic::StopComponent },
		{ "EABUtilityAbortActionLogic::PauseLogicPauseAction", (int64)EABUtilityAbortActionLogic::PauseLogicPauseAction },
		{ "EABUtilityAbortActionLogic::PauseLogicAbortAction", (int64)EABUtilityAbortActionLogic::PauseLogicAbortAction },
		{ "EABUtilityAbortActionLogic::ChooseNewAction", (int64)EABUtilityAbortActionLogic::ChooseNewAction },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityAbortActionLogic_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
	nullptr,
	"EABUtilityAbortActionLogic",
	"EABUtilityAbortActionLogic",
	Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityAbortActionLogic_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityAbortActionLogic_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityAbortActionLogic_Statics::Enum_MetaDataParams), Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityAbortActionLogic_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityAbortActionLogic()
{
	if (!Z_Registration_Info_UEnum_EABUtilityAbortActionLogic.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EABUtilityAbortActionLogic.InnerSingleton, Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityAbortActionLogic_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EABUtilityAbortActionLogic.InnerSingleton;
}
// ********** End Enum EABUtilityAbortActionLogic **************************************************

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
		{ "BlueprintType", "true" },
		{ "HighestScore.DisplayName", "Highest Scoring" },
		{ "HighestScore.Name", "EABActionSelectionMode::HighestScore" },
		{ "HighestScore.ToolTip", "Will attempt to run actions starting from the highest scoring" },
		{ "ModuleRelativePath", "Public/Helpers/ABUtilityTypes.h" },
		{ "RandomFromTop10Pct.DisplayName", "Random From Top 10%" },
		{ "RandomFromTop10Pct.Name", "EABActionSelectionMode::RandomFromTop10Pct" },
		{ "RandomFromTop10Pct.ToolTip", "Will get the top 10% scoring actions, randomly sort them, then attempt to run them" },
		{ "RandomFromTop25Pct.DisplayName", "Random From Top 25%" },
		{ "RandomFromTop25Pct.Name", "EABActionSelectionMode::RandomFromTop25Pct" },
		{ "RandomFromTop25Pct.ToolTip", "Will get the top 25% scoring actions, randomly sort them, then attempt to run them" },
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

// ********** Begin Class UABUtilityActionInstanceMemoryBase ***************************************
void UABUtilityActionInstanceMemoryBase::StaticRegisterNativesUABUtilityActionInstanceMemoryBase()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilityActionInstanceMemoryBase;
UClass* UABUtilityActionInstanceMemoryBase::GetPrivateStaticClass()
{
	using TClass = UABUtilityActionInstanceMemoryBase;
	if (!Z_Registration_Info_UClass_UABUtilityActionInstanceMemoryBase.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilityActionInstanceMemoryBase"),
			Z_Registration_Info_UClass_UABUtilityActionInstanceMemoryBase.InnerSingleton,
			StaticRegisterNativesUABUtilityActionInstanceMemoryBase,
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
	return Z_Registration_Info_UClass_UABUtilityActionInstanceMemoryBase.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilityActionInstanceMemoryBase_NoRegister()
{
	return UABUtilityActionInstanceMemoryBase::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilityActionInstanceMemoryBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/*\n* Classes\n*/" },
		{ "IncludePath", "Helpers/ABUtilityTypes.h" },
		{ "ModuleRelativePath", "Public/Helpers/ABUtilityTypes.h" },
		{ "ToolTip", "* Classes" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilityActionInstanceMemoryBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UABUtilityActionInstanceMemoryBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityActionInstanceMemoryBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilityActionInstanceMemoryBase_Statics::ClassParams = {
	&UABUtilityActionInstanceMemoryBase::StaticClass,
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
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityActionInstanceMemoryBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilityActionInstanceMemoryBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilityActionInstanceMemoryBase()
{
	if (!Z_Registration_Info_UClass_UABUtilityActionInstanceMemoryBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilityActionInstanceMemoryBase.OuterSingleton, Z_Construct_UClass_UABUtilityActionInstanceMemoryBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilityActionInstanceMemoryBase.OuterSingleton;
}
UABUtilityActionInstanceMemoryBase::UABUtilityActionInstanceMemoryBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilityActionInstanceMemoryBase);
UABUtilityActionInstanceMemoryBase::~UABUtilityActionInstanceMemoryBase() {}
// ********** End Class UABUtilityActionInstanceMemoryBase *****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Helpers_ABUtilityTypes_h__Script_AxelaBrockettUtilityAIBase_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EABUtilityActionRunStatus_StaticEnum, TEXT("EABUtilityActionRunStatus"), &Z_Registration_Info_UEnum_EABUtilityActionRunStatus, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 422754709U) },
		{ EABUtilityAbortActionLogic_StaticEnum, TEXT("EABUtilityAbortActionLogic"), &Z_Registration_Info_UEnum_EABUtilityAbortActionLogic, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2635248477U) },
		{ EABActionSelectionMode_StaticEnum, TEXT("EABActionSelectionMode"), &Z_Registration_Info_UEnum_EABActionSelectionMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1120867461U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UABUtilityActionInstanceMemoryBase, UABUtilityActionInstanceMemoryBase::StaticClass, TEXT("UABUtilityActionInstanceMemoryBase"), &Z_Registration_Info_UClass_UABUtilityActionInstanceMemoryBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilityActionInstanceMemoryBase), 2347871642U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Helpers_ABUtilityTypes_h__Script_AxelaBrockettUtilityAIBase_1135210122(TEXT("/Script/AxelaBrockettUtilityAIBase"),
	Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Helpers_ABUtilityTypes_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Helpers_ABUtilityTypes_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Helpers_ABUtilityTypes_h__Script_AxelaBrockettUtilityAIBase_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Helpers_ABUtilityTypes_h__Script_AxelaBrockettUtilityAIBase_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
