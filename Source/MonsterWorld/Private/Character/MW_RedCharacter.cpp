// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MW_RedCharacter.h"

#include "EnhancedInputComponent.h"
#include "PaperFlipbookComponent.h"
#include "Blueprint/UserWidget.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Interface/MW_Interactable.h"
#include "UI/MW_PlayerHUD.h"

AMW_RedCharacter::AMW_RedCharacter()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("Sping Arm");
	SpringArm->SetupAttachment(RootComponent);
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera Component");
	CameraComponent->SetupAttachment(SpringArm);
	CameraComponent->SetProjectionMode(ECameraProjectionMode::Orthographic);
	CameraComponent->OrthoWidth = 1000;
	
	InteractionDetector = CreateDefaultSubobject<UBoxComponent>("Interact Detector");
	InteractionDetector->SetupAttachment(GetSprite());
	InteractionDetector->SetCollisionResponseToAllChannels(ECR_Overlap);
	
}

void AMW_RedCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (IsValid(PlayerHUDClass))
	{
		HUDReference = CreateWidget<UMW_PlayerHUD>(GetWorld(), PlayerHUDClass);
		HUDReference->AddToViewport();
	}
	
	InteractionDetector->OnComponentBeginOverlap.AddDynamic(this, &AMW_RedCharacter::OnActorBeginOverlap);
	InteractionDetector->OnComponentEndOverlap.AddDynamic(this, &AMW_RedCharacter::OnActorEndOverlap);
}

void AMW_RedCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMW_RedCharacter::Move);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &AMW_RedCharacter::EndMove);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &AMW_RedCharacter::Interact);
	}
}

void AMW_RedCharacter::Move(const FInputActionValue& InputValue)
{
	MoveAxis = InputValue.Get<FVector2D>();
	const FVector MoveDirection = FVector(MoveAxis.X, MoveAxis.Y, 0);
	AddMovementInput(MoveDirection, 1);
	
	SetFlipBookAnimation();

}


void AMW_RedCharacter::SetFlipBookAnimation(const bool bTransitionToIdle) const
{
	if (MoveAxis.X > 0)
	{
		GetSprite()->SetFlipbook(bTransitionToIdle ? Right_Idle : Right_Walking);
	}
	else if (MoveAxis.X < 0)
	{
		GetSprite()->SetFlipbook(bTransitionToIdle ? Left_Idle : Left_Walking);
	}
	else if (MoveAxis.Y > 0)
	{
		GetSprite()->SetFlipbook(bTransitionToIdle ? Down_Idle : Down_Walking);
	}
	else if (MoveAxis.Y < 0)
	{
		GetSprite()->SetFlipbook(bTransitionToIdle ? Up_Idle : Up_Walking);
	}
}

void AMW_RedCharacter::Interact(const FInputActionValue& InputActionValue)
{
	if (InteractingActor.IsValid() && InteractingActor->Implements<UMW_Interactable>())
	{
		FMW_MessageInfo Info = IMW_Interactable::Execute_Interact(InteractingActor.Get());
		if (HUDReference)
		{
			HUDReference->BP_SetItemText(Info);
		}
	}
}

void AMW_RedCharacter::OnActorBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,const FHitResult& SweepResult)
{
	InteractingActor = OtherActor;
}

void AMW_RedCharacter::OnActorEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (InteractingActor == OtherActor)
	{
		InteractingActor = nullptr;
	}
}

void AMW_RedCharacter::EndMove(const FInputActionValue& InputValue)
{
	SetFlipBookAnimation(true);
}

