// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ArenaBattle/Public/ABEarth.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABEarth() {}
// Cross Module References
	ARENABATTLE_API UClass* Z_Construct_UClass_AABEarth_NoRegister();
	ARENABATTLE_API UClass* Z_Construct_UClass_AABEarth();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ArenaBattle();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void AABEarth::StaticRegisterNativesAABEarth()
	{
	}
	UClass* Z_Construct_UClass_AABEarth_NoRegister()
	{
		return AABEarth::StaticClass();
	}
	struct Z_Construct_UClass_AABEarth_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Grass_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Grass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AABEarth_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ArenaBattle,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABEarth_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ABEarth.h" },
		{ "ModuleRelativePath", "Public/ABEarth.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABEarth_Statics::NewProp_Grass_MetaData[] = {
		{ "Category", "Earth" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ABEarth.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AABEarth_Statics::NewProp_Grass = { "Grass", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AABEarth, Grass), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AABEarth_Statics::NewProp_Grass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AABEarth_Statics::NewProp_Grass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AABEarth_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABEarth_Statics::NewProp_Grass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AABEarth_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AABEarth>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AABEarth_Statics::ClassParams = {
		&AABEarth::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AABEarth_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AABEarth_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AABEarth_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AABEarth_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AABEarth()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AABEarth_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AABEarth, 407528821);
	template<> ARENABATTLE_API UClass* StaticClass<AABEarth>()
	{
		return AABEarth::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AABEarth(Z_Construct_UClass_AABEarth, &AABEarth::StaticClass, TEXT("/Script/ArenaBattle"), TEXT("AABEarth"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AABEarth);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
