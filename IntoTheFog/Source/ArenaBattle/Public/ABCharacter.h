// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/Character.h"
#include "ABCharacter.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnAttackEndEnemyDelegate);

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	Unarmed,
	Fist,
	OneHand,
	TwoHand,
};

UCLASS()
class ARENABATTLE_API AABCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AABCharacter();
	void SetCharacterState(ECharacterState NewState);
	ECharacterState GetCharacterState() const;
	int32 GetExp() const;
	float GetFinalAttackRange() const;
	float GetFinalAttackDamage() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	enum class EControlMode
	{
		Shoulder,
		Quarter,
		NPC
	};


	void SetControlMode(EControlMode NewControlMode);
	EControlMode CurrentControlMode = EControlMode::Shoulder;
	FVector DirectionToMove = FVector::ZeroVector;

	float ArmLengthTo = 0.0f;
	FRotator ArmRotationTo = FRotator::ZeroRotator;
	float ArmLengthSpeed = 0.0f;
	float ArmRotationSpeed = 0.0f;

public:	
	
	enum class EMovementState
	{
		Idle,
		Backstep,
		Roll,
		Attack,
		Hitted,
		Dead,
		Equip,
		Draw,
		Sheath
	};

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void PostInitializeComponents() override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool IsCurrentMovementStateIdle();
	EMovementState GetCurrentMovementState();
	void SetCurrentMovementState(EMovementState NewState);

	EMovementState CurrentMovementState = EMovementState::Idle;

	bool CanSetWeapon();
	void AcquireWeapon(class AABWeapon* NewWeapon);
	void DrawWeapon();
	void SheathWeapon();

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	class AABWeapon* CurrentWeapon;

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	class AABWeapon* CurrentOneHandWeapon;

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	class AABWeapon* CurrentTwoHandWeapon;

	UFUNCTION(BlueprintCallable)
	EWeaponType	GetCurrentWeaponType();

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	EWeaponType	CurrentWeaponType = EWeaponType::Unarmed;

	void SetCurrentWeaponType(EWeaponType NewWeaponType);

	int32 WeaponAcquired = 0;

	void Fist();
	void OneHand();
	void TwoHand();

	UPROPERTY(VisibleAnywhere, Category = Stat)
	class UABCharacterStatComponent* CharacterStat;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, Category = UI)
	class UWidgetComponent* HPBarWidget;

	void Attack();
	FOnAttackEndEnemyDelegate OnAttackEnemyEnd;

private:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);
	void LookUp(float NewAxisValue);
	void Turn(float NewAxisValue);
	
	void Walk();
	void Run();
	void ViewChange();
	void Roll();

	UFUNCTION()
	void OnAttackMontageEnded(/*UAnimMontage* Montage, bool bInterrupted*/);

	UFUNCTION()
	void OnEveryMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	void AttackStartComboState();
	void AttackEndComboState();
	void AttackCheck();

	void DrawOneHandCheck();
	void DrawTwoHandCheck();
	void SheathOneHandCheck();
	void SheathTwoHandCheck();

	void OnAssetLoadCompleted();

private:

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	bool CanNextCombo;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	bool IsComboInputOn;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	int32 CurrentCombo;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	int32 MaxCombo;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	float AttackRange;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	float AttackRadius;

	UPROPERTY()
	class UABAnimInstance* ABAnim;

	int AssetIndex = 0;

	FSoftObjectPath CharacterAssetToLoad = FSoftObjectPath(nullptr);
	TSharedPtr<struct FStreamableHandle> AssetStreamingHandle;

	UPROPERTY(Transient, VisibleInstanceOnly, BlueprintReadOnly, Category = State, Meta = (AllowPrivateAccess = true))
	ECharacterState CurrentState;

	UPROPERTY(Transient, VisibleInstanceOnly, BlueprintReadOnly, Category = State, Meta = (AllowPrivateAccess = true))
	bool bIsPlayer;

	UPROPERTY()
	class AABAIController* ABAIController;

	UPROPERTY()
	class AABPlayerController* ABPlayerController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = State, Meta = (AllowprivateAccess = true))
	float DeadTimer;

	FTimerHandle DeadTimerHandle = {};

	UPROPERTY()
	USoundBase* HitFist;

	UPROPERTY()
	USoundBase* HitOneHand;

	UPROPERTY()
	USoundBase* HitTwoHand;

	UPROPERTY()
	USoundBase* DrawOneHand;

	UPROPERTY()
	USoundBase* SheathOneHand;

	UPROPERTY()
	USoundBase* DrawTwoHand;

	UPROPERTY()
	USoundBase* SheathTwoHand;
};
