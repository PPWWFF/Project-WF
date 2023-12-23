#pragma once

#include "CoreMinimal.h"
#include "Architecture/WFAgentManagerBase.h"

class FWFModelAgentBase;

class FWFModelBase : public FWFAgentManagerBase
{
public:
	virtual ~FWFModelBase() override = default;

private:
	uint64 CurrentLastId = 0;
};
