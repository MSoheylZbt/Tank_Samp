// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TurretComponent.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANK_SAMP_API UTurretComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = TurretSetup)
	float MaxDegreePerSecond = 10.0f;
	UPROPERTY(EditAnywhere, Category = TurretSetup)
	float MaxRotation = 90.0f;
	UPROPERTY(EditAnywhere, Category = TurretSetup)
	float MinRotation = -90.0f;
public:
	void RotateTurret(float);
};
