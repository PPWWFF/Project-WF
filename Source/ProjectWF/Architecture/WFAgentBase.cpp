#include "WFAgentBase.h"

#include "WFAgentManagerBase.h"
#include "Core/WFDebug.h"


FWFAgentBase::FWFAgentBase(uint64 id)
	: Id(id)
{
}

void FWFAgentBase::SetPtrCache(TSharedPtr<FWFAgentManagerBase> cachePtr)
{
	ManagerPtrCache = cachePtr;
}

const uint64 FWFAgentBase::GetId()
{
	return Id;
}

void FWFAgentBase::PendTick(float seconds)
{
	if (!ManagerPtrCache.IsValid())
	{
		WF_WARN_S(TEXT("ptr cache invalid"));
		return;
	}

	TSharedPtr<FWFAgentManagerBase> PinnedPtr = ManagerPtrCache.Pin();
	if (!PinnedPtr.IsValid())
		return;

	PinnedPtr->PendTick(GetId(), seconds);
}

void FWFAgentBase::Tick(float deltaTime)
{
}
