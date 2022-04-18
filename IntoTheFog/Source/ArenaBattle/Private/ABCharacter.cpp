// Fill out your copyright notice in the Description page of Project Settings.


#include "ABCharacter.h"
#include "ABAnimInstance.h"
#include "ABWeapon.h"
#include "ABCharacterStatComponent.h"
#include "DrawDebugHelpers.h"
#include "Components/WidgetComponent.h"
#include "ABCharacterWidget.h"
#include "ABAIController.h"
#include "ABCharacterSetting.h"
#include "ABGameInstance.h"
#include "ABPlayerController.h"
#include "ABPlayerState.h"
#include "ABHUDWidget.h"
#include "ABGameMode.h"

// Sets default values
AABCharacter::AABCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));
	CharacterStat = CreateDefaultSubobject<UABCharacterStatComponent>(TEXT("CHARACTERSTAT"));
	HPBarWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HPBARWIDGET"));

	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);
	HPBarWidget->SetupAttachment(GetMesh());

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_CARDBOARD(TEXT("/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Cardboard.SK_CharM_Cardboard"));
	if (SK_CARDBOARD.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_CARDBOARD.Object);
	}

	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	static ConstructorHelpers::FClassFinder<UAnimInstance> WARRIOR_ANIM(TEXT("/Game/Book/Animations/WarriorAnimBlueprint.WarriorAnimBlueprint_C"));
	if (WARRIOR_ANIM.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(WARRIOR_ANIM.Class);
	}
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("ABCharacter"));

	HPBarWidget->SetRelativeLocation(FVector(0.0f, 0.0f, 180.0f));
	HPBarWidget->SetWidgetSpace(EWidgetSpace::Screen);
	static ConstructorHelpers::FClassFinder<UUserWidget> UI_HUD(TEXT("/Game/Book/UI/UI_HPBar.UI_HPBar_C"));
	if (UI_HUD.Succeeded())
	{
		HPBarWidget->SetWidgetClass(UI_HUD.Class);
		HPBarWidget->SetDrawSize(FVector2D(150.0f, 50.0f));
	}

	static ConstructorHelpers::FObjectFinder<USoundBase> HIT_FIST(TEXT("/Game/Book/Sounds/S_HitPunch2_Cue.S_HitPunch2_Cue"));
	if (HIT_FIST.Succeeded())
	{
		HitFist = HIT_FIST.Object;
	}

	static ConstructorHelpers::FObjectFinder<USoundBase> HIT_ONEHAND(TEXT("/Game/Book/Sounds/S_OneHand_Real_Slash_1_Cue.S_OneHand_Real_Slash_1_Cue"));
	if (HIT_ONEHAND.Succeeded())
	{
		HitOneHand = HIT_ONEHAND.Object;
	}

	static ConstructorHelpers::FObjectFinder<USoundBase> HIT_TWOHAND(TEXT("/Game/Book/Sounds/S_TwoHand_Real_Slash_1_Cue.S_TwoHand_Real_Slash_1_Cue"));
	if (HIT_TWOHAND.Succeeded())
	{
		HitTwoHand = HIT_TWOHAND.Object;
	}

	static ConstructorHelpers::FObjectFinder<USoundBase> DRAW_ONEHAND(TEXT("/Game/Book/Sounds/S_OneHand_Draw_Cue.S_OneHand_Draw_Cue"));
	if (DRAW_ONEHAND.Succeeded())
	{
		DrawOneHand = DRAW_ONEHAND.Object;
	}

	static ConstructorHelpers::FObjectFinder<USoundBase> SHEATH_ONEHAND(TEXT("/Game/Book/Sounds/S_OneHand_Real_Slash_1_Cue.S_OneHand_Real_Slash_1_Cue"));
	if (SHEATH_ONEHAND.Succeeded())
	{
		SheathOneHand = SHEATH_ONEHAND.Object;
	}

	static ConstructorHelpers::FObjectFinder<USoundBase> DRAW_TWOHAND(TEXT("/Game/Book/Sounds/S_TwoHand_Draw_Cue.S_TwoHand_Draw_Cue"));
	if (DRAW_TWOHAND.Succeeded())
	{
		DrawTwoHand = DRAW_TWOHAND.Object;
	}

	static ConstructorHelpers::FObjectFinder<USoundBase> SHEATH_TWOHAND(TEXT("/Game/Book/Sounds/S_TwoHand_Draw_Cue.S_TwoHand_Draw_Cue"));
	if (SHEATH_TWOHAND.Succeeded())
	{
		SheathTwoHand = SHEATH_TWOHAND.Object;
	}

	SetControlMode(EControlMode::Shoulder);

	AIControllerClass = AABAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	ArmLengthSpeed = 3.0f;
	ArmRotationSpeed = 10.0f;
	GetCharacterMovement()->JumpZVelocity = 400.0f;
	MaxCombo = 4;
	AttackEndComboState();

	AttackRange = 80.0f;
	AttackRadius = 50.0f;

	AssetIndex = 4;

	SetActorHiddenInGame(true);
	HPBarWidget->SetHiddenInGame(true);
	SetCanBeDamaged(false);

	DeadTimer = 3.0f;
	WeaponAcquired = 0;

	SetCurrentMovementState(EMovementState::Idle);
}

void AABCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	ABAnim = Cast<UABAnimInstance>(GetMesh()->GetAnimInstance());
	ABCHECK(nullptr != ABAnim);

	ABAnim->OnMontageEnded.AddDynamic(this, &AABCharacter::OnEveryMontageEnded);
	ABAnim->OnAttackEndCheck.AddUObject(this, &AABCharacter::OnAttackMontageEnded);

	ABAnim->OnNextAttackCheck.AddLambda([this]() -> void {
		ABLOG(Warning, TEXT("OnNextAttackCheck"));
		CanNextCombo = false;
		if (IsComboInputOn)
		{
			AttackStartComboState();
			ABAnim->JumpToAttackOneHandMontageSection(CurrentCombo);
		}
		});

	ABAnim->OnNextAttackFistCheck.AddLambda([this]() -> void {
		ABLOG(Warning, TEXT("OnNextAttackFistCheck"));
		CanNextCombo = false;
		if (IsComboInputOn)
		{
			AttackStartComboState();
			ABAnim->JumpToAttackFistMontageSection(CurrentCombo);
		}
		});

	ABAnim->OnAttackHitCheck.AddUObject(this, &AABCharacter::AttackCheck);

	ABAnim->OnDrawOneHandCheck.AddUObject(this, &AABCharacter::DrawOneHandCheck);
	ABAnim->OnDrawTwoHandCheck.AddUObject(this, &AABCharacter::DrawTwoHandCheck);
	ABAnim->OnSheathOneHandCheck.AddUObject(this, &AABCharacter::SheathOneHandCheck);
	ABAnim->OnSheathTwoHandCheck.AddUObject(this, &AABCharacter::SheathTwoHandCheck);

	ABAnim->OnJumpEndCheck.AddLambda([this]() -> void {
		ABLOG(Warning, TEXT("Jump has ended!"));
		SetCurrentMovementState(EMovementState::Idle);
		});

	ABAnim->OnRollEndCheck.AddLambda([this]() -> void {
		ABLOG(Warning, TEXT("Roll has ended!"));
		AttackEndComboState();
		SetCurrentMovementState(EMovementState::Idle);
		});

	CharacterStat->OnHPIsZero.AddLambda([this]()->void {
		ABLOG(Warning, TEXT("OnHPIsZero"));
		ABAnim->SetDeadAnim();
		});
}

// Called when the game starts or when spawned
void AABCharacter::BeginPlay()
{
	Super::BeginPlay();

	bIsPlayer = IsPlayerControlled();
	if (bIsPlayer)
	{
		ABPlayerController = Cast<AABPlayerController>(GetController());
		ABCHECK(nullptr != ABPlayerController);
	}
	else
	{
		ABAIController = Cast<AABAIController>(GetController());
		ABCHECK(nullptr != ABAIController);
	}

	auto DefaultSetting = GetDefault<UABCharacterSetting>();

	if (bIsPlayer)
	{
		auto ABPlayerState = Cast<AABPlayerState>(GetPlayerState());
		ABCHECK(nullptr != ABPlayerState);
		AssetIndex = ABPlayerState->GetCharacterIndex();
	}
	else
	{
		SetCurrentWeaponType(EWeaponType::Fist);
		AssetIndex = FMath::RandRange(0, DefaultSetting->CharacterAssets.Num() - 1);
	}

	CharacterAssetToLoad = DefaultSetting->CharacterAssets[AssetIndex];
	auto ABGameInstance = Cast<UABGameInstance>(GetGameInstance());
	ABCHECK(nullptr != ABGameInstance);
	AssetStreamingHandle = ABGameInstance->StreamableManager.RequestAsyncLoad(CharacterAssetToLoad, FStreamableDelegate::CreateUObject(this, &AABCharacter::OnAssetLoadCompleted));
	SetCharacterState(ECharacterState::LOADING);
}

