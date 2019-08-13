// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"
#include "TankTrackComponent.h"

void UTankMovementComponent::MoveForward(float Throw)
{
	/*UE_LOG(LogTemp, Warning, TEXT("Throw is : %f"), Throw)*/
	if (!LeftTrack || !RightTrack)	{ return; }
	RightTrack->ThrottleMove(Throw);
	LeftTrack->ThrottleMove(Throw);
}

void UTankMovementComponent::RotateRight(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Throw is : %f"), Throw)
	if (!LeftTrack || !RightTrack) { return; }
	RightTrack->ThrottleMove(-Throw);
	LeftTrack->ThrottleMove(Throw);
}


void UTankMovementComponent::TrackSetter(UTankTrackComponent* RightTrackToSet, UTankTrackComponent* LeftTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}
