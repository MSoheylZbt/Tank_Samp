// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "BarrelComponent.h"
#include "Projectile.h"
#include "TurretComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

EAimState UTankAimingComponent::GetFireState(){ return FireState; }


#pragma region AimAt Method
void UTankAimingComponent::AimAt(FVector HitLoc)
{
	//auto BarrelLocation = Barrel->GetComponentLocation().ToString();
	if (!ensure(Barrel)) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bIsAiming = UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, HitLoc, LaunchSpeed
		, false,0,0,ESuggestProjVelocityTraceOption::DoNotTrace);

	if (bIsAiming)
	{ 
		AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelAndTurret(AimDirection);	
	}
}

#pragma endregion


void UTankAimingComponent::BarrelAndTurretSetter(UBarrelComponent* BarrelToSet, UTurretComponent* TurretToSet)
{
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

int UTankAimingComponent::GetAmmo() { return Ammo; }

void UTankAimingComponent::MoveBarrelAndTurret(FVector TargetLocation)
{
	auto BarrelAimRotator = TargetLocation.Rotation();
	auto BarrelCurrentRotation = Barrel->GetForwardVector().Rotation();
	auto Delta = BarrelAimRotator - BarrelCurrentRotation;
	Barrel->Elevate(Delta.Pitch);
	if (FMath::Abs(Delta.Yaw) > 180)
	{
		Turret->RotateTurret(-Delta.Yaw);
	}
	else
	{
		Turret->RotateTurret(Delta.Yaw);
	}
}

void UTankAimingComponent::Fire()
{
	if (!ensure(Barrel)) { return; }
	if (FireState == EAimState::Locked || FireState == EAimState::Aiming)
	{
		auto Projecctile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);
		if (!ensure(Projecctile)) { return; }
		Projecctile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
		Ammo--;
	}
}
void UTankAimingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	if(Ammo == 0)
	{
		FireState = EAimState::OutOfAmmo;
	}
	else if ((FPlatformTime::Seconds() - LastFireTime) < ReloadTime)
	{
		FireState = EAimState::Reloading;
	}
	else if(IsBarrelMoving())
	{
		FireState = EAimState::Aiming;
	}
	else
	{
		FireState = EAimState::Locked;
	}
}

void UTankAimingComponent::BeginPlay()
{
	LastFireTime = FPlatformTime::Seconds();
}
bool UTankAimingComponent::IsBarrelMoving()
{
	if (!ensure(Barrel)) { return false; }
	return !(AimDirection.Equals(Barrel->GetForwardVector(), 0.01f));
}