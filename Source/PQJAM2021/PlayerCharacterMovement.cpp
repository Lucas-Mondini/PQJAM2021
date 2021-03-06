// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterMovement.h"

// Sets default values
APlayerCharacterMovement::APlayerCharacterMovement()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 600.0f;
	GetCharacterMovement()->AirControl = 0.2f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bUsePawnControlRotation = true;

	//distance from the player
	CameraBoom->TargetArmLength = 300.0f;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FallowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

	FollowCamera->bUsePawnControlRotation = false;


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

	if (Controller) {
		PlayerInputComponent->BindAxis("Yaw", this, &APawn::AddControllerYawInput);
		PlayerInputComponent->BindAxis("Pitch", this, &APawn::AddControllerPitchInput);

		PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
		PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

		PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacterMovement::MoveForward);
		PlayerInputComponent->BindAxis("MoveSide", this, &APlayerCharacterMovement::MoveSide);
	}

}

void APlayerCharacterMovement::MoveForward(float Axis) {
	FRotator Rotation = Controller->GetControlRotation();
	FRotator YawRotation(0.0f , Rotation.Yaw, 0.0f);

	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

	AddMovementInput(Direction, Axis);

}

void APlayerCharacterMovement::MoveSide(float Axis) {
	FRotator Rotation = Controller->GetControlRotation();
	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);

	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(Direction, Axis);
}