#pragma once

#include "CoreMinimal.h"

#include "WFGameInstance.generated.h"

UCLASS(Blueprintable)
class UWFGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	static TWeakObjectPtr<UWFGameInstance> Get(){return SingleInstance; }
public:
	virtual void Init() override;
	virtual void BeginDestroy() override;

	inline static TWeakObjectPtr<UWFGameInstance> SingleInstance = nullptr;
};
