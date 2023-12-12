// Fill out your copyright notice in the Description page of Project Settings.


#include "UMyHorizontalBox.h"

#include "Components/HorizontalBoxSlot.h"
#include "Framework/MetaData/DriverMetaData.h"

#define LOCTEXT_NAMESPACE "UMG"

TSharedRef<SWidget> UMyHorizontalBox::RebuildWidget()
{
	MyHorizontalBox = SNew(SHorizontalBox)
		.AddMetaData(FDriverMetaData::Id(DriverId));

	for ( UPanelSlot* PanelSlot : Slots )
	{
		if ( UHorizontalBoxSlot* TypedSlot = Cast<UHorizontalBoxSlot>(PanelSlot) )
		{
			TypedSlot->Parent = this;
			TypedSlot->BuildSlot(MyHorizontalBox.ToSharedRef());
		}
	}

	return MyHorizontalBox.ToSharedRef();
}

#if WITH_EDITOR

const FText UMyHorizontalBox::GetPaletteCategory()
{
	return LOCTEXT("Custom", "Custom");
}

#endif

#undef LOCTEXT_NAMESPACE