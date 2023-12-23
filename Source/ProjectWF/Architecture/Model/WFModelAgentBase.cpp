#include "WFModelAgentBase.h"

#include "WFModelBase.h"
#include "Architecture/View/WFViewAgentBase.h"
#include "Core/WFDebug.h"

FWFModelAgentBase::FWFModelAgentBase(uint64 id): FWFAgentBase(id)
{}

void FWFModelAgentBase::Tick(float deltaTime)
{
}

void FWFModelAgentBase::SetViewAgent(TSharedPtr<FWFViewAgentBase> viewAgent)
{
	ViewAgentPtrCache = viewAgent;
}
