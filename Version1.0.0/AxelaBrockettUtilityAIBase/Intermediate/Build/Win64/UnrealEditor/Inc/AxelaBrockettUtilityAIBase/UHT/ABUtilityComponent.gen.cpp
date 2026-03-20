// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/ABUtilityComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeABUtilityComponent() {}

// ********** Begin Cross Module References ********************************************************
AIMODULE_API UClass* Z_Construct_UClass_UBrainComponent();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityActionBase_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityComponent();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityComponent_NoRegister();
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityDataAsset_NoRegister();
UPackage* Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UABUtilityComponent Function OnActionCompleted ***************************
struct Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics
{
	struct ABUtilityComponent_eventOnActionCompleted_Parms
	{
		UABUtilityActionBase* Action;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Comment", "// Delegate binding functions\n" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "Delegate binding functions" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Action;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::NewProp_Action = { "Action", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityComponent_eventOnActionCompleted_Parms, Action), Z_Construct_UClass_UABUtilityActionBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::NewProp_Action,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityComponent, nullptr, "OnActionCompleted", Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::PropPointers), sizeof(Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::ABUtilityComponent_eventOnActionCompleted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::ABUtilityComponent_eventOnActionCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityComponent::execOnActionCompleted)
{
	P_GET_OBJECT(UABUtilityActionBase,Z_Param_Action);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnActionCompleted(Z_Param_Action);
	P_NATIVE_END;
}
// ********** End Class UABUtilityComponent Function OnActionCompleted *****************************

// ********** Begin Class UABUtilityComponent Function OnActionRequirementsChecked *****************
struct Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics
{
	struct ABUtilityComponent_eventOnActionRequirementsChecked_Parms
	{
		UABUtilityActionBase* Action;
		bool bRequirementsPassed;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Comment", "// Delegate binding functions\n" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "Delegate binding functions" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRequirementsPassed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Action;
	static void NewProp_bRequirementsPassed_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRequirementsPassed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::NewProp_Action = { "Action", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABUtilityComponent_eventOnActionRequirementsChecked_Parms, Action), Z_Construct_UClass_UABUtilityActionBase_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::NewProp_bRequirementsPassed_SetBit(void* Obj)
{
	((ABUtilityComponent_eventOnActionRequirementsChecked_Parms*)Obj)->bRequirementsPassed = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::NewProp_bRequirementsPassed = { "bRequirementsPassed", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ABUtilityComponent_eventOnActionRequirementsChecked_Parms), &Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::NewProp_bRequirementsPassed_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRequirementsPassed_MetaData), NewProp_bRequirementsPassed_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::NewProp_Action,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::NewProp_bRequirementsPassed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityComponent, nullptr, "OnActionRequirementsChecked", Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::PropPointers), sizeof(Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::ABUtilityComponent_eventOnActionRequirementsChecked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::ABUtilityComponent_eventOnActionRequirementsChecked_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityComponent::execOnActionRequirementsChecked)
{
	P_GET_OBJECT(UABUtilityActionBase,Z_Param_Action);
	P_GET_UBOOL(Z_Param_bRequirementsPassed);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnActionRequirementsChecked(Z_Param_Action,Z_Param_bRequirementsPassed);
	P_NATIVE_END;
}
// ********** End Class UABUtilityComponent Function OnActionRequirementsChecked *******************

// ********** Begin Class UABUtilityComponent Function OnRep_CurrentAction *************************
static FName NAME_UABUtilityComponent_OnRep_CurrentAction = FName(TEXT("OnRep_CurrentAction"));
void UABUtilityComponent::OnRep_CurrentAction()
{
	UFunction* Func = FindFunctionChecked(NAME_UABUtilityComponent_OnRep_CurrentAction);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
	ProcessEvent(Func,NULL);
	}
	else
	{
		OnRep_CurrentAction_Implementation();
	}
}
struct Z_Construct_UFunction_UABUtilityComponent_OnRep_CurrentAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityComponent_OnRep_CurrentAction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityComponent, nullptr, "OnRep_CurrentAction", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_OnRep_CurrentAction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityComponent_OnRep_CurrentAction_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UABUtilityComponent_OnRep_CurrentAction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityComponent_OnRep_CurrentAction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityComponent::execOnRep_CurrentAction)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_CurrentAction_Implementation();
	P_NATIVE_END;
}
// ********** End Class UABUtilityComponent Function OnRep_CurrentAction ***************************

