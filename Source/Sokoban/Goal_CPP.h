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

	UFUNCTION(BlueprintNativeEvent)
	void UpdateColor_BP(ENUM_Color Color);

	void UpdateColor(ENUM_Color Color);

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	UPaperSpriteComponent* Sprite;	

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	UBoxComponent* Box;

	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	bool bOccupied = false;

	FTimerHandle TimerHandle;

	ENUM_Color ColorOfGoal;
};
