// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/HorizontalBox.h"
#include "UObject/Object.h"
#include "UMyHorizontalBox.generated.h"

/**
 * 
 */
UCLASS()
class UMyHorizontalBox : public UHorizontalBox
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Automation")
	FName DriverId;

#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;
};
