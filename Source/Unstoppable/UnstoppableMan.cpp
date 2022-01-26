 #include "UnstoppableMan.h"

AUnstoppableMan::AUnstoppableMan()
{
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->InitCapsuleSize(55.0f, 96.0f);

	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("First Person Camera"));
	FirstPersonCamera->SetupAttachment(GetCapsuleComponent());
	FirstPersonCamera->bUsePawnControlRotation = true;

	HandsMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("HandsMesh"));
	HandsMesh->SetOnlyOwnerSee(true);
	HandsMesh->SetupAttachment(FirstPersonCamera);
	HandsMesh->CastShadow = false;
	HandsMesh->bCastDynamicShadow = false;

	bDead = false;
}

void AUnstoppableMan::Tick(float DeltaSeconds)
{
	if (!bDead) {
		AddMovementInput(GetActorForwardVector(), 1.0f);
	}
}

void AUnstoppableMan::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	InputComponent->BindAction("Crouch", IE_Pressed, this, &AUnstoppableMan::Crouch);
	InputComponent->BindAction("Crouch", IE_Released, this, &AUnstoppableMan::UnCrouch);

	InputComponent->BindAction("Dead", IE_Pressed, this, &AUnstoppableMan::Dead);

	InputComponent->BindAxis("LookRight", this, &AUnstoppableMan::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &AUnstoppableMan::AddControllerPitchInput);
}

void AUnstoppableMan::Crouch()
{
	ACharacter::Crouch(false);
}

void AUnstoppableMan::UnCrouch()
{
	ACharacter::UnCrouch(false);
}

void AUnstoppableMan::Dead()
{
	if (!bDead) {
		bDead = true;
		HandsMesh->SetSimulatePhysics(true);
	}
}