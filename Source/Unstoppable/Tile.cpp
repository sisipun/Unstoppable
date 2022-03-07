#include "Tile.h"
#include "Tags.h"
#include "UnstoppableMan.h"
#include "UnstoppableBaseGameMode.h"

ATile::ATile()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	GenerateTileCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	AttachPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("Attach Point"));

	Mesh->SetupAttachment(RootComponent);
	GenerateTileCollider->SetupAttachment(Mesh);
	AttachPoint->SetupAttachment(Mesh);

	GenerateTileCollider->OnComponentBeginOverlap.AddDynamic(this, &ATile::OnBeginOverlap);

	Tags.Add(Tags::TILE_TAG);
}

void ATile::BeginPlay()
{
	const TSet<UActorComponent*> Components = GetComponents();
	for (UActorComponent* Component : Components)
	{
		UE_LOG(LogTemp, Warning, TEXT("COMP2"));
		UArrowComponent* SpawnPoint = Cast<UArrowComponent>(Component);
		if (SpawnPoint && SpawnPoint != AttachPoint)
		{
			UE_LOG(LogTemp, Warning, TEXT("SPAWN2"));
			SpawnPoints.Add(SpawnPoint);
		}
	}

	Super::BeginPlay();
}

void ATile::OnBeginOverlap(
	UPrimitiveComponent* HitComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComponent,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult
)
{
	AUnstoppableMan* Player = Cast<AUnstoppableMan>(OtherActor);
	if (Player)
	{
		AUnstoppableBaseGameMode* GameMode = Cast<AUnstoppableBaseGameMode>(GetWorld()->GetAuthGameMode());
		if (GameMode)
		{
			GameMode->SpawnTile();
		}
	}
}