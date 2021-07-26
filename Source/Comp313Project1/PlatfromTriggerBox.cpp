// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatfromTriggerBox.h"
#include <Runtime/Engine/Public/GeneratedCodeHelpers.h>

APlatfromTriggerBox::APlatfromTriggerBox()
{
    //Register Events
    OnActorBeginOverlap.AddDynamic(this, &APlatfromTriggerBox::OnOverlapBegin);
    OnActorEndOverlap.AddDynamic(this, &APlatfromTriggerBox::OnOverlapEnd);
}

void APlatfromTriggerBox::BeginPlay()
{
    Super::BeginPlay();

}

void APlatfromTriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{

}

void APlatfromTriggerBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
    
    if (targetTag.GetStringLength() <= 0) {
        return;
    }

    if (OtherActor && (OtherActor != this)) {

        TArray<AActor*> movingWalls;
        UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMovingWall::StaticClass(), movingWalls);
        AActor* temp1 = NULL;

        for (AActor* Actor : movingWalls) {
            if (Actor->Tags.Num() == 0) {
                continue;
            }
            if (Actor->Tags[0] == targetTag) {
                temp1 = Actor;
                break;
            }
        }

        AMovingWall* temp = Cast<AMovingWall>(temp1);
        temp->MoveSideways(platformOffset, closeDelay);
    }
}
