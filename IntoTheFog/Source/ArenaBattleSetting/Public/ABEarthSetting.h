// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ABEarthSetting.generated.h"

/**
 * 
 */
UCLASS(config = ArenaBattle)
class ARENABATTLESETTING_API UABEarthSetting : public UObject
{
	GENERATED_BODY()
	
public:
	UABEarthSetting();

	UPROPERTY(config)
	TArray<FSoftObjectPath> EarthAssets;

	UPROPERTY(config)
	TArray<FSoftObjectPath> TreeAssets;
};
