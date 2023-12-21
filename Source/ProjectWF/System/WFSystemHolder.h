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

	//教臂沛 包访
	static FWFSystemHolder& Get();
	static bool IsValid();
	static void Initialize();
	static void Terminate();

	//积疙林扁
	void Start();
	void Shutdown();
	void Tick(float deltaTime);

private:
	inline static TSharedPtr<FWFSystemHolder> SingleInstance = nullptr;
};
