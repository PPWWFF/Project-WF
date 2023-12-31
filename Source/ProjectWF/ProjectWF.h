// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(LogProjectWF, Log, All);

class PROJECTWF_API FProjectWFModule : public IModuleInterface
{

public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static FProjectWFModule& Get()
	{
		return FModuleManager::LoadModuleChecked< FProjectWFModule >("ProjectWF");
	}

	static bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("ProjectWF");
	}
};