#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../CampaignDataStructs.h"
#include "QuestComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), hidecategories = ("Tags", "AssetUserData", "Activation", "Collision", "Cooking"))
class CAMPAIGNBUILDER_API UQuestComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UQuestComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quests")
		TArray<FQuest> quests;


	UFUNCTION(BlueprintCallable)
		static UQuestComponent* CreateQuestComp(UObject* owner) { return NewObject<UQuestComponent>(owner);  }

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;		
};