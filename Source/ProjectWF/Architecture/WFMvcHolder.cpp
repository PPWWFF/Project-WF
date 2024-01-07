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
}

void FWFMvcHolder::Shutdown()
{
}

void FWFMvcHolder::Tick(float deltaTime)
{
	if (OAModel.IsValid())
	{
		OAModel->Tick(deltaTime);
	}
	if (OAView.IsValid())
	{
		OAView->Tick(deltaTime);
	}
}

void FWFMvcHolder::SetOAModel(TSharedPtr<FWFModelBase> inOAModel)
{
	OAModel=inOAModel;
}

void FWFMvcHolder::SetOAView(TSharedPtr<FWFViewBase> inOAView)
{
	OAView=inOAView;
}

TSharedPtr<FWFModelBase> FWFMvcHolder::GetOAModel()
{
	return OAModel;
}

TSharedPtr<FWFViewBase> FWFMvcHolder::GetOAView()
{
	return OAView;
}