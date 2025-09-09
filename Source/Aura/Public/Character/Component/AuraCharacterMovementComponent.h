// 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AuraCharacterMovementComponent.generated.h"

UENUM()
enum class ECustomMovementMode : uint8
{
	None,
	Custom_Dash
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AURA_API UAuraCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	UAuraCharacterMovementComponent();

	void StartDash();

	virtual void PhysCustom(float DeltaTime, int32 Iterations) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Replicated)
	ECustomMovementMode MyMovementMode = ECustomMovementMode::None;

	FTimerHandle DashTimerHandle;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY()
	FVector DashDirection;
	
	UFUNCTION()
	void FinishDash();

	void Dash();
	
};
