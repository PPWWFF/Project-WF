#pragma once
#include "Architecture/Model/WFModelAgentBase.h"
#include "Architecture/Model/WFModelBase.h"
#include "Architecture/View/WFViewAgentBase.h"
#include "Architecture/View/WFViewBase.h"
#include "GameModule/WFGameModeBase.h"

#include "TestClasses.generated.h"

class FWFTestModel : public FWFModelBase
{
public:
	virtual void Tick(float DeltaTime) override;
};

class FWFTestView : public FWFViewBase
{
public:
	virtual void Tick(float DeltaTime) override;
};

class FWFTestModelAgent : public FWFModelAgentBase
{
public:
	FWFTestModelAgent(uint64 id)
		: FWFModelAgentBase(id)
	{
	}
};

class FWFTestViewAgent : public FWFViewAgentBase
{
public:
	FWFTestViewAgent(uint64 id)
		: FWFViewAgentBase(id)
	{
	}
};

UCLASS(Blueprintable)
class AWFTestGameMode : public AWFGameModeBase
{
	GENERATED_BODY()
public:
	virtual void StartPlay() override;

	UFUNCTION(BlueprintCallable,CallInEditor)
	void AddAgent();
};

UCLASS(Blueprintable)
class UWFTestAgentComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UWFTestAgentComponent();
};

UCLASS(Blueprintable)
class AWFTestActor : public AActor
{
	GENERATED_BODY()
public:
	AWFTestActor();
};