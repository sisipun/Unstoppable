// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "UnstoppableGameMode.h"
#include "UnstoppableHUD.h"
#include "UnstoppableCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnstoppableGameMode::AUnstoppableGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AUnstoppableHUD::StaticClass();
}
