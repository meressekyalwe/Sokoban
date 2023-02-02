// Fill out your copyright notice in the Description page of Project Settings.


#include "GameLevels.h"
#include "Engine/Engine.h"
#include "TileMapBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AGameLevels::AGameLevels()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TileMap = CreateDefaultSubobject<UPaperTileMapComponent>(TEXT("TileMapComponent"));

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	RootComponent = DefaultSceneRoot;

	TileMap->SetupAttachment(DefaultSceneRoot);
}

void AGameLevels::BeginPlay()
{
	Super::BeginPlay();

	Tags.Add(FName("Static"));
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

FString AGameLevels::GetTileUserDataString(FSTR_TileMapLocation TileMapLocation)
{
	FPaperTileInfo TileInfo = TileMap->GetTile(TileMapLocation.X, TileMapLocation.Y, TileMapLocation.Layer);

	if (TileInfo.TileSet)
	{
		FName Name = (TileInfo.TileSet)->GetTileUserData(TileInfo.GetTileIndex()); 

		return Name.ToString();
	}
	
	return {};
}

FVector AGameLevels::TileMapToWorld(FSTR_TileMapLocation TileMapLocation, float Y_coordinate)
{
	float Width = TileMap->TileMap->TileWidth * TileMapLocation.X;

	float Height = - TileMap->TileMap->TileHeight * (TileMapLocation.Y);

	FVector WorldLocation = TileMap->K2_GetComponentLocation();

	return FVector(Width, Y_coordinate, Height) + WorldLocation;
}

void AGameLevels::AnalyzeTileMap()
{
	int32 MapWidth, MapHeight, MapLayers;

	TileMap->GetMapSize(MapWidth, MapHeight, MapLayers);

	int i = 0;

	for (int32 j = 0; j < MapHeight; j++)
	{
		for (int32 k = 0; k < MapWidth; k++)
		{
			TileLocation = FSTR_TileMapLocation{ k, j, i };

			FString LeftS;

			FString RightS;

			if (GetTileUserDataString(FSTR_TileMapLocation{ k, j, i }).Split(TEXT("_"), &LeftS, &RightS, ESearchCase::IgnoreCase, ESearchDir::FromStart))
			{
				if (LeftS.Equals(FString(TEXT("PlayerStart"), ESearchCase::CaseSensitive)))
				{
					PlayerStartLocation = TileMapToWorld(TileLocation, 5.0f);
				}
				else if (LeftS.Equals(FString(TEXT("Box"), ESearchCase::CaseSensitive)))
				{
					BoxSpawnLocation.AddUnique({ TileLocation, StringToColor(RightS) });
				}
				else if (LeftS.Equals(FString(TEXT("Goal"), ESearchCase::CaseSensitive)))
				{
					GoalSpawnLocation.AddUnique({ TileLocation, StringToColor(RightS) });
				}
				else if (LeftS.Equals(FString(TEXT("Coin"), ESearchCase::CaseSensitive)))
				{
					CoinSpawnLocation.AddUnique({ TileLocation, StringToColor(RightS) });
				}
			}
		}
	}
}

void AGameLevels::ClearGameTileMapLayer()
{
	TileMap->MakeTileMapEditable();

	int32 MapWidth, MapHeight, MapLayers;

	TileMap->GetMapSize(MapWidth, MapHeight, MapLayers);

	for (int32 i = 0; i < MapHeight; i++)
	{
		for (int32 j = 0; j < MapWidth; j++)
		{
			FPaperTileInfo TileInfo{};
			TileMap->SetTile(j, i, 0, TileInfo);
		}
	}
}

void AGameLevels::SpawnBoxes(float Y_coordinate)
{
	
	for (int i = 0; i < BoxSpawnLocation.Num(); i++)
	{
		FVector Location(TileMapToWorld(BoxSpawnLocation[i].TileMapLocation, Y_coordinate));
		FTransform Transform(Location);
		ABox_CPP* Box = GetWorld()->SpawnActor<ABox_CPP>(BoxClass, Transform);
		Box->UpdateColor(BoxSpawnLocation[i].Color);
	}
}

void AGameLevels::SpawnGoals(float Y_coordinate)
{
	for (int i = 0; i < GoalSpawnLocation.Num(); i++)
	{
		FVector Location(TileMapToWorld(GoalSpawnLocation[i].TileMapLocation, Y_coordinate));
		FTransform Transform(Location);
		AGoal_CPP* Goal = GetWorld()->SpawnActor<AGoal_CPP>(GoalClass, Transform);
		Goal->UpdateColor(GoalSpawnLocation[i].Color);
	}
}

void AGameLevels::SpawnCoins(float Y_coordinate)
{
	for (int i = 0; i < CoinSpawnLocation.Num(); i++)
	{
		FVector Location(TileMapToWorld(CoinSpawnLocation[i].TileMapLocation, Y_coordinate));
		FTransform Transform(Location);
		GetWorld()->SpawnActor<ACoin_CPP>(CoinClass, Transform);
	}
}

void AGameLevels::SpawnPlayer()
{
	FTransform Transform(PlayerStartLocation);
	APlayer_CPP* Palyer = GetWorld()->SpawnActor<APlayer_CPP>(PlayerClass, Transform);
}



