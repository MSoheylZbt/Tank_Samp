// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TAnk.h"
#include "CoreMinimal.h"
#include "Engine/World.h"
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
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	ATAnk* GetControlledTank() const;
	void AimTowardsCrosshair();
	bool GetSightRayLocation(FVector&);
};
