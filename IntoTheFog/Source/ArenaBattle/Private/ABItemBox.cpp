// Fill out your copyright notice in the Description page of Project Settings.


#include "ABItemBox.h"
#include "ABWeapon.h"
#include "ABCharacter.h"

#include "ABWeaponOneHand.h"
#include "ABWeaponTwoHand.h"

// Sets default values
AABItemBox::AABItemBox()
{
	PrimaryActorTick.bCanEverTick = false;

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("TRIGGER"));
	Box = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BOX"));
	Effect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("EFFECT"));
	EffectSpawned = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("EFFECT_SPAWNED"));

	RootComponent = Trigger;
	Box->SetupAttachment(RootComponent);
	Effect->SetupAttachment(RootComponent);
	EffectSpawned->SetupAttachment(RootComponent);

	Trigger->SetBoxExtent(FVector(40.0f, 42.0f, 30.0f));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_BOX(TEXT("/Game/InfinityBladeGrassLands/Environments/Breakables/StaticMesh/Box/SM_Env_Breakables_Box1.SM_Env_Breakables_Box1"));
	if (SM_BOX.Succeeded())
	{
		Box->SetStaticMesh(SM_BOX.Object);
	}

	static ConstructorHelpers::FObjectFinder<UParticleSystem> P_CHESTOPEN(TEXT("/Game/InfinityBladeGrassLands/Effects/FX_Treasure/Chest/P_TreasureChest_Open_Mesh.P_TreasureChest_Open_Mesh"));
	if (P_CHESTOPEN.Succeeded())
	{
		Effect->SetTemplate(P_CHESTOPEN.Object);
		Effect->bAutoActivate = false;
	}

	static ConstructorHelpers::FObjectFinder<UParticleSystem> P_GOLDBAG(TEXT("/Game/InfinityBladeEffects/Effects/FX_Treasure/Gold_Bag/P_GoldSparkle_Bag_Lo_2.P_GoldSparkle_Bag_Lo_2"));
	if (P_GOLDBAG.Succeeded())
	{
		EffectSpawned->SetTemplate(P_GOLDBAG.Object);
		EffectSpawned->bAutoActivate = true;
	}

	static ConstructorHelpers::FObjectFinder<USoundBase> S_ITEM_PICKUP(TEXT("/Game/Book/Sounds/S_ItemPickup_2_Cue.S_ItemPickup_2_Cue"));
	if (S_ITEM_PICKUP.Succeeded())
	{
		ItemPickup = S_ITEM_PICKUP.Object;
	}


	Box->SetRelativeLocation(FVector(0.0f, -3.5f, -30.0f));
	EffectSpawned->SetRelativeLocation(FVector(0.0f, 0.0f, -20.0f));

	Trigger->SetCollisionProfileName(TEXT("ItemBox"));
	Box->SetCollisionProfileName(TEXT("NoCollision"));

	int32 RandWeaponClassIndex = FMath::RandRange(0, 1);

	if (RandWeaponClassIndex == 0)
	{
		WeaponItemClass = AABWeaponOneHand::StaticClass();
	}
	else if (RandWeaponClassIndex == 1)
	{
		WeaponItemClass = AABWeaponTwoHand::StaticClass();
	}

}

// Called when the game starts or when spawned
void AABItemBox::BeginPlay()
{
	Super::BeginPlay();
}

void AABItemBox::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AABItemBox::OnCharacterOverlap);
}

void AABItemBox::OnCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ABLOG_S(Warning);

	auto ABCharacter = Cast<AABCharacter>(OtherActor);

		if (nullptr != ABCharacter && nullptr != WeaponItemClass)
		{
			if (ABCharacter->CanSetWeapon())
			{
				auto NewWeapon = GetWorld()->SpawnActor<AABWeapon>(WeaponItemClass, FVector::ZeroVector, FRotator::ZeroRotator);
				ABCharacter->AcquireWeapon(NewWeapon);
				Effect->Activate(true);
				EffectSpawned->Activate(false);
				Box->SetHiddenInGame(true, true);
				SetActorEnableCollision(false);
				Effect->OnSystemFinished.AddDynamic(this, &AABItemBox::OnEffectFinished);

				if (ABCharacter->IsPlayerControlled())
				{
					UGameplayStatics::PlaySound2D(GetWorld(), ItemPickup, 2.5f, 0.6f);
				}
			}
			else
			{
				ABLOG(Warning, TEXT("%s can't equip weapon currently"), *ABCharacter->GetName());
			}
		}
}

void AABItemBox::OnEffectFinished(class UParticleSystemComponent* PSystem)
{
	Destroy();
}

