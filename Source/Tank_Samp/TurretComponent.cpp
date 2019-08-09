// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretComponent.h"

void UTurretComponent::RotateTurret(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = RelativeSpeed * MaxDegreePerSecond * GetWorld()->GetDeltaSeconds();
	auto NewRotation = RelativeRotation.Yaw + RotationChange;
	auto Rotation = RelativeSpeed = FMath::Clamp<float>(NewRotation,MinRotation,MaxRotation);
	SetRelativeRotation(FRotator(0, NewRotation, 0));
}