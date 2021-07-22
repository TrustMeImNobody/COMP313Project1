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
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid"));


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

// Called every frame
void AMovingWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!canMove) {
		return;
	}

	FVector NewLocation = GetActorLocation();
	//FRotator NewRotation = GetActorRotation();
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.X += DeltaHeight * FloatSpeed;       //Scale our height by a factor of 20
	//float DeltaRotation = DeltaTime * RotationSpeed;    //Rotate by 20 degrees per second
	//NewRotation.Yaw += DeltaRotation;
	//SetActorLocationAndRotation(NewLocation, NewRotation);
	SetActorLocation(NewLocation);

}

