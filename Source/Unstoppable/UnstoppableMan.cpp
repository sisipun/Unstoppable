#include "UnstoppableMan.h"

AUnstoppableMan::AUnstoppableMan()
{
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->InitCapsuleSize(55.0f, 96.0f);

	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("First Person Camera"));
	FirstPersonCamera->SetupAttachment(GetCapsuleComponent());
	FirstPersonCamera->bUsePawnControlRotation = true;
}

void AUnstoppableMan::Tick(float DeltaSeconds)
{
	AddMovementInput(GetActorForwardVector(), MovementSpeed * DeltaSeconds);
}

void AUnstoppableMan::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
	InputComponent->BindAxis("LookRight", this, &AUnstoppableMan::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &AUnstoppableMan::AddControllerPitchInput);
}