void AABCharacter::SetCharacterState(ECharacterState NewState)
{
	ABCHECK(CurrentState != NewState);
	CurrentState = NewState;

	switch (CurrentState)
	{
		case ECharacterState::LOADING:
		{
			if (bIsPlayer)
			{
				DisableInput(ABPlayerController);

				ABPlayerController->GetHUDWidget()->BindCharacterStat(CharacterStat);

				auto ABPlayerState = Cast<AABPlayerState>(GetPlayerState());
				ABCHECK(nullptr != ABPlayerState);
				CharacterStat->SetNewLevel(ABPlayerState->GetCharacterLevel());
			}
			else
			{
				auto ABGameMode = Cast<AABGameMode>(GetWorld()->GetAuthGameMode());
				ABCHECK(nullptr != ABGameMode);
				int32 TargetLevel = FMath::CeilToInt(((float)ABGameMode->GetScore() * 0.9f)) + FMath::RandRange(0, 3);
				int32 FinalLevel = FMath::Clamp<int32>(TargetLevel, 1, 99);
				ABLOG(Warning, TEXT("New NPC Level : %d"), FinalLevel);
				CharacterStat->SetNewLevel(FinalLevel);
			}

			SetActorHiddenInGame(true);
			HPBarWidget->SetHiddenInGame(true);
			SetCanBeDamaged(false);
		}
		break;
		case ECharacterState::READY:
		{
			SetActorHiddenInGame(false);
			SetCanBeDamaged(true);
			CharacterStat->OnHPIsZero.AddLambda([this]() ->void {
				SetCharacterState(ECharacterState::DEAD);
			});
			auto CharacterWidget = Cast<UABCharacterWidget>(HPBarWidget->GetUserWidgetObject());
			ABCHECK(nullptr != CharacterWidget);
			CharacterWidget->BindCharacterStat(CharacterStat);

			if (bIsPlayer)
			{
				HPBarWidget->SetHiddenInGame(false);
				SetControlMode(EControlMode::Shoulder);
				GetCharacterMovement()->MaxWalkSpeed = 562.5f;
				EnableInput(ABPlayerController);
			}
			else
			{
				SetControlMode(EControlMode::NPC);
				GetCharacterMovement()->MaxWalkSpeed = 545.0f;
				ABAIController->RunAI();
			}
		}
		break;
		case ECharacterState::DEAD:
		{
			SetActorEnableCollision(false);
			GetMesh()->SetHiddenInGame(false);
			HPBarWidget->SetHiddenInGame(true);
			ABAnim->SetDeadAnim();
			SetCanBeDamaged(false);

			if (bIsPlayer)
			{
				DisableInput(ABPlayerController);
			}
			else
			{
				ABAIController->StopAI();
			}

			GetWorld()->GetTimerManager().SetTimer(DeadTimerHandle, FTimerDelegate::CreateLambda([this]() -> void {
				if (bIsPlayer)
				{
					ABPlayerController->ShowResultUI();
				}
				else
				{
					Destroy();
				}
			}), DeadTimer, false);

		}
		break;
	}

}

ECharacterState AABCharacter::GetCharacterState() const
{
	return CurrentState;
}

int32 AABCharacter::GetExp() const
{
	return CharacterStat->GetDropExp();
}

float AABCharacter::GetFinalAttackRange() const
{
	return (nullptr != CurrentWeapon) ? CurrentWeapon->GetAttackRange() : AttackRange;
}

float AABCharacter::GetFinalAttackDamage() const
{
	float AttackDamage = (nullptr != CurrentWeapon) ? (CharacterStat->GetAttack() + CurrentWeapon->GetAttackDamage()) : CharacterStat->GetAttack();
	float AttackModifier = (nullptr != CurrentWeapon) ? (CurrentWeapon->GetAttackModifier()) : 1.0f;;

	return AttackDamage * AttackModifier * (1.0 + WeaponAcquired * 0.01);
}

