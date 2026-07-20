// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MW_PlayerController.generated.h"

class UInputMappingContext;
/**
 * 
 */
UCLASS()
class MONSTERWORLD_API AMW_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	
	AMW_PlayerController();
	
	
protected:
	
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> MonsterWorldInputContext;
	
};
