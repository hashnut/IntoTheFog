// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef ARENABATTLE_ABHealthPotion_generated_h
#error "ABHealthPotion.generated.h already included, missing '#pragma once' in ABHealthPotion.h"
#endif
#define ARENABATTLE_ABHealthPotion_generated_h

#define IntoTheFog_Source_ArenaBattle_Public_ABHealthPotion_h_12_SPARSE_DATA
#define IntoTheFog_Source_ArenaBattle_Public_ABHealthPotion_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnDestroyPotion); \
	DECLARE_FUNCTION(execOnCharacterOverlap);


#define IntoTheFog_Source_ArenaBattle_Public_ABHealthPotion_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnDestroyPotion); \
	DECLARE_FUNCTION(execOnCharacterOverlap);


#define IntoTheFog_Source_ArenaBattle_Public_ABHealthPotion_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAABHealthPotion(); \
	friend struct Z_Construct_UClass_AABHealthPotion_Statics; \
public: \
	DECLARE_CLASS(AABHealthPotion, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ArenaBattle"), NO_API) \
	DECLARE_SERIALIZER(AABHealthPotion)


#define IntoTheFog_Source_ArenaBattle_Public_ABHealthPotion_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAABHealthPotion(); \
	friend struct Z_Construct_UClass_AABHealthPotion_Statics; \
public: \
	DECLARE_CLASS(AABHealthPotion, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ArenaBattle"), NO_API) \
	DECLARE_SERIALIZER(AABHealthPotion)


#define IntoTheFog_Source_ArenaBattle_Public_ABHealthPotion_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AABHealthPotion(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AABHealthPotion) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AABHealthPotion); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AABHealthPotion); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AABHealthPotion(AABHealthPotion&&); \
	NO_API AABHealthPotion(const AABHealthPotion&); \
public:


#define IntoTheFog_Source_ArenaBattle_Public_ABHealthPotion_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AABHealthPotion(AABHealthPotion&&); \
	NO_API AABHealthPotion(const AABHealthPotion&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AABHealthPotion); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AABHealthPotion); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AABHealthPotion)


#define IntoTheFog_Source_ArenaBattle_Public_ABHealthPotion_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__PotionHeal() { return STRUCT_OFFSET(AABHealthPotion, PotionHeal); } \
	FORCEINLINE static uint32 __PPO__LevelDown() { return STRUCT_OFFSET(AABHealthPotion, LevelDown); }


#define IntoTheFog_Source_ArenaBattle_Public_ABHealthPotion_h_9_PROLOG
#define IntoTheFog_Source_ArenaBattle_Public_ABHealthPotion_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IntoTheFog_Source_ArenaBattle_Public_ABHealthPotion_h_12_PRIVATE_PROPERTY_OFFSET \
	IntoTheFog_Source_ArenaBattle_Public_ABHealthPotion_h_12_SPARSE_DATA \
	IntoTheFog_Source_ArenaBattle_Public_ABHealthPotion_h_12_RPC_WRAPPERS \
	IntoTheFog_Source_ArenaBattle_Public_ABHealthPotion_h_12_INCLASS \
	IntoTheFog_Source_ArenaBattle_Public_ABHealthPotion_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IntoTheFog_Source_ArenaBattle_Public_ABHealthPotion_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IntoTheFog_Source_ArenaBattle_Public_ABHealthPotion_h_12_PRIVATE_PROPERTY_OFFSET \
	IntoTheFog_Source_ArenaBattle_Public_ABHealthPotion_h_12_SPARSE_DATA \
	IntoTheFog_Source_ArenaBattle_Public_ABHealthPotion_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	IntoTheFog_Source_ArenaBattle_Public_ABHealthPotion_h_12_INCLASS_NO_PURE_DECLS \
	IntoTheFog_Source_ArenaBattle_Public_ABHealthPotion_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ARENABATTLE_API UClass* StaticClass<class AABHealthPotion>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IntoTheFog_Source_ArenaBattle_Public_ABHealthPotion_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
