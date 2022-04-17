// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ABItemSetting.generated.h"

/**
 * 
 */
UCLASS(config = ArenaBattle)
class ARENABATTLESETTING_API UABItemSetting : public UObject
{
	GENERATED_BODY()
	
public:
	UABItemSetting();

	UPROPERTY(config)
	TArray<FSoftObjectPath> PotionAssets;
};
