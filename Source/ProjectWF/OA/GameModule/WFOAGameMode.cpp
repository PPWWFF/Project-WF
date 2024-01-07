#include "WFOAGameMode.h"

#include "Architecture/WFMvcHolder.h"
#include "OA/Model/WFOAModel.h"
#include "OA/View/WFOAView.h"

void AWFOAGameMode::StartPlay()
{
	Super::StartPlay();
	if(!FWFMvcHolder::IsValid())
		return;

	FWFMvcHolder::Get().SetOAModel(MakeShareable(new FWFOAModel()));
	FWFMvcHolder::Get().SetOAView(MakeShareable(new FWFOAView()));
}

void AWFOAGameMode::EndPlay(const EEndPlayReason::Type endPlayReason)
{
	Super::EndPlay(endPlayReason);
	if(!FWFMvcHolder::IsValid())
		return;

	FWFMvcHolder::Get().SetOAModel(nullptr);
	FWFMvcHolder::Get().SetOAView(nullptr);
}
