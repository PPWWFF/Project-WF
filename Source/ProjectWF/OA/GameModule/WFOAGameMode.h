#pragma once
#include "GameModule/WFGameModeBase.h"

#include "WFOAGameMode.generated.h"

UCLASS(BlueprintType)
class AWFOAGameMode : public AWFGameModeBase
{
	GENERATED_BODY()
public:

	virtual void StartPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type endPlayReason) override;
};
