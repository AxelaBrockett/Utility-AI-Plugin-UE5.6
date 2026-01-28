// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Actions/Requirements/Examples/ABUtilityRequirement_MultiReq.h"

#ifdef AXELABROCKETTUTILITYAIBASE_ABUtilityRequirement_MultiReq_generated_h
#error "ABUtilityRequirement_MultiReq.generated.h already included, missing '#pragma once' in ABUtilityRequirement_MultiReq.h"
#endif
#define AXELABROCKETTUTILITYAIBASE_ABUtilityRequirement_MultiReq_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UABUtilityRequirement_MultiReq *******************************************
AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityRequirement_MultiReq_NoRegister();

#define FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_Examples_ABUtilityRequirement_MultiReq_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUABUtilityRequirement_MultiReq(); \
	friend struct Z_Construct_UClass_UABUtilityRequirement_MultiReq_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AXELABROCKETTUTILITYAIBASE_API UClass* Z_Construct_UClass_UABUtilityRequirement_MultiReq_NoRegister(); \
public: \
	DECLARE_CLASS2(UABUtilityRequirement_MultiReq, UABUtilityRequirementBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AxelaBrockettUtilityAIBase"), Z_Construct_UClass_UABUtilityRequirement_MultiReq_NoRegister) \
	DECLARE_SERIALIZER(UABUtilityRequirement_MultiReq)


#define FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_Examples_ABUtilityRequirement_MultiReq_h_27_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UABUtilityRequirement_MultiReq(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UABUtilityRequirement_MultiReq(UABUtilityRequirement_MultiReq&&) = delete; \
	UABUtilityRequirement_MultiReq(const UABUtilityRequirement_MultiReq&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UABUtilityRequirement_MultiReq); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UABUtilityRequirement_MultiReq); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UABUtilityRequirement_MultiReq) \
	NO_API virtual ~UABUtilityRequirement_MultiReq();


#define FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_Examples_ABUtilityRequirement_MultiReq_h_24_PROLOG
#define FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_Examples_ABUtilityRequirement_MultiReq_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_Examples_ABUtilityRequirement_MultiReq_h_27_INCLASS_NO_PURE_DECLS \
	FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_Examples_ABUtilityRequirement_MultiReq_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UABUtilityRequirement_MultiReq;

// ********** End Class UABUtilityRequirement_MultiReq *********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_marti_Documents_AxelaBrockettUtilityAIBase_HostProject_Plugins_AxelaBrockettUtilityAIBase_Source_AxelaBrockettUtilityAIBase_Public_Actions_Requirements_Examples_ABUtilityRequirement_MultiReq_h

// ********** Begin Enum EABUtilityRequirementGroupingOperator *************************************
#define FOREACH_ENUM_EABUTILITYREQUIREMENTGROUPINGOPERATOR(op) \
	op(EABUtilityRequirementGroupingOperator::AND) \
	op(EABUtilityRequirementGroupingOperator::OR) 

enum class EABUtilityRequirementGroupingOperator;
template<> struct TIsUEnumClass<EABUtilityRequirementGroupingOperator> { enum { Value = true }; };
template<> AXELABROCKETTUTILITYAIBASE_API UEnum* StaticEnum<EABUtilityRequirementGroupingOperator>();
// ********** End Enum EABUtilityRequirementGroupingOperator ***************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
