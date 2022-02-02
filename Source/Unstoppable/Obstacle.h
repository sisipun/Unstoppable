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
	UPROPERTY(VisibleAnywhere, BLueprintReadOnly, Category = "Collider")
		UBoxComponent* Collider;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
		UStaticMeshComponent* Mesh;

public:
	AObstacle();

};
