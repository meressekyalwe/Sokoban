// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Kismet/BlueprintFunctionLibrary.h"
#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "Engine/EngineTypes.h"
#include "Types.generated.h"

UENUM(BlueprintType)
enum class ENUM_Color : uint8
{	 
	Brown UMETA(DisplayName = "The color Brown"),
	Red UMETA(DisplayName = "The color Red"),
	Blue UMETA(DisplayName = "The color Blue"),
	Green UMETA(DisplayName = "The color Green"),
	Gray UMETA(DisplayName = "The color Gray")
};

UENUM(BlueprintType)
enum class ENUM_Direction : uint8
{
	Up UMETA(DisplayName = "The up direction"),
	Down UMETA(DisplayName = "The down direction"),
	Right UMETA(DisplayName = "The right direction"),
	Left UMETA(DisplayName = "The left direction"),
	Stop UMETA(DisplayName = "Don't move")
};

UENUM(BlueprintType)
enum class ENUM_PlayerCharacter : uint8
{
	Plumber1 UMETA(DisplayName = "The plumber character1"),
	Plumber2 UMETA(DisplayName = "The plumber character2"),
	CoolGuy UMETA(DisplayName = "The cool guy character")
};

USTRUCT(BlueprintType)
struct FSTR_TileMapLocation
{
	GENERATED_BODY()

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	int X = 0;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	int Y = 0;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	int Layer = 0;

	bool operator == (const FSTR_TileMapLocation TileMapLocation) const
	{
		return TileMapLocation.X == X && TileMapLocation.Y == Y && TileMapLocation.Layer == Layer;
	}
};

USTRUCT(BlueprintType)
struct FSTR_SpawnInformation 
{
	GENERATED_BODY()

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	FSTR_TileMapLocation TileMapLocation;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	ENUM_Color Color;

	bool operator == (const FSTR_SpawnInformation  SpawnInformation) const
	{
		return SpawnInformation.Color == Color && SpawnInformation.TileMapLocation == TileMapLocation;
	}
};


UCLASS()
class SOKOBAN_API UTypes : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

};
