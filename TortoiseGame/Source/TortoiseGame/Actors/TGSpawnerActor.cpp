// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/TGSpawnerActor.h"
#include "Controllers/TGSpawnController.h"
#include "Kismet/GameplayStatics.h"
#include "AI/Characters/TGBaseAICharacter.h"
#include "AI/Controllers/TGAICharacterController.h"

// Sets default values
ATGSpawnerActor::ATGSpawnerActor()
{
	SpawnerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpawnerMesh"));
}

void ATGSpawnerActor::BeginPlay()
{
	Super::BeginPlay();
	
	ATGSpawnController* CachedSpawnController = Cast<ATGSpawnController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (CachedSpawnController)
	{
		CachedSpawnController->OnStartActorSpawn.AddDynamic(this, &ATGSpawnerActor::TryToSpawnAICharacter);
	}
}

void ATGSpawnerActor::TryToSpawnAICharacter(EMovementType MoveType)
{
	if (!IsValid(CharacterClass) || MovementType != MoveType || bIsSpawning)
	{
		return;
	}

	bIsSpawning = true;

	const FVector ActorLocation = GetActorLocation() + FVector(100.0f, 100.0f, 10.f);
	const FRotator ActorRotation = GetActorRotation();

	ATGBaseAICharacter* AICharacter = GetWorld()->SpawnActor<ATGBaseAICharacter>(CharacterClass, ActorLocation, ActorRotation);
	if (IsValid(AICharacter))
	{
		if (!IsValid(AICharacter->Controller))
		{
			AICharacter->SpawnDefaultController();
		}
		AICharacter->MovementType = MovementType;
		SetBlackBoardValue(AICharacter);
	}

	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ATGSpawnerActor::ChangeSpawningState, SpawnDelay);
}

void ATGSpawnerActor::ChangeSpawningState()
{
	bIsSpawning = false;
}

void ATGSpawnerActor::SetBlackBoardValue(ATGBaseAICharacter* Character)
{
	ATGAICharacterController* CachedController = Cast<ATGAICharacterController>(Character->Controller);
	if (CachedController)
	{
		CachedController->SetBlackBoardValue(GetActorLocation(), FinishLocation + GetActorLocation(), Character->MovementType);
		UE_LOG(LogTemp, Warning, TEXT("Hello"));
	}
}

