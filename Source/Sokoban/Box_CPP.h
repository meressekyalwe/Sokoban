// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "PaperSpriteComponent.h"
#include "PaperTileSet.h"
#include "Types.h"
#include "Box_CPP.generated.h"

/**
 * 
 */
UCLASS()
class SOKOBAN_API ABox_CPP : public APaperSpriteActor
{
	GENERATED_BODY()

public:

	ABox_CPP();

	UFUNCTION(BlueprintNativeEvent)
	void UpdateColor_BP(ENUM_Color Color);

	void UpdateColor(ENUM_Color Color);

	//UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	//UPaperSpriteComponent* Sprite;
};
