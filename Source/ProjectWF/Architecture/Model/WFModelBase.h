#pragma once

#include "CoreMinimal.h"
#include "Core/WFDebug.h"

class FWFModelAgentBase;

class FWFModelBase
{
public:
	virtual ~FWFModelBase() = default;
	TSharedPtr<FWFModelAgentBase> FindModelAgent(uint64 id);

	void AddModelAgent(TSharedPtr<FWFModelAgentBase> agent);
	

	void RemoveAgent(uint64 id);

	virtual void Tick(float DeltaTime)
	{
	}

	const uint64 GetUniqueId();

private:
	const uint64 PeekLastId() const;

private:
	TMap<uint64, TSharedPtr<FWFModelAgentBase>> ModelAgents;

	uint64 CurrentLastId = 0;
};
