#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "UnstoppableManState.generated.h"

UCLASS()
class UNSTOPPABLE_API AUnstoppableManState : public APlayerState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Score")
		float PlayerScorePerSecond;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score")
		float PlayerScore;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score")
		int Coins;

public:
	UFUNCTION(BlueprintCallable)
		void AddCoin();

public:
	AUnstoppableManState();

	void Tick(float DeltaSeconds) override;

};
