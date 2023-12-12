#pragma once

#include "CoreMinimal.h"
#include "Components/SizeBox.h"
#include "UMySizeBox.generated.h"

/**
 * 
 */
UCLASS()
class UMySizeBox : public USizeBox
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
