// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "TankAimingComponent.h"
#include"TAnk.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto AimComponent = GetControlledTank()->FindComponentByClass<UTankAimingComponent>();
	if (AimComponent)
	{
		FindAimingComponent(AimComponent);
	}
	else
	{
		UE_LOG(LogTemp,Error,TEXT("Aim Component not Found !"))
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}



ATAnk* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATAnk>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!ensure(GetControlledTank())) { return; }
	FVector Hitlocation;
	if (GetSightRayLocation(Hitlocation))
	{
		if (!ensure(GetControlledTank())) { return; }
		GetControlledTank()->Aimtat(Hitlocation);
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
		GetLookVectorHitLocation(OutHitResult, LookDir);
	}

	return true;
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
