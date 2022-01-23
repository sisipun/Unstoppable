#include "UnstoppableMan.h"

AUnstoppableMan::AUnstoppableMan()
{
	GetCapsuleComponent()->InitCapsuleSize(55.0f, 96.0f);

	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("First Person Camera"));
	FirstPersonCamera->SetupAttachment(GetCapsuleComponent());
	FirstPersonCamera->bUsePawnControlRotation = true;
}

void AUnstoppableMan::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
	InputComponent->BindAxis("LookRight", this, &AUnstoppableMan::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &AUnstoppableMan::AddControllerPitchInput);
}
