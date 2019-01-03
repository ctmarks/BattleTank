// Copyright Embrace ITLimited

#include "SpawnPoint.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
USpawnPoint::USpawnPoint()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}




// Called when the game starts
void USpawnPoint::BeginPlay()
{
	Super::BeginPlay();

	SpawnedWheel = GetWorld()->SpawnActorDeferred<AActor>(
		SpawnClass, 
		GetComponentTransform(), 
		GetAttachmentRoot()->GetOwner()
		);

	if (!SpawnedWheel) { return; }
	SpawnedWheel->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
	UGameplayStatics::FinishSpawningActor(SpawnedWheel, GetComponentTransform());
}


// Called every frame
void USpawnPoint::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

AActor* USpawnPoint::GetWheel() const
{
	return SpawnedWheel;
}