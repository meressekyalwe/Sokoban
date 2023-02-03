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

	if (GameWidgetClass)
	{
		GameWidget = Cast<UGameWidget_CPP>(CreateWidget(GetWorld(), GameWidgetClass));
	}
}

bool ASOKOBANGameMode::LevelComplete()
{
	TArray<AActor*> FoundGoals;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGoal_CPP::StaticClass(), FoundGoals);

	int Counting = 0;

	for (AActor* TActor : FoundGoals)
	{
		AGoal_CPP* Goal = Cast<AGoal_CPP>(TActor);

		if (Goal != nullptr)
		{
			if (Goal->bOccupied)
			{
				Counting += 1;
			}			
		}
	}

	return FoundGoals.Num() == Counting;
}

void ASOKOBANGameMode::NextGameLevel()
{
	if (LevelComplete())
	{
		CurrentLevelIndex += 1;

		UGameplayStatics::SetGamePaused(GetWorld(), true);

		if (GameWidget)
		{
			GameWidget->SetStatistics(nSteps, nCoins, CurrentLevelIndex);

			APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
			PlayerController->bShowMouseCursor = true;

			if (CurrentLevelIndex == 1)
			{
				GameWidget->AddToViewport();
			}
			else
			{	
				GameWidget->SetVisibility(ESlateVisibility::Visible);
			}	
		}
	}
}

void ASOKOBANGameMode::SetNextLevel()
{
	GameLevel->SetTileMap(CurrentLevelIndex);

	UGameplayStatics::SetGamePaused(GetWorld(), false);
}

void ASOKOBANGameMode::SpawnGameLevel()
{
	FVector Location(ForceInitToZero);
	FTransform Transform(Location);
	GameLevel = GetWorld()->SpawnActor<AGameLevels>(GameLevelsClass, Transform);
	GameLevel->SetTileMap(CurrentLevelIndex);
}

void ASOKOBANGameMode::SetStatistiques(int32 OneStep, int32 OneCoin)
{
	if (OneStep) nSteps += OneStep;

	if (OneCoin) nCoins += OneCoin;
}






