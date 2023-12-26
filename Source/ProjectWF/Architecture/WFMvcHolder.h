#pragma once

#include "CoreMinimal.h"
#include "Templates/SharedPointer.h"
#include "UObject/GCObject.h"

class FWFModelBase;
class FWFViewBase;

class FWFMvcHolder : public FGCObject, public TSharedFromThis<FWFMvcHolder>
{
public:
	// FGCObject
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;
	virtual FString GetReferencerName() const override;
	


	//�̱��� ����
	static FWFMvcHolder& Get();
	static bool IsValid();
	static void Initialize();
	static void Terminate();

	//�����ֱ�
	void Start();
	void Shutdown();
	void Tick(float deltaTime);

	void SetOAModel(TSharedPtr<FWFModelBase> inOAModel);
	TSharedPtr<FWFModelBase> GetOAModel();

	void SetOAView(TSharedPtr<FWFViewBase> inOAView);
	TSharedPtr<FWFViewBase> GetOAView();

private:
	inline static TSharedPtr<FWFMvcHolder> SingleInstance = nullptr;
	
	TSharedPtr<FWFModelBase> OAModel = nullptr;
	TSharedPtr<FWFViewBase> OAView = nullptr;
	
};
