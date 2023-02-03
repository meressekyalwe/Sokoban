// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameLevels.h"
#include "GameWidget_CPP.h"
#include "PaperTileMapComponent.h"
#include "UObject/SoftObjectPtr.h"
#include "SOKOBANGameMode.generated.h"



UCLASS()
class SOKOBAN_API ASOKOBANGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	ASOKOBANGameMode();

	virtual void BeginPlay() override;

	bool LevelComplete();

	void NextGameLevel();

	void SetNextLevel();

	void SpawnGameLevel();

	void SetStatistiques(int32 OneStep, int32 OneCoin);

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGameLevels> GameLevelsClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameWidget_CPP> GameWidgetClass;

	UPROPERTY(VisibleInstanceOnly)
	class UGameWidget_CPP* GameWidget;

	UPROPERTY(BlueprintReadWrite)
	int32 CurrentLevelIndex = 0;

	UPROPERTY(BlueprintReadWrite)
	int32 nSteps = 0;

	UPROPERTY(BlueprintReadWrite)
	int32 nCoins = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AGameLevels* GameLevel = nullptr;
};
