// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseWidget_CPP.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"


bool UPauseWidget_CPP::Initialize()
{
	Super::Initialize();

	ContinueGame->OnClicked.AddDynamic(this, &UPauseWidget_CPP::ContinueGameButtonClicked);
	QuitGame->OnClicked.AddDynamic(this, &UPauseWidget_CPP::QuitGameButtonClicked);

	return true;
}

void UPauseWidget_CPP::ContinueGameButtonClicked()
{
	UGameplayStatics::SetGamePaused(GetWorld(), false);

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	if (PlayerController)
	{
		PlayerController->SetInputMode(FInputModeGameOnly());
		PlayerController->bShowMouseCursor = false;
	}

	RemoveFromParent();
}

void UPauseWidget_CPP::QuitGameButtonClicked()
{
	UWorld* World = GetWorld();

	if (World)
	{
		UKismetSystemLibrary::ExecuteConsoleCommand(World, TEXT("quit"));
	}
}
