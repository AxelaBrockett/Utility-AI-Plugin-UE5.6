// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DataAssets/ABUtilityDataAsset.h"

#ifdef AXELABROCKETTUTILITYAIBASE_ABUtilityDataAsset_generated_h
#error "ABUtilityDataAsset.generated.h already included, missing '#pragma once' in ABUtilityDataAsset.h"
#endif
#define AXELABROCKETTUTILITYAIBASE_ABUtilityDataAsset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UABUtilityDataAsset ******************************************************
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityDataAsset_NoRegister();

#define FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_DataAssets_ABUtilityDataAsset_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUABUtilityDataAsset(); \
	friend struct Z_Construct_UClass_UABUtilityDataAsset_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityDataAsset_NoRegister(); \
public: \
	DECLARE_CLASS2(UABUtilityDataAsset, UDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AxelaBrockettUtilityAIBase"), Z_Construct_UClass_UABUtilityDataAsset_NoRegister) \
	DECLARE_SERIALIZER(UABUtilityDataAsset)


#define FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_DataAssets_ABUtilityDataAsset_h_29_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UABUtilityDataAsset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UABUtilityDataAsset(UABUtilityDataAsset&&) = delete; \
	UABUtilityDataAsset(const UABUtilityDataAsset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UABUtilityDataAsset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UABUtilityDataAsset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UABUtilityDataAsset) \
	NO_API virtual ~UABUtilityDataAsset();


#define FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_DataAssets_ABUtilityDataAsset_h_26_PROLOG
#define FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_DataAssets_ABUtilityDataAsset_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_DataAssets_ABUtilityDataAsset_h_29_INCLASS_NO_PURE_DECLS \
	FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_DataAssets_ABUtilityDataAsset_h_29_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UABUtilityDataAsset;

// ********** End Class UABUtilityDataAsset ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_DataAssets_ABUtilityDataAsset_h

// ********** Begin Enum EABActionSelectionMode ****************************************************
#define FOREACH_ENUM_EABACTIONSELECTIONMODE(op) \
	op(EABActionSelectionMode::HighestScore) \
	op(EABActionSelectionMode::RandomFromTop10Pct) \
	op(EABActionSelectionMode::RandomFromTop25Pct) 

enum class EABActionSelectionMode;
template<> struct TIsUEnumClass<EABActionSelectionMode> { enum { Value = true }; };
template<> AXELABROCKETTUTILITYAIBASE_API UEnum* StaticEnum<EABActionSelectionMode>();
// ********** End Enum EABActionSelectionMode ******************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
