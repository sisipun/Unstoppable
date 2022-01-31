#include "EnemyController.h"
#include "EngineUtils.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

void AEnemyController::Tick(float DeltaSeconds)
{
	UE_LOG(LogTemp, Warning, TEXT("Pos"));
	AActor* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (Player)
	{
		UE_LOG(LogTemp, Warning, TEXT("Play"));
		MoveToActor(Player);
	}
}

