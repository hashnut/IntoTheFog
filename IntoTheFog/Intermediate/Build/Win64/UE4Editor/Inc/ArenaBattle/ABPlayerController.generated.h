// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ARENABATTLE_ABPlayerController_generated_h
#error "ABPlayerController.generated.h already included, missing '#pragma once' in ABPlayerController.h"
#endif
#define ARENABATTLE_ABPlayerController_generated_h

#define IntoTheFog_Source_ArenaBattle_Public_ABPlayerController_h_15_SPARSE_DATA
#define IntoTheFog_Source_ArenaBattle_Public_ABPlayerController_h_15_RPC_WRAPPERS
#define IntoTheFog_Source_ArenaBattle_Public_ABPlayerController_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define IntoTheFog_Source_ArenaBattle_Public_ABPlayerController_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAABPlayerController(); \
	friend struct Z_Construct_UClass_AABPlayerController_Statics; \
public: \
	DECLARE_CLASS(AABPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ArenaBattle"), NO_API) \
	DECLARE_SERIALIZER(AABPlayerController)


#define IntoTheFog_Source_ArenaBattle_Public_ABPlayerController_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAABPlayerController(); \
	friend struct Z_Construct_UClass_AABPlayerController_Statics; \
public: \
	DECLARE_CLASS(AABPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ArenaBattle"), NO_API) \
	DECLARE_SERIALIZER(AABPlayerController)


#define IntoTheFog_Source_ArenaBattle_Public_ABPlayerController_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AABPlayerController(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AABPlayerController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AABPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AABPlayerController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AABPlayerController(AABPlayerController&&); \
	NO_API AABPlayerController(const AABPlayerController&); \
public:


#define IntoTheFog_Source_ArenaBattle_Public_ABPlayerController_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AABPlayerController(AABPlayerController&&); \
	NO_API AABPlayerController(const AABPlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AABPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AABPlayerController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AABPlayerController)


#define IntoTheFog_Source_ArenaBattle_Public_ABPlayerController_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__HUDWidgetClass() { return STRUCT_OFFSET(AABPlayerController, HUDWidgetClass); } \
	FORCEINLINE static uint32 __PPO__MenuWidgetClass() { return STRUCT_OFFSET(AABPlayerController, MenuWidgetClass); } \
	FORCEINLINE static uint32 __PPO__ResultWidgetClass() { return STRUCT_OFFSET(AABPlayerController, ResultWidgetClass); } \
	FORCEINLINE static uint32 __PPO__HUDWidget() { return STRUCT_OFFSET(AABPlayerController, HUDWidget); } \
	FORCEINLINE static uint32 __PPO__MenuWidget() { return STRUCT_OFFSET(AABPlayerController, MenuWidget); } \
	FORCEINLINE static uint32 __PPO__ABPlayerState() { return STRUCT_OFFSET(AABPlayerController, ABPlayerState); } \
	FORCEINLINE static uint32 __PPO__ResultWidget() { return STRUCT_OFFSET(AABPlayerController, ResultWidget); }


#define IntoTheFog_Source_ArenaBattle_Public_ABPlayerController_h_12_PROLOG
#define IntoTheFog_Source_ArenaBattle_Public_ABPlayerController_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IntoTheFog_Source_ArenaBattle_Public_ABPlayerController_h_15_PRIVATE_PROPERTY_OFFSET \
	IntoTheFog_Source_ArenaBattle_Public_ABPlayerController_h_15_SPARSE_DATA \
	IntoTheFog_Source_ArenaBattle_Public_ABPlayerController_h_15_RPC_WRAPPERS \
	IntoTheFog_Source_ArenaBattle_Public_ABPlayerController_h_15_INCLASS \
	IntoTheFog_Source_ArenaBattle_Public_ABPlayerController_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IntoTheFog_Source_ArenaBattle_Public_ABPlayerController_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IntoTheFog_Source_ArenaBattle_Public_ABPlayerController_h_15_PRIVATE_PROPERTY_OFFSET \
	IntoTheFog_Source_ArenaBattle_Public_ABPlayerController_h_15_SPARSE_DATA \
	IntoTheFog_Source_ArenaBattle_Public_ABPlayerController_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	IntoTheFog_Source_ArenaBattle_Public_ABPlayerController_h_15_INCLASS_NO_PURE_DECLS \
	IntoTheFog_Source_ArenaBattle_Public_ABPlayerController_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ARENABATTLE_API UClass* StaticClass<class AABPlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IntoTheFog_Source_ArenaBattle_Public_ABPlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
