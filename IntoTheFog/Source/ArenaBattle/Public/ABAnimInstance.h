// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Arenabattle.h"
#include "Animation/AnimInstance.h"
#include "ABAnimInstance.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnNextAttackFistCheckDelegate);
DECLARE_MULTICAST_DELEGATE(FOnNextAttackCheckDelegate);
DECLARE_MULTICAST_DELEGATE(FOnNextAttackFistCheckDelegate);
DECLARE_MULTICAST_DELEGATE(FOnAttackHitCheckDelegate);
DECLARE_MULTICAST_DELEGATE(FOnAttackEndCheckDelegate);
DECLARE_MULTICAST_DELEGATE(FOnJumpEndCheckDelegate);
DECLARE_MULTICAST_DELEGATE(FOnRollEndCheckDelegate);
DECLARE_MULTICAST_DELEGATE(FOnDrawOneHandCheckDelegate);
DECLARE_MULTICAST_DELEGATE(FOnDrawTwoHandCheckDelegate);
DECLARE_MULTICAST_DELEGATE(FOnSheathOneHandCheckDelegate);
DECLARE_MULTICAST_DELEGATE(FOnSheathTwoHandCheckDelegate);

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UABAnimInstance();
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	void PlayAttackFistMontage();
	void JumpToAttackFistMontageSection(int32 NewSection);

	void PlayAttackOneHandMontage();
	void JumpToAttackOneHandMontageSection(int32 NewSection);
	void PlayDrawOneHandMontage();
	void PlaySheathOneHandMontage();

	void PlayAttackTwoHandMontage();
	void PlayDrawTwoHandMontage();
	void PlaySheathTwoHandMontage();

	void PlayJumpMontage();	
	void PlayRollMontage();



public:
	FOnNextAttackFistCheckDelegate OnNextAttackFistCheckDelegate;
	FOnNextAttackCheckDelegate OnNextAttackCheck;
	FOnNextAttackFistCheckDelegate OnNextAttackFistCheck;
	FOnAttackHitCheckDelegate OnAttackHitCheck;
	FOnAttackEndCheckDelegate OnAttackEndCheck;
	FOnJumpEndCheckDelegate OnJumpEndCheck;
	FOnRollEndCheckDelegate OnRollEndCheck;
	FOnDrawOneHandCheckDelegate OnDrawOneHandCheck;
	FOnDrawTwoHandCheckDelegate OnDrawTwoHandCheck;
	FOnSheathOneHandCheckDelegate OnSheathOneHandCheck;
	FOnSheathTwoHandCheckDelegate OnSheathTwoHandCheck;

	void SetDeadAnim();

private:
	UFUNCTION()
	void AnimNotify_AttackHitCheck();

	UFUNCTION()
	void AnimNotify_NextAttackCheck();

	UFUNCTION()
	void AnimNotify_NextAttackFistCheck();

	UFUNCTION()
	void AnimNotify_AttackEndCheck();

	UFUNCTION()
	void AnimNotify_JumpEndCheck();

	UFUNCTION()
	void AnimNotify_RollEndCheck();

	UFUNCTION()
	void AnimNotify_DrawOneHandCheck();

	UFUNCTION()
	void AnimNotify_DrawTwoHandCheck();

	UFUNCTION()
	void AnimNotify_SheathOneHandCheck();

	UFUNCTION()
	void AnimNotify_SheathTwoHandCheck();

	FName GetAttackMontageSectionName(int32 Section);

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta=(AllowPrivateAccess=true))
	float CurrentPawnSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsInAir;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsDead;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	UAnimMontage* AttackFistMontage;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	UAnimMontage* AttackOneHandMontage;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	UAnimMontage* DrawOneHandMontage;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	UAnimMontage* SheathOneHandMontage;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	UAnimMontage* AttackTwoHandMontage;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	UAnimMontage* DrawTwoHandMontage;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	UAnimMontage* SheathTwoHandMontage;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Movement, Meta = (AllowPrivateAccess = true))
	UAnimMontage* JumpMontage;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Movement, Meta = (AllowPrivateAccess = true))
	UAnimMontage* RollMontage;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Movement, Meta = (AllowPrivateAccess = true))
	UAnimMontage* DeadMontage;
};
