// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin_CPP.h"
#include "Player_CPP.h"
#include "Engine/GameEngine.h"

ACoin_CPP::ACoin_CPP()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComp"));

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(FName("Box"));

	Sprite->SetupAttachment(RootComponent);	

	BoxCollision->SetupAttachment(RootComponent);
}

void ACoin_CPP::BeginPlay()
{
	Tags.Add(FName("Coin"));

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ACoin_CPP::OverlapBegin);
}

void ACoin_CPP::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APlayer_CPP* Player = Cast<APlayer_CPP>(OtherActor);

	if (Player)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("Coin Overlap"));
		Destroy();
	}
}
