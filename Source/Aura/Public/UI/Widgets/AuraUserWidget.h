// 

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AuraUserWidget.generated.h"

class USizeBox;
/**
 * 
 */
UCLASS()
class AURA_API UAuraUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
	
	virtual void NativeConstruct() override;
	virtual void NativePreConstruct() override;
	
protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();

	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Widget", meta = (AllowPrivateAccess))
	float BoxWidth = 250;
	
	UPROPERTY(EditDefaultsOnly, Category = "Widget", meta = (AllowPrivateAccess))
	float BoxHeight = 250;
	
};
