#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "UMyButton.generated.h"

/**
 * 
 */
UCLASS()
class UMyButton : public UButton
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
