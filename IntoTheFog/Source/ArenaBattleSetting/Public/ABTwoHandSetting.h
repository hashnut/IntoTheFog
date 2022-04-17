// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ABTwoHandSetting.generated.h"

/**
 * 
 */
UCLASS(config = ArenaBattle)
class ARENABATTLESETTING_API UABTwoHandSetting : public UObject
{
	GENERATED_BODY()
	
public:
	UABTwoHandSetting();

	UPROPERTY(config)
	TArray<FSoftObjectPath> TwoHandAssets;
};
