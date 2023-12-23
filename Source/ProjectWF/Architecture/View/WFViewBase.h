#pragma once

#include "CoreMinimal.h"
#include "Architecture/WFAgentManagerBase.h"

class FWFModelAgentBase;
class FWFViewAgentBase;

class FWFViewBase : public FWFAgentManagerBase
{
public:
	virtual ~FWFViewBase() override = default;
};
