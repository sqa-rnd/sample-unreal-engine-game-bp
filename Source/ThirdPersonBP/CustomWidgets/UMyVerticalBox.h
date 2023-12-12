#pragma once

#include "CoreMinimal.h"
#include "Components/VerticalBox.h"
#include "UMyVerticalBox.generated.h"

/**
 * 
 */
UCLASS()
class UMyVerticalBox : public UVerticalBox
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
