// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Characters/TGBaseAICharacter.h"

UBehaviorTree* ATGBaseAICharacter::GetBehaviorTree() const
{
	return BehaviorTree;
}
