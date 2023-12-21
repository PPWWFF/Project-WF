#include "WFGameInstance.h"

#include "Architecture/WFMvcHolder.h"

void UWFGameInstance::Init()
{
	FWFMvcHolder::Initialize();
	SingleInstance=this;
}

void UWFGameInstance::BeginDestroy()
{
	FWFMvcHolder::Terminate();
	Super::BeginDestroy();
}
