// Fill out your copyright notice in the Description page of Project Settings.

#include "TAnk.h"
#include "TankAimingComponent.h"
#include "BarrelComponent.h"
#include "TankMovementComponent.h"
#include "Projectile.h" //if doesn't included there will no error but Fire will not work !

// Sets default values
ATAnk::ATAnk()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TankAimComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aim Component"));
}

void ATAnk::Aimtat(FVector HitLocation)
{
	TankAimComponent->AimAt(HitLocation,LaunchSpeed);
}

void ATAnk::BarrelSetter(UBarrelComponent* BarrelToSet)
{
	TankAimComponent->BarrelSetter(BarrelToSet);
	BarrelForProjectile = BarrelToSet;
}

void ATAnk::TurretSetter(UTurretComponent* TurretToSet)
{
	TankAimComponent->TurretSetter(TurretToSet);
}


void ATAnk::Fire()
{
	bool bIsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTime;
	if (BarrelForProjectile && bIsReloaded)
	{
		auto Projecctile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint,
			BarrelForProjectile->GetSocketLocation(FName("Projectile")),
			BarrelForProjectile->GetSocketRotation(FName("Projectile"))
			);
		Projecctile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}

// Called when the game starts or when spawned
void ATAnk::BeginPlay()
{
	Super::BeginPlay();
}


// Called to bind functionality to input
void ATAnk::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

