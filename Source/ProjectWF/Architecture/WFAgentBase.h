#pragma once

class FWFAgentManagerBase;

class FWFAgentBase
{
public:
	FWFAgentBase() = delete;
	explicit FWFAgentBase(uint64 id);
	virtual ~FWFAgentBase() = default;

	//이 에이전트를 관리하는 매니저 바로가기 포인터 추가
	void SetPtrCache(TSharedPtr<FWFAgentManagerBase> cachePtr);

	//아이디 획득
	const uint64 GetId();

	//N초간 틱 예약
	void PendTick(float seconds);

	//필요시 주기적인 행위
	virtual void Tick(float deltaTime);

protected:
	uint64 Id = 0;

	//즐겨찾기형 포인터
	TWeakPtr<FWFAgentManagerBase> ManagerPtrCache = nullptr;
};
