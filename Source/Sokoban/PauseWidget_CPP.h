// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "PauseWidget_CPP.generated.h"

/**
 * 
 */
UCLASS()
class SOKOBAN_API UPauseWidget_CPP : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual bool Initialize();

	UPROPERTY(meta = (BindWidget))
	class UButton* ContinueGame;

	UPROPERTY(meta = (BindWidget))
	class UButton* QuitGame;

	UFUNCTION()
	void ContinueGameButtonClicked();

	UFUNCTION()
	void QuitGameButtonClicked();
};
