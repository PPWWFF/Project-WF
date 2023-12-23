#include "WFAgentManagerBase.h"

#include "WFAgentBase.h"
#include "Core/WFDebug.h"

TSharedPtr<FWFAgentBase> FWFAgentManagerBase::FindAgent(uint64 id)
{
	TSharedPtr<FWFAgentBase>* targetAgentPtr = Agents.Find(id);
	if (targetAgentPtr == nullptr)
		return nullptr;

	return *targetAgentPtr;
}

void FWFAgentManagerBase::AddAgent(TSharedPtr<FWFAgentBase> agent)
{
	if (!agent.IsValid())
		return;

	uint64 Id = agent->GetId();
	if (FindAgent(Id))
	{
		WF_LOG_S(TEXT("Agent-Duplicate Key %llu"), Id);
		return;
	}

	Agents.Add(Id, agent);
	agent->SetPtrCache(AsShared());
}

void FWFAgentManagerBase::RemoveAgent(uint64 id)
{
	if (FindAgent(id))
	{
		TSharedPtr<FWFAgentBase> removedAgent = Agents.FindAndRemoveChecked(id);
		if (removedAgent.IsValid())
		{
			removedAgent->SetPtrCache(nullptr);
		}
	}
	else
	{
		WF_LOG_S(TEXT("Agent - Not Exist"));
	}
}

void FWFAgentManagerBase::Tick(float deltaTime)
{
	for (TTuple<uint64, float>& each : PendedTicker)
	{
		TSharedPtr<FWFAgentBase> FoundAgent = FindAgent(each.Key);
		if (!FoundAgent.IsValid())
		{
			TickRemoveTarget.Add(each.Key);
			continue;
		}

		FoundAgent->Tick(deltaTime);
		each.Value -= deltaTime;

		if (each.Value < 0)
		{
			TickRemoveTarget.Add(each.Key);
		}
	}

	for (uint64 each : TickRemoveTarget)
	{
		PendedTicker.Remove(each);
	}

	TickRemoveTarget.Empty();
}

const uint64 FWFAgentManagerBase::PeekLastId() const
{
	return CurrentLastId;
}

const uint64 FWFAgentManagerBase::GetUniqueId()
{
	uint64 ret = CurrentLastId;
	while (FindAgent(ret).IsValid())
	{
		if (CurrentLastId == UINT64_MAX)
			CurrentLastId = 0;
		CurrentLastId++;
	}
	return ret;
}

void FWFAgentManagerBase::PendTick(uint64 id, float seconds)
{
	float& FoundVal = PendedTicker.FindOrAdd(id);
	if (seconds > FoundVal)
	{
		FoundVal = seconds;
	}
}
