#include "QuestDetails.h"

#include "CampaignBuilder/HexTile.h"

#if WITH_EDITOR

#include "PropertyEditing.h"
#include "Editor/PropertyEditor/Public/DetailLayoutBuilder.h"
#include "Editor/PropertyEditor/Public/DetailCategoryBuilder.h"
#include "Editor/PropertyEditor/Public/DetailWidgetRow.h"

#define LOCTEXT_NAMESPACE "QuestDetials"

TSharedRef< IDetailCustomization > FQuestDetails::MakeInstance()
{
	return MakeShareable(new FQuestDetails);
}

void FQuestDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
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

	IDetailCategoryBuilder& QuestCategory = DetailBuilder.EditCategory("Quests", FText::GetEmpty(), ECategoryPriority::Important);
	QuestCategory.AddCustomRow(LOCTEXT("RowSearchName", "Quest")).
		NameContent()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("DetailName", "Quest Name"))
		.Font(IDetailLayoutBuilder::GetDetailFont())
		]
	.ValueContent()
	[
		SNew(SButton)
		.Text(LOCTEXT("ButtonText", "Test Button"))
		.HAlign(HAlign_Center)
		.ToolTipText(LOCTEXT("ButtonTooltip", "Do something"))
		]
	;


}

#endif