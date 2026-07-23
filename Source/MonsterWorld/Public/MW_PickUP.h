// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Definitions.h"
#include "GameFramework/Actor.h"
#include "Interface/MW_Interactable.h"
#include "MW_PickUP.generated.h"

class UBoxComponent;
class UPaperSpriteComponent;
class UPaperFlipbookComponent;



UCLASS()
class MONSTERWORLD_API AMW_PickUP : public AActor , public IMW_Interactable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMW_PickUP();

protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY()
	TObjectPtr<USceneComponent> RootComp;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category= "Animation")
	TObjectPtr<UPaperSpriteComponent> Sprite;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category= "Collision")
	TObjectPtr<UBoxComponent> InteractionDetector;
	
	UPROPERTY(EditDefaultsOnly)
	FMW_MessageInfo ItemMessage;
	
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual FMW_MessageInfo Interact_Implementation() override;

};
