// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (!GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("GetControlledTank Doesn't Work !"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Pawn Name it's : %s"), *GetControlledTank()->GetName())
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
	if (!GetControlledTank()) { return; }
	FVector Hitlocation;
	if (GetSightRayLocation(Hitlocation))
	{
	}
}

bool ATankPlayerController::GetSightRayLocation(FVector& OutHitResult)
{
	
	//LineTrace toward the crosshair and identify objects
	//Get hited object and OUT it

	//get crosshair location on screen
	int32 ViewportXSize, ViewPortYSize;
	GetViewportSize(ViewportXSize, ViewPortYSize);
	auto ScreenLocation = FVector2D(CrossHairXLocation*ViewportXSize, CrossHairYLocation*ViewPortYSize);
	UE_LOG(LogTemp, Warning, TEXT("Look Direction is : %s"), *ScreenLocation.ToString())

	return true;
}

//FHitResult Hit;
//FVector BeginLocation;
//FRotator BeginRotation;
//GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(BeginLocation, BeginRotation);

//FVector LineTraceEnd = BeginLocation + (BeginRotation.Vector() * 10000);
//FCollisionQueryParams QPar (FName(TEXT("")), false, GetOwner());

//GetWorld()->LineTraceSingleByObjectType(
//	Hit,
//	BeginLocation
//	, LineTraceEnd
//	, FCollisionObjectQueryParams(ECollisionChannel::ECC_Pawn), QPar);