// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"

AMyPlayerController::AMyPlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
}

void AMyPlayerController::HandlePauseButton()
{
	UGameplayStatics::SetGamePaused(GetWorld(), true);

	if (PauseWidgetClass)
	{
		PauseWidget = Cast<UPauseWidget_CPP>(CreateWidget(GetWorld(), PauseWidgetClass));

		if (PauseWidget)
		{
			PauseWidget->AddToViewport();
			SetInputMode(FInputModeUIOnly());
			bShowMouseCursor = true;
		}
	}
}

void AMyPlayerController::BeginPlay()
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

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Pause", EInputEvent::IE_Pressed, this, &AMyPlayerController::HandlePauseButton);
}
