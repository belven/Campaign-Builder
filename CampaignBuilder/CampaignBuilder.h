#pragma once
#include "CoreMinimal.h"
#include "Engine.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "UnrealEd.h"

DECLARE_LOG_CATEGORY_EXTERN(LogCampaignBuilder, Log, All);

class FCampaginEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	virtual bool IsGameModule() const override
	{
		return true;
	}
};