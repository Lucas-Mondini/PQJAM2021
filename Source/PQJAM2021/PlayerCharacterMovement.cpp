// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterMovement.h"

// Sets default values
APlayerCharacterMovement::APlayerCharacterMovement()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacterMovement::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacterMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacterMovement::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

