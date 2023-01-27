// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseWidget_CPP.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"


bool UPauseWidget_CPP::Initialize()
{
	Super::Initialize();

	ContinueGame->OnClicked.AddDynamic(this, &UPauseWidget_CPP::ContinueGameButtonClicked);

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
