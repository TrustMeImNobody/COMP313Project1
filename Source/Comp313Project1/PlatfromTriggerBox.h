// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Kismet/GameplayStatics.h"
#include "MovingWall.h"
#include "PlatfromTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class COMP313PROJECT1_API APlatfromTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	// constructor sets default values for this actor's properties
	APlatfromTriggerBox();

	// overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	// overlap end function
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int platformOffset = 400;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int closeDelay = 10;

};
