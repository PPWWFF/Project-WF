#pragma once
#include "CoreMinimal.h"
#include "WFSeededRandom.generated.h"

UCLASS(BlueprintType, EditInlineNew)
class UWFSeededRandom : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Random")
	int32 Seed = 0;

	FRandomStream RandomStream;

public:
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Random")
	void RegenerateSeed();

	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Random")
	void ResetStream();

	UFUNCTION(BlueprintCallable)
	const FRandomStream& GetStream() const;
};
