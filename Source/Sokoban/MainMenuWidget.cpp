// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "SOKOBANGameMode.h"


bool UMainMenuWidget::Initialize()
{
	Super::Initialize();

	//Title->SetText(FText(""));

	Settings->OnClicked.AddDynamic(this, &UMainMenuWidget::SettingsOnClicked);

	Start->OnClicked.AddDynamic(this, &UMainMenuWidget::StartOnClicked);

	Exit->OnClicked.AddDynamic(this, &UMainMenuWidget::ExitOnClicked);

	return true;
}

void UMainMenuWidget::SettingsOnClicked()
{
	
}

void UMainMenuWidget::StartOnClicked()
{	
	RemoveFromParent();
}

void UMainMenuWidget::ExitOnClicked()
{
	UWorld* World = GetWorld();

	if (World)
	{
		UKismetSystemLibrary::ExecuteConsoleCommand(World, TEXT("quit"));
	}
}


