// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ABEnemySetting.generated.h"

/**
 * 
 */
UCLASS(config = ArenaBattle)
class ARENABATTLESETTING_API UABEnemySetting : public UObject
{
	GENERATED_BODY()
	
public:
	UABEnemySetting();

	UPROPERTY(config)
	TArray<FSoftObjectPath> EnemyAssets;

	UPROPERTY(config)
	TArray<FSoftObjectPath> EnemyAnimations;
};
