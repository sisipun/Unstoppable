#include "UnstoppableBaseGameMode.h"

void AUnstoppableBaseGameMode::BeginPlay()
{
	Super::BeginPlay();
	for (TActorIterator<ATile> TileIter(GetWorld()); TileIter; ++TileIter)
	{
		Tiles.Add(*TileIter);
	}

	Tiles.Sort([](const ATile& t1, const ATile& t2) { return t1.GetActorLocation().X < t2.GetActorLocation().X; });

	FirstTile = Tiles[0];
	LastTile = Tiles.Last(0);
}

void AUnstoppableBaseGameMode::SpawnTile_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("AUnstoppableBaseGameMode::SpawnTile has no implementation"));
}