// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrackComponent.h"
#include "SpringWheel.h"
#include "SpawnComponent.h"

UTankTrackComponent::UTankTrackComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankTrackComponent::ThrottleSet(float Throttle)
{
	float CurrentThrottle = FMath::Clamp<float>(Throttle,-2,2);
	TrackMove(CurrentThrottle);
}


void UTankTrackComponent::TrackMove(float CurrentThrottle)
{

	auto ForceApplied = CurrentThrottle * MaxForce;
	auto Wheels = GetWheels();
	auto ForcePerWheel = ForceApplied / Wheels.Num();
	for (ASpringWheel* Wheel : Wheels)
	{
		Wheel->AddDrivingForce(ForcePerWheel);
	}
}

TArray<ASpringWheel*> UTankTrackComponent::GetWheels() const
{
	TArray <ASpringWheel*> ResultArray;
	TArray <USceneComponent*> Children;
	GetChildrenComponents(true, Children);
	for (USceneComponent* Child : Children)
	{
		auto SpawnPointChild = Cast<USpawnComponent>(Child);
		if (!SpawnPointChild) { continue; }

		AActor* SpawnChild = SpawnPointChild->GetSpawnActor();
		auto SpringWheel = Cast<ASpringWheel>(SpawnChild);
		if (!SpringWheel) { continue; }
		ResultArray.Add(SpringWheel);
	}
	return ResultArray;
}