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





AActor* ATankAIController::GetAITank() const
{
	return Cast<ATAnk>(GetPawn());
}

AActor* ATankAIController::GetPlayerTank() const
{
	
	return Cast <ATAnk>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
