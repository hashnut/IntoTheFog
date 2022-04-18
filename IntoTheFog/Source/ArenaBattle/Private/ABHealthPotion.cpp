// Fill out your copyright notice in the Description page of Project Settings.


#include "ABHealthPotion.h"
#include "ABCharacter.h"
#include "ABItemSetting.h"
#include "ABCharacterStatComponent.h"
#include "ABSection.h"

// Sets default values
AABHealthPotion::AABHealthPotion()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("TRIGGER"));
	Potion = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("POTION"));
	EffectTaken = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("EFFECT_Taken"));
	EffectSpawned = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("EFFECT_SPAWNED"));

	RootComponent = Trigger;
	Potion->SetupAttachment(RootComponent);
	EffectTaken->SetupAttachment(RootComponent);
	EffectSpawned->SetupAttachment(RootComponent);

	Trigger->SetBoxExtent(FVector(30.0f, 30.0f, 50.0f));

	auto DefaultSetting = GetDefault<UABItemSetting>();

	uint8 PotionIndex = FMath::RandRange(0, DefaultSetting->PotionAssets.Num() - 1);
	if (PotionIndex == 0)
	{
		CurrentPotionType = EPotionType::HEALTH;
	}
	else if (PotionIndex == 1)
	{
		CurrentPotionType = EPotionType::MISC;
	}
	else if (PotionIndex == 2)
	{
		CurrentPotionType = EPotionType::REGEN;
	}

	PotionAssetToLoad = DefaultSetting->PotionAssets[PotionIndex];
	ConstructorHelpers::FObjectFinder<UStaticMesh> SM_POTION(*PotionAssetToLoad.ToString());
	if (SM_POTION.Succeeded())
	{
		Potion->SetStaticMesh(SM_POTION.Object);
	}

	static ConstructorHelpers::FObjectFinder<UParticleSystem> P_EFFECT_TAKEN(TEXT("/Game/InfinityBladeEffects/Effects/FX_Ability/Heal/P_Heal_Pickup.P_Heal_Pickup"));
	if (P_EFFECT_TAKEN.Succeeded())
	{
		EffectTaken->SetTemplate(P_EFFECT_TAKEN.Object);
		EffectTaken->bAutoActivate = false;
	}

	static ConstructorHelpers::FObjectFinder<UParticleSystem> P_EFFECT_SPAWNED(TEXT("/Game/InfinityBladeEffects/Effects/FX_Treasure/Gold_Bag/P_DeadMans_Loot.P_DeadMans_Loot"));
	if (P_EFFECT_SPAWNED.Succeeded())
	{
		EffectSpawned->SetTemplate(P_EFFECT_SPAWNED.Object);
		EffectSpawned->bAutoActivate = true;
	}

	Potion->SetRelativeLocation(FVector(0.0f, -3.5f, -30.0f));
	EffectSpawned->SetRelativeLocation(FVector(0.0f, 0.0f, -30.0f));

	Trigger->SetCollisionProfileName(TEXT("ItemBox"));
	Potion->SetCollisionProfileName(TEXT("NoCollision"));

	static ConstructorHelpers::FObjectFinder<USoundBase> POTION_HEAL(TEXT("/Game/Book/Sounds/S_PotionHeal_Cue.S_PotionHeal_Cue"));
	if (POTION_HEAL.Succeeded())
	{
		PotionHeal = POTION_HEAL.Object;
	}

	static ConstructorHelpers::FObjectFinder<USoundBase> LEVEL_DOWN(TEXT("/Game/Book/Sounds/S_PotionHeal_Cue.S_PotionHeal_Cue"));
	if (LEVEL_DOWN.Succeeded())
	{
		LevelDown = LEVEL_DOWN.Object;
	}
}

void AABHealthPotion::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AABHealthPotion::OnCharacterOverlap);
}

// Called when the game starts or when spawned
void AABHealthPotion::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AABHealthPotion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AABHealthPotion::OnCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto ABCharacter = Cast<AABCharacter>(OtherActor);

	if (nullptr != ABCharacter)
	{
		int32 LevelDownOrNot = 0;
		float HPHealPercentage;

		switch (CurrentPotionType) 
		{
			case EPotionType::HEALTH:
			{
				HPHealPercentage = 1.3f;
				//LevelDownOrNot = FMath::RandRange(1, 100);
			}
			break;
			case EPotionType::MISC:
			{
				HPHealPercentage = FMath::RandRange(1.5f, 1.9f);
				//LevelDownOrNot = FMath::RandRange(1, 105);
			}
			break;
			case EPotionType::REGEN:
			{
				HPHealPercentage = FMath::RandRange(1.0f, 2.0f);
				//LevelDownOrNot = FMath::RandRange(1, 111);
			}
			break;
			default:
				HPHealPercentage = 1.0f;
		}

		ABCharacter->CharacterStat->SetHPHeal(HPHealPercentage);
		if (LevelDownOrNot >= 100 && ABCharacter->IsPlayerControlled())
		{
			int32 NewLevel = FMath::Clamp<int32>(ABCharacter->CharacterStat->GetCurrentLevel()-1, 1, 99);
			ABCharacter->CharacterStat->SetNewLevel(NewLevel);
			UGameplayStatics::PlaySound2D(GetWorld(), LevelDown, 1.0f, 0.8f);
		}

		EffectTaken->Activate(true);
		EffectSpawned->Activate(false);
		Potion->SetHiddenInGame(true, true);
		SetActorEnableCollision(false);
		GetWorld()->GetTimerManager().SetTimer(DestroyPotionTimerHandle, FTimerDelegate::CreateUObject(this, &AABHealthPotion::OnDestroyPotion), 0.8f, false);

		if (ABCharacter->IsPlayerControlled())
		{
			UGameplayStatics::PlaySound2D(GetWorld(), PotionHeal, 0.6f, 0.8f);
		}
	}

}

void AABHealthPotion::OnDestroyPotion()
{
	Destroy();
}

AABHealthPotion::EPotionType AABHealthPotion::GetCurrentPotionType()
{
	return CurrentPotionType;
}

void AABHealthPotion::SetCurrentPotionType(EPotionType NewPotionType)
{
	CurrentPotionType = NewPotionType;
}