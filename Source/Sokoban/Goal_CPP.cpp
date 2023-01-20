// Fill out your copyright notice in the Description page of Project Settings.


#include "Goal_CPP.h"

AGoal_CPP::AGoal_CPP()
{
	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComp"));

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
}

