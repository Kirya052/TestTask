// Fill out your copyright notice in the Description page of Project Settings.


#include "TGAICharacterController.h"
#include "AI/Characters/TGBaseAICharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

void ATGAICharacterController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (IsValid(InPawn))
	{
		checkf(InPawn->IsA<ATGBaseAICharacter>(), TEXT("ATGAICharacterController::SetPawn TGAICharacterController can possess only TGBaseAICharacter"));
		CachedAICharacter = StaticCast<ATGBaseAICharacter*>(InPawn);
		RunBehaviorTree(CachedAICharacter->GetBehaviorTree());
	}
	else
	{
		CachedAICharacter = nullptr;
	}
}

void ATGAICharacterController::SetBlackBoardValue(FVector StartPosition, FVector FinishPosition, EMovementType MoveType)
{
	if (Blackboard)
	{
		Blackboard->SetValueAsVector(BB_StartPosition, StartPosition);
		Blackboard->SetValueAsVector(BB_FinishPosition, FinishPosition);
		Blackboard->SetValueAsEnum(BB_MovementType, uint8(MoveType));
	}
}
