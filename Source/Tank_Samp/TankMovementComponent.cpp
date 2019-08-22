// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"
#include "TankTrackComponent.h"

void UTankMovementComponent::MoveForward(float Throw)
{
	/*UE_LOG(LogTemp, Warning, TEXT("Throw is : %f"), Throw)*/
	if (!ensure(LeftTrack || !RightTrack))	{ return; }
	LeftTrack->ThrottleSet(Throw);
	RightTrack->ThrottleSet(Throw);
}

void UTankMovementComponent::RotateRight(float Throw)
{
	//UE_LOG(LogTemp, Warning, TEXT("Throw is : %f"), Throw)
	if (!ensure(LeftTrack || !RightTrack)) { return; }
	LeftTrack->ThrottleSet(Throw);
	RightTrack->ThrottleSet(-Throw);
}


void UTankMovementComponent::TrackSetter(UTankTrackComponent* RightTrackToSet, UTankTrackComponent* LeftTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto WhereToGo = MoveVelocity.GetSafeNormal();
	auto WhereItIs = GetOwner()->GetActorForwardVector().GetSafeNormal();
	//UE_LOG(LogTemp, Warning, TEXT("%s Move Toward %s "), *GetOwner()->GetName(), *MoveVelocity.ToString())
	auto DotProductProjection =  FVector::DotProduct(WhereToGo, WhereItIs);
	MoveForward(DotProductProjection);
	auto CrossProductVector = FVector::CrossProduct(WhereToGo , WhereItIs);
	RotateRight(CrossProductVector.Z);
}
