// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/Actions/Examples/ABUtilityAction_LookAt.h"
#include "DataProviders/AIDataProvider.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeABUtilityAction_LookAt() {}

// ********** Begin Cross Module References ********************************************************
AIMODULE_API UScriptStruct* Z_Construct_UScriptStruct_FAIDataProviderBoolValue();
AIMODULE_API UScriptStruct* Z_Construct_UScriptStruct_FAIDataProviderFloatValue();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityAction_LookAt();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityAction_LookAt_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionBase();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionInstanceMemoryBase();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionLookAtIM();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionLookAtIM_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityLookAtType();
UPackage* Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UABUtilityActionLookAtIM *************************************************
void UABUtilityActionLookAtIM::StaticRegisterNativesUABUtilityActionLookAtIM()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilityActionLookAtIM;
UClass* UABUtilityActionLookAtIM::GetPrivateStaticClass()
{
	using TClass = UABUtilityActionLookAtIM;
	if (!Z_Registration_Info_UClass_UABUtilityActionLookAtIM.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilityActionLookAtIM"),
			Z_Registration_Info_UClass_UABUtilityActionLookAtIM.InnerSingleton,
			StaticRegisterNativesUABUtilityActionLookAtIM,
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
	return Z_Registration_Info_UClass_UABUtilityActionLookAtIM.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilityActionLookAtIM_NoRegister()
{
	return UABUtilityActionLookAtIM::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilityActionLookAtIM_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Actions/Actions/Examples/ABUtilityAction_LookAt.h" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_LookAt.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilityActionLookAtIM>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UABUtilityActionLookAtIM_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UABUtilityActionInstanceMemoryBase,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityActionLookAtIM_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilityActionLookAtIM_Statics::ClassParams = {
	&UABUtilityActionLookAtIM::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityActionLookAtIM_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilityActionLookAtIM_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilityActionLookAtIM()
{
	if (!Z_Registration_Info_UClass_UABUtilityActionLookAtIM.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilityActionLookAtIM.OuterSingleton, Z_Construct_UClass_UABUtilityActionLookAtIM_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilityActionLookAtIM.OuterSingleton;
}
UABUtilityActionLookAtIM::UABUtilityActionLookAtIM(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilityActionLookAtIM);
UABUtilityActionLookAtIM::~UABUtilityActionLookAtIM() {}
// ********** End Class UABUtilityActionLookAtIM ***************************************************

// ********** Begin Enum EABUtilityLookAtType ******************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EABUtilityLookAtType;
static UEnum* EABUtilityLookAtType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EABUtilityLookAtType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EABUtilityLookAtType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityLookAtType, (UObject*)Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase(), TEXT("EABUtilityLookAtType"));
	}
	return Z_Registration_Info_UEnum_EABUtilityLookAtType.OuterSingleton;
}
template<> AXELABROCKETTUTILITYAIBASE_API UEnum* StaticEnum<EABUtilityLookAtType>()
{
	return EABUtilityLookAtType_StaticEnum();
}
struct Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityLookAtType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Actor.Name", "EABUtilityLookAtType::Actor" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_LookAt.h" },
		{ "Rotator.Name", "EABUtilityLookAtType::Rotator" },
		{ "Vector.Name", "EABUtilityLookAtType::Vector" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EABUtilityLookAtType::Actor", (int64)EABUtilityLookAtType::Actor },
		{ "EABUtilityLookAtType::Vector", (int64)EABUtilityLookAtType::Vector },
		{ "EABUtilityLookAtType::Rotator", (int64)EABUtilityLookAtType::Rotator },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityLookAtType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
	nullptr,
	"EABUtilityLookAtType",
	"EABUtilityLookAtType",
	Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityLookAtType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityLookAtType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityLookAtType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityLookAtType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityLookAtType()
{
	if (!Z_Registration_Info_UEnum_EABUtilityLookAtType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EABUtilityLookAtType.InnerSingleton, Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityLookAtType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EABUtilityLookAtType.InnerSingleton;
}
// ********** End Enum EABUtilityLookAtType ********************************************************

// ********** Begin Class UABUtilityAction_LookAt **************************************************
void UABUtilityAction_LookAt::StaticRegisterNativesUABUtilityAction_LookAt()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilityAction_LookAt;
UClass* UABUtilityAction_LookAt::GetPrivateStaticClass()
{
	using TClass = UABUtilityAction_LookAt;
	if (!Z_Registration_Info_UClass_UABUtilityAction_LookAt.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilityAction_LookAt"),
			Z_Registration_Info_UClass_UABUtilityAction_LookAt.InnerSingleton,
			StaticRegisterNativesUABUtilityAction_LookAt,
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
	return Z_Registration_Info_UClass_UABUtilityAction_LookAt.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilityAction_LookAt_NoRegister()
{
	return UABUtilityAction_LookAt::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilityAction_LookAt_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * To set what the AI looks at, call UABUtilitySubsystem::GetMutableActionsAvailableToComponent()\n * passing in the relevent UABUtilityComponent, search for this Action in that array, then call\n * either SetLookAtActor(), SetLookAtVector() or SetLookAtRotator()\n */" },
		{ "DisplayName", "Utility Look At" },
		{ "IncludePath", "Actions/Actions/Examples/ABUtilityAction_LookAt.h" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_LookAt.h" },
		{ "ToolTip", "To set what the AI looks at, call UABUtilitySubsystem::GetMutableActionsAvailableToComponent()\npassing in the relevent UABUtilityComponent, search for this Action in that array, then call\neither SetLookAtActor(), SetLookAtVector() or SetLookAtRotator()" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CleanUpOnPause_MetaData[] = {
		{ "Category", "Utility Look At" },
		{ "Comment", "// If true, the AI Controller's focus will be cleared when the game is paused\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_LookAt.h" },
		{ "ToolTip", "If true, the AI Controller's focus will be cleared when the game is paused" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Precision_MetaData[] = {
		{ "Category", "Utility Look At" },
		{ "Comment", "// Success condition precision in degrees\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_LookAt.h" },
		{ "ToolTip", "Success condition precision in degrees" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookAtType_MetaData[] = {
		{ "Category", "Utility Look At" },
		{ "Comment", "// The type of focal point to look at\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_LookAt.h" },
		{ "ToolTip", "The type of focal point to look at" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookAtRotatorDisplacement_MetaData[] = {
		{ "Category", "Utility Look At" },
		{ "Comment", "// The displacement distance to use when looking in a rotation direction\n" },
		{ "EditCondition", "LookAtType==EABUtilityLookAtType::Rotator" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_LookAt.h" },
		{ "ToolTip", "The displacement distance to use when looking in a rotation direction" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bFailOnNoViableActors_MetaData[] = {
		{ "Category", "Utility Look At" },
		{ "Comment", "// If true, the Action will fail if no actors are found, otherwise it will continue to tick\n" },
		{ "ModuleRelativePath", "Public/Actions/Actions/Examples/ABUtilityAction_LookAt.h" },
		{ "ToolTip", "If true, the Action will fail if no actors are found, otherwise it will continue to tick" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CleanUpOnPause;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Precision;
	static const UECodeGen_Private::FBytePropertyParams NewProp_LookAtType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_LookAtType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LookAtRotatorDisplacement;
	static void NewProp_bFailOnNoViableActors_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFailOnNoViableActors;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilityAction_LookAt>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_LookAt_Statics::NewProp_CleanUpOnPause = { "CleanUpOnPause", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_LookAt, CleanUpOnPause), Z_Construct_UScriptStruct_FAIDataProviderBoolValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CleanUpOnPause_MetaData), NewProp_CleanUpOnPause_MetaData) }; // 4154625256
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABUtilityAction_LookAt_Statics::NewProp_Precision = { "Precision", nullptr, (EPropertyFlags)0x0040008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_LookAt, Precision), Z_Construct_UScriptStruct_FAIDataProviderFloatValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Precision_MetaData), NewProp_Precision_MetaData) }; // 2793119070
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UABUtilityAction_LookAt_Statics::NewProp_LookAtType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UABUtilityAction_LookAt_Statics::NewProp_LookAtType = { "LookAtType", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_LookAt, LookAtType), Z_Construct_UEnum_AxelaBrockettUtilityAIBase_EABUtilityLookAtType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookAtType_MetaData), NewProp_LookAtType_MetaData) }; // 269777417
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UABUtilityAction_LookAt_Statics::NewProp_LookAtRotatorDisplacement = { "LookAtRotatorDisplacement", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityAction_LookAt, LookAtRotatorDisplacement), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookAtRotatorDisplacement_MetaData), NewProp_LookAtRotatorDisplacement_MetaData) };
void Z_Construct_UClass_UABUtilityAction_LookAt_Statics::NewProp_bFailOnNoViableActors_SetBit(void* Obj)
{
	((UABUtilityAction_LookAt*)Obj)->bFailOnNoViableActors = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UABUtilityAction_LookAt_Statics::NewProp_bFailOnNoViableActors = { "bFailOnNoViableActors", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UABUtilityAction_LookAt), &Z_Construct_UClass_UABUtilityAction_LookAt_Statics::NewProp_bFailOnNoViableActors_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bFailOnNoViableActors_MetaData), NewProp_bFailOnNoViableActors_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABUtilityAction_LookAt_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_LookAt_Statics::NewProp_CleanUpOnPause,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_LookAt_Statics::NewProp_Precision,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_LookAt_Statics::NewProp_LookAtType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_LookAt_Statics::NewProp_LookAtType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_LookAt_Statics::NewProp_LookAtRotatorDisplacement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityAction_LookAt_Statics::NewProp_bFailOnNoViableActors,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityAction_LookAt_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UABUtilityAction_LookAt_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UABUtilityActionBase,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityAction_LookAt_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilityAction_LookAt_Statics::ClassParams = {
	&UABUtilityAction_LookAt::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UABUtilityAction_LookAt_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityAction_LookAt_Statics::PropPointers),
	0,
	0x009010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityAction_LookAt_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilityAction_LookAt_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilityAction_LookAt()
{
	if (!Z_Registration_Info_UClass_UABUtilityAction_LookAt.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilityAction_LookAt.OuterSingleton, Z_Construct_UClass_UABUtilityAction_LookAt_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilityAction_LookAt.OuterSingleton;
}
UABUtilityAction_LookAt::UABUtilityAction_LookAt() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilityAction_LookAt);
UABUtilityAction_LookAt::~UABUtilityAction_LookAt() {}
// ********** End Class UABUtilityAction_LookAt ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_LookAt_h__Script_AxelaBrockettUtilityAIBase_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EABUtilityLookAtType_StaticEnum, TEXT("EABUtilityLookAtType"), &Z_Registration_Info_UEnum_EABUtilityLookAtType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 269777417U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UABUtilityActionLookAtIM, UABUtilityActionLookAtIM::StaticClass, TEXT("UABUtilityActionLookAtIM"), &Z_Registration_Info_UClass_UABUtilityActionLookAtIM, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilityActionLookAtIM), 4021288557U) },
		{ Z_Construct_UClass_UABUtilityAction_LookAt, UABUtilityAction_LookAt::StaticClass, TEXT("UABUtilityAction_LookAt"), &Z_Registration_Info_UClass_UABUtilityAction_LookAt, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilityAction_LookAt), 2292851584U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_LookAt_h__Script_AxelaBrockettUtilityAIBase_3776686120(TEXT("/Script/AxelaBrockettUtilityAIBase"),
	Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_LookAt_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_LookAt_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_LookAt_h__Script_AxelaBrockettUtilityAIBase_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TestBuilds_Build1_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Actions_Examples_ABUtilityAction_LookAt_h__Script_AxelaBrockettUtilityAIBase_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
