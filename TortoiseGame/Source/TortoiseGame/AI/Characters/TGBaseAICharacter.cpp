// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Characters/TGBaseAICharacter.h"
#include "Kismet/GameplayStatics.h"

UBehaviorTree* ATGBaseAICharacter::GetBehaviorTree() const
{
	return BehaviorTree;
}

void ATGBaseAICharacter::PlayFinishSound()
{
	if (!IsValid(FinishSound) || bIsSoundPlaying)
	{
		return;
	}

	bIsSoundPlaying = true;
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), FinishSound, GetActorLocation());

	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ATGBaseAICharacter::ChangeSoundState, FinishSound->GetDuration());
}

void ATGBaseAICharacter::ChangeSoundState()
{
	bIsSoundPlaying = false;
	K2_DestroyActor();
}

void ATGBaseAICharacter::DestroyCharacter()
{
	K2_DestroyActor();
}

