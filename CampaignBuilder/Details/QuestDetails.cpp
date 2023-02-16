#include "QuestDetails.h"

#if WITH_EDITOR

#include "CampaignBuilder/HexTile.h"
#include "CampaignBuilder/Tables/CSVTable.h"
#include "Misc/FileHelper.h"
#include "PropertyEditing.h"
#include "Editor/PropertyEditor/Public/DetailLayoutBuilder.h"
#include "Editor/PropertyEditor/Public/DetailCategoryBuilder.h"
#include "Editor/PropertyEditor/Public/DetailWidgetRow.h"

#define LOCTEXT_NAMESPACE "QuestDetials"
#define mQuestCategory(builder)  builder->EditCategory("Quests", FText::GetEmpty(), ECategoryPriority::Important);

TSharedRef< IDetailCustomization > FQuestDetails::MakeInstance()
{
	return MakeShareable(new FQuestDetails);
}

FReply FQuestDetails::AddQuest()
{
	IDetailCategoryBuilder& QuestCategory = mQuestCategory(builder);
	builder->ForceRefreshDetails();
	return FReply::Handled();
}

AHexTile* FQuestDetails::GetTileSelected(const IDetailLayoutBuilder& DetailBuilder)
{
	AHexTile* tile = nullptr;
	TArray<TWeakObjectPtr<UObject>> CustomizedObjects;
	DetailBuilder.GetObjectsBeingCustomized(CustomizedObjects);

	for (TWeakObjectPtr<UObject> Object : CustomizedObjects)
	{
		if (Object.IsValid())
		{
			tile = Cast<AHexTile>(Object);

			if (!tile)
			{
				break;
			}
		}
	}

	check(tile);

	return tile;
}

void FQuestDetails::LoadTableFromFile(UCSVTable* table)
{
	const FString path = table->GetPath();

	if (FPaths::FileExists(path))
	{
		TArray<TArray<FString>> parsedCSV;
		FString FileContent;

		FFileHelper::LoadFileToString(FileContent, *path);

		const TCHAR* Terminators[] = { L"\r", L"\n" };
		const TCHAR* CSVDelimiters[] = { TEXT(","), TEXT("\t") };

		TArray<FString> CSVLines;
		FileContent.ParseIntoArray(CSVLines, Terminators, 2);

		TArray<FString> temp_array;
		for (int i = 0; i < CSVLines.Num(); i++) {
			temp_array.Empty();
			CSVLines[i].ParseIntoArray(temp_array, CSVDelimiters, 2);
			parsedCSV.Add(CleanData(temp_array));
		}

		table->LoadData(parsedCSV);
	}
}

TArray<FString> FQuestDetails::CleanData(TArray<FString> strings)
{
	TArray<FString> newStrings;
	for (FString s : strings)
	{
		newStrings.Add(s.TrimQuotes());
	}
	return newStrings;
}

TArray<FQuest> FQuestDetails::GetQuests(int32 tileID)
{
	TArray<FQuest> quests;
	FQuest quest1;
	quest1.locationID = 0;
	quest1.name = "Test quest 1";

	FQuest quest2;
	quest2.locationID = 0;
	quest2.name = "Test quest 2";

	FQuest quest3;
	quest3.locationID = 0;
	quest3.name = "Test quest 3";

	quests.Add(quest1);
	quests.Add(quest2);
	quests.Add(quest3);

	return quests;
}

void FQuestDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	builder = &DetailBuilder;

	const AHexTile* tile = GetTileSelected(*builder);

	TArray<FQuest> questsFound = GetQuests(tile->GetTileID());
	const bool questDataFound = questsFound.Num() > 0;

	if (tile != NULL && tile->canHaveQuests)
	{
		IDetailCategoryBuilder& QuestCategory = mQuestCategory(builder);
		QuestCategory.AddCustomRow(LOCTEXT("RowSearchName", "Quest"))
			.ValueContent()
			[
				SNew(SButton)
				.Text(LOCTEXT("ButtonText", "Add Quest"))
			.HAlign(HAlign_Center)
			.ToolTipText(LOCTEXT("ButtonTooltip", "Do something"))
			.OnClicked(this, &FQuestDetails::AddQuest)
			];

		if (questDataFound) {
			for (FQuest quest : questsFound) {
				QuestCategory.AddCustomRow(LOCTEXT("RowSearchName", "Quest"))
					.NameContent()
					[
						SNew(STextBlock)
						.Text(LOCTEXT("DetailName", "Quest Name"))
					.Font(IDetailLayoutBuilder::GetDetailFont())
					]
				.ValueContent()
					[
						SNew(STextBlock)
						.Text(FText::FromString(*quest.name))
					];
			}
		}
	}
}

#endif