#include "WFOARegionGenerator.h"

#include "WFOARoadGeneratorComponent.h"
#include "Core/WFDebug.h"



AWFOARegionGenerator::AWFOARegionGenerator()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("ROOTCOMPONENT");
	RandomGenerator = NewObject<UWFSeededRandom>(this, FName("Random"));

	RoadGenerator=CreateDefaultSubobject<UWFOARoadGeneratorComponent>("ROADGENERATORCOMPONENT");
}

void AWFOARegionGenerator::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	UWorld* WorldContext = GetWorld();
	if(!IsValid(WorldContext))
		return;
	
	if(bShowGizmo)
	{
		FVector RegionLocation = GetActorLocation();
		
		DrawDebugCircle(WorldContext, RegionLocation, Radius, 32, FColor::Blue, false, 1, 1, 3, {0, 1, 0}, {1, 0, 0});

		for (auto& Each : EntryPoints)
		{
			float EachRad = FMath::DegreesToRadians(Each);
			FVector EachPos = FVector(FMath::Sin(EachRad), FMath::Cos(EachRad), 0) * Radius;
			DrawDebugSphere(WorldContext, RegionLocation + EachPos, 30, 12, FColor::Green, false, 1, 1, 3);
		}
		for (auto& Each : CrossPoints)
		{
			DrawDebugSphere(WorldContext, RegionLocation + Each, 30, 12, FColor::Red, false, 1, 1, 3);
		}
	}
}

bool AWFOARegionGenerator::ShouldTickIfViewportsOnly() const
{
	return true;
}

void AWFOARegionGenerator::GenerateRegion()
{
	if (!IsValid(RandomGenerator))
		return;

	RandomGenerator->ResetStream();

	TArray<FVector2D> RoadStartPoints; 

	for (auto& Each : EntryPoints)
	{
		float EachRad = FMath::DegreesToRadians(Each);
		FVector2D EachPos = FVector2D(FMath::Sin(EachRad), FMath::Cos(EachRad)) * Radius;
		RoadStartPoints.Add(EachPos);
	}

	if(IsValid(RoadGenerator))
	{
		RoadGenerator->Init(RoadStartPoints, FVector2D::ZeroVector, RandomGenerator);	
	}
	
	const FRandomStream& Stream = RandomGenerator->GetStream();
	
	
}
