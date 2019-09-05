// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpringWheel.generated.h"

class UPhysicsConstraintComponent;
class USphereComponent;

UCLASS()
class TANK_SAMP_API ASpringWheel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere, Category = "Spring")
	USphereComponent* Charkh = nullptr;
	UPROPERTY(VisibleAnywhere, Category = "Spring")
	USphereComponent* Axel = nullptr;
	UPROPERTY(VisibleAnywhere, Category = "Spring")
	UPhysicsConstraintComponent* MassWheelConst = nullptr;
	UPROPERTY(VisibleAnywhere, Category = "Spring")
	UPhysicsConstraintComponent* AxelWheelConst = nullptr;

	void AddDrivingForce(float);

private:
	void ConstraintSet();
	void ApplyForce();
	virtual void BeginPlay() override;

	UFUNCTION() /// Dont't Forget UFUNCTION() for Delegate !!!!
	void OntHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	float TotalForcePercentThisFrame = 0;
	ASpringWheel();
};
