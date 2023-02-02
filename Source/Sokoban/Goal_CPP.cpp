// Fill out your copyright notice in the Description page of Project Settings.


#include "Goal_CPP.h"
#include "Engine/GameEngine.h"

AGoal_CPP::AGoal_CPP()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComp"));

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));

	Sprite->SetupAttachment(RootComponent);

	Box->SetupAttachment(RootComponent);

	Box->InitBoxExtent(FVector(50.f, 10.f, 50.f));
}


void AGoal_CPP::UpdateColor_BP_Implementation(ENUM_Color Color)
{
	// In BP
}

void AGoal_CPP::BeginPlay()
{
	Box->OnComponentBeginOverlap.AddDynamic(this, &AGoal_CPP::OverlapBegin);
	Box->OnComponentEndOverlap.AddDynamic(this, &AGoal_CPP::OverlapEnd);
}

void AGoal_CPP::UpdateColor(ENUM_Color Color)
{
	UpdateColor_BP(Color);
}

void AGoal_CPP::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ABox_CPP* BoxOverlap = Cast<ABox_CPP>(OtherActor);

	if (BoxOverlap)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("Begin Box Overlap"));

		bOccupied = true;
	}
}

void AGoal_CPP::OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ABox_CPP* BoxOverlap = Cast<ABox_CPP>(OtherActor);

	if (BoxOverlap)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("End Box Overlap"));

		bOccupied = false;
	}
}
