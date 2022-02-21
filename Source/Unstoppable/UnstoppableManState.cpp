#include "UnstoppableManState.h"
#include "UnstoppableMan.h"

AUnstoppableManState::AUnstoppableManState()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AUnstoppableManState::Tick(float DeltaSeconds)
{
	AUnstoppableMan* Player = Cast<AUnstoppableMan>(GetPawn());
	if (Player && !Player->IsDead()) {
		PlayerScore += (DeltaSeconds * PlayerScorePerSecond);
	}
}
