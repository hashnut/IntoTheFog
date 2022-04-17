// Fill out your copyright notice in the Description page of Project Settings.


#include "ABEarth.h"
#include "ABEarthSetting.h"

// Sets default values
AABEarth::AABEarth()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Grass = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Grass"));
	RootComponent = Grass;

	auto DefaultSetting = GetDefault<UABEarthSetting>();

	int32 RandIndex = FMath::RandRange(0, DefaultSetting->EarthAssets.Num() - 1);
	EarthAssetToLoad = DefaultSetting->EarthAssets[RandIndex];

	ConstructorHelpers::FObjectFinder<UStaticMesh> SM_GRASS(*EarthAssetToLoad.ToString());

	Grass->SetStaticMesh(SM_GRASS.Object);
}

// Called when the game starts or when spawned
void AABEarth::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AABEarth::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

