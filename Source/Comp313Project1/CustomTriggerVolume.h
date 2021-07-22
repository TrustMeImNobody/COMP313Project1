// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

#include "CustomTriggerVolume.generated.h"

/**
 * 
 */
UCLASS()
class COMP313PROJECT1_API ACustomTriggerVolume : public ATriggerVolume
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	// constructor sets default values for this actor's properties
	ACustomTriggerVolume();

	// overlap begin function
	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	// overlap end function
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
	
};
