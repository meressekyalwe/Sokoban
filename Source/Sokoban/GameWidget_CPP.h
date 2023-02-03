// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameWidget_CPP.generated.h"

/**
 * 
 */
UCLASS()
class SOKOBAN_API UGameWidget_CPP : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual bool Initialize();

	UFUNCTION()
	void NextLevelOnClicked();

	UFUNCTION()
	void ExitOnClicked();

	UFUNCTION()
	void SetStatistics(int32 nSteps, int32 nCoins, int32 IndeLevel);

private:

	UPROPERTY(meta = (BindWidget))
	class UButton* NextLevel;

	UPROPERTY(meta = (BindWidget))
	class UButton* Exit;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Steps;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Coins;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Level;

	bool bFinish = false;
};
