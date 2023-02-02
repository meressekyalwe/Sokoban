// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_CPP.h"
#include "Components/InputComponent.h"
#include "Engine/GameEngine.h"
#include "Engine/World.h"
#include "Kismet/KismetSystemLibrary.h"
#include "DrawDebugHelpers.h"
#include "Goal_CPP.h"

// Sets default values
APlayer_CPP::APlayer_CPP()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	Sprite = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("PaperFlipbookComponent"));

	Sprite->SetupAttachment(RootComponent);

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	Tags.Add(FName("Movable"));
}

// Called when the game starts or when spawned
void APlayer_CPP::BeginPlay()
{
	Super::BeginPlay();	
}

void APlayer_CPP::VerticalMove(float AxisValue)
{
	if (AxisValue <= -0.8f)
	{
		Move(ENUM_Direction::Down);
	}
	else if (AxisValue >= 0.8f)
	{
		Move(ENUM_Direction::Up);
	}
}

void APlayer_CPP::HorizontalMove(float AxisValue)
{
	if (AxisValue <= -0.8f)
	{
		Move(ENUM_Direction::Left);
	}
	else if (AxisValue >= 0.8)
	{
		Move(ENUM_Direction::Right);
	}
}

void APlayer_CPP::UpdateAnimation_BP_Implementation(ENUM_Direction Direction)
{
	// In Blueprint
}

void APlayer_CPP::UpdateAnimation(ENUM_Direction Direction)
{
	UpdateAnimation_BP(Direction);
}

FVector APlayer_CPP::DirectionToVector(float InTileSize, ENUM_Direction Direction)
{
	FVector DirectionVector;

	if (Direction == ENUM_Direction::Up)
	{
		DirectionVector = FVector(0.0f, 0.0f, 1.0f);
	}

	if (Direction == ENUM_Direction::Down)
	{
		DirectionVector = FVector(0.0f, 0.0f, -1.0f);
	}

	if (Direction == ENUM_Direction::Right)
	{
		DirectionVector = FVector(1.0f, 0.0f, 0.0f);
	}

	if (Direction == ENUM_Direction::Left)
	{
		DirectionVector = FVector(-1.0f, 0.0f, 0.0f);
	}

	return InTileSize * DirectionVector;
}


void APlayer_CPP::Move(ENUM_Direction Direction)
{
	if (bCanMove)
	{
		UpdateAnimation(Direction);


		if (TryMove(Direction))
		{
			bCanMove = false;
			GetWorld()->GetTimerManager().SetTimer(TimerHandle,this, &APlayer_CPP::PrintOnScreen, MoveDelayTime, true);
		}
	}
}

bool APlayer_CPP::TryMove(ENUM_Direction Direction)
{
	bool bMoveSuccessful = false;
	FVector MoveOffset = DirectionToVector(TileSize, Direction);

	FHitResult OutHit;
	const TArray<AActor*> ActorsToIgnore;
	FVector Start = GetActorLocation();
	FVector End = Start + MoveOffset;

	AActor* HitActor;

	if (UKismetSystemLibrary::LineTraceSingle(this, Start, End, ETraceTypeQuery::TraceTypeQuery1, false, ActorsToIgnore, EDrawDebugTrace::ForDuration, OutHit, true,  FLinearColor::Green, FLinearColor::Red, 0.2f ))
	{
		HitActor = OutHit.GetActor();
		HitActor->Tags.SetNum(1);
		HitActor->Tags = OutHit.GetActor()->Tags;
		HitActor->GetClass();

		if (HitActor->Tags[0] == FName("Static"))
		{
			bMoveSuccessful = false;
		}
		else if (HitActor->Tags[0] == FName("Movable"))
		{
			const TArray<AActor*> HiActorIgnore{ HitActor };

			if (UKismetSystemLibrary::LineTraceSingle(this, Start, End + MoveOffset, ETraceTypeQuery::TraceTypeQuery1, false, HiActorIgnore, EDrawDebugTrace::ForDuration, OutHit, true, FLinearColor::Green, FLinearColor::Red, 0.2f))
			{
				bMoveSuccessful = false;

				if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("Hit"));
			}
			else
			{
				if (bLerpMovement)
				{
					LerpTo(HitActor, MoveOffset);
				}
				else
				{
					HitActor->AddActorWorldOffset(MoveOffset, true);
					AddActorWorldOffset(MoveOffset, true);
				}

				bMoveSuccessful = true;
			}		
		}
		else if ((HitActor->Tags[0] == FName("Coin")))
		{
			if (bLerpMovement)
			{
				LerpTo(this, MoveOffset);
			}
			else
			{
				AddActorWorldOffset(MoveOffset, true);
			}

			bMoveSuccessful = true;
		}
	}
	else
	{

		if (bLerpMovement)
		{
			LerpTo(this, MoveOffset);
		}
		else
		{
			AddActorWorldOffset(MoveOffset, true);
		}

		bMoveSuccessful = true;
	}
	
	return bMoveSuccessful;
}

void APlayer_CPP::LerpTo_BP_Implementation(AActor* InHitActor, FVector InMoveOffset)
{
	// In BP 
}

void APlayer_CPP::LerpTo(AActor* InHitActor, FVector InMoveOffset)
{
	LerpTo_BP(InHitActor, InMoveOffset);
}

void APlayer_CPP::PrintOnScreen()
{
	if (bCanMove == true)
	{
		UpdateAnimation(ENUM_Direction::Stop);
	}

	bCanMove = true;
}

// Called every frame
void APlayer_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayer_CPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &APlayer_CPP::HorizontalMove);
	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &APlayer_CPP::VerticalMove);	
}



