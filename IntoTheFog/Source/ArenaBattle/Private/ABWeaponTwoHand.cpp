#include "ABWeaponTwoHand.h"
#include "ABTwoHandSetting.h"

AABWeaponTwoHand::AABWeaponTwoHand()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("TWOHAND_WEAPON"));
	RootComponent = Weapon;

	auto DefaultSetting = GetDefault<UABTwoHandSetting>();

	int32 RandIndex = FMath::RandRange(0, DefaultSetting->TwoHandAssets.Num() - 1);
	TwoHandAssetToLoad = DefaultSetting->TwoHandAssets[RandIndex];

	ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_TWOHAND(*TwoHandAssetToLoad.ToString());

	if (SK_TWOHAND.Succeeded())
	{
		Weapon->SetSkeletalMesh(SK_TWOHAND.Object);
	}
	Weapon->SetCollisionProfileName(TEXT("NoCollision"));

	AttackRange = 150.0f;
	AttackDamageMin = -2.5f;
	AttackDamageMax = 15.0f;
	AttackModifierMin = 1.1f;
	AttackModifierMax = 1.4f;
}

void AABWeaponTwoHand::BeginPlay()
{
	Super::BeginPlay();

	ABLOG(Warning, TEXT("TwoHand Weapon Setting Completed!"));
}