void AABCharacter::SetControlMode(EControlMode NewControlMode)
{
	CurrentControlMode = NewControlMode;

	switch (CurrentControlMode)
	{
		case EControlMode::Shoulder:
		{
			ArmLengthTo = 450.0f;
			SpringArm->bUsePawnControlRotation = true;
			SpringArm->bInheritPitch = true;
			SpringArm->bInheritRoll = true;
			SpringArm->bInheritYaw = true;
			SpringArm->bDoCollisionTest = true;
			bUseControllerRotationYaw = false;
			GetCharacterMovement()->bOrientRotationToMovement = true;
			GetCharacterMovement()->bUseControllerDesiredRotation = false;
			GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.f, 0.0f);
		}
		break;
		case EControlMode::Quarter:
		{
			ArmLengthTo = 600.0f;
			ArmRotationTo = FRotator(-45.0f, 0.0f, 0.0f);
			SpringArm->bUsePawnControlRotation = false;
			SpringArm->bInheritPitch = false;
			SpringArm->bInheritRoll = false;
			SpringArm->bInheritYaw = false;
			SpringArm->bDoCollisionTest = false;
			bUseControllerRotationYaw = true;
			bUseControllerRotationYaw = false;
			GetCharacterMovement()->bOrientRotationToMovement = false;
			GetCharacterMovement()->bUseControllerDesiredRotation = true;
			GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.f, 0.0f);
		}
		break;
	}
}

// Called every frame
void AABCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SpringArm->TargetArmLength = FMath::FInterpTo(SpringArm->TargetArmLength, ArmLengthTo, DeltaTime, ArmLengthSpeed);

	switch (CurrentControlMode)
	{
		case EControlMode::Quarter:
		{
			SpringArm->SetRelativeRotation(FMath::RInterpTo(SpringArm->GetRelativeRotation(), ArmRotationTo, DeltaTime, ArmRotationSpeed));
			if (DirectionToMove.SizeSquared() > 0.0f)
			{
				GetController()->SetControlRotation(FRotationMatrix::MakeFromX(DirectionToMove).Rotator());
				AddMovementInput(DirectionToMove);
			}
		}
		break;
	}

}

float AABCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	float FinalDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	ABLOG(Warning, TEXT("Actor : %s took Damage : %f"), *GetName(), FinalDamage);

	CharacterStat->SetDamage(FinalDamage);
	if (CurrentState == ECharacterState::DEAD)
	{
		if (EventInstigator->IsPlayerController())
		{
			auto PlayerController = Cast<AABPlayerController>(EventInstigator);
			ABCHECK(nullptr != PlayerController, 0.0f);
			PlayerController->NPCKill(this);
		}
	}
	return FinalDamage;
}

// Called to bind functionality to input
void AABCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("ViewChange"), EInputEvent::IE_Pressed, this, &AABCharacter::ViewChange);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AABCharacter::Roll);
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &AABCharacter::Attack);
	PlayerInputComponent->BindAction(TEXT("Run"), EInputEvent::IE_Pressed, this, &AABCharacter::Run);
	PlayerInputComponent->BindAction(TEXT("Run"), EInputEvent::IE_Released, this, &AABCharacter::Walk);

	PlayerInputComponent->BindAction(TEXT("Fist"), EInputEvent::IE_Pressed, this, &AABCharacter::Fist);
	PlayerInputComponent->BindAction(TEXT("OneHand"), EInputEvent::IE_Pressed, this, &AABCharacter::OneHand);
	PlayerInputComponent->BindAction(TEXT("TwoHand"), EInputEvent::IE_Pressed, this, &AABCharacter::TwoHand);

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AABCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AABCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AABCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AABCharacter::Turn);
}

bool AABCharacter::CanSetWeapon()
{
	if (GetCurrentMovementState() == EMovementState::Attack)
	{
		return false;
	}
	else if (GetCurrentMovementState() == EMovementState::Draw)
	{
		return false;
	}
	else if (GetCurrentMovementState() == EMovementState::Sheath)
	{
		return false;
	}

	return true;
}

