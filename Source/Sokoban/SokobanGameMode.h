// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainMenuWidget.h"
#include "PaperTileMap.h"
#include "PaperTileMapComponent.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "Goal_CPP.h"
#include "Coin_CPP.h"
#include "Box_CPP.h"
#include "Types.h"
#include "SOKOBANGameMode.generated.h"



UCLASS()
class SOKOBAN_API ASOKOBANGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	ASOKOBANGameMode();

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UMainMenuWidget> MainMenuWidgetClass;

	UPROPERTY(VisibleInstanceOnly)
	class UMainMenuWidget* MenuWidget;
};
