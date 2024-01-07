#pragma once
#include "CoreMinimal.h"
#include "WFOARoadGeneratorComponent.generated.h"

class UWFSeededRandom;

USTRUCT(BlueprintType)
struct FWFOARoadGeneratorContainer
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere)
	int32 CurrentTry = 0;

	UPROPERTY(EditAnywhere)
	int32 StartPoint = 0;

	UPROPERTY(EditAnywhere)
	FVector2D DirCenter;
};

UCLASS(BlueprintType)
class UWFOARoadGeneratorComponent : public UActorComponent 
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere)
	float MinimumRoadLength = 1;

	UPROPERTY(EditAnywhere)
	float MaximumRoadLength = 1;

	UPROPERTY(EditAnywhere)
	int32 MaxBranchingTry = 3;

	UPROPERTY(EditAnywhere)
	float AngleRange = 0.25f * PI;

	UPROPERTY(EditAnywhere)
	int32 Speed = 1;

	UPROPERTY(VisibleAnywhere)
	TWeakObjectPtr<UWFSeededRandom> RandomGenerator = nullptr;

	TArray<FVector2D> Cross;

	TSet<TPair<int32, int32>> Edges;

	TQueue<FWFOARoadGeneratorContainer> CalcQueue;
	FWFOARoadGeneratorContainer Current;

	FVector2D Center = FVector2D::ZeroVector;

	bool IsDone = true;
public:
	void Reset();
	void Init(const TArray<FVector2D>& initDir, FVector2D centerPos, UWFSeededRandom* randomSeed);
	void Calc();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
