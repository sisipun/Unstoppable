#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/Character.h"
#include "Perception/PawnSensingComponent.h"
#include "Enemy.generated.h"

UCLASS()
class UNSTOPPABLE_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
		UBehaviorTree* BehaviorTree;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
		UPawnSensingComponent* PawnSensingComponent;

	UFUNCTION()
		void OnDetectPawn(APawn* Pawn);
public:
	AEnemy();

	void BeginPlay() override;

};
