// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TortoiseGameTypes.h"
#include "TGSpawnController.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStartActorSpawn, EMovementType, MovementType);

UCLASS()
class TORTOISEGAME_API ATGSpawnController : public APlayerController
{
	GENERATED_BODY()

public:
	FOnStartActorSpawn OnStartActorSpawn;

	UFUNCTION(BlueprintCallable, Category = "SpawnActors")
	void StartSpawnActor(EMovementType MovementType);
};
