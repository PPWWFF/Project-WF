#pragma once

#include "CoreMinimal.h"

class FWFViewAgentBase;

class FWFModelAgentBase
{
public:
	FWFModelAgentBase() = delete;
	FWFModelAgentBase(uint64 id);

	const uint64 GetId();

	virtual TSharedPtr<FWFViewAgentBase> GetViewAgent();
	
protected:
	uint64 Id = 0;

	TSharedPtr<FWFViewAgentBase> ViewAgent = nullptr;
};
