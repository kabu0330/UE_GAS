// 


#include "Character/Component/AuraCharacterMovementComponent.h"


UAuraCharacterMovementComponent::UAuraCharacterMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	
}

void UAuraCharacterMovementComponent::StartDash()
{
	if (MovementMode == MOVE_Custom) return;

	MovementMode = MOVE_Custom;
	MyMovementMode = ECustomMovementMode::Custom_Dash;

	DashDirection = GetOwner()->GetActorForwardVector();
	
	FTimerDelegate TimerDelegate = FTimerDelegate::CreateUObject(this, &UAuraCharacterMovementComponent::FinishDash);
	GetWorld()->GetTimerManager().SetTimer(DashTimerHandle, TimerDelegate, 0.5f, false);
}

void UAuraCharacterMovementComponent::PhysCustom(float DeltaTime, int32 Iterations)
{
	Super::PhysCustom(DeltaTime, Iterations);

	switch (MyMovementMode)
	{
	case ECustomMovementMode::Custom_Dash:
		Dash();
		break;

	default:
		break;
	}
}

void UAuraCharacterMovementComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

void UAuraCharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAuraCharacterMovementComponent::FinishDash()
{
	MovementMode = MOVE_Walking;
	MyMovementMode = ECustomMovementMode::None;
	Velocity = FVector::ZeroVector;
	AddInputVector(Velocity);
	DashDirection = FVector::ZeroVector;
	DashTimerHandle.Invalidate();
}

void UAuraCharacterMovementComponent::Dash()
{
	Velocity = DashDirection * 1000.f;
	AddInputVector(Velocity);
	
	UE_LOG(LogTemp, Warning, TEXT("Dash: %s"), *Velocity.ToString());
}

void UAuraCharacterMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                    FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

