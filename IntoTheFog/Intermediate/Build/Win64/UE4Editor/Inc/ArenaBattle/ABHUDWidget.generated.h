// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ARENABATTLE_ABHUDWidget_generated_h
#error "ABHUDWidget.generated.h already included, missing '#pragma once' in ABHUDWidget.h"
#endif
#define ARENABATTLE_ABHUDWidget_generated_h

#define WithTheLight_Source_ArenaBattle_Public_ABHUDWidget_h_15_SPARSE_DATA
#define WithTheLight_Source_ArenaBattle_Public_ABHUDWidget_h_15_RPC_WRAPPERS
#define WithTheLight_Source_ArenaBattle_Public_ABHUDWidget_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define WithTheLight_Source_ArenaBattle_Public_ABHUDWidget_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUABHUDWidget(); \
	friend struct Z_Construct_UClass_UABHUDWidget_Statics; \
public: \
	DECLARE_CLASS(UABHUDWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ArenaBattle"), NO_API) \
	DECLARE_SERIALIZER(UABHUDWidget)


#define WithTheLight_Source_ArenaBattle_Public_ABHUDWidget_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUABHUDWidget(); \
	friend struct Z_Construct_UClass_UABHUDWidget_Statics; \
public: \
	DECLARE_CLASS(UABHUDWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ArenaBattle"), NO_API) \
	DECLARE_SERIALIZER(UABHUDWidget)


#define WithTheLight_Source_ArenaBattle_Public_ABHUDWidget_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UABHUDWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UABHUDWidget) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UABHUDWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UABHUDWidget); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UABHUDWidget(UABHUDWidget&&); \
	NO_API UABHUDWidget(const UABHUDWidget&); \
public:


#define WithTheLight_Source_ArenaBattle_Public_ABHUDWidget_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UABHUDWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UABHUDWidget(UABHUDWidget&&); \
	NO_API UABHUDWidget(const UABHUDWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UABHUDWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UABHUDWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UABHUDWidget)


#define WithTheLight_Source_ArenaBattle_Public_ABHUDWidget_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__HPBar() { return STRUCT_OFFSET(UABHUDWidget, HPBar); } \
	FORCEINLINE static uint32 __PPO__ExpBar() { return STRUCT_OFFSET(UABHUDWidget, ExpBar); } \
	FORCEINLINE static uint32 __PPO__PlayerName() { return STRUCT_OFFSET(UABHUDWidget, PlayerName); } \
	FORCEINLINE static uint32 __PPO__PlayerLevel() { return STRUCT_OFFSET(UABHUDWidget, PlayerLevel); } \
	FORCEINLINE static uint32 __PPO__CurrentScore() { return STRUCT_OFFSET(UABHUDWidget, CurrentScore); } \
	FORCEINLINE static uint32 __PPO__HighScore() { return STRUCT_OFFSET(UABHUDWidget, HighScore); }


#define WithTheLight_Source_ArenaBattle_Public_ABHUDWidget_h_12_PROLOG
#define WithTheLight_Source_ArenaBattle_Public_ABHUDWidget_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WithTheLight_Source_ArenaBattle_Public_ABHUDWidget_h_15_PRIVATE_PROPERTY_OFFSET \
	WithTheLight_Source_ArenaBattle_Public_ABHUDWidget_h_15_SPARSE_DATA \
	WithTheLight_Source_ArenaBattle_Public_ABHUDWidget_h_15_RPC_WRAPPERS \
	WithTheLight_Source_ArenaBattle_Public_ABHUDWidget_h_15_INCLASS \
	WithTheLight_Source_ArenaBattle_Public_ABHUDWidget_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define WithTheLight_Source_ArenaBattle_Public_ABHUDWidget_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WithTheLight_Source_ArenaBattle_Public_ABHUDWidget_h_15_PRIVATE_PROPERTY_OFFSET \
	WithTheLight_Source_ArenaBattle_Public_ABHUDWidget_h_15_SPARSE_DATA \
	WithTheLight_Source_ArenaBattle_Public_ABHUDWidget_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	WithTheLight_Source_ArenaBattle_Public_ABHUDWidget_h_15_INCLASS_NO_PURE_DECLS \
	WithTheLight_Source_ArenaBattle_Public_ABHUDWidget_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ARENABATTLE_API UClass* StaticClass<class UABHUDWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID WithTheLight_Source_ArenaBattle_Public_ABHUDWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
