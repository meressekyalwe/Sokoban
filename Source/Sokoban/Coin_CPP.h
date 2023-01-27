// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "PaperSpriteComponent.h"
#include "Coin_CPP.generated.h"

/**
 * 
 */
UCLASS()
class SOKOBAN_API ACoin_CPP : public APaperSpriteActor
{
	GENERATED_BODY()

public:

	ACoin_CPP();

	virtual void BeginPlay() override;
	
	//UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	//UPaperSpriteComponent* Sprite;
};
