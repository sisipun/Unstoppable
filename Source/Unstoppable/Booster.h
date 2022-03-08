#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Booster.generated.h"

UCLASS()
class UNSTOPPABLE_API ABooster : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Body")
		USphereComponent* Collider;

	UPROPERTY(BlueprintReadOnly, Category = "Body")
		UStaticMeshComponent* Mesh;

public:
	ABooster();
};
