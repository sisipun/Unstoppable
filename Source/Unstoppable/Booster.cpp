#include "Booster.h"
#include "Tags.h"

ABooster::ABooster()
{
	PrimaryActorTick.bCanEverTick = false;

	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	Collider->SetupAttachment(RootComponent);
	Mesh->SetupAttachment(Collider);

	Tags.Add(Tags::BOOSTER_TAG);
}