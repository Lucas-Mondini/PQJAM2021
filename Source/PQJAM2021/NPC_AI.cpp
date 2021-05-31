// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_AI.h"
#include "Components/MeshComponent.h"

// Sets default values
ANPC_AI::ANPC_AI()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ANPC_AI::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPC_AI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPC_AI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

