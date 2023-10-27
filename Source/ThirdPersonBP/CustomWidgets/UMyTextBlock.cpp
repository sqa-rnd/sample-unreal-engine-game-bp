// Fill out your copyright notice in the Description page of Project Settings.


#include "UMyTextBlock.h"

#include "Framework/MetaData/DriverMetaData.h"

#define LOCTEXT_NAMESPACE "UMG"

TSharedRef<SWidget> UMyTextBlock::RebuildWidget()
{
	MyTextBlock = SNew(STextBlock)
		.SimpleTextMode(bSimpleTextMode)
		.AddMetaData(FDriverMetaData::Id(DriverId));
		
		return MyTextBlock.ToSharedRef();
}

#if WITH_EDITOR

const FText UMyTextBlock::GetPaletteCategory()
{
	return LOCTEXT("Custom", "Custom");
}

#endif

#undef LOCTEXT_NAMESPACE