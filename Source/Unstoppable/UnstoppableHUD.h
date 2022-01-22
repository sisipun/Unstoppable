// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UnstoppableHUD.generated.h"

UCLASS()
class AUnstoppableHUD : public AHUD
{
	GENERATED_BODY()

public:
	AUnstoppableHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

