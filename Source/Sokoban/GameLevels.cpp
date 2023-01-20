// Fill out your copyright notice in the Description page of Project Settings.


#include "GameLevels.h"


// Sets default values
AGameLevels::AGameLevels()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TileMap = CreateAbstractDefaultSubobject<UPaperTileMapComponent>(TEXT("TileMapComponent"));

	TileMap->SetupAttachment(RootComponent);
}


