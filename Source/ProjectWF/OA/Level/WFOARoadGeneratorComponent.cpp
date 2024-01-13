#include "WFOARoadGeneratorComponent.h"

#include "Utils/WFSeededRandom.h"


void UWFOARoadGeneratorComponent::Reset()
{
	CalcQueue.Empty();
	Cross.Empty();
	Edges.Empty();

	IsDone = true;
}

void UWFOARoadGeneratorComponent::Init(const TArray<FVector2D>& initDir, FVector2D centerPos, UWFSeededRandom* randomSeed)
{
	if (!IsValid(randomSeed))
		return;

	Reset();
	Cross.Append(initDir);
	Center = centerPos;

	RandomGenerator = randomSeed;

	const FRandomStream& randomStream = RandomGenerator->GetStream();

	for (int32 index = 0; index < Cross.Num(); index++)
	{
		FWFOARoadGeneratorContainer startPoints;
		startPoints.StartPoint = index;
		startPoints.CurrentTry = randomStream.FRand() * MaxBranchingTry;

		Cross[index];

		CalcQueue.Enqueue(startPoints);
	}
}

void UWFOARoadGeneratorComponent::Calc()
{
	if (IsDone)
		return;

	CalcQueue.Dequeue(Current);


	if(CalcQueue.IsEmpty())
	{
		IsDone = true;
	}
}

void UWFOARoadGeneratorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!IsDone)
	{
		for (int32 i = 0; i < Speed; i++)
		{
			Calc();
		}
	}
}
