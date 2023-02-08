// Fill out your copyright notice in the Description page of Project Settings.


#include "Goal_CPP.h"
#include "Engine/GameEngine.h"
#include "SOKOBANGameMode.h"

AGoal_CPP::AGoal_CPP()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComp"));

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));

	SpriteComponent->SetupAttachment(RootComponent);

	BoxCollision->SetupAttachment(RootComponent);

	BoxCollision->InitBoxExtent(FVector(54.f, 10.f, 54.f));

	Sprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/PushPushPuzzle2DKit/Sprites/Goals/SP_GoalRed.SP_GoalRed'"));

	if (Sprite) SpriteComponent->SetSprite(Sprite);
}


void AGoal_CPP::BeginPlay()
{
	Super::BeginPlay();

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AGoal_CPP::OverlapBegin);
	BoxCollision->OnComponentEndOverlap.AddDynamic(this, &AGoal_CPP::OverlapEnd);
}

void AGoal_CPP::UpdateColor(ENUM_Color Color)
{
	if (Color == ENUM_Color::Blue)
	{
		Sprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/PushPushPuzzle2DKit/Sprites/Goals/SP_GoalBlue.SP_GoalBlue'"));

		if (Sprite) SpriteComponent->SetSprite(Sprite);
	}
	else if (Color == ENUM_Color::Brown)
	{
		Sprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/PushPushPuzzle2DKit/Sprites/Goals/SP_GoalBrown.SP_GoalBrown'"));

		if (Sprite) SpriteComponent->SetSprite(Sprite);
	}
	else if (Color == ENUM_Color::Gray)
	{
		Sprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/PushPushPuzzle2DKit/Sprites/Goals/SP_GoalGray.SP_GoalGray'"));

		if (Sprite) SpriteComponent->SetSprite(Sprite);
	}
	else if (Color == ENUM_Color::Green)
	{
		Sprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/PushPushPuzzle2DKit/Sprites/Goals/SP_GoalGreen.SP_GoalGreen'"));

		if (Sprite) SpriteComponent->SetSprite(Sprite);
	}
	else if (Color == ENUM_Color::Red)
	{
		Sprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/PushPushPuzzle2DKit/Sprites/Goals/SP_GoalRed.SP_GoalRed'"));

		if (Sprite) SpriteComponent->SetSprite(Sprite);
	}

	ColorOfGoal = Color;
}

void AGoal_CPP::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ABox_CPP* BoxOverlap = Cast<ABox_CPP>(OtherActor);

	ASOKOBANGameMode* GameMode = GetWorld()->GetAuthGameMode<ASOKOBANGameMode>();

	if (BoxOverlap)
	{
		if (BoxOverlap->ColorOfBox == this->ColorOfGoal)
		{
			bOccupied = true;

			if (GameMode)
			{
				GetWorld()->GetTimerManager().SetTimer(TimerHandle, [=]() { GameMode->NextGameLevel(); SpriteComponent->SetSprite(BoxOverlap->Sprite); }, 0.2, false);
			}
		}
	}
}

void AGoal_CPP::OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ABox_CPP* BoxOverlap = Cast<ABox_CPP>(OtherActor);

	if (BoxOverlap)
	{
		bOccupied = false;

		SpriteComponent->SetSprite(Sprite);
	}
}
