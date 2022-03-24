// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TortoiseGameTypes.h"
#include "TGBaseAICharacter.generated.h"

class UBehaviorTree;
UCLASS()
class TORTOISEGAME_API ATGBaseAICharacter : public ACharacter
{
	GENERATED_BODY()

public:

	UBehaviorTree* GetBehaviorTree() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
	EMovementType MovementType = EMovementType::Move;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
	UBehaviorTree* BehaviorTree;
};
