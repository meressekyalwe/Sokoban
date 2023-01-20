// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"
#include "Goal_CPP.generated.h"

/**
 * 
 */
UCLASS()
class SOKOBAN_API AGoal_CPP : public APaperSpriteActor
{
	GENERATED_BODY()

public:

	AGoal_CPP();

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	UPaperSpriteComponent* Sprite;	

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	UBoxComponent* Box;
};
