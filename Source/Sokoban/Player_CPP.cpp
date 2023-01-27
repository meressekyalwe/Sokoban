// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_CPP.h"
#include "Components/InputComponent.h"


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
	MovementDirection.Z = FMath::Clamp(AxisValue, -1.0f, 1.0f);
}

void APlayer_CPP::HorizontalMove(float AxisValue)
{
	MovementDirection.X = FMath::Clamp(AxisValue, -1.0f, 1.0f);
}

// Called every frame
void APlayer_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorTickInterval(Delaytime);

	if (!MovementDirection.IsZero())
	{
		const FVector NewActorLocation = GetActorLocation() + (MovementDirection * MovementSpeed);

		SetActorLocation(NewActorLocation);
	}
}

// Called to bind functionality to input
void APlayer_CPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &APlayer_CPP::VerticalMove);
	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &APlayer_CPP::HorizontalMove);
}



