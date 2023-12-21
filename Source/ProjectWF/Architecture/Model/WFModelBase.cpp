#include "WFModelBase.h"

#include "WFModelAgentBase.h"
#include "Chaos/AABB.h"
#include "Chaos/AABB.h"
#include "Chaos/AABB.h"
#include "Chaos/AABB.h"

TSharedPtr<FWFModelAgentBase> FWFModelBase::FindModelAgent(uint64 id)
{
	TSharedPtr<FWFModelAgentBase>* targetAgentPtr = ModelAgents.Find(id);
	if (targetAgentPtr == nullptr)
		return nullptr;

	return *targetAgentPtr;
}

void FWFModelBase::AddModelAgent(TSharedPtr<FWFModelAgentBase> agent)
{
	if (!agent.IsValid())
		return;

	uint64 Id = agent->GetId();
	if (FindModelAgent(Id))
	{
		WF_LOG_S(TEXT("ModelAgent-Duplicate Key %llu"), Id);
		return;
	}

	ModelAgents.Add(Id, agent);
}

void FWFModelBase::RemoveAgent(uint64 id)
{
	if (FindModelAgent(id))
	{
		ModelAgents.Remove(id);
	}
	else
	{
		WF_LOG_S(TEXT("ModelAgent - Not Exist"));
	}
}

const uint64 FWFModelBase::PeekLastId() const
{
	return CurrentLastId;
}

const uint64 FWFModelBase::GetUniqueId()
{
	uint64 ret = CurrentLastId;
	while (FindModelAgent(ret).IsValid())
	{
		if (CurrentLastId == UINT64_MAX)
			CurrentLastId = 0;
		CurrentLastId++;
	}
	return ret;
}
