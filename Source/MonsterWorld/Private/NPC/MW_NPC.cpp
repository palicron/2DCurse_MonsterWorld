// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC/MW_NPC.h"

#include "PaperSpriteComponent.h"

// Sets default values
AMW_NPC::AMW_NPC()
{

	PrimaryActorTick.bCanEverTick = true;
	
	RootComp = CreateDefaultSubobject<USceneComponent>("RootComp");
	RootComponent = RootComp;
	
	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>("Sprite");
	Sprite->SetupAttachment(RootComp);
	
	NPCMessage.bIsNPC = true;

}

// Called when the game starts or when spawned
void AMW_NPC::BeginPlay()
{
	Super::BeginPlay();
}


FMW_MessageInfo AMW_NPC::Interact_Implementation()
{
	return NPCMessage;
}


