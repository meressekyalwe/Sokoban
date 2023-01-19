// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once



#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "MainMenuWidget.h"

#include "SOKOBANGameMode.generated.h"


UCLASS()
class SOKOBAN_API ASOKOBANGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	ASOKOBANGameMode();

	virtual void BeginPlay() override;

	//virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditDefaultsOnly, Category = "UMG")
	TSubclassOf<UMainMenuWidget> MainMenuWidgetClass;

	UPROPERTY(VisibleInstanceOnly, Category = "UMG")
	class UMainMenuWidget* MMW;
};