void AABCharacter::AcquireWeapon(class AABWeapon* NewWeapon)
{
	ABCHECK(nullptr != NewWeapon);

	bool SameWeaponTypeAcquired = false;
	++WeaponAcquired;

	if (nullptr != CurrentWeapon)
	{
		if (CurrentWeapon->GetClass() == NewWeapon->GetClass())
		{
			ABLOG(Warning, TEXT("CurrentWeapon should be destroyed"));
			CurrentWeapon->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
			CurrentWeapon->Destroy();
			CurrentWeapon = nullptr;

			SameWeaponTypeAcquired = true;
		}
	}

	ABLOG(Warning, TEXT("Current Acquired Weapon Class : %s"), *(NewWeapon->GetClass()->GetName()));

	FName WeaponSocket;
	if (NewWeapon->GetClass()->GetName() == TEXT("ABWeaponOneHand"))
	{
		ABLOG(Warning, TEXT("OneHandWeapon Acquired!"));

		if (nullptr != CurrentOneHandWeapon)
		{
			CurrentOneHandWeapon->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
			CurrentOneHandWeapon->Destroy();
			CurrentOneHandWeapon = nullptr;
		}

		WeaponSocket = TEXT("thigh_lSocket");
		CurrentOneHandWeapon = NewWeapon;
	}
	else if (NewWeapon->GetClass()->GetName() == TEXT("ABWeaponTwoHand"))
	{
		ABLOG(Warning, TEXT("TwoHandWeapon Acquired!"));

		if (nullptr != CurrentTwoHandWeapon)
		{
			CurrentTwoHandWeapon->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
			CurrentTwoHandWeapon->Destroy();
			CurrentTwoHandWeapon = nullptr;
		}
		WeaponSocket = TEXT("clavicle_rSocket");
		CurrentTwoHandWeapon = NewWeapon;
	}

	if (nullptr != NewWeapon)
	{
		if (bIsPlayer)
		{
			if (SameWeaponTypeAcquired)
			{
				NewWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "hand_rSocket");
				CurrentWeapon = NewWeapon;
			}
			else
			{
				NewWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponSocket);
			}
		}
		else
		{
			NewWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "hand_rSocket");

			if (NewWeapon->GetClass()->GetName() == TEXT("ABWeaponOneHand"))
			{
				SetCurrentWeaponType(EWeaponType::OneHand);
				CurrentWeapon = NewWeapon;
			}
			else if (NewWeapon->GetClass()->GetName() == TEXT("ABWeaponTwoHand"))
			{
				SetCurrentWeaponType(EWeaponType::TwoHand);
				CurrentWeapon = NewWeapon;
			}
		}

		NewWeapon->SetOwner(this);
	}
}

void AABCharacter::DrawWeapon()
{
	if (IsCurrentMovementStateIdle())
	{
		if (GetCurrentWeaponType() == EWeaponType::OneHand)
		{
			ABLOG(Warning, TEXT("DrwaWeapon() for OneHand is called!"));
			SetCurrentMovementState(EMovementState::Draw);
			ABAnim->PlayDrawOneHandMontage();
			UGameplayStatics::PlaySound2D(GetWorld(), DrawOneHand, 1.0f, 1.0f);
		}
		else if (GetCurrentWeaponType() == EWeaponType::TwoHand)
		{
			ABLOG(Warning, TEXT("DrwaWeapon() for TwoHand is called!"));
			SetCurrentMovementState(EMovementState::Draw);
			ABAnim->PlayDrawTwoHandMontage();
			UGameplayStatics::PlaySound2D(GetWorld(), DrawTwoHand, 1.0f, 1.0f);
		}
	}
}

void AABCharacter::SheathWeapon()
{
	if (IsCurrentMovementStateIdle())
	{
		if (GetCurrentWeaponType() == EWeaponType::OneHand)
		{
			ABLOG(Warning, TEXT("SheathWeapon() for OneHand is called!"));
			SetCurrentMovementState(EMovementState::Sheath);
			ABAnim->PlaySheathOneHandMontage();
			UGameplayStatics::PlaySound2D(GetWorld(), SheathOneHand, 1.0f, 1.0f);
		}
		else if (GetCurrentWeaponType() == EWeaponType::TwoHand)
		{
			ABLOG(Warning, TEXT("SheathWeapon() for TwoHand is called!"));
			SetCurrentMovementState(EMovementState::Sheath);
			ABAnim->PlaySheathTwoHandMontage();
			UGameplayStatics::PlaySound2D(GetWorld(), SheathTwoHand, 1.5f, 1.0f);
		}
	}
}

