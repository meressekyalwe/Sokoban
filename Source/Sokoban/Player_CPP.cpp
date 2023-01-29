// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_CPP.h"
#include "Components/InputComponent.h"
#include "Engine/GameEngine.h"
#include "Engine/World.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
APlayer_CPP::APlayer_CPP()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	Sprite = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("PaperFlipbookComponent"));

	Sprite->SetupAttachment(RootComponent);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void APlayer_CPP::BeginPlay()
{
	Super::BeginPlay();	
}

void APlayer_CPP::VerticalMove(float AxisValue)
{
	if (AxisValue > 0)
	{
		Move(ENUM_Direction::Up);
	}
	if (AxisValue < 0)
	{
		Move(ENUM_Direction::Down);
	}
}

void APlayer_CPP::HorizontalMove(float AxisValue)
{
	if (AxisValue > 0)
	{
		Move(ENUM_Direction::Right);
	}
	if (AxisValue < 0)
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
	FVector DirectionMove(ForceInitToZero);

	switch (Direction)
	{
	case ENUM_Direction::Up:
		DirectionMove.Set(0.f, 0.f, 1.f);
		break;
	case ENUM_Direction::Down:
		DirectionMove.Set(0.f, 0.f, -1.f);
		break;
	case ENUM_Direction::Right:
		DirectionMove.Set(1.f, 0.f, 0.f);
		break;
	case ENUM_Direction::Left:
		DirectionMove.Set(-1.f, 0.f, 0.f);
		break;
	default:
		break;
	}

	return TileSize * FVector();
}


void APlayer_CPP::Move(ENUM_Direction Direction)
{
	if (bCanMove)
	{
		UpdateAnimation(Direction);

		if (TryMove(Direction))
		{
			bCanMove = false;
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]() { bCanMove = true; }, MoveDelayTime, false);
			UpdateAnimation(ENUM_Direction::Stop);
		}
	}
}

bool APlayer_CPP::TryMove(ENUM_Direction Direction)
{
	
	MoveOffset = DirectionToVector(TileSize, Direction);


	FHitResult OutHit;
	FVector Start = GetActorLocation();
	FVector End = GetActorLocation() + MoveOffset;
	FCollisionQueryParams TraceParams;


	if (GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, TraceParams))
	{
		TArray< struct FHitResult > OutHits;

		if (HitActor->ActorHasTag(FName("Movable")))
		{
			End = HitActor->GetActorLocation() + MoveOffset;

			if (GetWorld()->LineTraceMultiByChannel(OutHits, Start, End, ECC_Visibility, TraceParams))
			{
				if (OutHits.Num() == 2)
				{
					bMoveSuccessful = false;
				}
				else
				{
					if (bLerpMovement)
					{
						// Lerp Event
					
					}
					else
					{
						HitActor->AddActorWorldOffset(MoveOffset, true, nullptr, ETeleportType::None);
						AddActorWorldOffset(MoveOffset, true, nullptr, ETeleportType::None);
					}

					bMoveSuccessful = true;
				}

			}
		}
		else
		{
			if (!HitActor->ActorHasTag(FName("Coin")))
			{
				bMoveSuccessful = false;
			}
		}
	}
	else
	{
		if (HitActor->ActorHasTag(FName("Coin")) && bLerpMovement)
		{
			// Lerp Event
		}
		else
		{
			AddActorWorldOffset(MoveOffset, true, nullptr, ETeleportType::None);
		}

		bMoveSuccessful = true;
	}
	
	return bMoveSuccessful;
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



