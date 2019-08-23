// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrackComponent.h"

UTankTrackComponent::UTankTrackComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UTankTrackComponent::BeginPlay()
{
	OnComponentHit.AddDynamic(this, &UTankTrackComponent::OnHit);
}

void UTankTrackComponent::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse,
	const FHitResult& Hit)
{
	//UE_LOG(LogTemp,Warning,TEXT("OnHit"))
	TrackMove();
	AddSidewayForce();
	CurrentThrottle = 0;
}



void UTankTrackComponent::ThrottleSet(float Throttle)
{
	
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle+Throttle,-2,2);
}


void UTankTrackComponent::AddSidewayForce()
{
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	auto Accelration = -SlippageSpeed / DeltaTime * GetRightVector();
	auto RootTank = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = RootTank->GetMass() * Accelration;
	AddForce(CorrectionForce / 2);
}

void UTankTrackComponent::TrackMove()
{

	auto ForceVector = GetForwardVector() * CurrentThrottle * MaxForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	if (!ensure(TankRoot)) { return; }
	TankRoot->AddForceAtLocation(ForceVector, ForceLocation);

}