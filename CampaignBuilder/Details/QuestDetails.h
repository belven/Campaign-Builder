#pragma once
#if WITH_EDITOR

#include "IDetailCustomization.h"
#include "CampaignBuilder/CampaignDataStructs.h"
#include "CampaignBuilder/Tables/CSVTable.h"

class AHexTile;
class UCSVTable;

class FQuestDetails : public IDetailCustomization
{
public:
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;
	static TSharedRef<IDetailCustomization> MakeInstance();
	AHexTile* GetTileSelected(const IDetailLayoutBuilder& DetailBuilder);

	void LoadTableFromFile(UCSVTable* table);
	TArray<FString> CleanData(TArray<FString> strings);

	FReply AddQuest();
	TArray<FQuest> GetQuests(int32 tileID);
private:
	IDetailLayoutBuilder* builder = nullptr;
};

#endif