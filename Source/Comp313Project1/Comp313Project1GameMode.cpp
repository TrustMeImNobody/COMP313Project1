// Copyright Epic Games, Inc. All Rights Reserved.

#include "Comp313Project1GameMode.h"
#include "Comp313Project1Character.h"
#include "UObject/ConstructorHelpers.h"

AComp313Project1GameMode::AComp313Project1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
