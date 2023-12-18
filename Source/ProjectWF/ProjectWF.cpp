// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectWF.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, ProjectWF, "ProjectWF" );

DEFINE_LOG_CATEGORY(LogProjectWF)

void FProjectWFModule::StartupModule()
{
	IModuleInterface::StartupModule();
}

void FProjectWFModule::ShutdownModule()
{
	IModuleInterface::ShutdownModule();
}
