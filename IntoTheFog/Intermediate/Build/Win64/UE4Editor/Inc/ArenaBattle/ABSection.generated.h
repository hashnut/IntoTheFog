// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef ARENABATTLE_ABSection_generated_h
#error "ABSection.generated.h already included, missing '#pragma once' in ABSection.h"
#endif
#define ARENABATTLE_ABSection_generated_h

#define WithTheLight_Source_ArenaBattle_Public_ABSection_h_14_SPARSE_DATA
#define WithTheLight_Source_ArenaBattle_Public_ABSection_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnRespawnPotion); \
	DECLARE_FUNCTION(execOnSpawnPotion); \
	DECLARE_FUNCTION(execOnSpawnItemBox); \
	DECLARE_FUNCTION(execOnKeyNPCDestroyed); \
	DECLARE_FUNCTION(execOnGateTriggerBeginOverlap); \
	DECLARE_FUNCTION(execOnTriggerBeginOverlap);


#define WithTheLight_Source_ArenaBattle_Public_ABSection_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnRespawnPotion); \
	DECLARE_FUNCTION(execOnSpawnPotion); \
	DECLARE_FUNCTION(execOnSpawnItemBox); \
	DECLARE_FUNCTION(execOnKeyNPCDestroyed); \
	DECLARE_FUNCTION(execOnGateTriggerBeginOverlap); \
	DECLARE_FUNCTION(execOnTriggerBeginOverlap);


#define WithTheLight_Source_ArenaBattle_Public_ABSection_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAABSection(); \
	friend struct Z_Construct_UClass_AABSection_Statics; \
public: \
	DECLARE_CLASS(AABSection, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ArenaBattle"), NO_API) \
	DECLARE_SERIALIZER(AABSection)


#define WithTheLight_Source_ArenaBattle_Public_ABSection_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAABSection(); \
	friend struct Z_Construct_UClass_AABSection_Statics; \
public: \
	DECLARE_CLASS(AABSection, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ArenaBattle"), NO_API) \
	DECLARE_SERIALIZER(AABSection)


#define WithTheLight_Source_ArenaBattle_Public_ABSection_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AABSection(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AABSection) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AABSection); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AABSection); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AABSection(AABSection&&); \
	NO_API AABSection(const AABSection&); \
public:


#define WithTheLight_Source_ArenaBattle_Public_ABSection_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AABSection(AABSection&&); \
	NO_API AABSection(const AABSection&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AABSection); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AABSection); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AABSection)


#define WithTheLight_Source_ArenaBattle_Public_ABSection_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__GateTriggers() { return STRUCT_OFFSET(AABSection, GateTriggers); } \
	FORCEINLINE static uint32 __PPO__Mesh() { return STRUCT_OFFSET(AABSection, Mesh); } \
	FORCEINLINE static uint32 __PPO__Trigger() { return STRUCT_OFFSET(AABSection, Trigger); } \
	FORCEINLINE static uint32 __PPO__EnemySpawnTime() { return STRUCT_OFFSET(AABSection, EnemySpawnTime); } \
	FORCEINLINE static uint32 __PPO__ItemBoxSpawnTime() { return STRUCT_OFFSET(AABSection, ItemBoxSpawnTime); } \
	FORCEINLINE static uint32 __PPO__PotionSpawnTime() { return STRUCT_OFFSET(AABSection, PotionSpawnTime); }


#define WithTheLight_Source_ArenaBattle_Public_ABSection_h_11_PROLOG
#define WithTheLight_Source_ArenaBattle_Public_ABSection_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WithTheLight_Source_ArenaBattle_Public_ABSection_h_14_PRIVATE_PROPERTY_OFFSET \
	WithTheLight_Source_ArenaBattle_Public_ABSection_h_14_SPARSE_DATA \
	WithTheLight_Source_ArenaBattle_Public_ABSection_h_14_RPC_WRAPPERS \
	WithTheLight_Source_ArenaBattle_Public_ABSection_h_14_INCLASS \
	WithTheLight_Source_ArenaBattle_Public_ABSection_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define WithTheLight_Source_ArenaBattle_Public_ABSection_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WithTheLight_Source_ArenaBattle_Public_ABSection_h_14_PRIVATE_PROPERTY_OFFSET \
	WithTheLight_Source_ArenaBattle_Public_ABSection_h_14_SPARSE_DATA \
	WithTheLight_Source_ArenaBattle_Public_ABSection_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	WithTheLight_Source_ArenaBattle_Public_ABSection_h_14_INCLASS_NO_PURE_DECLS \
	WithTheLight_Source_ArenaBattle_Public_ABSection_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ARENABATTLE_API UClass* StaticClass<class AABSection>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID WithTheLight_Source_ArenaBattle_Public_ABSection_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
