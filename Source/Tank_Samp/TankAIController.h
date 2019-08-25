// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AiController.h"
#include "TankAIController.generated.h"

#pragma region ForwardDecelartion
class UTankAimingComponent;
#pragma endregion




UCLASS()
class TANK_SAMP_API ATankAIController : public AAIController
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
	float AIAndPlayerDistance = 1.0;
	UTankAimingComponent* TankAim;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void SetPawn(APawn* InPawn) override;
	UFUNCTION()
	void OnTankDeath();
};
