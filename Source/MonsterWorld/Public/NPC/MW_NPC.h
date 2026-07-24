// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Interface/MW_Interactable.h"
#include "MW_NPC.generated.h"

class UBoxComponent;
class UPaperSpriteComponent;

UCLASS()
class MONSTERWORLD_API AMW_NPC : public APawn , public IMW_Interactable
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMW_NPC();


	virtual void BeginPlay() override;
	
	virtual FMW_MessageInfo Interact_Implementation() override;
protected:
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FMW_MessageInfo NPCMessage;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TObjectPtr<UPaperSpriteComponent> Sprite;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TObjectPtr<USceneComponent> RootComp;
	
	






};
