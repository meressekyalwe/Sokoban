// Fill out your copyright notice in the Description page of Project Settings.


#include "Box_CPP.h"
#include "UObject/ConstructorHelpers.h"
#include "PaperSprite.h"

ABox_CPP::ABox_CPP()
{
	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComp"));

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	SpriteComponent->SetupAttachment(RootComponent);

	Sprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/PushPushPuzzle2DKit/Sprites/Boxes/SP-BoxRed.SP-BoxRed'"));

	if (Sprite) SpriteComponent->SetSprite(Sprite);
}

void ABox_CPP::UpdateColor(ENUM_Color Color)
{

	if (Color == ENUM_Color::Blue)
	{
		Sprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/PushPushPuzzle2DKit/Sprites/Boxes/SP_BoxBlue.SP_BoxBlue'"));

		if (Sprite) SpriteComponent->SetSprite(Sprite);
	}
	else if (Color == ENUM_Color::Brown)
	{
		Sprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/PushPushPuzzle2DKit/Sprites/Boxes/SP_BoxBrown.SP_BoxBrown'"));

		if (Sprite) SpriteComponent->SetSprite(Sprite);
	}
	else if (Color == ENUM_Color::Gray)
	{
		Sprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/PushPushPuzzle2DKit/Sprites/Boxes/SP_BoxGray.SP_BoxGray'"));

		if (Sprite) SpriteComponent->SetSprite(Sprite);
	}
	else if (Color == ENUM_Color::Green)
	{
		Sprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/PushPushPuzzle2DKit/Sprites/Boxes/SP_BoxGreen.SP_BoxGreen'"));

		if (Sprite) SpriteComponent->SetSprite(Sprite);
	}
	else if (Color == ENUM_Color::Red)
	{
		Sprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/PushPushPuzzle2DKit/Sprites/Boxes/SP-BoxRed.SP-BoxRed'"));

		if (Sprite) SpriteComponent->SetSprite(Sprite);
	}

	ColorOfBox = Color;

	Tags.Add(FName("Movable")); // Movement
}

