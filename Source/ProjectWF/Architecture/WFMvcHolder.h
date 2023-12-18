#pragma once

#include "CoreMinimal.h"
#include "Templates/SharedPointer.h"
#include "UObject/GCObject.h"

class FWFMvcHolder : public FGCObject, public TSharedFromThis<FWFMvcHolder>
{
public:
	static FWFMvcHolder& Get()
	{
		return *SingleInstance;
	}
	static bool IsValid()
	{
		return SingleInstance.IsValid();
	}

private:
	inline static TSharedPtr<FWFMvcHolder> SingleInstance = nullptr;
};
