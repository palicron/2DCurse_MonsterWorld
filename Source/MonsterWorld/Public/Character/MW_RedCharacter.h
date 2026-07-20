// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "PaperCharacter.h"
#include "MW_RedCharacter.generated.h"

class UInputAction;
class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class MONSTERWORLD_API AMW_RedCharacter : public APaperCharacter
{
	GENERATED_BODY()
	
public:
	
	AMW_RedCharacter();
	
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<USpringArmComponent> SpringArm;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UCameraComponent> CameraComponent;
	
	UPROPERTY(EditDefaultsOnly,Category= "Inputs")
	TObjectPtr<UInputAction> MoveAction;
	
	UFUNCTION()
	void Move(const FInputActionValue& InputValue);
	
	
	
	
};
