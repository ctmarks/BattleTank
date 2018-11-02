// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

// Sets default values
ATankPlayerController::ATankPlayerController()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called at the start of the game
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));

	// Get the pointer to tank pawn that the player controller is possesing
	auto ControlledTank = GetControlledTank();

	// Print the pointer if it isn't equal to nullptr
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController not controlling a Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing: %s"), *ControlledTank->GetName());
	}
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	// Get world location through linetrace through crosshair
	// If it hits the landscape
		// Tell controlled tank to aim at this point
}
