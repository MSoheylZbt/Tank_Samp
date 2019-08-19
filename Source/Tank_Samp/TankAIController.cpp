// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "GameFramework/Actor.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	TankAim = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	Super::Tick(DeltaTime);
	if (PlayerTank)
	{
		MoveToActor(PlayerTank,AIandPlayerDistance);
		if (!ensure(TankAim)) { return; }
		TankAim->AimAt(PlayerTank->GetActorLocation());
		//TODO Read up TODO , and fix firing
		TankAim->Fire();
	}
}

