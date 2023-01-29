// Fill out your copyright notice in the Description page of Project Settings.


#include "Goal_CPP.h"

AGoal_CPP::AGoal_CPP()
{
	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComp"));

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	Sprite->SetupAttachment(RootComponent);
}


void AGoal_CPP::UpdateColor_BP_Implementation(ENUM_Color Color)
{
	// In BP
}

void AGoal_CPP::UpdateColor(ENUM_Color Color)
{
	UpdateColor_BP(Color);
}
