#include "UMyButton.h"

#include "Components/ButtonSlot.h"
#include "Framework/MetaData/DriverMetaData.h"

#define LOCTEXT_NAMESPACE "UMG"

TSharedRef<SWidget> UMyButton::RebuildWidget()
{
	MyButton = SNew(SButton)
		.OnClicked(BIND_UOBJECT_DELEGATE(FOnClicked, SlateHandleClicked))
		.OnPressed(BIND_UOBJECT_DELEGATE(FSimpleDelegate, SlateHandlePressed))
		.OnReleased(BIND_UOBJECT_DELEGATE(FSimpleDelegate, SlateHandleReleased))
		.OnHovered_UObject( this, &ThisClass::SlateHandleHovered )
		.OnUnhovered_UObject( this, &ThisClass::SlateHandleUnhovered )
		.ButtonStyle(&WidgetStyle)
		.ClickMethod(ClickMethod)
		.TouchMethod(TouchMethod)
		.PressMethod(PressMethod)
		.IsFocusable(IsFocusable)
		.AddMetaData(FDriverMetaData::Id(DriverId));
	
	if ( GetChildrenCount() > 0 )
	{
		Cast<UButtonSlot>(GetContentSlot())->BuildSlot(MyButton.ToSharedRef());
	}
	
	
	return MyButton.ToSharedRef();
}

#if WITH_EDITOR

const FText UMyButton::GetPaletteCategory()
{
	return LOCTEXT("Custom", "Custom");
}

#endif

#undef LOCTEXT_NAMESPACE