#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyController.generated.h"

UCLASS()
class UNSTOPPABLE_API AEnemyController : public AAIController
{
	GENERATED_BODY()

public:
	void Tick(float DeltaSeconds) override;
};
