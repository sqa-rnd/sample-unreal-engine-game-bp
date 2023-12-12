#pragma once

#include "CoreMinimal.h"
#include "Components/Image.h"
#include "UMyImage.generated.h"

/**
 * 
 */
UCLASS()
class UMyImage : public UImage
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
