// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrackComponent.generated.h"

class ASpringWheel;


UCLASS(meta = (BlueprintSpawnableComponent))
class TANK_SAMP_API UTankTrackComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable , Category = Throttle)	
	void ThrottleSet(float Throttle);
protected:
	UPROPERTY(EditDefaultsOnly)
	float MaxForce = 60000000.0;
private:
	UTankTrackComponent();

	void TrackMove(float CurrentThrottle);
	TArray<ASpringWheel*> GetWheels() const;
};
