#include "WFModelAgentBase.h"

#include "Architecture/View/WFViewAgentBase.h"

FWFModelAgentBase::FWFModelAgentBase(uint64 id)
	: Id(id)
{
}

const uint64 FWFModelAgentBase::GetId()
{
	return Id;
}

TSharedPtr<FWFViewAgentBase> FWFModelAgentBase::GetViewAgent()
{
	if(!ViewAgent.IsValid())
	{
		//이미 있는데 또만들기 금지
		ViewAgent = MakeShareable(new FWFViewAgentBase(Id));
	}
	
	return ViewAgent;
}
