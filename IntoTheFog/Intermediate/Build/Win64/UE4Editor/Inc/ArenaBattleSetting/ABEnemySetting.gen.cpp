// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ArenaBattleSetting/Public/ABEnemySetting.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABEnemySetting() {}
// Cross Module References
	ARENABATTLESETTING_API UClass* Z_Construct_UClass_UABEnemySetting_NoRegister();
	ARENABATTLESETTING_API UClass* Z_Construct_UClass_UABEnemySetting();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_ArenaBattleSetting();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSoftObjectPath();
// End Cross Module References
	void UABEnemySetting::StaticRegisterNativesUABEnemySetting()
	{
	}
	UClass* Z_Construct_UClass_UABEnemySetting_NoRegister()
	{
		return UABEnemySetting::StaticClass();
	}
	struct Z_Construct_UClass_UABEnemySetting_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_EnemyAssets_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnemyAssets_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_EnemyAssets;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_EnemyAnimations_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnemyAnimations_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_EnemyAnimations;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UABEnemySetting_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_ArenaBattleSetting,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABEnemySetting_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "ABEnemySetting.h" },
		{ "ModuleRelativePath", "Public/ABEnemySetting.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABEnemySetting_Statics::NewProp_EnemyAssets_Inner = { "EnemyAssets", nullptr, (EPropertyFlags)0x0000000000004000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSoftObjectPath, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABEnemySetting_Statics::NewProp_EnemyAssets_MetaData[] = {
		{ "ModuleRelativePath", "Public/ABEnemySetting.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UABEnemySetting_Statics::NewProp_EnemyAssets = { "EnemyAssets", nullptr, (EPropertyFlags)0x0010000000004000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UABEnemySetting, EnemyAssets), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UABEnemySetting_Statics::NewProp_EnemyAssets_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UABEnemySetting_Statics::NewProp_EnemyAssets_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABEnemySetting_Statics::NewProp_EnemyAnimations_Inner = { "EnemyAnimations", nullptr, (EPropertyFlags)0x0000000000004000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSoftObjectPath, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABEnemySetting_Statics::NewProp_EnemyAnimations_MetaData[] = {
		{ "ModuleRelativePath", "Public/ABEnemySetting.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UABEnemySetting_Statics::NewProp_EnemyAnimations = { "EnemyAnimations", nullptr, (EPropertyFlags)0x0010000000004000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UABEnemySetting, EnemyAnimations), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UABEnemySetting_Statics::NewProp_EnemyAnimations_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UABEnemySetting_Statics::NewProp_EnemyAnimations_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABEnemySetting_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABEnemySetting_Statics::NewProp_EnemyAssets_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABEnemySetting_Statics::NewProp_EnemyAssets,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABEnemySetting_Statics::NewProp_EnemyAnimations_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABEnemySetting_Statics::NewProp_EnemyAnimations,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UABEnemySetting_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABEnemySetting>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UABEnemySetting_Statics::ClassParams = {
		&UABEnemySetting::StaticClass,
		"ArenaBattle",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UABEnemySetting_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UABEnemySetting_Statics::PropPointers),
		0,
		0x001000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UABEnemySetting_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UABEnemySetting_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UABEnemySetting()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UABEnemySetting_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UABEnemySetting, 2989828942);
	template<> ARENABATTLESETTING_API UClass* StaticClass<UABEnemySetting>()
	{
		return UABEnemySetting::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UABEnemySetting(Z_Construct_UClass_UABEnemySetting, &UABEnemySetting::StaticClass, TEXT("/Script/ArenaBattleSetting"), TEXT("UABEnemySetting"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UABEnemySetting);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
