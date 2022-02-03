#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Character.h"
#include "UnstoppableMan.generated.h"

UCLASS()
class UNSTOPPABLE_API AUnstoppableMan : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
		USkeletalMeshComponent* HandsMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		UCameraComponent* FirstPersonCamera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
		float DashSpeed;

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
	AUnstoppableMan();

	void Tick(float DeltaSeconds) override;

	void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

	bool IsDead();

private:

	void Crouch();

	void UnCrouch();

	void Dash(float Scale);

	void Dead();

	bool bDead;
};
