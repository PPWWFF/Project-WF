#pragma once
#include "CoreMinimal.h"
#include "Utils/WFSeededRandom.h"
#include "WFOARegionGenerator.generated.h"


class UWFOARoadGeneratorComponent;

UCLASS(BlueprintType)
class AWFOARegionGenerator : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	float Radius = 10;

	UPROPERTY(EditAnywhere)
	bool bShowGizmo = false;

	UPROPERTY(EditAnywhere)
	TArray<FVector> CrossPoints;

	UPROPERTY(EditAnywhere)
	TArray<float> EntryPoints;

	UPROPERTY(EditAnywhere, Instanced)
	UWFSeededRandom* RandomGenerator = nullptr;

	UPROPERTY(EditAnywhere)
	TArray<FVector4> CrossEdges;

	UPROPERTY(EditAnywhere)
	TArray<FVector4> EntryEdges;

	UPROPERTY(EditAnywhere)
	TArray<int32> HalfEdges;

	UPROPERTY(EditAnywhere)
	UWFOARoadGeneratorComponent* RoadGenerator;

public:
	AWFOARegionGenerator();

	virtual void Tick(float deltaTime) override;
	virtual bool ShouldTickIfViewportsOnly() const override;

	UFUNCTION(CallInEditor)
	void GenerateRegion();
};
