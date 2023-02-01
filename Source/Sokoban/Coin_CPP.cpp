// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin_CPP.h"

ACoin_CPP::ACoin_CPP()
{
	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComp"));

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	Sprite->SetupAttachment(RootComponent);	
}

void ACoin_CPP::BeginPlay()
{
	Tags.Add(FName("Coin"));
}
