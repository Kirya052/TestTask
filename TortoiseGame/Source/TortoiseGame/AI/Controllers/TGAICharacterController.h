// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TortoiseGameTypes.h"
#include "TGAICharacterController.generated.h"

/**
 * 
 */
UCLASS()
class TORTOISEGAME_API ATGAICharacterController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void SetPawn(APawn* InPawn) override;

	void SetBlackBoardValue(FVector StartPosition, FVector FinishPosition, EMovementType MoveType);

private:
	TWeakObjectPtr<class ATGBaseAICharacter> CachedAICharacter;
};
