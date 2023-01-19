// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "SOKOBANGameMode.h"
#include "MyPlayerController.h"
#include "MainMenuWidget.h"
#include "Engine.h" 

ASOKOBANGameMode::ASOKOBANGameMode()
{
	PrimaryActorTick.bCanEverTick = true;

	PlayerControllerClass = AMyPlayerController::StaticClass();		
}

void ASOKOBANGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (MainMenuWidgetClass)
	{
		MMW = Cast<UMainMenuWidget>(CreateWidget(GetWorld(), MainMenuWidgetClass));

		if (MMW)
		{
			MMW->AddToViewport();
		}
	}
}
