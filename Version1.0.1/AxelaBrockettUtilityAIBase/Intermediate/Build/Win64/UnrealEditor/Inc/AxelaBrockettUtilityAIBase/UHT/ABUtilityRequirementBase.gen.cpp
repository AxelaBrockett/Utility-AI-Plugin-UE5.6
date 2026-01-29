// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/Requirements/ABUtilityRequirementBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeABUtilityRequirementBase() {}

// ********** Begin Cross Module References ********************************************************
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityRequirementBase();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityRequirementBase_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UFunction* Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementChecked__DelegateSignature();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
UPackage* Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnAsyncRequirementChecked ********************************************
struct Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementChecked__DelegateSignature_Statics
{
	struct _Script_AxelaBrockettUtilityAIBase_eventOnAsyncRequirementChecked_Parms
	{
		const UABUtilityRequirementBase* Requirement;
		bool bRequirementPassed;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Actions/Requirements/ABUtilityRequirementBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Requirement_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRequirementPassed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Requirement;
	static void NewProp_bRequirementPassed_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRequirementPassed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementChecked__DelegateSignature_Statics::NewProp_Requirement = { "Requirement", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_AxelaBrockettUtilityAIBase_eventOnAsyncRequirementChecked_Parms, Requirement), Z_Construct_UClass_UABUtilityRequirementBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Requirement_MetaData), NewProp_Requirement_MetaData) };
void Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementChecked__DelegateSignature_Statics::NewProp_bRequirementPassed_SetBit(void* Obj)
{
	((_Script_AxelaBrockettUtilityAIBase_eventOnAsyncRequirementChecked_Parms*)Obj)->bRequirementPassed = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementChecked__DelegateSignature_Statics::NewProp_bRequirementPassed = { "bRequirementPassed", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_AxelaBrockettUtilityAIBase_eventOnAsyncRequirementChecked_Parms), &Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementChecked__DelegateSignature_Statics::NewProp_bRequirementPassed_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRequirementPassed_MetaData), NewProp_bRequirementPassed_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementChecked__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementChecked__DelegateSignature_Statics::NewProp_Requirement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementChecked__DelegateSignature_Statics::NewProp_bRequirementPassed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementChecked__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementChecked__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase, nullptr, "OnAsyncRequirementChecked__DelegateSignature", Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementChecked__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementChecked__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementChecked__DelegateSignature_Statics::_Script_AxelaBrockettUtilityAIBase_eventOnAsyncRequirementChecked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementChecked__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementChecked__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementChecked__DelegateSignature_Statics::_Script_AxelaBrockettUtilityAIBase_eventOnAsyncRequirementChecked_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementChecked__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_AxelaBrockettUtilityAIBase_OnAsyncRequirementChecked__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnAsyncRequirementChecked_DelegateWrapper(const FMulticastScriptDelegate& OnAsyncRequirementChecked, const UABUtilityRequirementBase* Requirement, bool bRequirementPassed)
{
	struct _Script_AxelaBrockettUtilityAIBase_eventOnAsyncRequirementChecked_Parms
	{
		const UABUtilityRequirementBase* Requirement;
		bool bRequirementPassed;
	};
	_Script_AxelaBrockettUtilityAIBase_eventOnAsyncRequirementChecked_Parms Parms;
	Parms.Requirement=Requirement;
	Parms.bRequirementPassed=bRequirementPassed ? true : false;
	OnAsyncRequirementChecked.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnAsyncRequirementChecked **********************************************

// ********** Begin Class UABUtilityRequirementBase ************************************************
void UABUtilityRequirementBase::StaticRegisterNativesUABUtilityRequirementBase()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilityRequirementBase;
UClass* UABUtilityRequirementBase::GetPrivateStaticClass()
{
	using TClass = UABUtilityRequirementBase;
	if (!Z_Registration_Info_UClass_UABUtilityRequirementBase.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilityRequirementBase"),
			Z_Registration_Info_UClass_UABUtilityRequirementBase.InnerSingleton,
			StaticRegisterNativesUABUtilityRequirementBase,
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
	return Z_Registration_Info_UClass_UABUtilityRequirementBase.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilityRequirementBase_NoRegister()
{
	return UABUtilityRequirementBase::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilityRequirementBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Requirement for determining if a utility action can run\n */" },
		{ "IncludePath", "Actions/Requirements/ABUtilityRequirementBase.h" },
		{ "ModuleRelativePath", "Public/Actions/Requirements/ABUtilityRequirementBase.h" },
		{ "ToolTip", "Requirement for determining if a utility action can run" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilityRequirementBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UABUtilityRequirementBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityRequirementBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilityRequirementBase_Statics::ClassParams = {
	&UABUtilityRequirementBase::StaticClass,
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
	0x001010A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityRequirementBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilityRequirementBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilityRequirementBase()
{
	if (!Z_Registration_Info_UClass_UABUtilityRequirementBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilityRequirementBase.OuterSingleton, Z_Construct_UClass_UABUtilityRequirementBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilityRequirementBase.OuterSingleton;
}
UABUtilityRequirementBase::UABUtilityRequirementBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilityRequirementBase);
UABUtilityRequirementBase::~UABUtilityRequirementBase() {}
// ********** End Class UABUtilityRequirementBase **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_ABUtilityRequirementBase_h__Script_AxelaBrockettUtilityAIBase_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UABUtilityRequirementBase, UABUtilityRequirementBase::StaticClass, TEXT("UABUtilityRequirementBase"), &Z_Registration_Info_UClass_UABUtilityRequirementBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilityRequirementBase), 3894013929U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_ABUtilityRequirementBase_h__Script_AxelaBrockettUtilityAIBase_2665070858(TEXT("/Script/AxelaBrockettUtilityAIBase"),
	Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_ABUtilityRequirementBase_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_ABUtilityRequirementBase_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
