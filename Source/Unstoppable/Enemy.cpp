#include "Enemy.h"
#include "EnemyController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Tags.h"
#include "UnstoppableMan.h"

AEnemy::AEnemy()
{
	AIControllerClass = AEnemyController::StaticClass();
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;

	PawnSensingComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Pawn Sensing"));
	PawnSensingComponent->SetPeripheralVisionAngle(90.0f);

	Tags.Add(Tags::ENEMY_TAG);
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	if (PawnSensingComponent) {
		PawnSensingComponent->OnSeePawn.AddDynamic(this, &AEnemy::OnDetectPawn);
	}
}

void AEnemy::Tick(float DeltaSeconds)
{
	if (Target && !PawnSensingComponent->CouldSeePawn(Target))
	{
		Target = nullptr;
		AEnemyController* Controller = Cast<AEnemyController>(GetController());
		if (Controller)
		{
			Controller->OnLostTarget();
		}
	} 
}

void AEnemy::OnDetectPawn(APawn* Pawn)
{
	AUnstoppableMan* Player = Cast<AUnstoppableMan>(Pawn);
	if (Player)
	{
		AEnemyController* Controller = Cast<AEnemyController>(GetController());
		if (Controller)
		{
			Target = Pawn;
			Controller->OnDetectTarget(Pawn);
		}
	}
}