AABCharacter::EMovementState AABCharacter::GetCurrentMovementState()
{
	return CurrentMovementState;
}

void AABCharacter::SetCurrentMovementState(EMovementState NewState)
{
	CurrentMovementState = NewState;
}

bool AABCharacter::IsCurrentMovementStateIdle()
{
	return (CurrentMovementState == EMovementState::Idle) ? true : false ;
}

UFUNCTION(BlueprintCallable)
EWeaponType AABCharacter::GetCurrentWeaponType()
{
	return CurrentWeaponType;
}

void AABCharacter::SetCurrentWeaponType(EWeaponType NewWeaponType)
{
	CurrentWeaponType = NewWeaponType;
}

void AABCharacter::Fist()
{
	if (IsCurrentMovementStateIdle())
	{
		if (GetCurrentWeaponType() == EWeaponType::Unarmed)
		{
			SetCurrentWeaponType(EWeaponType::Fist);
		}
		else if (GetCurrentWeaponType() == EWeaponType::Fist)
		{
			SetCurrentWeaponType(EWeaponType::Unarmed);
		}
		else
		{
			SheathWeapon();
			SetCurrentWeaponType(EWeaponType::Fist);
		}
	}
}

void AABCharacter::OneHand()
{
	ABLOG(Warning, TEXT("OneHand is clicked! + CurrentMovementState is Idle "));

	if (IsCurrentMovementStateIdle())
	{
		ABLOG(Warning, TEXT("CurrentMovementState is Idle!"));

		if (nullptr != CurrentOneHandWeapon)
		{
			if (GetCurrentWeaponType() == EWeaponType::Unarmed || GetCurrentWeaponType() == EWeaponType::Fist)
			{
				ABLOG(Warning, TEXT("CurrentWeaponType is Unarmed or Fist!"));

				SetCurrentWeaponType(EWeaponType::OneHand);
				DrawWeapon();
			}
			else if (GetCurrentWeaponType() == EWeaponType::OneHand)
			{
				SheathWeapon();
				ABLOG(Warning, TEXT("CurrentWeaponType is OneHand!"));
				SetCurrentWeaponType(EWeaponType::Unarmed);
			}
			else if (GetCurrentWeaponType() == EWeaponType::TwoHand)
			{
				ABLOG(Warning, TEXT("SheathOneHand First!"));
			}
		}
	}
}

void AABCharacter::TwoHand()
{
	ABLOG(Warning, TEXT("TwoHand is clicked! + CurrentMovementState is Idle "));

	if (IsCurrentMovementStateIdle())
	{
		ABLOG(Warning, TEXT("CurrentMovementState is Idle!"));

		if (nullptr != CurrentTwoHandWeapon)
		{
			if (GetCurrentWeaponType() == EWeaponType::Unarmed || GetCurrentWeaponType() == EWeaponType::Fist)
			{
				ABLOG(Warning, TEXT("CurrentWeaponType is Unarmed or Fist!"));

				SetCurrentWeaponType(EWeaponType::TwoHand);
				DrawWeapon();
			}
			else if (GetCurrentWeaponType() == EWeaponType::OneHand)
			{
				ABLOG(Warning, TEXT("SheathOneHand First!"));
			}
			else if (GetCurrentWeaponType() == EWeaponType::TwoHand)
			{
				ABLOG(Warning, TEXT("CurrentWeaponType is TwoHand!"));
				SheathWeapon();
				SetCurrentWeaponType(EWeaponType::Unarmed);
			}
		}
	}
}

