#include "WFSeededRandom.h"

void UWFSeededRandom::RegenerateSeed()
{
	Seed=FMath::Rand();
	ResetStream();
}

void UWFSeededRandom::ResetStream()
{
	RandomStream.Initialize(Seed);
	RandomStream.Reset();
}

const FRandomStream& UWFSeededRandom::GetStream() const
{
	return RandomStream;
}
