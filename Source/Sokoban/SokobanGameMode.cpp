// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "SOKOBANGameMode.h"
#include "MyPlayerController.h"
#include "MainMenuWidget.h"
#include "Runtime/Engine/Classes/Kismet/GamePlayStatics.h"
#include "Engine/Engine.h"
#include "PaperTileSet.h"
#include "Containers/UnrealString.h"

ASOKOBANGameMode::ASOKOBANGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASOKOBANGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (MainMenuWidgetClass)
	{
		MenuWidget = Cast<UMainMenuWidget>(CreateWidget(GetWorld(), MainMenuWidgetClass));

		if (MenuWidget)
		{
			MenuWidget->AddToViewport();
		}
	}
}




