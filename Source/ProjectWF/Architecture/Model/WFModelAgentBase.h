#pragma once

#include "CoreMinimal.h"
#include "Architecture/WFAgentBase.h"

class FWFModelBase;
class FWFViewAgentBase;

class FWFModelAgentBase : public FWFAgentBase
{
public:
	virtual ~FWFModelAgentBase() override = default;

	explicit FWFModelAgentBase(uint64 id);


	virtual void Tick(float deltaTime) override;

	void SetViewAgent(TSharedPtr<FWFViewAgentBase> viewAgent);
protected:
	TWeakPtr<FWFViewAgentBase> ViewAgentPtrCache = nullptr;
};