// ********** Begin Class UABUtilityComponent Function OnRep_LastSuccessfulAction ******************
static FName NAME_UABUtilityComponent_OnRep_LastSuccessfulAction = FName(TEXT("OnRep_LastSuccessfulAction"));
void UABUtilityComponent::OnRep_LastSuccessfulAction()
{
	UFunction* Func = FindFunctionChecked(NAME_UABUtilityComponent_OnRep_LastSuccessfulAction);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
	ProcessEvent(Func,NULL);
	}
	else
	{
		OnRep_LastSuccessfulAction_Implementation();
	}
}
struct Z_Construct_UFunction_UABUtilityComponent_OnRep_LastSuccessfulAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UABUtilityComponent_OnRep_LastSuccessfulAction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UABUtilityComponent, nullptr, "OnRep_LastSuccessfulAction", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UABUtilityComponent_OnRep_LastSuccessfulAction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UABUtilityComponent_OnRep_LastSuccessfulAction_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UABUtilityComponent_OnRep_LastSuccessfulAction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UABUtilityComponent_OnRep_LastSuccessfulAction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UABUtilityComponent::execOnRep_LastSuccessfulAction)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_LastSuccessfulAction_Implementation();
	P_NATIVE_END;
}
// ********** End Class UABUtilityComponent Function OnRep_LastSuccessfulAction ********************

