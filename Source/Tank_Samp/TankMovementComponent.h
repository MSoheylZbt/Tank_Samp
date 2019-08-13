// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrackComponent;

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANK_SAMP_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void MoveForward(float Throw);
	UFUNCTION(BlueprintCallable)
	void RotateRight(float Throw);
	UFUNCTION(BlueprintCallable)
	void TrackSetter(UTankTrackComponent* RightTrackToSet, UTankTrackComponent* LeftTrackToSet);
private:
	UTankTrackComponent* RightTrack;
	UTankTrackComponent* LeftTrack;
};
