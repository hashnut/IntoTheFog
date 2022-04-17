// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "ABWeapon.h"
#include "ABWeaponOneHand.generated.h"

/**
 *
 */
UCLASS()
class ARENABATTLE_API AABWeaponOneHand : public AABWeapon
{
	GENERATED_BODY()

	public:
	AABWeaponOneHand();

protected:
	virtual void BeginPlay() override;

private:
	FSoftObjectPath OneHandAssetToLoad = FSoftObjectPath(nullptr);
};
