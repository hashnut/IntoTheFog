// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ArenaBattleSetting/Public/ABTwoHandSetting.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABTwoHandSetting() {}
// Cross Module References
	ARENABATTLESETTING_API UClass* Z_Construct_UClass_UABTwoHandSetting_NoRegister();
	ARENABATTLESETTING_API UClass* Z_Construct_UClass_UABTwoHandSetting();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_ArenaBattleSetting();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSoftObjectPath();
// End Cross Module References
	void UABTwoHandSetting::StaticRegisterNativesUABTwoHandSetting()
	{
	}
	UClass* Z_Construct_UClass_UABTwoHandSetting_NoRegister()
	{
		return UABTwoHandSetting::StaticClass();
	}
	struct Z_Construct_UClass_UABTwoHandSetting_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TwoHandAssets_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TwoHandAssets_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TwoHandAssets;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UABTwoHandSetting_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_ArenaBattleSetting,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABTwoHandSetting_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "ABTwoHandSetting.h" },
		{ "ModuleRelativePath", "Public/ABTwoHandSetting.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UABTwoHandSetting_Statics::NewProp_TwoHandAssets_Inner = { "TwoHandAssets", nullptr, (EPropertyFlags)0x0000000000004000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSoftObjectPath, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UABTwoHandSetting_Statics::NewProp_TwoHandAssets_MetaData[] = {
		{ "ModuleRelativePath", "Public/ABTwoHandSetting.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UABTwoHandSetting_Statics::NewProp_TwoHandAssets = { "TwoHandAssets", nullptr, (EPropertyFlags)0x0010000000004000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UABTwoHandSetting, TwoHandAssets), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UABTwoHandSetting_Statics::NewProp_TwoHandAssets_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UABTwoHandSetting_Statics::NewProp_TwoHandAssets_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UABTwoHandSetting_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABTwoHandSetting_Statics::NewProp_TwoHandAssets_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UABTwoHandSetting_Statics::NewProp_TwoHandAssets,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UABTwoHandSetting_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UABTwoHandSetting>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UABTwoHandSetting_Statics::ClassParams = {
		&UABTwoHandSetting::StaticClass,
		"ArenaBattle",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UABTwoHandSetting_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UABTwoHandSetting_Statics::PropPointers),
		0,
		0x001000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UABTwoHandSetting_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UABTwoHandSetting_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UABTwoHandSetting()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UABTwoHandSetting_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UABTwoHandSetting, 15717723);
	template<> ARENABATTLESETTING_API UClass* StaticClass<UABTwoHandSetting>()
	{
		return UABTwoHandSetting::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UABTwoHandSetting(Z_Construct_UClass_UABTwoHandSetting, &UABTwoHandSetting::StaticClass, TEXT("/Script/ArenaBattleSetting"), TEXT("UABTwoHandSetting"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UABTwoHandSetting);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
