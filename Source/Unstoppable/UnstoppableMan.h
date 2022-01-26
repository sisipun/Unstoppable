#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
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

	AUnstoppableMan();

	void Tick(float DeltaSeconds) override;

	void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
private:

	void Crouch();

	void UnCrouch();

	void Dead();

	void MoveX(float Scale);

	void MoveY(float Scale);

	bool bDead;
};
