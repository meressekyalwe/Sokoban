// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class SOKOBAN_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
	virtual bool Initialize();

protected:

	UFUNCTION()
	void SettingsOnClicked();

	UFUNCTION()
	void StartOnClicked();

	UFUNCTION()
	void ExitOnClicked();

private:

	//UPROPERTY(meta = (BindWidget))
	//class UTextBlock* Title;

	UPROPERTY(meta = (BindWidget))
	class UButton* Settings;

	UPROPERTY(meta = (BindWidget))
	class UButton* Start;

	UPROPERTY(meta = (BindWidget))
	class UButton* Exit;
};
