// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ArenaBattle/Public/ABWeaponOneHand.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABWeaponOneHand() {}
// Cross Module References
	ARENABATTLE_API UClass* Z_Construct_UClass_AABWeaponOneHand_NoRegister();
	ARENABATTLE_API UClass* Z_Construct_UClass_AABWeaponOneHand();
	ARENABATTLE_API UClass* Z_Construct_UClass_AABWeapon();
	UPackage* Z_Construct_UPackage__Script_ArenaBattle();
// End Cross Module References
	void AABWeaponOneHand::StaticRegisterNativesAABWeaponOneHand()
	{
	}
	UClass* Z_Construct_UClass_AABWeaponOneHand_NoRegister()
	{
		return AABWeaponOneHand::StaticClass();
	}
	struct Z_Construct_UClass_AABWeaponOneHand_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AABWeaponOneHand_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AABWeapon,
		(UObject* (*)())Z_Construct_UPackage__Script_ArenaBattle,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABWeaponOneHand_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
		{ "IncludePath", "ABWeaponOneHand.h" },
		{ "ModuleRelativePath", "Public/ABWeaponOneHand.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AABWeaponOneHand_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AABWeaponOneHand>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AABWeaponOneHand_Statics::ClassParams = {
		&AABWeaponOneHand::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AABWeaponOneHand_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AABWeaponOneHand_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AABWeaponOneHand()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AABWeaponOneHand_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AABWeaponOneHand, 2083175144);
	template<> ARENABATTLE_API UClass* StaticClass<AABWeaponOneHand>()
	{
		return AABWeaponOneHand::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AABWeaponOneHand(Z_Construct_UClass_AABWeaponOneHand, &AABWeaponOneHand::StaticClass, TEXT("/Script/ArenaBattle"), TEXT("AABWeaponOneHand"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AABWeaponOneHand);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
