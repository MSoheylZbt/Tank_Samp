// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretComponent.h"

void UTurretComponent::RotateTurret(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = RelativeSpeed * MaxDegreePerSecond * GetWorld()->GetDeltaSeconds();
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, Rotation, 0));
}