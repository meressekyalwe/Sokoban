// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainMenuWidget.h"
#include "PauseWidget_CPP.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SOKOBAN_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AMyPlayerController();

	void HandlePauseButton();

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UMainMenuWidget> MainMenuWidgetClass;

	UPROPERTY(VisibleInstanceOnly)
	class UMainMenuWidget* MenuWidget;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UPauseWidget_CPP> PauseWidgetClass;

	UPROPERTY(VisibleInstanceOnly)
	class UPauseWidget_CPP* PauseWidget;
};
