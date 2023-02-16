#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexTile.generated.h"

class UInstancedStaticMeshComponent;

UCLASS(hidecategories = ("Rendering", "Replication", "Collision", "HLOD", "World_Partition", "Input", "Replication", "Actor", "Cooking", "Data_Layers"))
class CAMPAIGNBUILDER_API AHexTile : public AActor
{
	GENERATED_BODY()

public:
	AHexTile();

	UFUNCTION(BlueprintCallable)
		void AddComponentInstance(UActorComponent* comp);
	int GetTileID() const;

	UPROPERTY()
		UInstancedStaticMeshComponent* meshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile Data")
		int32 tileID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Allowed Data")
		bool canHaveQuests;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Allowed Data")
		bool canHaveItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Allowed Data")
		bool canHaveEntities;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
		UMaterial* material;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
		UStaticMesh* mesh;
protected:
	virtual void OnConstruction(const FTransform& Transform) override;
};