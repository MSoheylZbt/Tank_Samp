// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "BarrelComponent.h"
#include "TurretComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

#pragma region AimAt methode
void UTankAimingComponent::AimAt(FVector HitLoc,float LaunchSpeed)
{
	//auto BarrelLocation = Barrel->GetComponentLocation().ToString();
	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bIsAiming = UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, HitLoc, LaunchSpeed
		, false,0,0,ESuggestProjVelocityTraceOption::DoNotTrace);

	auto Time = GetWorld()->GetTimeSeconds();
	if (bIsAiming)
	{
		auto LaunchVelocityUnit = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelAndTurret(LaunchVelocityUnit);
		//UE_LOG(LogTemp,Warning,TEXT("%f : it's Aiming !"),Time)
	}
	else
	{
		//UE_LOG(LogTemp, Error, TEXT("%f : it's not Aiming !"), Time)
	}
}
#pragma endregion

void UTankAimingComponent::BarrelSetter(UBarrelComponent* BarrelToSet)
{
	if (!BarrelToSet) { return; }
	Barrel = BarrelToSet;
}

void UTankAimingComponent::TurretSetter(UTurretComponent* TurretToSet)
{
	if (!TurretToSet) { return; }
	Turret = TurretToSet;
}

void UTankAimingComponent::MoveBarrelAndTurret(FVector TargetLocation)
{
	auto BarrelAimRotator = TargetLocation.Rotation();
	auto BarrelCurrentRotation = Barrel->GetForwardVector().Rotation();
	auto Delta = BarrelAimRotator - BarrelCurrentRotation;
	Barrel->Elevate(Delta.Pitch);
	Turret->RotateTurret(Delta.Yaw);
}


