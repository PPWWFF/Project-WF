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
		//�̹� �ִµ� �Ǹ���� ����
		ViewAgent = MakeShareable(new FWFViewAgentBase(Id));
	}
	
	return ViewAgent;
}
