// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

// Called at the start of the game
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));

	// Get the pointer to tank pawn that the player controller is possesing
	auto ControlledTank = GetControlledTank();

	/// Null check the pointer to controlled tank, print error if it isn't there
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AIController not controlling a Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possesing: %s"), *ControlledTank->GetName());
	}

	// Get the pointer to the player controlled tank
	auto PlayerTank = GetPlayerTank();

	/// Null check the pointer to the player controlled tank, print the success or error
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AIController can't find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player tank: %s"), *PlayerTank->GetName());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}


