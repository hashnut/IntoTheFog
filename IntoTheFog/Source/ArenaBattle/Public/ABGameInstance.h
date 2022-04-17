// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "Engine/DataTable.h"
#include "Engine/GameInstance.h"
#include "Engine/StreamableManager.h"
#include "ABGameInstance.generated.h"

USTRUCT(BlueprintType)
struct FABCharacterData : public FTableRowBase
{
	GENERATED_BODY()

public:
	FABCharacterData() : Level(1), MaxHP(100.0f), Attack(10.0f), DropExp(30), NextExp(30) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerData")
	int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerData")
	float MaxHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerData")
	float Attack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerData")
	int32 DropExp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerData")
	int32 NextExp;
};

USTRUCT(BlueprintType)
struct FABEnemyData : public FTableRowBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyData")
	FName Monster;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyData")
	float MaxHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyData")
	float Attack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyData")
	int32 DropExp;
};

UCLASS()
class ARENABATTLE_API UABGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UABGameInstance();

	virtual void Init() override;
	FABCharacterData* GetABCharacterData(int32 Level);
	FABEnemyData* GetABEnemyData(FName Monster);

	FStreamableManager StreamableManager;

private:
	UPROPERTY()
	class UDataTable* ABCharacterTable;

	UPROPERTY()
	class UDataTable* ABEnemyTable;
};
