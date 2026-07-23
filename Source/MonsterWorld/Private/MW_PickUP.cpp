// Fill out your copyright notice in the Description page of Project Settings.


#include "MW_PickUP.h"

#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AMW_PickUP::AMW_PickUP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	RootComp = CreateDefaultSubobject<USceneComponent>("RootComp");
	RootComponent = RootComp;
	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>("Sprite");
	Sprite->SetupAttachment(RootComponent);
	Sprite->SetRelativeLocation(FVector::ZeroVector);
	Sprite->SetRelativeRotation(FRotator::ZeroRotator);
	InteractionDetector = CreateDefaultSubobject<UBoxComponent>("Interaction Detector");
	InteractionDetector->SetCollisionResponseToAllChannels(ECR_Overlap);
	InteractionDetector->SetupAttachment(Sprite);
	
}

// Called when the game starts or when spawned
void AMW_PickUP::BeginPlay()
{
	Super::BeginPlay();
	
	InteractionDetector->OnComponentBeginOverlap.AddDynamic(this, &AMW_PickUP::OnOverlapBegin);
	
}



// Called every frame
void AMW_PickUP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FMW_MessageInfo AMW_PickUP::Interact_Implementation()
{
	Destroy();
	
	return ItemMessage;
}

void AMW_PickUP::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

