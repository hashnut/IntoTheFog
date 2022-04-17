// Fill out your copyright notice in the Description page of Project Settings.


#include "ABGameInstance.h"

UABGameInstance::UABGameInstance()
{
	FString CharacterDataPath = TEXT("/Game/Book/GameData/ABCharacterData.ABCharacterData");
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_ABCHARACTER(*CharacterDataPath);
	ABCHECK(DT_ABCHARACTER.Succeeded());
	ABCharacterTable = DT_ABCHARACTER.Object;
	ABCHECK(ABCharacterTable->GetRowMap().Num() > 0);

	FString EnemyDataPath = TEXT("/Game/Book/GameData/ABEnemyData.ABEnemyData");
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_ABENEMY(*EnemyDataPath);
	ABCHECK(DT_ABENEMY.Succeeded());
	ABEnemyTable = DT_ABENEMY.Object;
	ABCHECK(ABEnemyTable->GetRowMap().Num() > 0);
}

void UABGameInstance::Init()
{
	Super::Init();
	ABLOG(Warning, TEXT("DropExp of Level 20 ABCharacter : %d"), GetABCharacterData(20)->DropExp);
	ABLOG(Warning, TEXT("MaxHp of %s : %f"), TEXT("FrostGiant"), GetABEnemyData(FName(TEXT("FrostGiant")))->MaxHP);
}

FABCharacterData* UABGameInstance::GetABCharacterData(int32 Level)
{
	return ABCharacterTable->FindRow<FABCharacterData>(*FString::FromInt(Level), TEXT(""));
}

FABEnemyData* UABGameInstance::GetABEnemyData(FName MonsterName)
{
	return ABEnemyTable->FindRow<FABEnemyData>(MonsterName, TEXT(""));
}