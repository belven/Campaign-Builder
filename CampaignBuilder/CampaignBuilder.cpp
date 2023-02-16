// Copyright Epic Games, Inc. All Rights Reserved.

#include "CampaignBuilder.h"

#include "Details/QuestDetails.h"

IMPLEMENT_PRIMARY_GAME_MODULE(FQuestEditorModule, CampaignBuilder, "CampaignBuilder");

//IMPLEMENT_GAME_MODULE(FQuestEditorModule, QuestModule);

DEFINE_LOG_CATEGORY(LogCampaignBuilder)


void FQuestEditorModule::StartupModule()
{
    auto& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

    // Register our customization to be used by a class 'UMyClass' or 'AMyClass'. Note the prefix must be dropped.
    PropertyModule.RegisterCustomClassLayout(
        "HexTile",
        FOnGetDetailCustomizationInstance::CreateStatic(&FQuestDetails::MakeInstance)
    );

    PropertyModule.NotifyCustomizationModuleChanged();

}

void FQuestEditorModule::ShutdownModule() {}