// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TAnk.h"
#include "GameFramework/Actor.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	AITank = Cast<ATAnk>(GetPawn());
	PlayerTank = Cast<ATAnk>(GetWorld()->GetFirstPlayerController()->GetPawn());

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (PlayerTank)
	{
		MoveToActor(PlayerTank,AIandPlayerDistance);
		AITank->Aimtat(PlayerTank->GetActorLocation());
		AITank->Fire();
		
	}
}

