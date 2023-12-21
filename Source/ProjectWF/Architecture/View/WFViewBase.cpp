#include "WFViewBase.h"

#include "WFViewAgentBase.h"

TSharedPtr<FWFViewAgentBase> FWFViewBase::FindViewAgent(uint64 id)
{
	TSharedPtr<FWFViewAgentBase>* targetAgentPtr = ViewAgents.Find(id);
	if (targetAgentPtr == nullptr)
		return nullptr;

	return *targetAgentPtr;
}

void FWFViewBase::AddViewAgent(TSharedPtr<FWFViewAgentBase> agent)
{
	uint64 Id = agent->GetId();
	if (FindViewAgent(Id))
	{
		WF_LOG_S(TEXT("ModelAgent-Duplicate Key %llu"), Id);
		return;
	}

	ViewAgents.Add(Id, agent);
}

void FWFViewBase::RemoveViewAgent(uint64 id)
{
	if (FindViewAgent(id))
	{
		ViewAgents.Remove(id);
	}
	else
	{
		WF_LOG_S(TEXT("ViewAgent - Not Exist"));
	}
}
