// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "MovingWall.generated.h"

UCLASS()
class COMP313PROJECT1_API AMovingWall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingWall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void AllowMove();
	virtual void StopMove();

	virtual void MoveSideways(float offset, int timeOpen);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float FloatSpeed = 20.0f;
	UPROPERTY(BlueprintReadWrite)
		float volume = 1;
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* VisualMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool canMove;
	UPROPERTY(BlueprintReadWrite)
		bool positionLocked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool moveX = false;
	UPROPERTY()
		bool special;
	UPROPERTY()
		bool moving;
	UPROPERTY()
		float stepAmount;
	UPROPERTY()
		FVector destLocation;
	UPROPERTY()
		USoundBase* sound;
	UPROPERTY()
		FTimerHandle timer1;
	UPROPERTY()
		FTimerHandle timer2;
};
