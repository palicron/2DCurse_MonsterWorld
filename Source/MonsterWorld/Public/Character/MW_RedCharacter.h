// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "PaperCharacter.h"
#include "MW_RedCharacter.generated.h"

class UPaperFlipbook;
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
	
	UFUNCTION(BlueprintCallable)
	FVector2D GetMoveAxis() const { return MoveAxis; };
protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<USpringArmComponent> SpringArm;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UCameraComponent> CameraComponent;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category= "Animation")
	TObjectPtr<UPaperFlipbook> Down_Idle;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category= "Animation")
	TObjectPtr<UPaperFlipbook> Down_Walking;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category= "Animation")
	TObjectPtr<UPaperFlipbook> Up_Idle;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category= "Animation")
	TObjectPtr<UPaperFlipbook> Up_Walking;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category= "Animation")
	TObjectPtr<UPaperFlipbook> Right_Idle;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category= "Animation")
	TObjectPtr<UPaperFlipbook> Right_Walking;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category= "Animation")
	TObjectPtr<UPaperFlipbook> Left_Idle;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category= "Animation")
	TObjectPtr<UPaperFlipbook> Left_Walking;
	
	UPROPERTY(EditDefaultsOnly,Category= "Inputs")
	TObjectPtr<UInputAction> MoveAction;
	
	UPROPERTY()
	FVector2D MoveAxis;
	
	UFUNCTION()
	void Move(const FInputActionValue& InputValue);
	
	UFUNCTION()
	void EndMove(const FInputActionValue& InputValue);
	
	UFUNCTION()
	void SetFlipBookAnimation(const bool bTransitionToIdle = false) const;
	
	
	
	
};
