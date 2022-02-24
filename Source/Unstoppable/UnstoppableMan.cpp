#include "UnstoppableMan.h"
#include "Blueprint/UserWidget.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerState.h"

#include "Booster.h"
#include "Tags.h"
#include "UnstoppableManState.h"

AUnstoppableMan::AUnstoppableMan()
{
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->InitCapsuleSize(55.0f, 96.0f);
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AUnstoppableMan::OnBeginOverlap);

	GetCharacterMovement()->NavAgentProps.bCanCrouch = true;
	GetCharacterMovement()->NavAgentProps.bCanJump = true;
	GetCharacterMovement()->NavAgentProps.bCanWalk = true;

	GetCharacterMovement()->GravityScale = 2.0f;
	GetCharacterMovement()->MaxWalkSpeed = 1024.0f;
	GetCharacterMovement()->MaxWalkSpeedCrouched = 820.0f;
	GetCharacterMovement()->JumpZVelocity = 1024.0f;
	GetCharacterMovement()->AirControl = 0.4f;

	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("First Person Camera"));
	FirstPersonCamera->SetupAttachment(GetCapsuleComponent());
	FirstPersonCamera->bUsePawnControlRotation = true;

	HandsMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("HandsMesh"));
	HandsMesh->SetOnlyOwnerSee(true);
	HandsMesh->SetupAttachment(FirstPersonCamera);
	HandsMesh->CastShadow = false;
	HandsMesh->bCastDynamicShadow = false;

	Tags.Add(Tags::PLAYER_TAG);

	bDead = false;
}

void AUnstoppableMan::BeginPlay()
{
	Super::BeginPlay();
	if (HudWidgetClass != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("CLASS"));
		HudWidget = CreateWidget(GetWorld(), HudWidgetClass);
		HudWidget->AddToViewport();
	}
}

void AUnstoppableMan::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (!bDead) {
		AddMovementInput(GetActorForwardVector(), 1.0f);
	}

	GetPlayerState()->Score += 100 * DeltaSeconds;
}

void AUnstoppableMan::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	InputComponent->BindAction("Crouch", IE_Pressed, this, &AUnstoppableMan::Crouch);
	InputComponent->BindAction("Crouch", IE_Released, this, &AUnstoppableMan::UnCrouch);

	InputComponent->BindAction("Dead", IE_Pressed, this, &AUnstoppableMan::Dead);

	InputComponent->BindAxis("LookRight", this, &AUnstoppableMan::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &AUnstoppableMan::AddControllerPitchInput);
	InputComponent->BindAxis("Dash", this, &AUnstoppableMan::Dash);
}

void AUnstoppableMan::OnBeginOverlap(
	UPrimitiveComponent* HitComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComponent,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult
)
{
	if (bDead)
	{
		return;
	}
	if (OtherActor->ActorHasTag(Tags::ENEMY_TAG) || OtherActor->ActorHasTag(Tags::OBSTACLE_TAG))
	{
		Dead();
	}
}

void AUnstoppableMan::Crouch()
{
	ACharacter::Crouch(false);
}

void AUnstoppableMan::UnCrouch()
{
	ACharacter::UnCrouch(false);
}

void AUnstoppableMan::Dash(float Scale)
{
	if (Scale != 0.0f)
	{
		LaunchCharacter(GetActorRightVector() * Scale * DashSpeed, false, false);
	}
}

void AUnstoppableMan::Dead()
{
	if (!bDead) {
		bDead = true;
		HandsMesh->SetSimulatePhysics(true);
	}
}

bool AUnstoppableMan::IsDead()
{
	return bDead;
}