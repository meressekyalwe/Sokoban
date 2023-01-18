// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "SokobanGameMode.h"
#include "SokobanCharacter.h"

ASokobanGameMode::ASokobanGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = ASokobanCharacter::StaticClass();	
}
