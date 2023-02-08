// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"
#include "Types.h"
#include "Box_CPP.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "Goal_CPP.generated.h"



UCLASS()
class SOKOBAN_API AGoal_CPP : public AActor
{
	GENERATED_BODY()

public:

	AGoal_CPP();

	virtual void BeginPlay() override;

	void UpdateColor(ENUM_Color Color);

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	UPaperSprite* Sprite;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	UPaperSpriteComponent* SpriteComponent;	

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	UBoxComponent* BoxCollision;

	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	bool bOccupied = false;

	FTimerHandle TimerHandle;

	ENUM_Color ColorOfGoal;
};
