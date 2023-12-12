#include "UMyVerticalBox.h"

#include "Framework/MetaData/DriverMetaData.h"
#include "Components/VerticalBoxSlot.h"

#define LOCTEXT_NAMESPACE "UMG"

TSharedRef<SWidget> UMyVerticalBox::RebuildWidget()
{
	MyVerticalBox = SNew(SVerticalBox)
		.AddMetaData(FDriverMetaData::Id(DriverId));

	for ( UPanelSlot* PanelSlot : Slots )
	{
		if ( UVerticalBoxSlot* TypedSlot = Cast<UVerticalBoxSlot>(PanelSlot) )
		{
			TypedSlot->Parent = this;
			TypedSlot->BuildSlot(MyVerticalBox.ToSharedRef());
		}
	}

	return MyVerticalBox.ToSharedRef();
}

#if WITH_EDITOR

const FText UMyVerticalBox::GetPaletteCategory()
{
	return LOCTEXT("Custom", "Custom");
}

#endif

#undef LOCTEXT_NAMESPACE