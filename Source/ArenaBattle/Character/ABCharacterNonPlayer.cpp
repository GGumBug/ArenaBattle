// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ABCharacterNonPlayer.h"

AABCharacterNonPlayer::AABCharacterNonPlayer()
{

}

void AABCharacterNonPlayer::SetDead()
{
	Super::SetDead();

	FTimerHandle DeadTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(DeadTimerHandle, FTimerDelegate::CreateLambda(
		[&]()
		{
			Destroy();
		}
	), DeadEventDelayTime, false); 
	// [&]는 외부에 선언된 변수들을 값이 아닌 참조 형태로 람다 내부에서 사용하도록 합니다. 
	// 이로 인해 람다 내부에서 외부 변수의 변경 사항을 실시간으로 반영할 수 있습니다.
}
