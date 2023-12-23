#pragma once

class FWFAgentBase;


class FWFAgentManagerBase : public TSharedFromThis<FWFAgentManagerBase>
{
public:
	virtual ~FWFAgentManagerBase() = default;

	//에이전트 찾기
	TSharedPtr<FWFAgentBase> FindAgent(uint64 id);

	//에이전트 추가
	void AddAgent(TSharedPtr<FWFAgentBase> agent);

	//에이전트 삭제
	void RemoveAgent(uint64 id);

	//틱 내부함수
	virtual void Tick(float deltaTime);

	//중복없는 새 아이디 발급
	const uint64 GetUniqueId();

	//기존 아이디 발급
	const uint64 PeekLastId() const;

	//해당 ID를 앞으로 몇초간 틱을 돌립니다 (최소 1번)
	void PendTick(uint64 id, float seconds);

protected:
	static inline uint64 CurrentLastId = 0;
	
	TMap<uint64, TSharedPtr<FWFAgentBase>> Agents;

	TMap<uint64, float> PendedTicker;
	TSet<uint64> TickRemoveTarget;
};
