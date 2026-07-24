// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Core/Definitions.h"
#include "MW_PlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class MONSTERWORLD_API UMW_PlayerHUD : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintImplementableEvent)
	void BP_SetItemText(FMW_MessageInfo ItemMessage);
	
};
