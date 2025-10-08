// Copyright Epic Games, Inc. All Rights Reserved.


#include "MetalDetectorPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "MetalDetectorCameraManager.h"

AMetalDetectorPlayerController::AMetalDetectorPlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = AMetalDetectorCameraManager::StaticClass();
}

void AMetalDetectorPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}
