#include "UnstoppableManState.h"


AUnstoppableManState::AUnstoppableManState()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AUnstoppableManState::Tick(float DeltaSeconds)
{
	PlayerScore += (DeltaSeconds * PlayerScorePerSecond);
	UE_LOG(LogTemp, Warning, TEXT("Score: %f"), PlayerScore);
}
