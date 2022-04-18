#include "ABSection.h"
#include "ABCharacter.h"
#include "ABItemBox.h"
#include "ABPlayerController.h"
#include "ABGameMode.h"
#include "ABEarthSetting.h"
#include "ABGameInstance.h"
#include "ABEarth.h"
#include "ABTree.h"
#include "ABHealthPotion.h"

AABSection::AABSection()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	RootComponent = Mesh;

	FString AssetPath = TEXT("/Game/Book/StaticMesh/SM_PLAIN_BASIC_HUGE.SM_PLAIN_BASIC_HUGE");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_BASIC(*AssetPath);
	if (SM_BASIC.Succeeded())
	{
		Mesh->SetStaticMesh(SM_BASIC.Object);
	}
	else
	{
		ABLOG(Error, TEXT("Failed to load staticmesh asset. : %s"), *AssetPath);
	}

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("TRIGGER"));
	Trigger->SetBoxExtent(FVector(3090.0f, 3090.0f, 300.0f));
	Trigger->SetupAttachment(RootComponent);
	Trigger->SetRelativeLocation(FVector(0.0f, 0.0f, 250.0f));
	Trigger->SetCollisionProfileName(TEXT("ABTrigger"));
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AABSection::OnTriggerBeginOverlap);

	static FName GateSockets[] = { { TEXT("+XGate")}, {TEXT("-XGate")}, {TEXT("+YGate")}, {TEXT("-YGate")},
								   { TEXT("D1Gate") }, { TEXT("D2Gate") }, { TEXT("D3Gate") }, { TEXT("D4Gate") }};
	for (FName GateSocket : GateSockets)
	{
		ABCHECK(Mesh->DoesSocketExist(GateSocket));

		UBoxComponent* NewGateTrigger = CreateDefaultSubobject<UBoxComponent>(*GateSocket.ToString().Append(TEXT("Trigger")));
		float xPos = 0.0f, yPos = 0.0f, zPos = 300.0f;
		float xExtent = 1200.0f, yExtent = 3000.0f, zExtent = 300.0f;
		if (GateSocket == TEXT("+XGate")) 
		{
			xPos = 1680.0f;
			xExtent = 1200.0f;
			yExtent = 3000.0f;
		} 
		else if (GateSocket == TEXT("-XGate"))
		{
			xPos = -1680.0f;
			xExtent = 1200.0f;
			yExtent = 3000.0f;
		}
		else if (GateSocket == TEXT("+YGate"))
		{
			yPos = 1680.0f;
			xExtent = 3000.0f;
			yExtent = 1200.0f;
		}
		else if (GateSocket == TEXT("-YGate"))
		{
			yPos = -1680.0f;
			xExtent = 3000.0f;
			yExtent = 1200.0f;
		}
		else if (GateSocket == TEXT("D1Gate"))
		{
			xPos = 1680.0f;
			yPos = 1680.0f;
			xExtent = 1200.0f;
			yExtent = 1200.0f;
		}
		else if (GateSocket == TEXT("D2Gate"))
		{
			xPos = 1680.0f;
			yPos = -1680.0f;
			xExtent = 1200.0f;
			yExtent = 1200.0f;
		}
		else if (GateSocket == TEXT("D3Gate"))
		{
			xPos = -1680.0f;
			yPos = 1680.0f;
			xExtent = 1200.0f;
			yExtent = 1200.0f;
		}
		else if (GateSocket == TEXT("D4Gate"))
		{
			xPos = -1680.0f;
			yPos = -1680.0f;
			xExtent = 1200.0f;
			yExtent = 1200.0f;
		}


		NewGateTrigger->SetBoxExtent(FVector(xExtent, yExtent, zExtent));
		NewGateTrigger->SetupAttachment(RootComponent, GateSocket);
		NewGateTrigger->SetRelativeLocation(FVector(xPos, yPos, zPos));
		NewGateTrigger->SetCollisionProfileName(TEXT("ABTrigger"));
		GateTriggers.Add(NewGateTrigger);

		NewGateTrigger->OnComponentBeginOverlap.AddDynamic(this, &AABSection::OnGateTriggerBeginOverlap);
		NewGateTrigger->ComponentTags.Add(GateSocket);
	}

	EnemySpawnTime = 1.0f;
	NumberOfNpc = 2;

	ItemBoxSpawnTime = 0.5f;
	NumberOfBox = 30;

	NumberOfGrass = 200;
	NumberOfTree = 100;

	PotionSpawnTime = 0.5f;
	NumberOfPotion = 30;

	NpcAndItemSpawned = false;
}

void AABSection::OnConstruction(const FTransform& Transform)
{ 
	Super::OnConstruction(Transform);
	SetState(ESectionState::COMPLETE);
}

void AABSection::BeginPlay()
{
	Super::BeginPlay();
	SetState(ESectionState::COMPLETE);
	
	auto DefaultSetting = GetDefault<UABEarthSetting>();
	
	for (int i = 0; i < NumberOfGrass; ++i)
	{
		FVector2D RandXY = FMath::RandPointInCircle(SectionRadius * 1.414);
		GetWorld()->SpawnActor<AABEarth>(GetActorLocation() + FVector(RandXY, -10.0f), FRotator::ZeroRotator);
	}

	for (int i = 0; i < NumberOfTree; ++i)
	{
		FVector2D RandXY = FMath::RandPointInCircle(3000.0f);
		GetWorld()->SpawnActor<AABTree>(GetActorLocation() + FVector(RandXY, -10.0f), FRotator::ZeroRotator);
	}
}

