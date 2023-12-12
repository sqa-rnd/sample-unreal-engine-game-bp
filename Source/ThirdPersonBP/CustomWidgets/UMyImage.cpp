#include "UMyImage.h"

#include "Widgets/Images/SImage.h"
#include "Framework/MetaData/DriverMetaData.h"

#define LOCTEXT_NAMESPACE "UMG"

TSharedRef<SWidget> UMyImage::RebuildWidget()
{
	MyImage = SNew(SImage)
		.FlipForRightToLeftFlowDirection(bFlipForRightToLeftFlowDirection)
		.AddMetaData(FDriverMetaData::Id(DriverId));

	return MyImage.ToSharedRef();
}

#if WITH_EDITOR

const FText UMyImage::GetPaletteCategory()
{
	return LOCTEXT("Custom", "Custom");
}

#endif

#undef LOCTEXT_NAMESPACE