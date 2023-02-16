
#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CampaignDataStructs.generated.h"

USTRUCT(BlueprintType)
struct FQuest
{
	GENERATED_USTRUCT_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
		FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
		FString description;	
};

UCLASS()
class CAMPAIGNBUILDER_API UCampaignDataStructs : public UObject
{
	GENERATED_BODY()
};