// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ARENABATTLE_ABAnimInstance_generated_h
#error "ABAnimInstance.generated.h already included, missing '#pragma once' in ABAnimInstance.h"
#endif
#define ARENABATTLE_ABAnimInstance_generated_h

#define IntoTheFog_Source_ArenaBattle_Public_ABAnimInstance_h_27_SPARSE_DATA
#define IntoTheFog_Source_ArenaBattle_Public_ABAnimInstance_h_27_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execAnimNotify_SheathTwoHandCheck); \
	DECLARE_FUNCTION(execAnimNotify_SheathOneHandCheck); \
	DECLARE_FUNCTION(execAnimNotify_DrawTwoHandCheck); \
	DECLARE_FUNCTION(execAnimNotify_DrawOneHandCheck); \
	DECLARE_FUNCTION(execAnimNotify_RollEndCheck); \
	DECLARE_FUNCTION(execAnimNotify_JumpEndCheck); \
	DECLARE_FUNCTION(execAnimNotify_AttackEndCheck); \
	DECLARE_FUNCTION(execAnimNotify_NextAttackFistCheck); \
	DECLARE_FUNCTION(execAnimNotify_NextAttackCheck); \
	DECLARE_FUNCTION(execAnimNotify_AttackHitCheck);


#define IntoTheFog_Source_ArenaBattle_Public_ABAnimInstance_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAnimNotify_SheathTwoHandCheck); \
	DECLARE_FUNCTION(execAnimNotify_SheathOneHandCheck); \
	DECLARE_FUNCTION(execAnimNotify_DrawTwoHandCheck); \
	DECLARE_FUNCTION(execAnimNotify_DrawOneHandCheck); \
	DECLARE_FUNCTION(execAnimNotify_RollEndCheck); \
	DECLARE_FUNCTION(execAnimNotify_JumpEndCheck); \
	DECLARE_FUNCTION(execAnimNotify_AttackEndCheck); \
	DECLARE_FUNCTION(execAnimNotify_NextAttackFistCheck); \
	DECLARE_FUNCTION(execAnimNotify_NextAttackCheck); \
	DECLARE_FUNCTION(execAnimNotify_AttackHitCheck);


#define IntoTheFog_Source_ArenaBattle_Public_ABAnimInstance_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUABAnimInstance(); \
	friend struct Z_Construct_UClass_UABAnimInstance_Statics; \
public: \
	DECLARE_CLASS(UABAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/ArenaBattle"), NO_API) \
	DECLARE_SERIALIZER(UABAnimInstance)


#define IntoTheFog_Source_ArenaBattle_Public_ABAnimInstance_h_27_INCLASS \
private: \
	static void StaticRegisterNativesUABAnimInstance(); \
	friend struct Z_Construct_UClass_UABAnimInstance_Statics; \
public: \
	DECLARE_CLASS(UABAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/ArenaBattle"), NO_API) \
	DECLARE_SERIALIZER(UABAnimInstance)


#define IntoTheFog_Source_ArenaBattle_Public_ABAnimInstance_h_27_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UABAnimInstance(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UABAnimInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UABAnimInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UABAnimInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UABAnimInstance(UABAnimInstance&&); \
	NO_API UABAnimInstance(const UABAnimInstance&); \
public:


#define IntoTheFog_Source_ArenaBattle_Public_ABAnimInstance_h_27_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UABAnimInstance(UABAnimInstance&&); \
	NO_API UABAnimInstance(const UABAnimInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UABAnimInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UABAnimInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UABAnimInstance)


#define IntoTheFog_Source_ArenaBattle_Public_ABAnimInstance_h_27_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CurrentPawnSpeed() { return STRUCT_OFFSET(UABAnimInstance, CurrentPawnSpeed); } \
	FORCEINLINE static uint32 __PPO__IsInAir() { return STRUCT_OFFSET(UABAnimInstance, IsInAir); } \
	FORCEINLINE static uint32 __PPO__IsDead() { return STRUCT_OFFSET(UABAnimInstance, IsDead); } \
	FORCEINLINE static uint32 __PPO__AttackFistMontage() { return STRUCT_OFFSET(UABAnimInstance, AttackFistMontage); } \
	FORCEINLINE static uint32 __PPO__AttackOneHandMontage() { return STRUCT_OFFSET(UABAnimInstance, AttackOneHandMontage); } \
	FORCEINLINE static uint32 __PPO__DrawOneHandMontage() { return STRUCT_OFFSET(UABAnimInstance, DrawOneHandMontage); } \
	FORCEINLINE static uint32 __PPO__SheathOneHandMontage() { return STRUCT_OFFSET(UABAnimInstance, SheathOneHandMontage); } \
	FORCEINLINE static uint32 __PPO__AttackTwoHandMontage() { return STRUCT_OFFSET(UABAnimInstance, AttackTwoHandMontage); } \
	FORCEINLINE static uint32 __PPO__DrawTwoHandMontage() { return STRUCT_OFFSET(UABAnimInstance, DrawTwoHandMontage); } \
	FORCEINLINE static uint32 __PPO__SheathTwoHandMontage() { return STRUCT_OFFSET(UABAnimInstance, SheathTwoHandMontage); } \
	FORCEINLINE static uint32 __PPO__JumpMontage() { return STRUCT_OFFSET(UABAnimInstance, JumpMontage); } \
	FORCEINLINE static uint32 __PPO__RollMontage() { return STRUCT_OFFSET(UABAnimInstance, RollMontage); } \
	FORCEINLINE static uint32 __PPO__DeadMontage() { return STRUCT_OFFSET(UABAnimInstance, DeadMontage); }


#define IntoTheFog_Source_ArenaBattle_Public_ABAnimInstance_h_24_PROLOG
#define IntoTheFog_Source_ArenaBattle_Public_ABAnimInstance_h_27_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IntoTheFog_Source_ArenaBattle_Public_ABAnimInstance_h_27_PRIVATE_PROPERTY_OFFSET \
	IntoTheFog_Source_ArenaBattle_Public_ABAnimInstance_h_27_SPARSE_DATA \
	IntoTheFog_Source_ArenaBattle_Public_ABAnimInstance_h_27_RPC_WRAPPERS \
	IntoTheFog_Source_ArenaBattle_Public_ABAnimInstance_h_27_INCLASS \
	IntoTheFog_Source_ArenaBattle_Public_ABAnimInstance_h_27_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IntoTheFog_Source_ArenaBattle_Public_ABAnimInstance_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IntoTheFog_Source_ArenaBattle_Public_ABAnimInstance_h_27_PRIVATE_PROPERTY_OFFSET \
	IntoTheFog_Source_ArenaBattle_Public_ABAnimInstance_h_27_SPARSE_DATA \
	IntoTheFog_Source_ArenaBattle_Public_ABAnimInstance_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	IntoTheFog_Source_ArenaBattle_Public_ABAnimInstance_h_27_INCLASS_NO_PURE_DECLS \
	IntoTheFog_Source_ArenaBattle_Public_ABAnimInstance_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ARENABATTLE_API UClass* StaticClass<class UABAnimInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IntoTheFog_Source_ArenaBattle_Public_ABAnimInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
