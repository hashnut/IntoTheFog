// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "ABWeapon.h"
#include "ABWeaponTwoHand.generated.h"

/**
 *
 */
UCLASS()
class ARENABATTLE_API AABWeaponTwoHand : public AABWeapon
{
	GENERATED_BODY()

	public:
	AABWeaponTwoHand();

protected:
	virtual void BeginPlay() override;

private:
	FSoftObjectPath TwoHandAssetToLoad = FSoftObjectPath(nullptr);
};
