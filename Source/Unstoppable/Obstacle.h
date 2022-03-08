#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

UCLASS()
class UNSTOPPABLE_API AObstacle : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(BLueprintReadOnly, Category = "Body")
		UBoxComponent* Collider;

	UPROPERTY(BlueprintReadOnly, Category = "Body")
		UStaticMeshComponent* Mesh;

public:
	AObstacle();

};
