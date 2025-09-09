// 


#include "Character/AuraCharacter.h"

#include "AbilitySystemComponent.h"
#include "Character/Component/AuraCharacterMovementComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerController.h"
#include "Player/AuraPlayerState.h"
#include "UI/HUD/AuraHUD.h"


// AAuraCharacter::AAuraCharacter()
// {
//
// }

AAuraCharacter::AAuraCharacter(const FObjectInitializer& ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	
	// 탑다운 게임 기본 설정
	GetCharacterMovement()->bOrientRotationToMovement = true; // 캐릭터 이동 방향으로 메시 회전
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true; // 평면에 스냅
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	UAuraCharacterMovementComponent* CMP = Cast<UAuraCharacterMovementComponent>(GetCharacterMovement());
	if (CMP)
	{
		UE_LOG(LogTemp, Warning, TEXT("CMP Create"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("CMP Fail"));
	}
}

void AAuraCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// 서버에서 GAS 초기화
	InitAbilityActorInfo();
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// 클라에서 GAS 초기화
	InitAbilityActorInfo();
}

void AAuraCharacter::InitAbilityActorInfo()
{
	AAuraPlayerState* PS = GetPlayerState<AAuraPlayerState>();
	check(PS);
	PS->GetAbilitySystemComponent()->InitAbilityActorInfo(PS, this);
	AbilitySystemComponent = PS->GetAbilitySystemComponent();
	AttributeSet = PS->GetAttributeSet();

	// 서버에서는 문제가 될 수 있는 코드이므로
	if (AAuraPlayerController* PC = Cast<AAuraPlayerController>(GetController()))
	{
		if (AAuraHUD* AuraHUD = PC->GetHUD<AAuraHUD>())
		{
			AuraHUD->InitOverlay(PC, PS, AbilitySystemComponent, AttributeSet);
		}
	}
}

void AAuraCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAuraCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

