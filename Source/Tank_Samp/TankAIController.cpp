// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include"Navigation/PathFollowingComponent.h"
#include "GameFramework/Actor.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TankAim = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	auto PlayerTank = Cast<AActor>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank)
	{
		auto Condition = MoveToActor(PlayerTank, AIAndPlayerDistance, true, true, true);
		if (Condition == EPathFollowingRequestResult::AlreadyAtGoal)
		{
			
			UE_LOG(LogTemp, Error, TEXT("%f : AlreadyAtGoal"), GetWorld()->GetTimeSeconds())
		}
		if (!ensure(TankAim)) { return; }
		TankAim->AimAt(PlayerTank->GetActorLocation());
		if (TankAim->GetFireState() == EAimState::Locked)
		{
			TankAim->Fire();
		}
	}
}

