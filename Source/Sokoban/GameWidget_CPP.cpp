// Fill out your copyright notice in the Description page of Project Settings.


#include "GameWidget_CPP.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "SOKOBANGameMode.h"
#include "Engine/World.h"
#include "Components/TextBlock.h"

bool UGameWidget_CPP::Initialize()
{
	Super::Initialize();

	NextLevel->OnClicked.AddDynamic(this, &UGameWidget_CPP::NextLevelOnClicked);

	Exit->OnClicked.AddDynamic(this, &UGameWidget_CPP::ExitOnClicked);

	return true;
}

void UGameWidget_CPP::NextLevelOnClicked()
{
	ASOKOBANGameMode* GameMode = GetWorld()->GetAuthGameMode<ASOKOBANGameMode>();

	if (GameMode)
	{
		GameMode->SetNextLevel();

		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		PlayerController->bShowMouseCursor = false;
		SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UGameWidget_CPP::ExitOnClicked()
{
	if (!bFinish)
	{
		UWorld* World = GetWorld();

		if (World)
		{
			UKismetSystemLibrary::ExecuteConsoleCommand(World, TEXT("quit"));
		}
	}
	else
	{
		UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
	}
}

void UGameWidget_CPP::SetStatistics(int32 nSteps, int32 nCoins, int32 IndeLevel)
{
	Steps->SetText(FText::FromString(FString::FromInt(nSteps)));

	Coins->SetText(FText::FromString(FString::FromInt(nCoins)));

	FString Str;

	if (IndeLevel < 8)
	{
		Str = FString((FString("Level ") + FString::FromInt(nCoins + 1))) + FString(" Complete");
	}
	else
	{
		bFinish = true;
		Str = FString("    You Finish    ");
	}

	Level->SetText(FText::FromString(Str));
}


