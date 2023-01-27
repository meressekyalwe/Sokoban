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
}

void ASOKOBANGameMode::SpawnLevel()
{
	FVector Location(0);
	FTransform Transform(Location);
	AGameLevels* GameLevel = GetWorld()->SpawnActor<AGameLevels>(GameLevelsClass, Transform);
	GameLevel->AnalyzeTileMap();
	GameLevel->SpawnPlayer();
	GameLevel->ClearGameTileMapLayer();
	GameLevel->SpawnBoxes(4);
	GameLevel->SpawnCoins(3);
	GameLevel->SpawnGoals(3);
}




