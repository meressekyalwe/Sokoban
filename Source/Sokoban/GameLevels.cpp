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

FString AGameLevels::GetTileUserDataString(FSTR_TileMapLocation _TileLocation)
{
	FPaperTileInfo TileInfo = TileMap->GetTile(TileLocation.X, TileLocation.Y, TileLocation.Layer);

	FName Name = TileInfo.StaticStruct()->GetFName();

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
				TileLocation = FSTR_TileMapLocation{MapWidth, MapHeight, MapLayers};

				FString LeftS;

				FString RightS;

				if (GetTileUserDataString(TileLocation).Split(TEXT("_"), &LeftS, &RightS, ESearchCase::IgnoreCase, ESearchDir::FromStart))
				{
					FSTR_SpawnInformation SpawnInformation = FSTR_SpawnInformation{ TileLocation, ENUM_Color::Brown }; // String To Color

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
