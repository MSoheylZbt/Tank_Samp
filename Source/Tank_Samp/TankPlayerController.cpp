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

ATAnk* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATAnk>(GetPawn());
}