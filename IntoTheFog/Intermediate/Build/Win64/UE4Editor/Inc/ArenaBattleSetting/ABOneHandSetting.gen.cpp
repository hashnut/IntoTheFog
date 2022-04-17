// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ArenaBattleSetting/Public/ABOneHandSetting.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABOneHandSetting() {}
// Cross Module References
	ARENABATTLESETTING_API UClass* Z_Construct_UClass_UABOneHandSetting_NoRegister();
	ARENABATTLESETTING_API UClass* Z_Construct_UClass_UABOneHandSetting();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_ArenaBattleSetting();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSoftObjectPath();
// End Cross Module References
	void UABOneHandSetting::StaticRegisterNativesUABOneHandSetting()
	{
	}
	UClass* Z_Construct_UClass_UABOneHandSetting_NoRegister()
	{
		return UABOneHandSetting::StaticClass();
	}
	struct Z_Construct_UClass_UABOneHandSetting_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_OneHandAssets_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OneHandAssets_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_OneHandAssets;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UABOneHandSetting_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_ArenaBattleSetting,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABOneHandSetting_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "ABOneHandSetting.h" },
		{ "ModuleRelativePath", "Public/ABOneHandSetting.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABOneHandSetting_Statics::NewProp_OneHandAssets_Inner = { "OneHandAssets", nullptr, (EPropertyFlags)0x0000000000004000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSoftObjectPath, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABOneHandSetting_Statics::NewProp_OneHandAssets_MetaData[] = {
		{ "ModuleRelativePath", "Public/ABOneHandSetting.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UABOneHandSetting_Statics::NewProp_OneHandAssets = { "OneHandAssets", nullptr, (EPropertyFlags)0x0010000000004000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UABOneHandSetting, OneHandAssets), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UABOneHandSetting_Statics::NewProp_OneHandAssets_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UABOneHandSetting_Statics::NewProp_OneHandAssets_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABOneHandSetting_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABOneHandSetting_Statics::NewProp_OneHandAssets_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABOneHandSetting_Statics::NewProp_OneHandAssets,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UABOneHandSetting_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABOneHandSetting>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UABOneHandSetting_Statics::ClassParams = {
		&UABOneHandSetting::StaticClass,
		"ArenaBattle",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UABOneHandSetting_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UABOneHandSetting_Statics::PropPointers),
		0,
		0x001000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UABOneHandSetting_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UABOneHandSetting_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UABOneHandSetting()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UABOneHandSetting_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UABOneHandSetting, 2753787817);
	template<> ARENABATTLESETTING_API UClass* StaticClass<UABOneHandSetting>()
	{
		return UABOneHandSetting::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UABOneHandSetting(Z_Construct_UClass_UABOneHandSetting, &UABOneHandSetting::StaticClass, TEXT("/Script/ArenaBattleSetting"), TEXT("UABOneHandSetting"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UABOneHandSetting);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
