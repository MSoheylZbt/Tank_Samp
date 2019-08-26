// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "TAnk.h"
#include "TankAimingComponent.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	TankAim = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (TankAim)
	{
		FindAimingComponent(TankAim);
	}

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}




void ATankPlayerController::AimTowardsCrosshair()
{
	if (!ensure(GetPawn())) { return; }
	FVector Hitlocation;
	if (GetSightRayLocation(Hitlocation))
	{
		if (!ensure(TankAim)) { return; }
		TankAim->AimAt(Hitlocation);
	}
}
#pragma region GetSightRayLocation = Get the hited object.
bool ATankPlayerController::GetSightRayLocation(FVector& OutHitResult)
{
	
	//LineTrace toward the crosshair and identify objects
	//Get hited object and OUT it

	//get crosshair location on screen
	int32 ViewportXSize, ViewPortYSize;
	GetViewportSize(ViewportXSize, ViewPortYSize);
	auto ScreenLocation = FVector2D(CrossHairXLocation*ViewportXSize, CrossHairYLocation*ViewPortYSize);

	//Convert Crosshair Location on screen to 3D world direction
	FVector LookDir;
	if (ConvertScreenPosToWorldDirection(ScreenLocation, LookDir))
	{
		return GetLookVectorHitLocation(OutHitResult, LookDir);
	}

	return false;
}

#pragma endregion

bool ATankPlayerController::ConvertScreenPosToWorldDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}


bool ATankPlayerController::GetLookVectorHitLocation(FVector& HitLocation,FVector LookDirection) const
{
	FHitResult Hit;
	FVector BeginLocation = PlayerCameraManager->GetCameraLocation();
	FVector LineTraceEnd = BeginLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(Hit, BeginLocation, LineTraceEnd, ECollisionChannel::ECC_Visibility))
	{
		HitLocation = Hit.Location;
		return true;
	}
	HitLocation = FVector(0.0);
	return false;
}

void ATankPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossesedTank = Cast<ATAnk>(InPawn);
		if (!ensure(PossesedTank)) { return; }
		PossesedTank->OnDeath.AddUniqueDynamic(this,&ATankPlayerController::OnTankDie);
	}
}

void ATankPlayerController::OnTankDie()
{
	StartSpectatingOnly();
}
