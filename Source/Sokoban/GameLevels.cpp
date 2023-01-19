// Fill out your copyright notice in the Description page of Project Settings.


#include "GameLevels.h"

// Sets default values
AGameLevels::AGameLevels()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	//TileMap = PAPER2APaperTileMapActor

}

// Called when the game starts or when spawned
void AGameLevels::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameLevels::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

