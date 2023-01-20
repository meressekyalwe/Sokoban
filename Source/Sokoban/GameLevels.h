// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperTileMapComponent.h"
#include "GameLevels.generated.h"


UCLASS()
class SOKOBAN_API AGameLevels : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameLevels();



private:

	UPROPERTY(EditAnywhere)
	UPaperTileMapComponent* TileMap;


};