void AABSection::SetState(ESectionState NewState)
{
	switch (NewState)
	{
		case ESectionState::BATTLE:
		{
			if (!NpcAndItemSpawned)
			{
				GetWorld()->GetTimerManager().SetTimer(SpawnNPCTimerHandle, FTimerDelegate::CreateUObject(this, &AABSection::OnNPCSpawn), EnemySpawnTime, false);
				GetWorld()->GetTimerManager().SetTimer(SpawnItemBoxTimerHandle, FTimerDelegate::CreateUObject(this, &AABSection::OnSpawnItemBox), ItemBoxSpawnTime, false);
				GetWorld()->GetTimerManager().SetTimer(SpawnPotionTimerHandle, FTimerDelegate::CreateUObject(this, &AABSection::OnSpawnPotion), PotionSpawnTime, false);
			}
			NpcAndItemSpawned = true;

		}
		break;
		case ESectionState::COMPLETE:
		{
			for (UBoxComponent* GateTrigger : GateTriggers)
			{
				GateTrigger->SetCollisionProfileName(TEXT("ABTrigger"));
			}
		}
		break;
	}

	CurrentState = NewState;
}

void AABSection::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (CurrentState == ESectionState::COMPLETE)
	{
		SetState(ESectionState::BATTLE);
	}
}

void AABSection::OnGateTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ABCHECK(OverlappedComponent->ComponentTags.Num() == 1);

	UBoxComponent* CurrentComponent = Cast<UBoxComponent>(OverlappedComponent);
	CurrentComponent->SetCollisionProfileName(TEXT("NoCollision"));

	FName ComponentTag = OverlappedComponent->ComponentTags[0];
	FName SocketName = FName(*ComponentTag.ToString().Left(2));
	if (!Mesh->DoesSocketExist(SocketName))
		return;

	FVector NewLocation = Mesh->GetSocketLocation(SocketName);

	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams CollisionQueryParam(NAME_None, false, this);
	FCollisionObjectQueryParams ObjectQueryParam(FCollisionObjectQueryParams::InitType::AllObjects);
	bool bResult = GetWorld()->OverlapMultiByObjectType(OverlapResults, NewLocation, FQuat::Identity, ObjectQueryParam, FCollisionShape::MakeSphere(1400.0f), CollisionQueryParam);

	if (!bResult)
	{
		auto NewSection = GetWorld()->SpawnActor<AABSection>(NewLocation, FRotator::ZeroRotator);
	}
	else
	{
		ABLOG(Warning, TEXT("New Section area is not empty"));
	}
}

void AABSection::OnNPCSpawn()
{
	for (int i = 0; i < NumberOfNpc; ++i)
	{
		FVector2D RandXY = FMath::RandPointInCircle(3090.0f);
		auto KeyNPC = GetWorld()->SpawnActor<AABCharacter>(GetActorLocation() + FVector(RandXY, 0.0f) + FVector::UpVector * 88.0f, FRotator::ZeroRotator);
		if (nullptr != KeyNPC)
		{
			KeyNPC->OnDestroyed.AddDynamic(this, &AABSection::OnKeyNPCDestroyed);
		}
	}
}

void AABSection::OnKeyNPCDestroyed(AActor* DestroyedActor)
{
	auto ABCharacter = Cast<AABCharacter>(DestroyedActor);
	ABCHECK(nullptr != ABCharacter);

	auto ABPlayerController = Cast<AABPlayerController>(ABCharacter->LastHitBy);
	ABCHECK(nullptr != ABPlayerController);

	auto ABGameMode = Cast<AABGameMode>(GetWorld()->GetAuthGameMode());
	ABCHECK(nullptr != ABGameMode);
	ABGameMode->AddScore(ABPlayerController);

	FVector2D RandXY = FMath::RandPointInCircle(3090.0f);
	auto KeyNPC = GetWorld()->SpawnActor<AABCharacter>(GetActorLocation() + FVector(RandXY, 0.0f) + FVector::UpVector * 88.0f, FRotator::ZeroRotator);
	if (nullptr != KeyNPC)
	{
		KeyNPC->OnDestroyed.AddDynamic(this, &AABSection::OnKeyNPCDestroyed);
	}
}

void AABSection::OnAssetLoadCompleted()
{

}

void AABSection::OnSpawnItemBox()
{
	for (int i = 0; i < NumberOfBox; ++i)
	{
		FVector2D RandXY = FMath::RandPointInCircle(2000.0f);
		GetWorld()->SpawnActor<AABItemBox>(GetActorLocation() + FVector(RandXY, 30.0f), FRotator::ZeroRotator);
	}
}

void AABSection::OnSpawnPotion()
{
	for (int i = 0; i < NumberOfPotion; ++i)
	{
		FVector2D RandXY = FMath::RandPointInCircle(3000.0f);
		auto NewPotion = GetWorld()->SpawnActor<AABHealthPotion>(GetActorLocation() + FVector(RandXY, 30.0f), FRotator::ZeroRotator);
		NewPotion->OnDestroyed.AddDynamic(this, &AABSection::OnRespawnPotion);
	}
}

void AABSection::OnRespawnPotion(AActor* ABHealthPotion)
{
	FVector2D RandXY = FMath::RandPointInCircle(3000.0f);
	auto NewPotion = GetWorld()->SpawnActor<AABHealthPotion>(GetActorLocation() + FVector(RandXY, 30.0f), FRotator::ZeroRotator);
	NewPotion->OnDestroyed.AddDynamic(this, &AABSection::OnRespawnPotion);
}