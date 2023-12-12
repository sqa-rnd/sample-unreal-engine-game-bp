#include "UMySizeBox.h"

#include "Components/SizeBoxSlot.h"
#include "Framework/MetaData/DriverMetaData.h"

#define LOCTEXT_NAMESPACE "UMG"

TSharedRef<SWidget> UMySizeBox::RebuildWidget()
{

	MySizeBox = SNew(SBox)
		.AddMetaData(FDriverMetaData::Id(DriverId));

	if (GetChildrenCount() > 0)
	{
		Cast<USizeBoxSlot>(GetContentSlot())->BuildSlot(MySizeBox.ToSharedRef());
	}

	return MySizeBox.ToSharedRef();
}

#if WITH_EDITOR

const FText UMySizeBox::GetPaletteCategory()
{
	return LOCTEXT("Custom", "Custom");
}

#endif

#undef LOCTEXT_NAMESPACE