// Fill out your copyright notice in the Description page of Project Settings.


#include "ABTree.h"
#include "ABEarthSetting.h"

// Sets default values
AABTree::AABTree()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Tree = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TREE"));
	RootComponent = Tree;

	auto DefaultSetting = GetDefault<UABEarthSetting>();

	int32 RandIndex = FMath::RandRange(0, DefaultSetting->TreeAssets.Num() - 1);
	TreeAssetToLoad = DefaultSetting->TreeAssets[RandIndex];

	ConstructorHelpers::FObjectFinder<UStaticMesh> SM_TREE(*TreeAssetToLoad.ToString());
	Tree->SetStaticMesh(SM_TREE.Object);
}

// Called when the game starts or when spawned
void AABTree::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AABTree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

