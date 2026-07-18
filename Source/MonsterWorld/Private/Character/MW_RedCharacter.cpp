// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MW_RedCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AMW_RedCharacter::AMW_RedCharacter()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("Sping Arm");
	SpringArm->SetupAttachment(RootComponent);
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera Component");
	CameraComponent->SetupAttachment(SpringArm);
	CameraComponent->SetProjectionMode(ECameraProjectionMode::Orthographic);
	CameraComponent->OrthoWidth = 1000;
	
}
