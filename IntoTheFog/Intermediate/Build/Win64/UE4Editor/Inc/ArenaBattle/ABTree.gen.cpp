// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ArenaBattle/Public/ABTree.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABTree() {}
// Cross Module References
	ARENABATTLE_API UClass* Z_Construct_UClass_AABTree_NoRegister();
	ARENABATTLE_API UClass* Z_Construct_UClass_AABTree();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ArenaBattle();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void AABTree::StaticRegisterNativesAABTree()
	{
	}
	UClass* Z_Construct_UClass_AABTree_NoRegister()
	{
		return AABTree::StaticClass();
	}
	struct Z_Construct_UClass_AABTree_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Tree_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Tree;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AABTree_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ArenaBattle,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABTree_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ABTree.h" },
		{ "ModuleRelativePath", "Public/ABTree.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AABTree_Statics::NewProp_Tree_MetaData[] = {
		{ "Category", "Earth" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ABTree.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AABTree_Statics::NewProp_Tree = { "Tree", nullptr, (EPropertyFlags)0x00400000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AABTree, Tree), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AABTree_Statics::NewProp_Tree_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AABTree_Statics::NewProp_Tree_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AABTree_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABTree_Statics::NewProp_Tree,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AABTree_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AABTree>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AABTree_Statics::ClassParams = {
		&AABTree::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AABTree_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AABTree_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AABTree_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AABTree_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AABTree()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AABTree_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AABTree, 1196377484);
	template<> ARENABATTLE_API UClass* StaticClass<AABTree>()
	{
		return AABTree::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AABTree(Z_Construct_UClass_AABTree, &AABTree::StaticClass, TEXT("/Script/ArenaBattle"), TEXT("AABTree"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AABTree);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
