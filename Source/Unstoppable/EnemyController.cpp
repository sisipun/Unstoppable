#include "EnemyController.h"
#include "BehaviorTree/BlackboardData.h"
#include "EngineUtils.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

#include "Enemy.h"

AEnemyController::AEnemyController()
{
	PrimaryActorTick.bCanEverTick = false;

	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("Behavior Tree"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard"));

	TargetPawnKey = "Target";
}

void AEnemyController::OnPossess(APawn* Pawn)
{
	Super::OnPossess(Pawn);

	AEnemy* Enemy = Cast<AEnemy>(Pawn);
	if (Enemy)
	{
		UBlackboardData* BlackboardData = Enemy->BehaviorTree->BlackboardAsset;
		if (BlackboardData)
		{
			BlackboardComponent->InitializeBlackboard(*BlackboardData);
		}

		BehaviorTreeComponent->StartTree(*Enemy->BehaviorTree);
	}
}

void AEnemyController::OnSeeTarget(APawn* Target)
{
	BlackboardComponent->SetValueAsObject(TargetPawnKey, Target);
}

