// 

#pragma once

#include "CoreMinimal.h"
#include "AuraCharacterBase.h"
#include "Interface/IEnemyInterface.h"
#include "AuraEnemy.generated.h"

UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IIEnemyInterface
{
	GENERATED_BODY()

public:
	AAuraEnemy();

	/** Enemy Interface */
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
