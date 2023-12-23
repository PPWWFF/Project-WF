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

FWFTestModelAgent::FWFTestModelAgent(uint64 id): FWFModelAgentBase(id)
{
}

FWFTestViewAgent::FWFTestViewAgent(uint64 id):FWFViewAgentBase(id)
{}

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
	uint64 newUniqueId = testModel->GetUniqueId();
	TSharedPtr<FWFTestModelAgent> testModelAgent = MakeShareable(new FWFTestModelAgent(newUniqueId));
 	if(!testModelAgent.IsValid())
 		return;

	TSharedPtr<FWFTestViewAgent> testViewAgent = MakeShareable(new FWFTestViewAgent(newUniqueId));
	if(!testViewAgent.IsValid())
		return;
 
 	testModel->AddAgent(testModelAgent);
 	testView->AddAgent(testViewAgent);
}

UWFTestAgentComponent::UWFTestAgentComponent()
{
}

AWFTestActor::AWFTestActor()
{
}
