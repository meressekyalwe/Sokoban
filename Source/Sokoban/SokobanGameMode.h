// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameLevels.h"
#include "SOKOBANGameMode.generated.h"



UCLASS()
class SOKOBAN_API ASOKOBANGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	ASOKOBANGameMode();

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGameLevels> GameLevelsClass;

	void SpawnLevel();
};
