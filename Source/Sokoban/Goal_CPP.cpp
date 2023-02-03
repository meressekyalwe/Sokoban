// Fill out your copyright notice in the Description page of Project Settings.


#include "Goal_CPP.h"
#include "Engine/GameEngine.h"
#include "SOKOBANGameMode.h"

AGoal_CPP::AGoal_CPP()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComp"));

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));

	Sprite->SetupAttachment(RootComponent);

	Box->SetupAttachment(RootComponent);

	Box->InitBoxExtent(FVector(54.f, 10.f, 54.f));
}


void AGoal_CPP::UpdateColor_BP_Implementation(ENUM_Color Color)
{
	// In BP
}

void AGoal_CPP::BeginPlay()
{
	Super::BeginPlay();

	Box->OnComponentBeginOverlap.AddDynamic(this, &AGoal_CPP::OverlapBegin);
	Box->OnComponentEndOverlap.AddDynamic(this, &AGoal_CPP::OverlapEnd);
}

void AGoal_CPP::UpdateColor(ENUM_Color Color)
{
	UpdateColor_BP(Color);

	ColorOfGoal = Color;
}

void AGoal_CPP::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ABox_CPP* BoxOverlap = Cast<ABox_CPP>(OtherActor);

	ASOKOBANGameMode* GameMode = GetWorld()->GetAuthGameMode<ASOKOBANGameMode>();

	if (BoxOverlap)
	{
		if (BoxOverlap->ColorOfBox == this->ColorOfGoal) bOccupied = true;	

		if (GameMode)
		{
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, [GameMode]() { GameMode->NextGameLevel(); }, 0.2, false);
		}
	}
}

void AGoal_CPP::OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ABox_CPP* BoxOverlap = Cast<ABox_CPP>(OtherActor);

	if (BoxOverlap)
	{
		bOccupied = false;
	}
}
