#include "UMySlider.h"

#include "Widgets/Input/SSlider.h"
#include "Framework/MetaData/DriverMetaData.h"

#define LOCTEXT_NAMESPACE "UMG"

TSharedRef<SWidget> UMySlider::RebuildWidget()
{

	MySlider = SNew(SSlider)
		.Style(&WidgetStyle)
		.IsFocusable(IsFocusable)
		.OnMouseCaptureBegin(BIND_UOBJECT_DELEGATE(FSimpleDelegate, HandleOnMouseCaptureBegin))
		.OnMouseCaptureEnd(BIND_UOBJECT_DELEGATE(FSimpleDelegate, HandleOnMouseCaptureEnd))
		.OnControllerCaptureBegin(BIND_UOBJECT_DELEGATE(FSimpleDelegate, HandleOnControllerCaptureBegin))
		.OnControllerCaptureEnd(BIND_UOBJECT_DELEGATE(FSimpleDelegate, HandleOnControllerCaptureEnd))
		.OnValueChanged(BIND_UOBJECT_DELEGATE(FOnFloatValueChanged, HandleOnValueChanged))
		.AddMetaData(FDriverMetaData::Id(DriverId));
		
	return MySlider.ToSharedRef();
}

#if WITH_EDITOR

const FText UMySlider::GetPaletteCategory()
{
	return LOCTEXT("Custom", "Custom");
}

#endif