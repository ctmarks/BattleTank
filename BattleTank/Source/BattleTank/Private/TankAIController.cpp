// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"


// Called at the start of the game
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Get reference to controlled tank
	auto Tank = Cast<ATank>(GetPawn());

	// If we can't find the tank exit out
	if (!Tank) { return; }

	// Get the player's location this frame
	auto PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

	// Aim at the player's location
	Tank->AimAt(PlayerLocation);

	// Shoot at the player
	Tank->Fire();
}


