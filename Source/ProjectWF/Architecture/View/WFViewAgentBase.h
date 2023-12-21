#pragma once

#include "CoreMinimal.h"

class FWFViewAgentBase
{
public:
	FWFViewAgentBase()=delete;
	FWFViewAgentBase(uint64 id);

	uint64 GetId()
	{
		return Id;
	}

private:
	uint64 Id=0;
};