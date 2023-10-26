// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuParent.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class THIRDPERSONBP_API UMainMenuParent : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget, DriverId="PlayButton"))
	class UTextBlock* MenuTitle;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	class UButton* PlayButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	class UButton* SettingsButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	class UButton* QuitButton;
};
