// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterStat/ABCharacterStatComponent.h"
#include "ABCharacterStatComponent.h"

// Sets default values
AABCharacterStatComponent::AABCharacterStatComponent()
{
	MaxHp = 200.0f;
	CurrentHp = MaxHp;
}

// Called when the game starts or when spawned
void AABCharacterStatComponent::BeginPlay()
{
	Super::BeginPlay();
	
	SetHP(MaxHp);
}

float AABCharacterStatComponent::ApplyDamage(float InDamage)
{
	const float PrevHP = CurrentHp;
	const float ActualDamage = FMath::Clamp<float>(InDamage, 0, InDamage);

	SetHP(PrevHP - ActualDamage);
	// KINDA_SMALL_NUMBER 부동 소수점 연산에서 0에 가까운 값을 판별할 때 기준값으로 사용됩니다.
	if (CurrentHp <= KINDA_SMALL_NUMBER)
	{
		OnHpZero.Broadcast();
	}

	return 0.0f;
}

void AABCharacterStatComponent::SetHP(float NewHP)
{
	CurrentHp = FMath::Clamp<float>(NewHP, 0.0f, MaxHp);

	OnHpChanged.Broadcast(CurrentHp);
}

