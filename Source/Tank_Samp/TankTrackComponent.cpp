// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrackComponent.h"


void UTankTrackComponent::ThrottleMove(float Throttle)
{
	//auto Name = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("%s Throttle is : %f"), *Name, Throttle)
	auto ForceVector = GetForwardVector() * Throttle * MaxForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	if (!ensure(TankRoot)) {return;}
	TankRoot->AddForceAtLocation(ForceVector, ForceLocation);
}