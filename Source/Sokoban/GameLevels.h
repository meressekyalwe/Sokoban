// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperTileMap.h"
#include "PaperTileMapComponent.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "Goal_CPP.h"
#include "Coin_CPP.h"
#include "Box_CPP.h"
#include "Player_CPP.h"
#include "Types.h"
#include "Containers/UnrealString.h"
#include "PaperTileSet.h"
#include "GameLevels.generated.h"


UCLASS()
class SOKOBAN_API AGameLevels : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameLevels();

	virtual void BeginPlay() override;

	// Tile Map
	ENUM_Color StringToColor(FString String);

	FString GetTileUserDataString(FSTR_TileMapLocation TileMapLocation);

	FVector TileMapToWorld(FSTR_TileMapLocation TileMapLocation, float Y_coordinate);

	void AnalyzeTileMap();

	void ClearGameTileMapLayer();

	// Spawning 

	void SpawnBoxes(float Y_coordinate);

	void SpawnGoals(float Y_coordinate);

	void SpawnCoins(float Y_coordinate);

	void SpawnPlayer();

	// SPAWN
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Spawn")
	TArray<FSTR_SpawnInformation> BoxSpawnLocation;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Spawn")
	TArray<FSTR_SpawnInformation> GoalSpawnLocation;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Spawn")
	TArray<FSTR_SpawnInformation> CoinSpawnLocation;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Spawn")
	FVector PlayerStartLocation;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Spawn")
	FVector PlayerHideLocation;

	// COMPONENT
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Spawn")
	FSTR_TileMapLocation TileLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperTileMapComponent* TileMap;

	// SUBCLASS
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGoal_CPP> GoalClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ACoin_CPP> CoinClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ABox_CPP> BoxClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<APlayer_CPP> PlayerClass;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Spawn")
	USceneComponent* DefaultSceneRoot;
};
