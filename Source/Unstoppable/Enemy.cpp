#include "Enemy.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Tags.h"
#include "EnemyController.h"

AEnemy::AEnemy()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;

	AIControllerClass = AEnemyController::StaticClass();

	Tags.Add(Tags::ENEMY_TAG);
}
