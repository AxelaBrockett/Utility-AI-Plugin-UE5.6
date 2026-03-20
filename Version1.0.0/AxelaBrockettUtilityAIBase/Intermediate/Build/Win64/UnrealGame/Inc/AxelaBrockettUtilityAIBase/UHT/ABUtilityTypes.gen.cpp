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
AXELABROCKETTUTILITYAIBASE_API UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityAbortActionLogic();
AXELABROCKETTUTILITYAIBASE_API UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityActionRunStatus();
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

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Helpers_ABUtilityTypes_h__Script_AxelaBrockettUtilityAIBase_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EABUtilityActionRunStatus_StaticEnum, TEXT("EABUtilityActionRunStatus"), &Z_Registration_Info_UEnum_EABUtilityActionRunStatus, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 422754709U) },
		{ EABUtilityAbortActionLogic_StaticEnum, TEXT("EABUtilityAbortActionLogic"), &Z_Registration_Info_UEnum_EABUtilityAbortActionLogic, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2635248477U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Helpers_ABUtilityTypes_h__Script_AxelaBrockettUtilityAIBase_4279613001(TEXT("/Script/AxelaBrockettUtilityAIBase"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Helpers_ABUtilityTypes_h__Script_AxelaBrockettUtilityAIBase_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Helpers_ABUtilityTypes_h__Script_AxelaBrockettUtilityAIBase_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
