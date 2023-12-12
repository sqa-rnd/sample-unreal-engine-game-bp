// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ComboBox.h"
#include "Components/ComboBoxString.h"
#include "UMyComboBox.generated.h"

/**
 * 
 */
UCLASS()
class UMyComboBox : public UComboBoxString
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
