#include "HexTile.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

AHexTile::AHexTile()
{
	canHaveQuests = true;

	const ConstructorHelpers::FObjectFinder<UStaticMesh> tileMesh(TEXT("StaticMesh'/Game/TopDown/Models/hexagon_Circle.hexagon_Circle'"));
	if (tileMesh.Succeeded())
	{
		mesh = tileMesh.Object;
	}

	const ConstructorHelpers::FObjectFinder<UMaterial> materialFound(TEXT("Material'/Game/TopDown/Models/Grass.Grass'"));
	if (materialFound.Succeeded())
	{
		material = materialFound.Object;
	}
}

void AHexTile::AddComponentInstance(UActorComponent* comp)
{
	if (GetComponentByClass(comp->GetClass()) == NULL) {
		AddInstanceComponent(comp);
		comp->RegisterComponent();
	}
}

int AHexTile::GetTileID() const
{
	return tileID;
}

void AHexTile::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (meshComp == NULL) {
		meshComp = NewObject<UInstancedStaticMeshComponent>(this);
		meshComp->SetupAttachment(RootComponent);
		meshComp->RegisterComponent();
		FTransform trans = GetActorTransform();
		meshComp->AddInstance(trans, true);
	}

	meshComp->SetStaticMesh(mesh);
	meshComp->SetMaterial(0, material);
}
