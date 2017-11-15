// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Alpha_ProjectGameMode.h"
#include "Alpha_ProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAlpha_ProjectGameMode::AAlpha_ProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
