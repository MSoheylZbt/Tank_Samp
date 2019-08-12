// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrackComponent.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANK_SAMP_API UTankTrackComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
private:
	UFUNCTION(BlueprintCallable , Category = Throttle)	
	void ThrottleSetter(float Throttle);

	UPROPERTY(EditDefaultsOnly)
	float MaxForce = 400000;
	
};
