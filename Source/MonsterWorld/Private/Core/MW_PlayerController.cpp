// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/MW_PlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

AMW_PlayerController::AMW_PlayerController()
{
	
}

void AMW_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(MonsterWorldInputContext, 0);
	}
}


