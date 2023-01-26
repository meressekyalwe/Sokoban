// Fill out your copyright notice in the Description page of Project Settings.


#include "GameLevels.h"
#include "Engine/Engine.h"
#include "PaperTileSet.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AGameLevels::AGameLevels()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TileMap = CreateDefaultSubobject<UPaperTileMapComponent>(TEXT("TileMapComponent"));

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	RootComponent = DefaultSceneRoot;

	TileMap->AttachTo(DefaultSceneRoot);
}

ENUM_Color AGameLevels::StringToColor(FString String)
{
	ENUM_Color Color{};

	if (String.Equals(FString(TEXT("Brown"), ESearchCase::CaseSensitive)))
	{
		Color = ENUM_Color::Brown;
	}
	if (String.Equals(FString(TEXT("Red"), ESearchCase::CaseSensitive)))
	{
		Color = ENUM_Color::Red;
	}
	if (String.Equals(FString(TEXT("Blue"), ESearchCase::CaseSensitive)))
	{
		Color = ENUM_Color::Blue;
	}
	if (String.Equals(FString(TEXT("Green"), ESearchCase::CaseSensitive)))
	{
		Color = ENUM_Color::Green;
	}
	if (String.Equals(FString(TEXT("Gray"), ESearchCase::CaseSensitive)))
	{
		Color = ENUM_Color::Gray;
	}

	return Color;
}

FString AGameLevels::GetTileUserDataString(FSTR_TileMapLocation _TileLocation)
{
	FPaperTileInfo Tile = TileMap->GetTile(_TileLocation.X, _TileLocation.Y, _TileLocation.Layer);

	FName Name = Tile.TileSet->GetTileUserData(Tile.GetTileIndex()); // BUG !!!

	return Name.ToString();
}

FVector AGameLevels::TileMapToWorld(FSTR_TileMapLocation TileMapLocation, float Y_coordinate)
{
	float Width = TileMap->TileMap->TileWidth * TileMapLocation.X;

	float Height = TileMap->TileMap->TileHeight * (TileMapLocation.Y - 1);

	FVector WorldLocation = TileMap->K2_GetComponentLocation();

	return FVector(Width, Y_coordinate, Height) + WorldLocation;
}

void AGameLevels::AnalyzeTileMap()
{
	int32 MapWidth, MapHeight, MapLayers;

	TileMap->GetMapSize(MapWidth, MapHeight, MapLayers);

	for (int32 i = 0; i < MapLayers; i++)
	{
		for (int32 j = 0; j < MapHeight; j++)
		{
			for (int32 k = 0; k < MapWidth; k++)
			{
				TileLocation = FSTR_TileMapLocation{ k, j, i };

				FString LeftS;

				FString RightS;

				FString SpriteName = GetTileUserDataString(FSTR_TileMapLocation{ k, j, i });

				if (SpriteName.Split(TEXT("_"), &LeftS, &RightS, ESearchCase::IgnoreCase, ESearchDir::FromStart))
				{
					FSTR_SpawnInformation SpawnInformation = FSTR_SpawnInformation{ TileLocation, StringToColor(RightS) }; // String To Color

					if (LeftS.Equals(FString(TEXT("PlayerStart"), ESearchCase::CaseSensitive)))
					{
						PlayerStartLocation = TileMapToWorld(TileLocation, 5.0f);
					}
					if (LeftS.Equals(FString(TEXT("Box"), ESearchCase::CaseSensitive)))
					{
						BoxSpawnLocation.Add(SpawnInformation);
					}
					if (LeftS.Equals(FString(TEXT("Goal"), ESearchCase::CaseSensitive)))
					{
						GoalSpawnLocation.Add(SpawnInformation);
					}
					if (LeftS.Equals(FString(TEXT("Coin"), ESearchCase::CaseSensitive)))
					{
						CoinSpawnLocation.Add(SpawnInformation);
					}
				}
			}
		}
	}
}

void AGameLevels::SpawnBoxes(float Y_coordinate)
{
	for (int i = 0; i < BoxSpawnLocation.Num(); i++)
	{
		FVector Location(TileMapToWorld(BoxSpawnLocation[i].TileMapLocation, Y_coordinate));
		FTransform Transform(Location);
		GetWorld()->SpawnActor<ABox_CPP>(BoxClass, Transform);
	}
}

void AGameLevels::SpawnGoals(float Y_coordinate)
{
	for (int i = 0; i < GoalSpawnLocation.Num(); i++)
	{
		FVector Location(TileMapToWorld(GoalSpawnLocation[i].TileMapLocation, Y_coordinate));
		FTransform Transform(Location);
		GetWorld()->SpawnActor<AGoal_CPP>(GoalClass, Transform);
	}
}

void AGameLevels::SpawnCoins(float Y_coordinate)
{
	for (int i = 0; i < CoinSpawnLocation.Num(); i++)
	{
		FVector Location(TileMapToWorld(CoinSpawnLocation[i].TileMapLocation, Y_coordinate));
		FTransform Transform(Location);
		GetWorld()->SpawnActor<AGoal_CPP>(CoinClass, Transform);
	}
}

void AGameLevels::SetPlayerLocation(FVector Location)
{
	//UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

}
