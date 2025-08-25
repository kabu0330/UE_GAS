// 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Interface/IEnemyInterface.h"
#include "AuraPlayerController.generated.h"

struct FInputActionValue;
class UInputMappingContext;
class UInputAction;
class IIEnemyInterface;
/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AAuraPlayerController();
	virtual void PlayerTick(float DeltaTime) override;
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess), Category = "InputMapping")
	TObjectPtr<UInputMappingContext> AuraContext;

	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess), Category = "InputMapping")
	TObjectPtr<UInputAction> MoveAction;

	UFUNCTION()
	void Move(const FInputActionValue& InputActionValue);

	TScriptInterface<IIEnemyInterface> LastActor;
	TScriptInterface<IIEnemyInterface> ThisActor;
	
	void CursorTrace();
	
};
