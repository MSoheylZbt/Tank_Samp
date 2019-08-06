// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	
	Super::BeginPlay();
	if (!GetAITank())
	{
		UE_LOG(LogTemp,Error, TEXT("GetAITank Doesn't Work !"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Ai Pawn name is : %s"), *GetAITank()->GetName())
	}

	if (!GetPlayerTank())
	{
		UE_LOG(LogTemp,Error,TEXT("GetPlayerTank Doesn't Work!"))
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("Player Tank name is : %s"),*GetPlayerTank()->GetName())
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetAITank())
	{
		GetAITank()->Aimtat(GetPlayerTank()->GetActorLocation());
	}
}



ATAnk* ATankAIController::GetAITank() const
{
	return Cast<ATAnk>(GetPawn());
}

ATAnk* ATankAIController::GetPlayerTank() const
{
	
	return Cast<ATAnk>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
