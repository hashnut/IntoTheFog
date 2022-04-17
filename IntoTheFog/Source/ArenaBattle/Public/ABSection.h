// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/Actor.h"
#include "ABSection.generated.h"



UCLASS()
class ARENABATTLE_API AABSection : public AActor
{
	GENERATED_BODY()
	
public:	
	AABSection();
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	virtual void BeginPlay() override;

private:
	enum class ESectionState : uint8
	{
		COMPLETE = 0,
		BATTLE,
	};

	void SetState(ESectionState NewState);
	ESectionState CurrentState = ESectionState::COMPLETE;

	UFUNCTION()
	void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnGateTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	int32 NumberOfNpc;
	void OnNPCSpawn();

	UFUNCTION()
	void OnKeyNPCDestroyed(AActor* DestroyedActor);

	UFUNCTION()
	void OnSpawnItemBox();

	UFUNCTION()
	void OnSpawnPotion();

	UFUNCTION()
	void OnRespawnPotion(AActor* ABHealthPotion);

private:
	UPROPERTY(VisibleAnywhere, Category = Trigger, Meta = (AllowPrivateAccess = true))
	TArray<UBoxComponent*> GateTriggers;

	UPROPERTY(VisibleAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, Category = Trigger, Meta = (AllowPrivateAccess = true))
	UBoxComponent* Trigger;

	UPROPERTY(EditAnywhere, Category = Spawn, Meta = (AllowPrivateAccess = true))
	float EnemySpawnTime;

	UPROPERTY(EditAnywhere, Category = Spawn, Meta = (AllowPrivateAccess = true))
	float ItemBoxSpawnTime;

	UPROPERTY(EditAnywhere, Category = Spawn, Meta = (AllowPrivateAccess = true))
	float PotionSpawnTime;

	int32 NumberOfBox;
	int32 NumberOfGrass;
	int32 NumberOfTree;
	int32 NumberOfPotion;

	float SectionRadius = 3090.0f;

	FTimerHandle SpawnNPCTimerHandle = {};
	FTimerHandle SpawnItemBoxTimerHandle = {};
	FTimerHandle SpawnPotionTimerHandle = {};

private:
	void OnAssetLoadCompleted();

private:
	FSoftObjectPath EarthAssetToLoad = FSoftObjectPath(nullptr);
	FSoftObjectPath TreeAssetToLoad = FSoftObjectPath(nullptr);

	TSharedPtr<struct FStreamableHandle> AssetStreamingHandle;

};
