#include "TestClasses.h"

#include "Architecture/WFMvcHolder.h"

void FWFTestModel::Tick(float DeltaTime)
{
	FWFModelBase::Tick(DeltaTime);
}

void FWFTestView::Tick(float DeltaTime)
{
	FWFViewBase::Tick(DeltaTime);
}

void AWFTestGameMode::StartPlay()
{
	Super::StartPlay();

	
}

void AWFTestGameMode::AddAgent()
{
	TSharedPtr<FWFTestModel> testModel = FWFMvcHolder::Get().GetTestModel();
 	if(!testModel.IsValid())
 		return;
 
 	TSharedPtr<FWFTestView> testView = FWFMvcHolder::Get().GetTestView();
 	if(!testView.IsValid())
 		return;
 	
 	TSharedPtr<FWFTestModelAgent> testModelAgent = MakeShareable(new FWFTestModelAgent(testModel->GetUniqueId()));
 	if(!testModelAgent.IsValid())
 		return;
 
 	testModel->AddModelAgent(testModelAgent);
 	testView->AddViewAgent(testModelAgent->GetViewAgent());
}

UWFTestAgentComponent::UWFTestAgentComponent()
{
}

AWFTestActor::AWFTestActor()
{
}
