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

	void UpdateAnimation(ENUM_Direction Direction);

	// Movement
	FVector DirectionToVector(float InTileSize, ENUM_Direction Direction);

	void Move(ENUM_Direction Direction);

	bool TryMove(ENUM_Direction Direction);

	void LerpTo(AActor* InHitActor, FVector InMoveOffset);

	void PrintOnScreen();

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		UBoxComponent* BoxCollision;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		class UCameraComponent* GameCamera;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		UPaperFlipbookComponent* FlipbookComponent;

	UPROPERTY()
		UPaperFlipbook* Flipbook;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		float TileSize = 128.0f;

private:
	// Movement all functions can directlly uses in this class
	bool bCanMove = true;

	bool bLerpMovement = true;

	FTimerHandle TimerHandle;

	float MoveDelayTime = 0.2f;
};
