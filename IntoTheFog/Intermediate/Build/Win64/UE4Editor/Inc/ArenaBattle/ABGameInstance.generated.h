// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ARENABATTLE_ABGameInstance_generated_h
#error "ABGameInstance.generated.h already included, missing '#pragma once' in ABGameInstance.h"
#endif
#define ARENABATTLE_ABGameInstance_generated_h

#define WithTheLight_Source_ArenaBattle_Public_ABGameInstance_h_38_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FABEnemyData_Statics; \
	ARENABATTLE_API static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> ARENABATTLE_API UScriptStruct* StaticStruct<struct FABEnemyData>();

#define WithTheLight_Source_ArenaBattle_Public_ABGameInstance_h_14_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FABCharacterData_Statics; \
	ARENABATTLE_API static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> ARENABATTLE_API UScriptStruct* StaticStruct<struct FABCharacterData>();

#define WithTheLight_Source_ArenaBattle_Public_ABGameInstance_h_58_SPARSE_DATA
#define WithTheLight_Source_ArenaBattle_Public_ABGameInstance_h_58_RPC_WRAPPERS
#define WithTheLight_Source_ArenaBattle_Public_ABGameInstance_h_58_RPC_WRAPPERS_NO_PURE_DECLS
#define WithTheLight_Source_ArenaBattle_Public_ABGameInstance_h_58_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUABGameInstance(); \
	friend struct Z_Construct_UClass_UABGameInstance_Statics; \
public: \
	DECLARE_CLASS(UABGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/ArenaBattle"), NO_API) \
	DECLARE_SERIALIZER(UABGameInstance)


#define WithTheLight_Source_ArenaBattle_Public_ABGameInstance_h_58_INCLASS \
private: \
	static void StaticRegisterNativesUABGameInstance(); \
	friend struct Z_Construct_UClass_UABGameInstance_Statics; \
public: \
	DECLARE_CLASS(UABGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/ArenaBattle"), NO_API) \
	DECLARE_SERIALIZER(UABGameInstance)


#define WithTheLight_Source_ArenaBattle_Public_ABGameInstance_h_58_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UABGameInstance(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UABGameInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UABGameInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UABGameInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UABGameInstance(UABGameInstance&&); \
	NO_API UABGameInstance(const UABGameInstance&); \
public:


#define WithTheLight_Source_ArenaBattle_Public_ABGameInstance_h_58_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UABGameInstance(UABGameInstance&&); \
	NO_API UABGameInstance(const UABGameInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UABGameInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UABGameInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UABGameInstance)


#define WithTheLight_Source_ArenaBattle_Public_ABGameInstance_h_58_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ABCharacterTable() { return STRUCT_OFFSET(UABGameInstance, ABCharacterTable); } \
	FORCEINLINE static uint32 __PPO__ABEnemyTable() { return STRUCT_OFFSET(UABGameInstance, ABEnemyTable); }


#define WithTheLight_Source_ArenaBattle_Public_ABGameInstance_h_55_PROLOG
#define WithTheLight_Source_ArenaBattle_Public_ABGameInstance_h_58_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WithTheLight_Source_ArenaBattle_Public_ABGameInstance_h_58_PRIVATE_PROPERTY_OFFSET \
	WithTheLight_Source_ArenaBattle_Public_ABGameInstance_h_58_SPARSE_DATA \
	WithTheLight_Source_ArenaBattle_Public_ABGameInstance_h_58_RPC_WRAPPERS \
	WithTheLight_Source_ArenaBattle_Public_ABGameInstance_h_58_INCLASS \
	WithTheLight_Source_ArenaBattle_Public_ABGameInstance_h_58_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define WithTheLight_Source_ArenaBattle_Public_ABGameInstance_h_58_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WithTheLight_Source_ArenaBattle_Public_ABGameInstance_h_58_PRIVATE_PROPERTY_OFFSET \
	WithTheLight_Source_ArenaBattle_Public_ABGameInstance_h_58_SPARSE_DATA \
	WithTheLight_Source_ArenaBattle_Public_ABGameInstance_h_58_RPC_WRAPPERS_NO_PURE_DECLS \
	WithTheLight_Source_ArenaBattle_Public_ABGameInstance_h_58_INCLASS_NO_PURE_DECLS \
	WithTheLight_Source_ArenaBattle_Public_ABGameInstance_h_58_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ARENABATTLE_API UClass* StaticClass<class UABGameInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID WithTheLight_Source_ArenaBattle_Public_ABGameInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
