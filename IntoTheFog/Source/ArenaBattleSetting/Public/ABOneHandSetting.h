// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ABOneHandSetting.generated.h"

/**
 * 
 */
UCLASS(config = ArenaBattle)
class ARENABATTLESETTING_API UABOneHandSetting : public UObject
{
	GENERATED_BODY()
	
public:
	UABOneHandSetting();

	UPROPERTY(config)
	TArray<FSoftObjectPath> OneHandAssets;
};
