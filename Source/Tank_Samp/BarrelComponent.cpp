// Fill out your copyright notice in the Description page of Project Settings.


#include "BarrelComponent.h"


void UBarrelComponent::Elevate(float RelativeSpeed)
{
	/*UE_LOG(LogTemp,Warning,TEXT("Barrel Elevate ! Degree : %f"),Degree)*/
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = RelativeSpeed * MaxDegreePerSecond*GetWorld()->DeltaTimeSeconds;
	auto NewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(NewElevation, MinElevationDegree, MaxElevationDegree);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}
