#include "WFGameModeBase.h"

#include "Architecture/WFMvcHolder.h"

AWFGameModeBase::AWFGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AWFGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if(FWFMvcHolder::IsValid())
	{
		FWFMvcHolder::Get().Tick(DeltaSeconds);	
	}
}
