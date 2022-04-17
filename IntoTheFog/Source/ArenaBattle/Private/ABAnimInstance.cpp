// Fill out your copyright notice in the Description page of Project Settings.


#include "ABAnimInstance.h"

UABAnimInstance::UABAnimInstance()
{
	CurrentPawnSpeed = 0.0f;
	IsInAir = false;
	IsDead = false;

	static ConstructorHelpers::FObjectFinder<UAnimMontage>ATTACK_FIST_MONTAGE(TEXT("/Game/Book/Montage/Fist/Fist_Attack_Montage.Fist_Attack_Montage"));
	if (ATTACK_FIST_MONTAGE.Succeeded())
	{
		AttackFistMontage = ATTACK_FIST_MONTAGE.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage>ATTACK_ONEHAND_MONTAGE(TEXT("/Game/Book/Animations/SK_Mannequin_Skeleton_Montage.SK_Mannequin_Skeleton_Montage"));
	if (ATTACK_ONEHAND_MONTAGE.Succeeded())
	{
		AttackOneHandMontage = ATTACK_ONEHAND_MONTAGE.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage>DRAW_ONEHAND_MONTAGE(TEXT("/Game/Book/Montage/OneHand/Draw_Sword_Montage.Draw_Sword_Montage"));
	if (DRAW_ONEHAND_MONTAGE.Succeeded())
	{
		DrawOneHandMontage = DRAW_ONEHAND_MONTAGE.Object;
	}
	
	static ConstructorHelpers::FObjectFinder<UAnimMontage>SHEATH_ONEHAND_MONTAGE(TEXT("/Game/Book/Montage/OneHand/Sheath_Sword_Montage.Sheath_Sword_Montage"));
	if (SHEATH_ONEHAND_MONTAGE.Succeeded())
	{
		SheathOneHandMontage = SHEATH_ONEHAND_MONTAGE.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage>ATTACK_TWOHAND_MONTAGE(TEXT("/Game/Book/Montage/TwoHand/Great_Sword_Slash_1_Montage.Great_Sword_Slash_1_Montage"));
	if (ATTACK_TWOHAND_MONTAGE.Succeeded())
	{
		AttackTwoHandMontage = ATTACK_TWOHAND_MONTAGE.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage>DRAW_TWOHAND_MONTAGE(TEXT("/Game/Book/Montage/TwoHand/Great_Sword_Draw_Montage.Great_Sword_Draw_Montage"));
	if (DRAW_TWOHAND_MONTAGE.Succeeded())
	{
		DrawTwoHandMontage = DRAW_TWOHAND_MONTAGE.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage>SHEATH_TWOHAND_MONTAGE(TEXT("/Game/Book/Montage/TwoHand/Great_Sword_Sheath_Montage.Great_Sword_Sheath_Montage"));
	if (SHEATH_TWOHAND_MONTAGE.Succeeded())
	{
		SheathTwoHandMontage = SHEATH_TWOHAND_MONTAGE.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage>JUMP_MONTAGE(TEXT("/Game/Book/Montage/Common/Jump_Montage.Jump_Montage"));
	if (JUMP_MONTAGE.Succeeded())
	{
		JumpMontage = JUMP_MONTAGE.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage>ROLL_MONTAGE(TEXT("/Game/Book/Montage/Common/Roll_Montage.Roll_Montage"));
	if (ROLL_MONTAGE.Succeeded())
	{
		RollMontage = ROLL_MONTAGE.Object;
	}

	static ConstructorHelpers::FObjectFinder<UAnimMontage>DEAD_MONTAGE(TEXT("/Game/Book/Montage/Common/WarriorDead_Montage.WarriorDead_Montage"));
	if (DEAD_MONTAGE.Succeeded())
	{
		DeadMontage = DEAD_MONTAGE.Object;
	}

} 

void UABAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (!::IsValid(Pawn))
		return;

	if (!IsDead)
	{
		CurrentPawnSpeed = Pawn->GetVelocity().Size();
		auto Character = Cast<ACharacter>(Pawn);
		if (Character)
		{
			IsInAir = Character->GetMovementComponent()->IsFalling();
		}
	}
}

void UABAnimInstance::PlayAttackFistMontage()
{
	ABCHECK(!IsDead);
	Montage_Play(AttackFistMontage, 0.8f);
}

void UABAnimInstance::JumpToAttackFistMontageSection(int32 NewSection)
{
	ABCHECK(!IsDead);
	ABCHECK(Montage_IsPlaying(AttackFistMontage));
	Montage_JumpToSection(GetAttackMontageSectionName(NewSection));
}

void UABAnimInstance::PlayAttackOneHandMontage()
{
	ABCHECK(!IsDead);
	Montage_Play(AttackOneHandMontage, 0.6f);
}

void UABAnimInstance::JumpToAttackOneHandMontageSection(int32 NewSection)
{
	ABCHECK(!IsDead);
	ABCHECK(Montage_IsPlaying(AttackOneHandMontage));
	Montage_JumpToSection(GetAttackMontageSectionName(NewSection));
}

void UABAnimInstance::PlayDrawOneHandMontage()
{
	ABCHECK(!IsDead);
	Montage_Play(DrawOneHandMontage, 1.0f);
}

void UABAnimInstance::PlaySheathOneHandMontage()
{
	ABCHECK(!IsDead);
	Montage_Play(SheathOneHandMontage, 1.0f);
}

void UABAnimInstance::PlayAttackTwoHandMontage()
{
	ABCHECK(!IsDead);
	Montage_Play(AttackTwoHandMontage, 1.0f);
}

void UABAnimInstance::PlayDrawTwoHandMontage()
{
	ABCHECK(!IsDead);
	Montage_Play(DrawTwoHandMontage, 1.0f);
}

void UABAnimInstance::PlaySheathTwoHandMontage()
{
	ABCHECK(!IsDead);
	Montage_Play(SheathTwoHandMontage, 1.0f);
}

void UABAnimInstance::PlayJumpMontage()
{
	ABCHECK(!IsDead);
	Montage_Play(JumpMontage, 1.2f);
}

void UABAnimInstance::PlayRollMontage()
{
	ABCHECK(!IsDead);
	Montage_Play(RollMontage, 1.8f);
}

void UABAnimInstance::SetDeadAnim()
{
	UABAnimInstance::IsDead = true;
}

void UABAnimInstance::AnimNotify_AttackHitCheck()
{
	OnAttackHitCheck.Broadcast();
}

void UABAnimInstance::AnimNotify_NextAttackCheck()
{
	OnNextAttackCheck.Broadcast();
}

void UABAnimInstance::AnimNotify_NextAttackFistCheck()
{
	OnNextAttackFistCheck.Broadcast();
}

void UABAnimInstance::AnimNotify_AttackEndCheck()
{
	OnAttackEndCheck.Broadcast();
}

void UABAnimInstance::AnimNotify_JumpEndCheck()
{
	OnJumpEndCheck.Broadcast();
}

void UABAnimInstance::AnimNotify_RollEndCheck()
{
	OnRollEndCheck.Broadcast();
}

void UABAnimInstance::AnimNotify_DrawOneHandCheck()
{
	OnDrawOneHandCheck.Broadcast();
}

void UABAnimInstance::AnimNotify_DrawTwoHandCheck()
{
	OnDrawTwoHandCheck.Broadcast();
}

void UABAnimInstance::AnimNotify_SheathOneHandCheck()
{
	OnSheathOneHandCheck.Broadcast();
}

void UABAnimInstance::AnimNotify_SheathTwoHandCheck()
{
	OnSheathTwoHandCheck.Broadcast();
}

FName UABAnimInstance::GetAttackMontageSectionName(int32 Section)
{
	ABCHECK(FMath::IsWithinInclusive<int32>(Section, 1, 4), NAME_None);
	return FName(*FString::Printf(TEXT("Attack%d"), Section));
}
