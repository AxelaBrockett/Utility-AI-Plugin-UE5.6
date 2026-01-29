// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/Actions/Examples/ABUtilityAction_ZGMoveTo.h"
#include "DataProviders/AIDataProvider.h"
#include "ZoneGraphTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeABUtilityAction_ZGMoveTo() {}

// ********** Begin Cross Module References ********************************************************
AIMODULE_API UScriptStruct* Z_Construct_UScriptStruct_FAIDataProviderBoolValue();
AIMODULE_API UScriptStruct* Z_Construct_UScriptStruct_FAIDataProviderFloatValue();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityAction_ZGMoveTo();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityAction_ZGMoveTo_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionBase();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
NAVIGATIONSYSTEM_API UClass* Z_Construct_UClass_UNavigationQueryFilter_NoRegister();
UPackage* Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase();
ZONEGRAPH_API UScriptStruct* Z_Construct_UScriptStruct_FZoneGraphTagFilter();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UABUtilityAction_ZGMoveTo ************************************************
void UABUtilityAction_ZGMoveTo::StaticRegisterNativesUABUtilityAction_ZGMoveTo()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilityAction_ZGMoveTo;
UClass* UABUtilityAction_ZGMoveTo::GetPrivateStaticClass()
{
	using TClass = UABUtilityAction_ZGMoveTo;
	if (!Z_Registration_Info_UClass_UABUtilityAction_ZGMoveTo.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilityAction_ZGMoveTo"),
			Z_Registration_Info_UClass_UABUtilityAction_ZGMoveTo.InnerSingleton,
			StaticRegisterNativesUABUtilityAction_ZGMoveTo,
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
	return Z_Registration_Info_UClass_UABUtilityAction_ZGMoveTo.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilityAction_ZGMoveTo_NoRegister()
{
	return UABUtilityAction_ZGMoveTo::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Move agent to Zone Graph location\n */" },
		{ "DisplayName", "Utility ZG Move To" },
		{ "IncludePath", "Actions/Actions/Examples/ABUtilityAction_ZGMoveTo.h" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_ZGMoveTo.h" },
		{ "ToolTip", "Move agent to Zone Graph location" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ZGQueryExtent_MetaData[] = {
		{ "Category", "Utility AI ZG Move To" },
		{ "Comment", "// The extent from the actor for which to search for Zone Graphs\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_ZGMoveTo.h" },
		{ "ToolTip", "The extent from the actor for which to search for Zone Graphs" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TagFilter_MetaData[] = {
		{ "Category", "Utility AI ZG Move To" },
		{ "Comment", "// The Zone Graphs tag requirements to include in the search\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_ZGMoveTo.h" },
		{ "ToolTip", "The Zone Graphs tag requirements to include in the search" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FilterClass_MetaData[] = {
		{ "Category", "Utility AI ZG Move To" },
		{ "Comment", "// \"None\" will result in the default filter being used\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_ZGMoveTo.h" },
		{ "ToolTip", "\"None\" will result in the default filter being used" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AllowPartialPath_MetaData[] = {
		{ "Category", "Utility AI ZG Move To" },
		{ "Comment", "// If true, AI will use an incomplete path when the goal cannot be reached\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_ZGMoveTo.h" },
		{ "ToolTip", "If true, AI will use an incomplete path when the goal cannot be reached" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AllowStrafe_MetaData[] = {
		{ "Category", "Utility AI ZG Move To" },
		{ "Comment", "// If true, AI will be able to strafe along paths\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_ZGMoveTo.h" },
		{ "ToolTip", "If true, AI will be able to strafe along paths" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReachTestIncludesAgentRadius_MetaData[] = {
		{ "Category", "Utility AI ZG Move To" },
		{ "Comment", "// If true, AI's capsule radius is added to the goal reach threshold\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_ZGMoveTo.h" },
		{ "ToolTip", "If true, AI's capsule radius is added to the goal reach threshold" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReachTestIncludesGoalRadius_MetaData[] = {
		{ "Category", "Utility AI ZG Move To" },
		{ "Comment", "// If true, goal's capsule radius is added to the goal reach threshold\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_ZGMoveTo.h" },
		{ "ToolTip", "If true, goal's capsule radius is added to the goal reach threshold" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RequireNavigableEndLocation_MetaData[] = {
		{ "Category", "Utility AI ZG Move To" },
		{ "Comment", "// If true, end location must be navigable\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_ZGMoveTo.h" },
		{ "ToolTip", "If true, end location must be navigable" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectGoalLocation_MetaData[] = {
		{ "Category", "Utility AI ZG Move To" },
		{ "Comment", "// If true, goal location will be projected onto NavMesh before usage\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_ZGMoveTo.h" },
		{ "ToolTip", "If true, goal location will be projected onto NavMesh before usage" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UsePathFinding_MetaData[] = {
		{ "Category", "Utility AI ZG Move To" },
		{ "Comment", "// Setting to false will move the AI directly towards the goal location\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_ZGMoveTo.h" },
		{ "ToolTip", "Setting to false will move the AI directly towards the goal location" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartFromPreviousPath_MetaData[] = {
		{ "Category", "Utility AI ZG Move To" },
		{ "Comment", "// If true, new path will start at the end of the previous path (if any)\n// Generated path will merge with remaining points of the previous path\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_ZGMoveTo.h" },
		{ "ToolTip", "If true, new path will start at the end of the previous path (if any)\nGenerated path will merge with remaining points of the previous path" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RestartActionOnMoveCompleted_MetaData[] = {
		{ "Category", "Utility AI ZG Move To" },
		{ "Comment", "// If true, the action will complete when the move is finished\n// If false, the action will loop and move again without the action completing\n// The action will need to be aborted if this is false as there is no other completion criteria\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_ZGMoveTo.h" },
		{ "ToolTip", "If true, the action will complete when the move is finished\nIf false, the action will loop and move again without the action completing\nThe action will need to be aborted if this is false as there is no other completion criteria" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AcceptableRadius_MetaData[] = {
		{ "Category", "Utility AI ZG Move To" },
		{ "Comment", "// A fixed distance added to the goal reach threshold\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_ZGMoveTo.h" },
		{ "ToolTip", "A fixed distance added to the goal reach threshold" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MovementGoalAdvancementDistance_MetaData[] = {
		{ "Category", "Utility AI ZG Move To" },
		{ "Comment", "// The distance along the ZG the movement goal will advance in one go\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_ZGMoveTo.h" },
		{ "ToolTip", "The distance along the ZG the movement goal will advance in one go" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ZGQueryExtent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TagFilter;
	static const UECodeGen_Private::FClassPropertyParams NewProp_FilterClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AllowPartialPath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AllowStrafe;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReachTestIncludesAgentRadius;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReachTestIncludesGoalRadius;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RequireNavigableEndLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ProjectGoalLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_UsePathFinding;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StartFromPreviousPath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RestartActionOnMoveCompleted;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AcceptableRadius;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MovementGoalAdvancementDistance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilityAction_ZGMoveTo>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_ZGQueryExtent = { "ZGQueryExtent", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_ZGMoveTo, ZGQueryExtent), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ZGQueryExtent_MetaData), NewProp_ZGQueryExtent_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_TagFilter = { "TagFilter", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_ZGMoveTo, TagFilter), Z_Construct_UScriptStruct_FZoneGraphTagFilter, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TagFilter_MetaData), NewProp_TagFilter_MetaData) }; // 2933134815
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_FilterClass = { "FilterClass", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_ZGMoveTo, FilterClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UNavigationQueryFilter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FilterClass_MetaData), NewProp_FilterClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_AllowPartialPath = { "AllowPartialPath", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_ZGMoveTo, AllowPartialPath), Z_Construct_UScriptStruct_FAIDataProviderBoolValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AllowPartialPath_MetaData), NewProp_AllowPartialPath_MetaData) }; // 4154625256
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_AllowStrafe = { "AllowStrafe", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_ZGMoveTo, AllowStrafe), Z_Construct_UScriptStruct_FAIDataProviderBoolValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AllowStrafe_MetaData), NewProp_AllowStrafe_MetaData) }; // 4154625256
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_ReachTestIncludesAgentRadius = { "ReachTestIncludesAgentRadius", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_ZGMoveTo, ReachTestIncludesAgentRadius), Z_Construct_UScriptStruct_FAIDataProviderBoolValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReachTestIncludesAgentRadius_MetaData), NewProp_ReachTestIncludesAgentRadius_MetaData) }; // 4154625256
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_ReachTestIncludesGoalRadius = { "ReachTestIncludesGoalRadius", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_ZGMoveTo, ReachTestIncludesGoalRadius), Z_Construct_UScriptStruct_FAIDataProviderBoolValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReachTestIncludesGoalRadius_MetaData), NewProp_ReachTestIncludesGoalRadius_MetaData) }; // 4154625256
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_RequireNavigableEndLocation = { "RequireNavigableEndLocation", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_ZGMoveTo, RequireNavigableEndLocation), Z_Construct_UScriptStruct_FAIDataProviderBoolValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RequireNavigableEndLocation_MetaData), NewProp_RequireNavigableEndLocation_MetaData) }; // 4154625256
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_ProjectGoalLocation = { "ProjectGoalLocation", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_ZGMoveTo, ProjectGoalLocation), Z_Construct_UScriptStruct_FAIDataProviderBoolValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectGoalLocation_MetaData), NewProp_ProjectGoalLocation_MetaData) }; // 4154625256
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_UsePathFinding = { "UsePathFinding", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_ZGMoveTo, UsePathFinding), Z_Construct_UScriptStruct_FAIDataProviderBoolValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UsePathFinding_MetaData), NewProp_UsePathFinding_MetaData) }; // 4154625256
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_StartFromPreviousPath = { "StartFromPreviousPath", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_ZGMoveTo, StartFromPreviousPath), Z_Construct_UScriptStruct_FAIDataProviderBoolValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartFromPreviousPath_MetaData), NewProp_StartFromPreviousPath_MetaData) }; // 4154625256
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_RestartActionOnMoveCompleted = { "RestartActionOnMoveCompleted", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_ZGMoveTo, RestartActionOnMoveCompleted), Z_Construct_UScriptStruct_FAIDataProviderBoolValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RestartActionOnMoveCompleted_MetaData), NewProp_RestartActionOnMoveCompleted_MetaData) }; // 4154625256
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_AcceptableRadius = { "AcceptableRadius", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_ZGMoveTo, AcceptableRadius), Z_Construct_UScriptStruct_FAIDataProviderFloatValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AcceptableRadius_MetaData), NewProp_AcceptableRadius_MetaData) }; // 2793119070
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_MovementGoalAdvancementDistance = { "MovementGoalAdvancementDistance", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_ZGMoveTo, MovementGoalAdvancementDistance), Z_Construct_UScriptStruct_FAIDataProviderFloatValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MovementGoalAdvancementDistance_MetaData), NewProp_MovementGoalAdvancementDistance_MetaData) }; // 2793119070
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_ZGQueryExtent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_TagFilter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_FilterClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_AllowPartialPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_AllowStrafe,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_ReachTestIncludesAgentRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_ReachTestIncludesGoalRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_RequireNavigableEndLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_ProjectGoalLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_UsePathFinding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_StartFromPreviousPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_RestartActionOnMoveCompleted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_AcceptableRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::NewProp_MovementGoalAdvancementDistance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UABUtilityActionBase,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::ClassParams = {
	&UABUtilityAction_ZGMoveTo::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::PropPointers),
	0,
	0x009010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilityAction_ZGMoveTo()
{
	if (!Z_Registration_Info_UClass_UABUtilityAction_ZGMoveTo.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilityAction_ZGMoveTo.OuterSingleton, Z_Construct_UClass_UABUtilityAction_ZGMoveTo_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilityAction_ZGMoveTo.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilityAction_ZGMoveTo);
UABUtilityAction_ZGMoveTo::~UABUtilityAction_ZGMoveTo() {}
// ********** End Class UABUtilityAction_ZGMoveTo **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_ZGMoveTo_h__Script_AxelaBrockettUtilityAIBase_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UABUtilityAction_ZGMoveTo, UABUtilityAction_ZGMoveTo::StaticClass, TEXT("UABUtilityAction_ZGMoveTo"), &Z_Registration_Info_UClass_UABUtilityAction_ZGMoveTo, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilityAction_ZGMoveTo), 3238816326U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_ZGMoveTo_h__Script_AxelaBrockettUtilityAIBase_592059554(TEXT("/Script/AxelaBrockettUtilityAIBase"),
	Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_ZGMoveTo_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_ZGMoveTo_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
