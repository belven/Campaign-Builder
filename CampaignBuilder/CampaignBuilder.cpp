// Copyright Epic Games, Inc. All Rights Reserved.

#include "CampaignBuilder.h"

#include "Details/QuestDetails.h"

IMPLEMENT_PRIMARY_GAME_MODULE(FCampaginEditorModule, CampaignBuilder, "CampaignBuilder");

DEFINE_LOG_CATEGORY(LogCampaignBuilder)


void FCampaginEditorModule::StartupModule()
{
    auto& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
    
    PropertyModule.RegisterCustomClassLayout(
        "HexTile",
        FOnGetDetailCustomizationInstance::CreateStatic(&FQuestDetails::MakeInstance)
    );

    PropertyModule.NotifyCustomizationModuleChanged();

}

void FCampaginEditorModule::ShutdownModule() {}