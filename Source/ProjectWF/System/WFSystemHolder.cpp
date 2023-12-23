#include "WFSystemHolder.h"

void FWFSystemHolder::AddReferencedObjects(FReferenceCollector& Collector)
{
}

FString FWFSystemHolder::GetReferencerName() const
{
	return "FWFSystemHolder";
}

FWFSystemHolder& FWFSystemHolder::Get()
{
	return *SingleInstance;
}

bool FWFSystemHolder::IsValid()
{
	return SingleInstance.IsValid();
}

void FWFSystemHolder::Initialize()
{
	SingleInstance = MakeShareable(new FWFSystemHolder());
}

void FWFSystemHolder::Terminate()
{
	if(!SingleInstance.IsValid())
		return;
	
	SingleInstance->Shutdown();
	SingleInstance.Reset();
}

void FWFSystemHolder::Start()
{
}

void FWFSystemHolder::Shutdown()
{
}

void FWFSystemHolder::Tick(float deltaTime)
{
}
