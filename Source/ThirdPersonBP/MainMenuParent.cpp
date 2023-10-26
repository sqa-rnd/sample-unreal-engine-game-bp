// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuParent.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Framework/MetaData/DriverMetaData.h"

void UMainMenuParent::NativeConstruct()
{
	Super::NativeConstruct();

	if(MenuTitle)
	{
		MenuTitle->SetText(FText::FromString(TEXT("Hellow World")));
	}

	if(PlayButton)
	{
		//PlayButton.Add
	}
}