// ********** Begin Class UABUtilityComponent ******************************************************
void UABUtilityComponent::StaticRegisterNativesUABUtilityComponent()
{
	UClass* Class = UABUtilityComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnActionCompleted", &UABUtilityComponent::execOnActionCompleted },
		{ "OnActionRequirementsChecked", &UABUtilityComponent::execOnActionRequirementsChecked },
		{ "OnRep_CurrentAction", &UABUtilityComponent::execOnRep_CurrentAction },
		{ "OnRep_LastSuccessfulAction", &UABUtilityComponent::execOnRep_LastSuccessfulAction },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UABUtilityComponent;
UClass* UABUtilityComponent::GetPrivateStaticClass()
{
	using TClass = UABUtilityComponent;
	if (!Z_Registration_Info_UClass_UABUtilityComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ABUtilityComponent"),
			Z_Registration_Info_UClass_UABUtilityComponent.InnerSingleton,
			StaticRegisterNativesUABUtilityComponent,
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
	return Z_Registration_Info_UClass_UABUtilityComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UABUtilityComponent_NoRegister()
{
	return UABUtilityComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UABUtilityComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "AI" },
		{ "Comment", "/**\n * Utility brain component\n */" },
		{ "HideCategories", "Sockets Collision" },
		{ "IncludePath", "Components/ABUtilityComponent.h" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "Utility brain component" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UtilityDataAsset_MetaData[] = {
		{ "Category", "Utility" },
		{ "Comment", "// Data asset of type UABUtilityDataAsset\n" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "Data asset of type UABUtilityDataAsset" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentAction_MetaData[] = {
		{ "Comment", "// Replicated properties\n" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "Replicated properties" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastSuccessfulAction_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UtilityActions_MetaData[] = {
		{ "Comment", "// Cached actions from the data asset\n" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "Cached actions from the data asset" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRestartLogicWhenResumingComponentLogic_MetaData[] = {
		{ "Category", "Pausing" },
		{ "Comment", "// Restart the component when resuming after pausing\n" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "Restart the component when resuming after pausing" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRunComponentAsynchronously_MetaData[] = {
		{ "Category", "Async" },
		{ "Comment", "// Use available async functions\n" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "Use available async functions" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseParallelRequirementChecking_MetaData[] = {
		{ "Category", "Async" },
		{ "Comment", "// Use ParallelFor to check action requirements\n" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "Use ParallelFor to check action requirements" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRetryOnFailure_MetaData[] = {
		{ "Category", "Utility" },
		{ "Comment", "// In the event of all actions failing, retry\n" },
		{ "ModuleRelativePath", "Public/Components/ABUtilityComponent.h" },
		{ "ToolTip", "In the event of all actions failing, retry" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UtilityDataAsset;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LastSuccessfulAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UtilityActions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_UtilityActions;
	static void NewProp_bRestartLogicWhenResumingComponentLogic_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRestartLogicWhenResumingComponentLogic;
	static void NewProp_bRunComponentAsynchronously_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRunComponentAsynchronously;
	static void NewProp_bUseParallelRequirementChecking_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseParallelRequirementChecking;
	static void NewProp_bRetryOnFailure_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRetryOnFailure;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UABUtilityComponent_OnActionCompleted, "OnActionCompleted" }, // 1363129238
		{ &Z_Construct_UFunction_UABUtilityComponent_OnActionRequirementsChecked, "OnActionRequirementsChecked" }, // 1225115453
		{ &Z_Construct_UFunction_UABUtilityComponent_OnRep_CurrentAction, "OnRep_CurrentAction" }, // 1002384322
		{ &Z_Construct_UFunction_UABUtilityComponent_OnRep_LastSuccessfulAction, "OnRep_LastSuccessfulAction" }, // 692858777
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABUtilityComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_UtilityDataAsset = { "UtilityDataAsset", nullptr, (EPropertyFlags)0x0124080000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityComponent, UtilityDataAsset), Z_Construct_UClass_UABUtilityDataAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UtilityDataAsset_MetaData), NewProp_UtilityDataAsset_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_CurrentAction = { "CurrentAction", "OnRep_CurrentAction", (EPropertyFlags)0x0124080100000020, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityComponent, CurrentAction), Z_Construct_UClass_UABUtilityActionBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentAction_MetaData), NewProp_CurrentAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_LastSuccessfulAction = { "LastSuccessfulAction", "OnRep_LastSuccessfulAction", (EPropertyFlags)0x0124080100000020, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityComponent, LastSuccessfulAction), Z_Construct_UClass_UABUtilityActionBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastSuccessfulAction_MetaData), NewProp_LastSuccessfulAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_UtilityActions_Inner = { "UtilityActions", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UABUtilityActionBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_UtilityActions = { "UtilityActions", nullptr, (EPropertyFlags)0x0124080000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UABUtilityComponent, UtilityActions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UtilityActions_MetaData), NewProp_UtilityActions_MetaData) };
void Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bRestartLogicWhenResumingComponentLogic_SetBit(void* Obj)
{
	((UABUtilityComponent*)Obj)->bRestartLogicWhenResumingComponentLogic = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bRestartLogicWhenResumingComponentLogic = { "bRestartLogicWhenResumingComponentLogic", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(uint8), sizeof(UABUtilityComponent), &Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bRestartLogicWhenResumingComponentLogic_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRestartLogicWhenResumingComponentLogic_MetaData), NewProp_bRestartLogicWhenResumingComponentLogic_MetaData) };
void Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bRunComponentAsynchronously_SetBit(void* Obj)
{
	((UABUtilityComponent*)Obj)->bRunComponentAsynchronously = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bRunComponentAsynchronously = { "bRunComponentAsynchronously", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(uint8), sizeof(UABUtilityComponent), &Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bRunComponentAsynchronously_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRunComponentAsynchronously_MetaData), NewProp_bRunComponentAsynchronously_MetaData) };
void Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bUseParallelRequirementChecking_SetBit(void* Obj)
{
	((UABUtilityComponent*)Obj)->bUseParallelRequirementChecking = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bUseParallelRequirementChecking = { "bUseParallelRequirementChecking", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(uint8), sizeof(UABUtilityComponent), &Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bUseParallelRequirementChecking_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseParallelRequirementChecking_MetaData), NewProp_bUseParallelRequirementChecking_MetaData) };
void Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bRetryOnFailure_SetBit(void* Obj)
{
	((UABUtilityComponent*)Obj)->bRetryOnFailure = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bRetryOnFailure = { "bRetryOnFailure", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(uint8), sizeof(UABUtilityComponent), &Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bRetryOnFailure_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRetryOnFailure_MetaData), NewProp_bRetryOnFailure_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABUtilityComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_UtilityDataAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_CurrentAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_LastSuccessfulAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_UtilityActions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_UtilityActions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bRestartLogicWhenResumingComponentLogic,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bRunComponentAsynchronously,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bUseParallelRequirementChecking,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABUtilityComponent_Statics::NewProp_bRetryOnFailure,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UABUtilityComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBrainComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_AxelaBrockettUtilityAIBase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UABUtilityComponent_Statics::ClassParams = {
	&UABUtilityComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UABUtilityComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UABUtilityComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UABUtilityComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UABUtilityComponent()
{
	if (!Z_Registration_Info_UClass_UABUtilityComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UABUtilityComponent.OuterSingleton, Z_Construct_UClass_UABUtilityComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UABUtilityComponent.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void UABUtilityComponent::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_CurrentAction(TEXT("CurrentAction"));
	static FName Name_LastSuccessfulAction(TEXT("LastSuccessfulAction"));
	const bool bIsValid = true
		&& Name_CurrentAction == ClassReps[(int32)ENetFields_Private::CurrentAction].Property->GetFName()
		&& Name_LastSuccessfulAction == ClassReps[(int32)ENetFields_Private::LastSuccessfulAction].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in UABUtilityComponent"));
}
#endif
DEFINE_VTABLE_PTR_HELPER_CTOR(UABUtilityComponent);
UABUtilityComponent::~UABUtilityComponent() {}
// ********** End Class UABUtilityComponent ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h__Script_AxelaBrockettUtilityAIBase_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UABUtilityComponent, UABUtilityComponent::StaticClass, TEXT("UABUtilityComponent"), &Z_Registration_Info_UClass_UABUtilityComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UABUtilityComponent), 3589753585U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h__Script_AxelaBrockettUtilityAIBase_3971217847(TEXT("/Script/AxelaBrockettUtilityAIBase"),
	Z_CompiledInDeferFile_FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Components_ABUtilityComponent_h__Script_AxelaBrockettUtilityAIBase_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
