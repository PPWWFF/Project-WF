#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "WFGameModeBase.generated.h"

UCLASS(Blueprintable)
class AWFGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AWFGameModeBase();

	//모델, 뷰 틱 돌려준다
	virtual void Tick(float DeltaSeconds) override;
};
