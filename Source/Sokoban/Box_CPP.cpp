// Fill out your copyright notice in the Description page of Project Settings.


#include "Box_CPP.h"

ABox_CPP::ABox_CPP()
{
	//Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComp"));
}

void ABox_CPP::UpdateColor_BP_Implementation(ENUM_Color Color)
{
	// In BP
}

void ABox_CPP::UpdateColor(ENUM_Color Color)
{
	UpdateColor_BP(Color);
}
