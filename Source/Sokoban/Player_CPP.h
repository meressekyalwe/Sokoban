// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/BoxComponent.h"
#include "PaperFlipbookComponent.h"
#include "Types.h"
#include "TimerManager.h"
#include "Player_CPP.generated.h"

UCLASS()
class SOKOBAN_API APlayer_CPP : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayer_CPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void VerticalMove(float AxisValue);

	void HorizontalMove(float AxisValue);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	UPaperFlipbookComponent* Sprite;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	FVector MovementDirection;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	float MovementSpeed = 128.0f;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	float Delaytime = 0.2f;	
};
