// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ARENABATTLE_ABTree_generated_h
#error "ABTree.generated.h already included, missing '#pragma once' in ABTree.h"
#endif
#define ARENABATTLE_ABTree_generated_h

#define IntoTheFog_Source_ArenaBattle_Public_ABTree_h_12_SPARSE_DATA
#define IntoTheFog_Source_ArenaBattle_Public_ABTree_h_12_RPC_WRAPPERS
#define IntoTheFog_Source_ArenaBattle_Public_ABTree_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define IntoTheFog_Source_ArenaBattle_Public_ABTree_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAABTree(); \
	friend struct Z_Construct_UClass_AABTree_Statics; \
public: \
	DECLARE_CLASS(AABTree, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ArenaBattle"), NO_API) \
	DECLARE_SERIALIZER(AABTree)


#define IntoTheFog_Source_ArenaBattle_Public_ABTree_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAABTree(); \
	friend struct Z_Construct_UClass_AABTree_Statics; \
public: \
	DECLARE_CLASS(AABTree, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ArenaBattle"), NO_API) \
	DECLARE_SERIALIZER(AABTree)


#define IntoTheFog_Source_ArenaBattle_Public_ABTree_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AABTree(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AABTree) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AABTree); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AABTree); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AABTree(AABTree&&); \
	NO_API AABTree(const AABTree&); \
public:


#define IntoTheFog_Source_ArenaBattle_Public_ABTree_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AABTree(AABTree&&); \
	NO_API AABTree(const AABTree&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AABTree); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AABTree); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AABTree)


#define IntoTheFog_Source_ArenaBattle_Public_ABTree_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Tree() { return STRUCT_OFFSET(AABTree, Tree); }


#define IntoTheFog_Source_ArenaBattle_Public_ABTree_h_9_PROLOG
#define IntoTheFog_Source_ArenaBattle_Public_ABTree_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IntoTheFog_Source_ArenaBattle_Public_ABTree_h_12_PRIVATE_PROPERTY_OFFSET \
	IntoTheFog_Source_ArenaBattle_Public_ABTree_h_12_SPARSE_DATA \
	IntoTheFog_Source_ArenaBattle_Public_ABTree_h_12_RPC_WRAPPERS \
	IntoTheFog_Source_ArenaBattle_Public_ABTree_h_12_INCLASS \
	IntoTheFog_Source_ArenaBattle_Public_ABTree_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IntoTheFog_Source_ArenaBattle_Public_ABTree_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IntoTheFog_Source_ArenaBattle_Public_ABTree_h_12_PRIVATE_PROPERTY_OFFSET \
	IntoTheFog_Source_ArenaBattle_Public_ABTree_h_12_SPARSE_DATA \
	IntoTheFog_Source_ArenaBattle_Public_ABTree_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	IntoTheFog_Source_ArenaBattle_Public_ABTree_h_12_INCLASS_NO_PURE_DECLS \
	IntoTheFog_Source_ArenaBattle_Public_ABTree_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ARENABATTLE_API UClass* StaticClass<class AABTree>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IntoTheFog_Source_ArenaBattle_Public_ABTree_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
