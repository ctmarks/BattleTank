// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
//#include "Engine/World.h"
//#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.h"


// Called at the start of the game
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Get reference to controlled tank
	auto Tank = GetPawn();

	// Get the player's location this frame
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (ensure (PlayerTank && Tank))
	{
		

		// Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); // Check radius is in cm
		
		auto AimingComponent = Tank->FindComponentByClass<UTankAimingComponent>();
		if (!ensure(AimingComponent)) { return; }
		// Aim at the player's location
		AimingComponent->AimAt(PlayerTank->GetActorLocation());



		// Shoot at the player
		AimingComponent->Fire();
	}

}


