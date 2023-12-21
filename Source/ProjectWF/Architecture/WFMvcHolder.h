#pragma once

#include "CoreMinimal.h"
#include "Templates/SharedPointer.h"
#include "UObject/GCObject.h"

class FWFTestView;
class FWFTestModel;

class FWFMvcHolder : public FGCObject, public TSharedFromThis<FWFMvcHolder>
{
public:
	// FGCObject
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;
	virtual FString GetReferencerName() const override;
	


	//教臂沛 包访
	static FWFMvcHolder& Get();
	static bool IsValid();
	static void Initialize();
	static void Terminate();

	//积疙林扁
	void Start();
	void Shutdown();
	void Tick(float deltaTime);

	TSharedPtr<FWFTestModel> GetTestModel();
	TSharedPtr<FWFTestView> GetTestView();

private:
	inline static TSharedPtr<FWFMvcHolder> SingleInstance = nullptr;

	TSharedPtr<FWFTestModel> TestModel = nullptr;
	TSharedPtr<FWFTestView> TestView = nullptr;
	
};
