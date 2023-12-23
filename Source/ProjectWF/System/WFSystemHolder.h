#pragma once

#include "CoreMinimal.h"
#include "Templates/SharedPointer.h"
#include "UObject/GCObject.h"

class FWFSystemHolder : public FGCObject, public TSharedFromThis<FWFSystemHolder>
{
public:
	//FGCObject
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;
	virtual FString GetReferencerName() const override;

	//�̱��� ����
	static FWFSystemHolder& Get();
	static bool IsValid();
	static void Initialize();
	static void Terminate();

	//�����ֱ�
	void Start();
	void Shutdown();
	void Tick(float deltaTime);

private:
	inline static TSharedPtr<FWFSystemHolder> SingleInstance = nullptr;
};
