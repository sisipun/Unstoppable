#include "Obstacle.h"
#include "Tags.h"

AObstacle::AObstacle()
{
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	Collider->SetupAttachment(RootComponent);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Collider);

	Tags.Add(Tags::OBSTACLE_TAG);
}

