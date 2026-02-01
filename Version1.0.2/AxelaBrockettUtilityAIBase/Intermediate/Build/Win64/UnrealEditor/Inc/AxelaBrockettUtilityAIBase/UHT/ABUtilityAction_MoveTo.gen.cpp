// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/Actions/Examples/ABUtilityAction_MoveTo.h"
#include "DataProviders/AIDataProvider.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeABUtilityAction_MoveTo() {}

// ********** Begin Cross Module References ********************************************************
AIMODULE_API UClass* Z_Construct_UClass_UEnvQuery_NoRegister();
AIMODULE_API UEnum* Z_Construct_UEnum_AIModule_EEnvQueryRunMode();
AIMODULE_API UScriptStruct* Z_Construct_UScriptStruct_FAIDataProviderBoolValue();
AIMODULE_API UScriptStruct* Z_Construct_UScriptStruct_FAIDataProviderFloatValue();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityAction_MoveTo();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityAction_MoveTo_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionBase();
AXELABROCKETTUTILITYAIBASE_API UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityAction_MoveToTypes();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
NAVIGATIONSYSTEM_API UClass* Z_Construct_UClass_UNavigationQueryFilter_NoRegister();
UPackage* Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EABUtilityAction_MoveToTypes **********************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EABUtilityAction_MoveToTypes;
static UEnum* EABUtilityAction_MoveToTypes_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EABUtilityAction_MoveToTypes.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EABUtilityAction_MoveToTypes.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityAction_MoveToTypes, (UObject*)Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase(), TEXT("EABUtilityAction_MoveToTypes"));
	}
	return Z_Registration_Info_UEnum_EABUtilityAction_MoveToTypes.OuterSingleton;
}
template<> AXELABROCKETTUTILITYAIBASE_API UEnum* StaticEnum<EABUtilityAction_MoveToTypes>()
{
	return EABUtilityAction_MoveToTypes_StaticEnum();
}
struct Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityAction_MoveToTypes_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "ActorOfType.Name", "EABUtilityAction_MoveToTypes::ActorOfType" },
		{ "EQSGeneratedActor.Name", "EABUtilityAction_MoveToTypes::EQSGeneratedActor" },
		{ "EQSGeneratedPoint.Name", "EABUtilityAction_MoveToTypes::EQSGeneratedPoint" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_MoveTo.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EABUtilityAction_MoveToTypes::EQSGeneratedPoint", (int64)EABUtilityAction_MoveToTypes::EQSGeneratedPoint },
		{ "EABUtilityAction_MoveToTypes::EQSGeneratedActor", (int64)EABUtilityAction_MoveToTypes::EQSGeneratedActor },
		{ "EABUtilityAction_MoveToTypes::ActorOfType", (int64)EABUtilityAction_MoveToTypes::ActorOfType },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityAction_MoveToTypes_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
	nullptr,
	"EABUtilityAction_MoveToTypes",
	"EABUtilityAction_MoveToTypes",
	Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityAction_MoveToTypes_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityAction_MoveToTypes_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityAction_MoveToTypes_Statics::Enum_MetaDataParams), Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityAction_MoveToTypes_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityAction_MoveToTypes()
{
	if (!Z_Registration_Info_UEnum_EABUtilityAction_MoveToTypes.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EABUtilityAction_MoveToTypes.InnerSingleton, Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityAction_MoveToTypes_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EABUtilityAction_MoveToTypes.InnerSingleton;
}
// ********** End Enum EABUtilityAction_MoveToTypes ************************************************

// ********** Begin Class UABUtilityAction_MoveTo **************************************************
void UABUtilityAction_MoveTo::StaticRegisterNativesUABUtilityAction_MoveTo()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilityAction_MoveTo;
UClass* UABUtilityAction_MoveTo::GetPrivateStaticClass()
{
	using TClass = UABUtilityAction_MoveTo;
	if (!Z_Registration_Info_UClass_UABUtilityAction_MoveTo.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilityAction_MoveTo"),
			Z_Registration_Info_UClass_UABUtilityAction_MoveTo.InnerSingleton,
			StaticRegisterNativesUABUtilityAction_MoveTo,
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
	return Z_Registration_Info_UClass_UABUtilityAction_MoveTo.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilityAction_MoveTo_NoRegister()
{
	return UABUtilityAction_MoveTo::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilityAction_MoveTo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Move agent to location\n */" },
		{ "DisplayName", "Utility Move To" },
		{ "IncludePath", "Actions/Actions/Examples/ABUtilityAction_MoveTo.h" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_MoveTo.h" },
		{ "ToolTip", "Move agent to location" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveToTargetType_MetaData[] = {
		{ "Category", "Utility AI Move To" },
		{ "Comment", "// How to generate the point to move to\n// EQSGeneratedPoint expects an EQS that returns a vector\n// EQSGeneratedActor expects an EQS that returns an actor\n// ActorOfType expects a subclass of AActor\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_MoveTo.h" },
		{ "ToolTip", "How to generate the point to move to\nEQSGeneratedPoint expects an EQS that returns a vector\nEQSGeneratedActor expects an EQS that returns an actor\nActorOfType expects a subclass of AActor" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PointGenerationEQS_MetaData[] = {
		{ "Category", "Utility AI Move To" },
		{ "Comment", "// EQS for generating a point to move to\n" },
		{ "EditCondition", "MoveToTargetType==EABUtilityAction_MoveToTypes::EQSGeneratedPoint" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_MoveTo.h" },
		{ "ToolTip", "EQS for generating a point to move to" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorGenerationEQS_MetaData[] = {
		{ "Category", "Utility AI Move To" },
		{ "Comment", "// EQS for generating an actor to move to\n" },
		{ "EditCondition", "MoveToTargetType==EABUtilityAction_MoveToTypes::EQSGeneratedActor" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_MoveTo.h" },
		{ "ToolTip", "EQS for generating an actor to move to" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RunMode_MetaData[] = {
		{ "Category", "Utility AI Move To" },
		{ "Comment", "// Determines the items that will be returned by the EQS\n" },
		{ "EditCondition", "MoveToTargetType!=EABUtilityAction_MoveToTypes::ActorOfType" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_MoveTo.h" },
		{ "ToolTip", "Determines the items that will be returned by the EQS" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorSubclass_MetaData[] = {
		{ "Category", "Utility AI Move To" },
		{ "Comment", "// Subclass of Actor to find and move to\n" },
		{ "EditCondition", "MoveToTargetType==EABUtilityAction_MoveToTypes::ActorOfType" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_MoveTo.h" },
		{ "ToolTip", "Subclass of Actor to find and move to" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FilterClass_MetaData[] = {
		{ "Category", "Utility AI Move To" },
		{ "Comment", "// \"None\" will result in the default filter being used\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_MoveTo.h" },
		{ "ToolTip", "\"None\" will result in the default filter being used" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AllowPartialPath_MetaData[] = {
		{ "Category", "Utility AI Move To" },
		{ "Comment", "// If true, AI will use an incomplete path when the goal cannot be reached\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_MoveTo.h" },
		{ "ToolTip", "If true, AI will use an incomplete path when the goal cannot be reached" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AllowStrafe_MetaData[] = {
		{ "Category", "Utility AI Move To" },
		{ "Comment", "// If true, AI will be able to strafe along paths\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_MoveTo.h" },
		{ "ToolTip", "If true, AI will be able to strafe along paths" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReachTestIncludesAgentRadius_MetaData[] = {
		{ "Category", "Utility AI Move To" },
		{ "Comment", "// If true, AI's capsule radius is added to the goal reach threshold\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_MoveTo.h" },
		{ "ToolTip", "If true, AI's capsule radius is added to the goal reach threshold" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReachTestIncludesGoalRadius_MetaData[] = {
		{ "Category", "Utility AI Move To" },
		{ "Comment", "// If true, goal's capsule radius is added to the goal reach threshold\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_MoveTo.h" },
		{ "ToolTip", "If true, goal's capsule radius is added to the goal reach threshold" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RequireNavigableEndLocation_MetaData[] = {
		{ "Category", "Utility AI Move To" },
		{ "Comment", "// If true, end location must be navigable\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_MoveTo.h" },
		{ "ToolTip", "If true, end location must be navigable" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectGoalLocation_MetaData[] = {
		{ "Category", "Utility AI Move To" },
		{ "Comment", "// If true, goal location will be projected onto NavMesh before usage\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_MoveTo.h" },
		{ "ToolTip", "If true, goal location will be projected onto NavMesh before usage" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UsePathFinding_MetaData[] = {
		{ "Category", "Utility AI Move To" },
		{ "Comment", "// Setting to false will move the AI directly towards the goal location\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_MoveTo.h" },
		{ "ToolTip", "Setting to false will move the AI directly towards the goal location" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartFromPreviousPath_MetaData[] = {
		{ "Category", "Utility AI Move To" },
		{ "Comment", "// If true, new path will start at the end of the previous path (if any)\n// Generated path will merge with remaining points of the previous path\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_MoveTo.h" },
		{ "ToolTip", "If true, new path will start at the end of the previous path (if any)\nGenerated path will merge with remaining points of the previous path" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TrackMovingActor_MetaData[] = {
		{ "Category", "Utility AI Move To" },
		{ "Comment", "// If true, the goal location will be updated as the goal actor moves\n" },
		{ "EditCondition", "MoveToTargetType!=EABUtilityAction_MoveToTypes::EQSGeneratedPoint" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_MoveTo.h" },
		{ "ToolTip", "If true, the goal location will be updated as the goal actor moves" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbortMoveOnPause_MetaData[] = {
		{ "Category", "Utility AI Move To" },
		{ "Comment", "// If true, when pausing, the move will abort, otherwise it will pause the move\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_MoveTo.h" },
		{ "ToolTip", "If true, when pausing, the move will abort, otherwise it will pause the move" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AcceptableRadius_MetaData[] = {
		{ "Category", "Utility AI Move To" },
		{ "Comment", "// A fixed distance added to the goal reach threshold\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_MoveTo.h" },
		{ "ToolTip", "A fixed distance added to the goal reach threshold" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorTrackingGoalMovementTolerance_MetaData[] = {
		{ "Category", "Utility AI Move To" },
		{ "Comment", "// If tracking an actor, this value defines when the goal location is recalculated\n// It is recommended that this value is less than AcceptanceRadius\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_MoveTo.h" },
		{ "ToolTip", "If tracking an actor, this value defines when the goal location is recalculated\nIt is recommended that this value is less than AcceptanceRadius" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_MoveToTargetType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_MoveToTargetType;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PointGenerationEQS;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActorGenerationEQS;
	static const UECodeGen_Private::FBytePropertyParams NewProp_RunMode;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ActorSubclass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_FilterClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AllowPartialPath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AllowStrafe;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReachTestIncludesAgentRadius;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReachTestIncludesGoalRadius;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RequireNavigableEndLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ProjectGoalLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_UsePathFinding;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StartFromPreviousPath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TrackMovingActor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AbortMoveOnPause;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AcceptableRadius;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActorTrackingGoalMovementTolerance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilityAction_MoveTo>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_MoveToTargetType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_MoveToTargetType = { "MoveToTargetType", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_MoveTo, MoveToTargetType), Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityAction_MoveToTypes, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveToTargetType_MetaData), NewProp_MoveToTargetType_MetaData) }; // 2483200163
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_PointGenerationEQS = { "PointGenerationEQS", nullptr, (EPropertyFlags)0x0144000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_MoveTo, PointGenerationEQS), Z_Construct_UClass_UEnvQuery_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PointGenerationEQS_MetaData), NewProp_PointGenerationEQS_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_ActorGenerationEQS = { "ActorGenerationEQS", nullptr, (EPropertyFlags)0x0144000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_MoveTo, ActorGenerationEQS), Z_Construct_UClass_UEnvQuery_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorGenerationEQS_MetaData), NewProp_ActorGenerationEQS_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_RunMode = { "RunMode", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_MoveTo, RunMode), Z_Construct_UEnum_AIModule_EEnvQueryRunMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RunMode_MetaData), NewProp_RunMode_MetaData) }; // 3794952332
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_ActorSubclass = { "ActorSubclass", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_MoveTo, ActorSubclass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorSubclass_MetaData), NewProp_ActorSubclass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_FilterClass = { "FilterClass", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_MoveTo, FilterClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UNavigationQueryFilter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FilterClass_MetaData), NewProp_FilterClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_AllowPartialPath = { "AllowPartialPath", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_MoveTo, AllowPartialPath), Z_Construct_UScriptStruct_FAIDataProviderBoolValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AllowPartialPath_MetaData), NewProp_AllowPartialPath_MetaData) }; // 4154625256
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_AllowStrafe = { "AllowStrafe", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_MoveTo, AllowStrafe), Z_Construct_UScriptStruct_FAIDataProviderBoolValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AllowStrafe_MetaData), NewProp_AllowStrafe_MetaData) }; // 4154625256
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_ReachTestIncludesAgentRadius = { "ReachTestIncludesAgentRadius", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_MoveTo, ReachTestIncludesAgentRadius), Z_Construct_UScriptStruct_FAIDataProviderBoolValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReachTestIncludesAgentRadius_MetaData), NewProp_ReachTestIncludesAgentRadius_MetaData) }; // 4154625256
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_ReachTestIncludesGoalRadius = { "ReachTestIncludesGoalRadius", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_MoveTo, ReachTestIncludesGoalRadius), Z_Construct_UScriptStruct_FAIDataProviderBoolValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReachTestIncludesGoalRadius_MetaData), NewProp_ReachTestIncludesGoalRadius_MetaData) }; // 4154625256
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_RequireNavigableEndLocation = { "RequireNavigableEndLocation", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_MoveTo, RequireNavigableEndLocation), Z_Construct_UScriptStruct_FAIDataProviderBoolValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RequireNavigableEndLocation_MetaData), NewProp_RequireNavigableEndLocation_MetaData) }; // 4154625256
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_ProjectGoalLocation = { "ProjectGoalLocation", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_MoveTo, ProjectGoalLocation), Z_Construct_UScriptStruct_FAIDataProviderBoolValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectGoalLocation_MetaData), NewProp_ProjectGoalLocation_MetaData) }; // 4154625256
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_UsePathFinding = { "UsePathFinding", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_MoveTo, UsePathFinding), Z_Construct_UScriptStruct_FAIDataProviderBoolValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UsePathFinding_MetaData), NewProp_UsePathFinding_MetaData) }; // 4154625256
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_StartFromPreviousPath = { "StartFromPreviousPath", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_MoveTo, StartFromPreviousPath), Z_Construct_UScriptStruct_FAIDataProviderBoolValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartFromPreviousPath_MetaData), NewProp_StartFromPreviousPath_MetaData) }; // 4154625256
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_TrackMovingActor = { "TrackMovingActor", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_MoveTo, TrackMovingActor), Z_Construct_UScriptStruct_FAIDataProviderBoolValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TrackMovingActor_MetaData), NewProp_TrackMovingActor_MetaData) }; // 4154625256
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_AbortMoveOnPause = { "AbortMoveOnPause", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_MoveTo, AbortMoveOnPause), Z_Construct_UScriptStruct_FAIDataProviderBoolValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbortMoveOnPause_MetaData), NewProp_AbortMoveOnPause_MetaData) }; // 4154625256
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_AcceptableRadius = { "AcceptableRadius", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_MoveTo, AcceptableRadius), Z_Construct_UScriptStruct_FAIDataProviderFloatValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AcceptableRadius_MetaData), NewProp_AcceptableRadius_MetaData) }; // 2793119070
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_ActorTrackingGoalMovementTolerance = { "ActorTrackingGoalMovementTolerance", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_MoveTo, ActorTrackingGoalMovementTolerance), Z_Construct_UScriptStruct_FAIDataProviderFloatValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorTrackingGoalMovementTolerance_MetaData), NewProp_ActorTrackingGoalMovementTolerance_MetaData) }; // 2793119070
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_MoveToTargetType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_MoveToTargetType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_PointGenerationEQS,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_ActorGenerationEQS,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_RunMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_ActorSubclass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_FilterClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_AllowPartialPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_AllowStrafe,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_ReachTestIncludesAgentRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_ReachTestIncludesGoalRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_RequireNavigableEndLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_ProjectGoalLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_UsePathFinding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_StartFromPreviousPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_TrackMovingActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_AbortMoveOnPause,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_AcceptableRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::NewProp_ActorTrackingGoalMovementTolerance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UABUtilityActionBase,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::ClassParams = {
	&UABUtilityAction_MoveTo::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::PropPointers),
	0,
	0x009010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilityAction_MoveTo()
{
	if (!Z_Registration_Info_UClass_UABUtilityAction_MoveTo.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilityAction_MoveTo.OuterSingleton, Z_Construct_UClass_UABUtilityAction_MoveTo_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilityAction_MoveTo.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilityAction_MoveTo);
UABUtilityAction_MoveTo::~UABUtilityAction_MoveTo() {}
// ********** End Class UABUtilityAction_MoveTo ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_MoveTo_h__Script_AxelaBrockettUtilityAIBase_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EABUtilityAction_MoveToTypes_StaticEnum, TEXT("EABUtilityAction_MoveToTypes"), &Z_Registration_Info_UEnum_EABUtilityAction_MoveToTypes, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2483200163U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UABUtilityAction_MoveTo, UABUtilityAction_MoveTo::StaticClass, TEXT("UABUtilityAction_MoveTo"), &Z_Registration_Info_UClass_UABUtilityAction_MoveTo, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilityAction_MoveTo), 1312537438U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_MoveTo_h__Script_AxelaBrockettUtilityAIBase_4036265817(TEXT("/Script/AxelaBrockettUtilityAIBase"),
	Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_MoveTo_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_MoveTo_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_MoveTo_h__Script_AxelaBrockettUtilityAIBase_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_MoveTo_h__Script_AxelaBrockettUtilityAIBase_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
