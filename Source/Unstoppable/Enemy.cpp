#include "Enemy.h"
#include "EnemyController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Tags.h"
#include "UnstoppableMan.h"

AEnemy::AEnemy()
{
	AIControllerClass = AEnemyController::StaticClass();
	PrimaryActorTick.bCanEverTick = false;

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

void AEnemy::OnDetectPawn(APawn* Pawn)
{
	AUnstoppableMan* Player = Cast<AUnstoppableMan>(Pawn);
	if (Player)
	{
		AEnemyController* Controller = Cast<AEnemyController>(GetController());
		if (Controller)
		{
			Controller->OnSeeTarget(Player);
		}
	}
}