// Fill out your copyright notice in the Description page of Project Settings.


#include "TGSpawnController.h"

void ATGSpawnController::StartSpawnActor(EMovementType MovementType)
{
	if (OnStartActorSpawn.IsBound())
	{
		OnStartActorSpawn.Broadcast(MovementType);
	}
}
