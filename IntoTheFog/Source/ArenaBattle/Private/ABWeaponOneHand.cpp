// Fill out your copyright notice in the Description page of Project Settings.


#include "ABWeaponOneHand.h"
#include "ABOneHandSetting.h"

AABWeaponOneHand::AABWeaponOneHand()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ONEHAND_WEAPON"));
	RootComponent = Weapon;

	auto DefaultSetting = GetDefault<UABOneHandSetting>();

	int32 RandIndex = FMath::RandRange(0, DefaultSetting->OneHandAssets.Num() - 1);
	OneHandAssetToLoad = DefaultSetting->OneHandAssets[RandIndex];

	ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_ONEHAND(*OneHandAssetToLoad.ToString());

	if (SK_ONEHAND.Succeeded())
	{
		Weapon->SetSkeletalMesh(SK_ONEHAND.Object);
	}
	Weapon->SetCollisionProfileName(TEXT("NoCollision"));

	AttackRange = 120.0f;
	AttackDamageMin = -1.5f;
	AttackDamageMax = 10.0f;
	AttackModifierMin = 0.85f;
	AttackModifierMax = 1.25f;
}

void AABWeaponOneHand::BeginPlay()
{
	Super::BeginPlay();

	ABLOG(Warning, TEXT("OneHand Weapon Setting Completed!"));
}
