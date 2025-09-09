// 


#include "UI/Widgets/AuraUserWidget.h"

#include "Components/SizeBox.h"


void UAuraUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}

void UAuraUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

}

void UAuraUserWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
}
