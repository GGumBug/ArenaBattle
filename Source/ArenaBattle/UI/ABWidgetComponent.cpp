// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ABWidgetComponent.h"
#include "UI/ABUserWidget.h"

void UABWidgetComponent::InitWidget()
{
	Super::InitWidget();
	// 부모 InitWidget의 Widget = CreateWidget(World, WidgetClass); 줄에서 Widget 인스턴스가 생성된다.

	UABUserWidget* ABUserWidget = Cast<UABUserWidget>(GetWidget());
	if (ABUserWidget)
	{
		// WidgetComponent 에는 GetOwner() 함수가 존재
		ABUserWidget->SetOwningActor(GetOwner());
	}
}
