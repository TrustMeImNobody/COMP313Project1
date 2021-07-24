// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingWall.h"

// Sets default values
AMovingWall::AMovingWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	static ConstructorHelpers::FObjectFinder<USoundBase> audioReference(TEXT("'/Game/MyCreations/WallMove.WallMove'"));
	sound = audioReference.Object;

	if (CubeVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

}

// Called when the game starts or when spawned
void AMovingWall::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMovingWall::AllowMove() {
	canMove = true;
}

void AMovingWall::StopMove() {
	canMove = false;
}

void AMovingWall::MoveSideways(float offset, int timeOpen) {
	if (moving) {
		return;
	}
	FVector startLocation = GetActorLocation();
	FVector stopLocation = startLocation;
	stopLocation.X += offset;
	stepAmount = offset / 800;
	special = true;
	moving = true;
	canMove = true;
	destLocation = stopLocation;

	if(sound!=NULL){
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), sound, startLocation, 1, 1, 0);
	}

	FTimerHandle timer;
	GetWorld()->GetTimerManager().SetTimer(timer, [this,offset,startLocation, stopLocation]() {
		if (sound != NULL) {
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), sound, stopLocation, 1, 1, 0);
		}
		stepAmount = -(offset / 800);
		destLocation = startLocation;
		FTimerHandle timer2;
		GetWorld()->GetTimerManager().SetTimer(timer2, [this, stopLocation]() {
			special = false;
			moving = false;
			canMove = false;
			}, 3, 0);
		}, timeOpen, 0);
}

// Called every frame
void AMovingWall::Tick(float DeltaTime)
{
	//Super::Tick(DeltaTime);

	if (!canMove) {
		GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
		return;
	}

	if (special) {
		FVector newLocation = GetActorLocation();
		if (newLocation.X == destLocation.X) {
			stepAmount = 0;
		}
		
		newLocation.X += stepAmount;
		SetActorLocation(newLocation);
		return;
	}

	FVector NewLocation = GetActorLocation();
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.X += DeltaHeight * FloatSpeed;
	SetActorLocation(NewLocation);

}

