// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TAnk.h"
#include "AIController.h"
#include "GameFramework/Actor.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class TANK_SAMP_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;


	AActor* GetAITank() const;
	AActor* GetPlayerTank() const;
};
