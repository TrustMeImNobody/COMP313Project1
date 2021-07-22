// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomTriggerVolume.h"

// include draw debug helpers header file
#include "DrawDebugHelpers.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))

ACustomTriggerVolume::ACustomTriggerVolume()
{
    //Register Events
    OnActorBeginOverlap.AddDynamic(this, &ACustomTriggerVolume::OnOverlapBegin);
    OnActorEndOverlap.AddDynamic(this, &ACustomTriggerVolume::OnOverlapEnd);
}

void ACustomTriggerVolume::BeginPlay()
{
    Super::BeginPlay();

    DrawDebugBox(GetWorld(), GetActorLocation(), GetActorScale() * 100, FColor::Cyan, true, -1, 0, 5);

}

void ACustomTriggerVolume::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && (OtherActor != this)) {
        // print to screen using above defined method when actor enters trigger volume
        print("Overlap Begin");
        printFString("Other Actor = %s", *OtherActor->GetName());

        ACharacter* player = UGameplayStatics::GetPlayerCharacter(GetWorld(),0);
        if (*OtherActor->GetName() == player->GetName()) {
            print("Gottem");
        }
    }
}

void ACustomTriggerVolume::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && (OtherActor != this)) {
        // print to screen using above defined method when actor leaves trigger volume
        print("Overlap Ended");
        printFString("%s has left the Trigger Volume", *OtherActor->GetName());
    }
}