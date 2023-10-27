#pragma once

#include "CoreMinimal.h"
#include "Components/TextBlock.h"
#include "UMyTextBlock.generated.h"

/**
 * 
 */
UCLASS()
class UMyTextBlock : public UTextBlock
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Automation")
	FName DriverId;

#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;
};
