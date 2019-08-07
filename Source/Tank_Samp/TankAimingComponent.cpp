// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"

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
	bool bIsAiming = UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, HitLoc, LaunchSpeed, false, 0.0f, 0.0f
		, ESuggestProjVelocityTraceOption::DoNotTrace);
	if (bIsAiming)
	{
		auto LaunchVelocityUnit = OutLaunchVelocity.GetSafeNormal().ToString();
		auto TankName = GetOwner()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s Barrel Should Target %s"), *TankName, *LaunchVelocityUnit)
		//MoveBarrel
			//take Unit vector
			//rotate the barrel to taken vector position.
	}

}
#pragma endregion

void UTankAimingComponent::BarrelSetter(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

