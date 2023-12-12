#pragma once

#include "CoreMinimal.h"
#include "Components/EditableText.h"
#include "Components/EditableTextBox.h"
#include "UMyEditableTextBox.generated.h"

/**
 * 
 */
UCLASS()
class UMyEditableTextBlock : public UEditableTextBox
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
