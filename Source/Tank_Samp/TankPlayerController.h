// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TAnk.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANK_SAMP_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATAnk* GetControlledTank() const;
	virtual void BeginPlay() override;
	
};
