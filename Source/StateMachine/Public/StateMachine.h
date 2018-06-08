#pragma once

#include "CoreMinimal.h"
#include "ModuleManager.h"

class FStateMachineModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};