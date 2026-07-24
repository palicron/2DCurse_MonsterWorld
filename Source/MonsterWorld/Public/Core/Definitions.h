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

	FMW_MessageInfo() : Name("Item"), ItemID(0) {}
};


