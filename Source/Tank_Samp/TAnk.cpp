// Fill out your copyright notice in the Description page of Project Settings.

#include "TAnk.h"
#include "BarrelComponent.h"
#include "Projectile.h" //if doesn't included there will no error but Fire will not work !

// Sets default values
ATAnk::ATAnk()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}



void ATAnk::Fire()
{
	if (!ensure(BarrelForProjectile)) { return; }
	bool bIsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTime;
	if (bIsReloaded)
	{
		//TODO Check Fire is work without below or not.
		

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
	BarrelForProjectile = FindComponentByClass<UBarrelComponent>();
}


// Called to bind functionality to input
void ATAnk::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