void AABCharacter::Attack()
{
	ABLOG(Warning, TEXT("IsCurrentMovementStateIdle? : %s"), (IsCurrentMovementStateIdle()) ? TEXT("TRUE") : TEXT("FALSE"));

	if (IsCurrentMovementStateIdle()) {

		SetCurrentMovementState(EMovementState::Attack);

		if (GetCurrentWeaponType() == EWeaponType::Unarmed)
		{
			SetCurrentMovementState(EMovementState::Idle);
		}
		else if (GetCurrentWeaponType() == EWeaponType::Fist)
		{
			ABLOG(Warning, TEXT("Attack Fist Montage Should be Called!"));

			ABCHECK(CurrentCombo == 0);
			AttackStartComboState();
			ABAnim->PlayAttackFistMontage();
			ABAnim->JumpToAttackFistMontageSection(CurrentCombo);
		}
		else if (GetCurrentWeaponType() == EWeaponType::OneHand)
		{
			ABCHECK(nullptr != CurrentWeapon);
			ABCHECK(CurrentCombo == 0);
			AttackStartComboState();
			ABAnim->PlayAttackOneHandMontage();
			ABAnim->JumpToAttackOneHandMontageSection(CurrentCombo);
		}
		else if (GetCurrentWeaponType() == EWeaponType::TwoHand)
		{
			ABCHECK(nullptr != CurrentWeapon);
			ABCHECK(CurrentCombo == 0);
			AttackStartComboState();
			ABAnim->PlayAttackTwoHandMontage();
		}

	}
	else if (GetCurrentMovementState() == EMovementState::Attack)
	{
		ABCHECK(FMath::IsWithinInclusive<int32>(CurrentCombo, 1, MaxCombo));
		if (CanNextCombo)
		{
			IsComboInputOn = true;
		}
	}
}

void AABCharacter::UpDown(float NewAxisValue)
{
	switch (CurrentControlMode)
	{
		case EControlMode::Shoulder:
		{
			AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X), NewAxisValue);
		}
		break;
		case EControlMode::Quarter:
		{
			DirectionToMove.X = NewAxisValue;
		}
		break;
	}
}

void AABCharacter::LeftRight(float NewAxisValue)
{
	switch (CurrentControlMode)
	{
		case EControlMode::Shoulder:
		{
			AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::Y), NewAxisValue);
		}
		break;
		case EControlMode::Quarter:
		{
			DirectionToMove.Y = NewAxisValue;
		}
		break;
	}
}

void AABCharacter::LookUp(float NewAxisValue)
{
	switch (CurrentControlMode)
	{
		case EControlMode::Shoulder:
		{
			AddControllerPitchInput(NewAxisValue);
		}
		break;
	}
}

void AABCharacter::Turn(float NewAxisValue)
{
	switch (CurrentControlMode)
	{
		case EControlMode::Shoulder:
		{
			AddControllerYawInput(NewAxisValue);
		}
		break;
	} 
}

void AABCharacter::Walk() {
	if (GetCurrentWeaponType() == EWeaponType::Unarmed)
	{
		GetCharacterMovement()->MaxWalkSpeed = 562.5f;
	}
	else
	{
		GetCharacterMovement()->MaxWalkSpeed = 400.0f;
	}
}

void AABCharacter::Run() {
	if (GetCurrentWeaponType() == EWeaponType::Unarmed)
	{
		GetCharacterMovement()->MaxWalkSpeed = 750.0f;
	}
	else
	{
		GetCharacterMovement()->MaxWalkSpeed = 600.0f;
	}
}

void AABCharacter::ViewChange()
{
	switch (CurrentControlMode)
	{
		case EControlMode::Shoulder:
		{
			GetController()->SetControlRotation(GetActorRotation());
			SetControlMode(EControlMode::Quarter);
		}
		break;
		case EControlMode::Quarter:
		{
			GetController()->SetControlRotation(SpringArm->GetRelativeRotation());
			SetControlMode(EControlMode::Shoulder);
		}
		break;
	}
}

void AABCharacter::Roll()
{
	if (IsCurrentMovementStateIdle()) 
	{
		ABLOG(Warning, TEXT("Roll has Started!"));
		SetCurrentMovementState(EMovementState::Roll);
		ABAnim->PlayRollMontage();
	}
	else
	{
		ABLOG(Warning, TEXT("CurrentMovementState is not Idle!"));
	}
}

void AABCharacter::OnAttackMontageEnded(/*UAnimMontage* Montage, bool bInterrupted*/)
{
	ABCHECK(CurrentCombo > 0);
	AttackEndComboState();
	OnAttackEnemyEnd.Broadcast();
	SetCurrentMovementState(EMovementState::Idle);
}

void AABCharacter::OnEveryMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	ABLOG(Warning, TEXT("Current Montage has eneded! : %s"), *(Montage->GetName()));
	SetCurrentMovementState(EMovementState::Idle);
}

void AABCharacter::AttackStartComboState()
{
	CanNextCombo = true;
	IsComboInputOn = false;
	ABCHECK(FMath::IsWithinInclusive<int32>(CurrentCombo, 0, MaxCombo - 1));
	CurrentCombo = FMath::Clamp<int32>(CurrentCombo + 1, 1, MaxCombo);
}

