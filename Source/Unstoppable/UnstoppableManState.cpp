#include "UnstoppableManState.h"
#include "UnstoppableMan.h"

AUnstoppableManState::AUnstoppableManState()
{
	PrimaryActorTick.bCanEverTick = true;
	Coins = 0;
	PlayerScore = 0.0f;
}

void AUnstoppableManState::Tick(float DeltaSeconds)
{
	AUnstoppableMan* Player = Cast<AUnstoppableMan>(GetPawn());
	if (Player && !Player->IsDead()) {
		PlayerScore += (DeltaSeconds * PlayerScorePerSecond);
	}
}

void AUnstoppableManState::AddCoin()
{
	Coins++;
}
