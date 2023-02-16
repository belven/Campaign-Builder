
#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CampaignDataStructs.generated.h"

USTRUCT(BlueprintType)
struct FRowData
{
	GENERATED_USTRUCT_BODY()
public:

	UPROPERTY()
		int32 ID;
};

USTRUCT(BlueprintType)
struct FQuest : public FRowData
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
		int32 locationID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
		FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
		FString description;
};

USTRUCT(BlueprintType)
struct FQuestObjectives : public FRowData
{
	GENERATED_USTRUCT_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Objective")
		FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Objective")
		FString description;
};

UENUM(BlueprintType)
enum class ERewardType : uint8
{
	Experience,
	Item,
	End
};

USTRUCT(BlueprintType)
struct FQuestRewards : public FRowData
{
	GENERATED_USTRUCT_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Rewards")
		FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest  Rewards")
		FString description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest  Rewards")
		ERewardType type;
};

UCLASS()
class CAMPAIGNBUILDER_API UCampaignDataStructs : public UObject
{
	GENERATED_BODY()
};