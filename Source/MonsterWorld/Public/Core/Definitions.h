#pragma once

#include "CoreMinimal.h"
#include "Definitions.Generated.h"

USTRUCT(BlueprintType)
struct FMW_MessageInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 ItemID;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	uint8 bIsNPC : 1;

	FMW_MessageInfo() : Name("Item"), ItemID(0) , bIsNPC(false){}
};


