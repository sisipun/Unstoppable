// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

UCLASS()
class UNSTOPPABLE_API ATile : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Body")
		UBoxComponent* GenerateTileCollider;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Body")
		UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Body")
		UArrowComponent* AttachPoint;

public:
	UFUNCTION()
		void OnBeginOverlap(
			UPrimitiveComponent* HitComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComponent,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult
		);

public:
	ATile();
};
