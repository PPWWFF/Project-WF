#pragma once

#include "CoreMinimal.h"
#include "Architecture/Model/WFModelAgentBase.h"
#include "Core/WFDebug.h"

class FWFModelAgentBase;
class FWFViewAgentBase;

class FWFViewBase
{
	public:
	virtual ~FWFViewBase() = default;
	TSharedPtr<FWFViewAgentBase> FindViewAgent(uint64 id);
	
	void AddViewAgent(TSharedPtr<FWFViewAgentBase> agent);

	void RemoveViewAgent(uint64 id);

	virtual void Tick(float DeltaTime)
	{
	}

private:
	TMap<uint64, TSharedPtr<FWFViewAgentBase>> ViewAgents;
};
