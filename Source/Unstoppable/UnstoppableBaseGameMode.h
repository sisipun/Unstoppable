#pragma once

#include "CoreMinimal.h"
#include "EngineUtils.h"
#include "GameFramework/GameModeBase.h"
#include "Tile.h"
#include "UnstoppableBaseGameMode.generated.h"

UCLASS()
class UNSTOPPABLE_API AUnstoppableBaseGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tiles")
		TArray<TSubclassOf<ATile>> TileTypes;

	UPROPERTY(BlueprintReadOnly, Category = "Tiles")
		TArray<ATile*> Tiles;

	UPROPERTY(BlueprintReadWrite, Category = "Tiles")
		ATile* FirstTile;

	UPROPERTY(BlueprintReadWrite, Category = "Tiles")
		ATile* LastTile;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tiles")
		int32 MaxSpawnedTiles;

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Tiles")
	void SpawnTile();

protected:
	void BeginPlay() override;
};
