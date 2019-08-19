// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "TAnk.h"
#include "GameFramework/Actor.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	AITank = Cast<ATAnk>(GetPawn());
	PlayerTank = Cast<ATAnk>(GetWorld()->GetFirstPlayerController()->GetPawn());
	TankAim = AITank->FindComponentByClass<UTankAimingComponent>();

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (PlayerTank)
	{
		MoveToActor(PlayerTank,AIandPlayerDistance);
		if (!ensure(TankAim)) { return; }
		TankAim->AimAt(PlayerTank->GetActorLocation());
		AITank->Fire();
		
	}
}