void AABCharacter::AttackEndComboState()
{
	IsComboInputOn = false;
	CanNextCombo = false;
	CurrentCombo = 0;
}

void AABCharacter::AttackCheck()
{
	float FinalAttackRange = GetFinalAttackRange();
	 
	TArray<FHitResult> HitResultArray;
	FCollisionQueryParams Params(NAME_None, false, this);
	bool bResult = GetWorld()->SweepMultiByChannel(
		HitResultArray, GetActorLocation(), GetActorLocation() + GetActorForwardVector() * FinalAttackRange,
		FQuat::Identity, ECollisionChannel::ECC_GameTraceChannel2, FCollisionShape::MakeSphere(50.0f), Params);

//#if ENABLE_DRAW_DEBUG
//	FVector TraceVec = GetActorForwardVector() * FinalAttackRange;
//	FVector Center = GetActorLocation() + TraceVec * 0.5f;
//	float HalfHeight = FinalAttackRange * 0.5f + AttackRadius;
//	FQuat CapsuleRot = FRotationMatrix::MakeFromZ(TraceVec).ToQuat();
//	FColor DrawColor = bResult ? FColor::Green : FColor::Red;
//	float DebugLifeTime = 5.0f;
//
//	DrawDebugCapsule(GetWorld(), Center, HalfHeight, AttackRadius, CapsuleRot, DrawColor, false, DebugLifeTime);
//#endif
		
	if (bResult)
	{
		for (auto& HitResult : HitResultArray)
		{
			if (HitResult.Actor.IsValid())
			{
				AABCharacter* HittedCharacter = Cast<AABCharacter>(HitResult.Actor);
				if (HittedCharacter->IsPlayerControlled() || IsPlayerControlled())
				{
					ABLOG(Warning, TEXT("Hit Actor Name : %s"), *HitResult.Actor->GetName());
					FDamageEvent DamageEvent;
					HitResult.Actor->TakeDamage(GetFinalAttackDamage(), DamageEvent, GetController(), this);
				}

				if (GetCurrentWeaponType() == EWeaponType::Fist)
				{
					UGameplayStatics::PlaySound2D(GetWorld(), HitFist, 0.7, 0.7);
				}
				else if (GetCurrentWeaponType() == EWeaponType::OneHand)
				{
					UGameplayStatics::PlaySound2D(GetWorld(), HitOneHand, 0.9, 0.8);
				}
				else if (GetCurrentWeaponType() == EWeaponType::TwoHand)
				{
					UGameplayStatics::PlaySound2D(GetWorld(), HitTwoHand, 0.8, 0.6);
				}
			}
		}
		
	}
}

void AABCharacter::DrawOneHandCheck()
{
	ABLOG(Warning, TEXT("Drawing OneHand weapon!"));
	ABCHECK(nullptr != CurrentOneHandWeapon);
	CurrentWeapon = CurrentOneHandWeapon;

	CurrentWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "hand_rSocket");

}

void AABCharacter::DrawTwoHandCheck()
{
	ABLOG(Warning, TEXT("Drawing TwoHand weapon!"));
	ABCHECK(nullptr != CurrentTwoHandWeapon);
	CurrentWeapon = CurrentTwoHandWeapon;

	CurrentWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "hand_rSocket");
}

void AABCharacter::SheathOneHandCheck()
{
	ABLOG(Warning, TEXT("Sheathing OneHand weapon!"));
	ABCHECK(nullptr != CurrentOneHandWeapon);
	CurrentOneHandWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "thigh_lSocket");

	CurrentWeapon = nullptr;
}

void AABCharacter::SheathTwoHandCheck()
{
	ABLOG(Warning, TEXT("Sheathing TwoHand weapon!"));
	ABCHECK(nullptr != CurrentTwoHandWeapon);
	CurrentTwoHandWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "clavicle_rSocket");

	CurrentWeapon = nullptr;
}

void AABCharacter::OnAssetLoadCompleted()
{
	USkeletalMesh* AssetLoaded = Cast<USkeletalMesh>(AssetStreamingHandle->GetLoadedAsset());
	AssetStreamingHandle.Reset();
	ABCHECK(nullptr != AssetLoaded);
	GetMesh()->SetSkeletalMesh(AssetLoaded);
	SetCharacterState(ECharacterState::READY);
}

