#include "Coin.h"
#include "Tags.h"

ACoin::ACoin()
{
	PrimaryActorTick.bCanEverTick = false;

	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	Collider->SetupAttachment(RootComponent);
	Mesh->SetupAttachment(Collider);

	Tags.Add(Tags::COIN_TAG);
}

