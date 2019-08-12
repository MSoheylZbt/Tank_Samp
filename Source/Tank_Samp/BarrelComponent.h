// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "BarrelComponent.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANK_SAMP_API UBarrelComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Elevate(float);
	
private:
	UPROPERTY(EditDefaultsOnly,Category = Setup)
	float MaxElevationDegree = 30.0f;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinElevationDegree = 0.0f;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreePerSecond = 10.0f;
};
