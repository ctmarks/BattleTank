// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "SprungWheel.h"
#include "SpawnPoint.h"


UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
}

TArray<ASprungWheel*> UTankTrack::GetWheels() const
{
	TArray<USceneComponent*> SpawnPoints;
	GetChildrenComponents(false, SpawnPoints);

	TArray<ASprungWheel*> SprungWheels;
	for (USceneComponent* SpawnPoint : SpawnPoints)
	{
		SprungWheels.Add(Cast<ASprungWheel>(Cast<USpawnPoint>(SpawnPoint)->GetWheel()));
	}
	return SprungWheels;
}

void UTankTrack::SetThrottle(float Throttle)
{
	float CurrentThrottle = FMath::Clamp<float>(Throttle, -1, 1);
	DriveTrack(CurrentThrottle);
}

void UTankTrack::DriveTrack(float CurrentThrottle)
{
	auto ForceApplied = CurrentThrottle * TrackMaxDrivingForce;
	auto Wheels = GetWheels();
	auto ForcePerWheel = ForceApplied / Wheels.Num();
	for (ASprungWheel* Wheel : Wheels) 
	{
		Wheel->AddDrivingForce(ForcePerWheel);
	}
}