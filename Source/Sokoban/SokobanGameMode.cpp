// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "SOKOBANGameMode.h"
#include "MyPlayerController.h"
#include "MainMenuWidget.h"
#include "Runtime/Engine/Classes/Kismet/GamePlayStatics.h"

ASOKOBANGameMode::ASOKOBANGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
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

void ASOKOBANGameMode::SpawnGameLevels()
{
	UGameplayStatics::OpenLevel(this, "GameMap");

	FVector Location(0);
	FTransform Transform(Location);

	GetWorld()->SpawnActor<AGameLevels>(GameLevelsClass, Transform);
}
