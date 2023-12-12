#include "UMyCheckbox.h"

#include "Framework/MetaData/DriverMetaData.h"


#define LOCTEXT_NAMESPACE "UMG"

TSharedRef<SWidget> UMyCheckbox::RebuildWidget()
{
	MyCheckbox = SNew(SCheckBox)
		.OnCheckStateChanged( BIND_UOBJECT_DELEGATE(FOnCheckStateChanged, SlateOnCheckStateChangedCallback) )
		.Style(&WidgetStyle)
		.HAlign( HorizontalAlignment )
		.ClickMethod(ClickMethod)
		.TouchMethod(TouchMethod)
		.PressMethod(PressMethod)
		.IsFocusable(IsFocusable)
		.AddMetaData(FDriverMetaData::Id(DriverId))
		;

	if ( GetChildrenCount() > 0 )
	{
		MyCheckbox->SetContent(GetContentSlot()->Content ? GetContentSlot()->Content->TakeWidget() : SNullWidget::NullWidget);
	}
	
	return MyCheckbox.ToSharedRef();
}

#if WITH_EDITOR

const FText UMyCheckbox::GetPaletteCategory()
{
	return LOCTEXT("Custom", "Custom");
}

#endif

#undef LOCTEXT_NAMESPACE