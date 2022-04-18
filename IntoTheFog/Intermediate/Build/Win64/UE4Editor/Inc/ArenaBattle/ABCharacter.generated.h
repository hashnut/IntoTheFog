// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAnimMontage;
enum class EWeaponType : uint8;
#ifdef ARENABATTLE_ABCharacter_generated_h
#error "ABCharacter.generated.h already included, missing '#pragma once' in ABCharacter.h"
#endif
#define ARENABATTLE_ABCharacter_generated_h

#define IntoTheFog_Source_ArenaBattle_Public_ABCharacter_h_23_SPARSE_DATA
#define IntoTheFog_Source_ArenaBattle_Public_ABCharacter_h_23_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnEveryMontageEnded); \
	DECLARE_FUNCTION(execOnAttackMontageEnded); \
	DECLARE_FUNCTION(execGetCurrentWeaponType);


#define IntoTheFog_Source_ArenaBattle_Public_ABCharacter_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnEveryMontageEnded); \
	DECLARE_FUNCTION(execOnAttackMontageEnded); \
	DECLARE_FUNCTION(execGetCurrentWeaponType);


#define IntoTheFog_Source_ArenaBattle_Public_ABCharacter_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAABCharacter(); \
	friend struct Z_Construct_UClass_AABCharacter_Statics; \
public: \
	DECLARE_CLASS(AABCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ArenaBattle"), NO_API) \
	DECLARE_SERIALIZER(AABCharacter)


#define IntoTheFog_Source_ArenaBattle_Public_ABCharacter_h_23_INCLASS \
private: \
	static void StaticRegisterNativesAABCharacter(); \
	friend struct Z_Construct_UClass_AABCharacter_Statics; \
public: \
	DECLARE_CLASS(AABCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ArenaBattle"), NO_API) \
	DECLARE_SERIALIZER(AABCharacter)


#define IntoTheFog_Source_ArenaBattle_Public_ABCharacter_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AABCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AABCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AABCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AABCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AABCharacter(AABCharacter&&); \
	NO_API AABCharacter(const AABCharacter&); \
public:


#define IntoTheFog_Source_ArenaBattle_Public_ABCharacter_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AABCharacter(AABCharacter&&); \
	NO_API AABCharacter(const AABCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AABCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AABCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AABCharacter)


#define IntoTheFog_Source_ArenaBattle_Public_ABCharacter_h_23_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CanNextCombo() { return STRUCT_OFFSET(AABCharacter, CanNextCombo); } \
	FORCEINLINE static uint32 __PPO__IsComboInputOn() { return STRUCT_OFFSET(AABCharacter, IsComboInputOn); } \
	FORCEINLINE static uint32 __PPO__CurrentCombo() { return STRUCT_OFFSET(AABCharacter, CurrentCombo); } \
	FORCEINLINE static uint32 __PPO__MaxCombo() { return STRUCT_OFFSET(AABCharacter, MaxCombo); } \
	FORCEINLINE static uint32 __PPO__AttackRange() { return STRUCT_OFFSET(AABCharacter, AttackRange); } \
	FORCEINLINE static uint32 __PPO__AttackRadius() { return STRUCT_OFFSET(AABCharacter, AttackRadius); } \
	FORCEINLINE static uint32 __PPO__ABAnim() { return STRUCT_OFFSET(AABCharacter, ABAnim); } \
	FORCEINLINE static uint32 __PPO__CurrentState() { return STRUCT_OFFSET(AABCharacter, CurrentState); } \
	FORCEINLINE static uint32 __PPO__bIsPlayer() { return STRUCT_OFFSET(AABCharacter, bIsPlayer); } \
	FORCEINLINE static uint32 __PPO__ABAIController() { return STRUCT_OFFSET(AABCharacter, ABAIController); } \
	FORCEINLINE static uint32 __PPO__ABPlayerController() { return STRUCT_OFFSET(AABCharacter, ABPlayerController); } \
	FORCEINLINE static uint32 __PPO__DeadTimer() { return STRUCT_OFFSET(AABCharacter, DeadTimer); } \
	FORCEINLINE static uint32 __PPO__HitFist() { return STRUCT_OFFSET(AABCharacter, HitFist); } \
	FORCEINLINE static uint32 __PPO__HitOneHand() { return STRUCT_OFFSET(AABCharacter, HitOneHand); } \
	FORCEINLINE static uint32 __PPO__HitTwoHand() { return STRUCT_OFFSET(AABCharacter, HitTwoHand); } \
	FORCEINLINE static uint32 __PPO__DrawOneHand() { return STRUCT_OFFSET(AABCharacter, DrawOneHand); } \
	FORCEINLINE static uint32 __PPO__SheathOneHand() { return STRUCT_OFFSET(AABCharacter, SheathOneHand); } \
	FORCEINLINE static uint32 __PPO__DrawTwoHand() { return STRUCT_OFFSET(AABCharacter, DrawTwoHand); } \
	FORCEINLINE static uint32 __PPO__SheathTwoHand() { return STRUCT_OFFSET(AABCharacter, SheathTwoHand); }


#define IntoTheFog_Source_ArenaBattle_Public_ABCharacter_h_20_PROLOG
#define IntoTheFog_Source_ArenaBattle_Public_ABCharacter_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IntoTheFog_Source_ArenaBattle_Public_ABCharacter_h_23_PRIVATE_PROPERTY_OFFSET \
	IntoTheFog_Source_ArenaBattle_Public_ABCharacter_h_23_SPARSE_DATA \
	IntoTheFog_Source_ArenaBattle_Public_ABCharacter_h_23_RPC_WRAPPERS \
	IntoTheFog_Source_ArenaBattle_Public_ABCharacter_h_23_INCLASS \
	IntoTheFog_Source_ArenaBattle_Public_ABCharacter_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IntoTheFog_Source_ArenaBattle_Public_ABCharacter_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IntoTheFog_Source_ArenaBattle_Public_ABCharacter_h_23_PRIVATE_PROPERTY_OFFSET \
	IntoTheFog_Source_ArenaBattle_Public_ABCharacter_h_23_SPARSE_DATA \
	IntoTheFog_Source_ArenaBattle_Public_ABCharacter_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	IntoTheFog_Source_ArenaBattle_Public_ABCharacter_h_23_INCLASS_NO_PURE_DECLS \
	IntoTheFog_Source_ArenaBattle_Public_ABCharacter_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ARENABATTLE_API UClass* StaticClass<class AABCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IntoTheFog_Source_ArenaBattle_Public_ABCharacter_h


#define FOREACH_ENUM_EWEAPONTYPE(op) \
	op(EWeaponType::Unarmed) \
	op(EWeaponType::Fist) \
	op(EWeaponType::OneHand) \
	op(EWeaponType::TwoHand) 

enum class EWeaponType : uint8;
template<> ARENABATTLE_API UEnum* StaticEnum<EWeaponType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
