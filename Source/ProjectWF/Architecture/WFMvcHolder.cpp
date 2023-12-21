#include "WFMvcHolder.h"

#include "Test/TestClasses.h"

void FWFMvcHolder::AddReferencedObjects(FReferenceCollector& Collector)
{
}

FString FWFMvcHolder::GetReferencerName() const
{
	return "FWFMvcHolder";
}

FWFMvcHolder& FWFMvcHolder::Get()
{
	return *SingleInstance;
}

bool FWFMvcHolder::IsValid()
{
	return SingleInstance.IsValid();
}

void FWFMvcHolder::Initialize()
{
	TSharedPtr<FWFMvcHolder> NewMvcHolder = MakeShareable(new FWFMvcHolder());
	if(!NewMvcHolder.IsValid())
		return;

	SingleInstance = NewMvcHolder;
	NewMvcHolder->Start();
}

void FWFMvcHolder::Terminate()
{
	if(!SingleInstance.IsValid())
		return;
	
	SingleInstance->Shutdown();
	SingleInstance.Reset();
}

void FWFMvcHolder::Start()
{
	TestModel = MakeShareable(new FWFTestModel());
	TestView = MakeShareable(new FWFTestView());
}

void FWFMvcHolder::Shutdown()
{
	TestModel.Reset();
	TestView.Reset();
}

void FWFMvcHolder::Tick(float deltaTime)
{
	if (TestModel.IsValid())
	{
		TestModel->Tick(deltaTime);
	}
	if (TestView.IsValid())
	{
		TestView->Tick(deltaTime);
	}
}

TSharedPtr<FWFTestModel> FWFMvcHolder::GetTestModel()
{
	return TestModel;
}
TSharedPtr<FWFTestView> FWFMvcHolder::GetTestView()
{
	return TestView;
}
