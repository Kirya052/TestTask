// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TortoiseGameTypes.h"
#include "TGSpawnerActor.generated.h"


class ATGBaseAICharacter;
UCLASS()
class TORTOISEGAME_API ATGSpawnerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ATGSpawnerActor();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SpawnerMesh")
	class UStaticMeshComponent* SpawnerMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI Spawner")
	TSubclassOf<ATGBaseAICharacter> CharacterClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI Spawner")
	EMovementType MovementType = EMovementType::Move;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI Spawner")
	float SpawnDelay = 1.0f;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, meta = (MakeEditWidget))
	FVector FinishLocation = FVector::ZeroVector;

	UFUNCTION()
	void TryToSpawnAICharacter(EMovementType MoveType);

private:
	bool bIsSpawning = false;

	void ChangeSpawningState();

	void SetBlackBoardValue(ATGBaseAICharacter* Character);
};
