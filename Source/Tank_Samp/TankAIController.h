// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AiController.h"
#include "TankAIController.generated.h"

#pragma region ForwardDecelartion
class ATAnk;
#pragma endregion




UCLASS()
class TANK_SAMP_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
private:
	ATAnk* GetAITank() const;
	ATAnk* GetPlayerTank() const;
};
