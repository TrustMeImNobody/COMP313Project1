// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatfromTriggerBox.h"
// include draw debug helpers header file
#include "DrawDebugHelpers.h"
#include <Runtime/Engine/Public/GeneratedCodeHelpers.h>

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))

APlatfromTriggerBox::APlatfromTriggerBox()
{
    //Register Events
    OnActorBeginOverlap.AddDynamic(this, &APlatfromTriggerBox::OnOverlapBegin);
    OnActorEndOverlap.AddDynamic(this, &APlatfromTriggerBox::OnOverlapEnd);
}

void APlatfromTriggerBox::BeginPlay()
{
    Super::BeginPlay();

    DrawDebugBox(GetWorld(), GetActorLocation(), GetActorScale() * 100, FColor::Cyan, true, -1, 0, 5);

}

void APlatfromTriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && (OtherActor != this)) {
        // print to screen using above defined method when actor enters trigger volume
        print("Overlap Begin");
        printFString("Other Actor = %s", *OtherActor->GetName());

        ACharacter* player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
        //if (*OtherActor->GetName() == player->GetName()) {
        print("Gottem");
        //}

        /*
        TArray<AActor*> movingWalls;
        UGameplayStatics::GetAllActorsOfClass(GetWorld(),AMovingWall::StaticClass(),movingWalls);
        AActor* temp1 = NULL;

        for (AActor* Actor : movingWalls) {
            if (Actor->GetName() == "FirstDoor") {
                temp1 = Actor;
                break;
            }
        }

        AMovingWall* temp = Cast<AMovingWall>(temp1);
        temp->AllowMove();
        */
    }
}

void APlatfromTriggerBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && (OtherActor != this)) {
        // print to screen using above defined method when actor leaves trigger volume
        print("Overlap Ended");
        printFString("%s has left the Trigger Volume", *OtherActor->GetName());

        TArray<AActor*> movingWalls;
        UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMovingWall::StaticClass(), movingWalls);
        AActor* temp1 = NULL;

        for (AActor* Actor : movingWalls) {
            if (Actor->GetName() == "FirstDoor") {
                temp1 = Actor;
                break;
            }
        }

        AMovingWall* temp = Cast<AMovingWall>(temp1);
        temp->MoveSideways(400, 5);
    }
}
