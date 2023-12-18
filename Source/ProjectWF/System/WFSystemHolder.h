#pragma once

#include "CoreMinimal.h"
#include "Templates/SharedPointer.h"
#include "UObject/GCObject.h"

class FWFSystemHolder : public FGCObject, public TSharedFromThis<FWFSystemHolder>
{
public:
	static FWFSystemHolder& Get()
	{
		return *SingleInstance;
	}
	static bool IsValid()
	{
		return SingleInstance.IsValid();
	}

private:
	inline static TSharedPtr<FWFSystemHolder> SingleInstance = nullptr;
};
