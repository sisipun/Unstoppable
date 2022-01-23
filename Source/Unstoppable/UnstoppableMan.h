#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Character.h"
#include "UnstoppableMan.generated.h"

UCLASS()
class UNSTOPPABLE_API AUnstoppableMan : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		UCameraComponent* FirstPersonCamera;

	AUnstoppableMan();

	void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
};