// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"

#pragma region ForwardDecelartion
class UBarrelComponent;
class UTurretComponent;
#pragma endregion



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANK_SAMP_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void AimAt(FVector,float);
	void BarrelSetter(UBarrelComponent* BarrelToSet);
	void TurretSetter(UTurretComponent* TurretToSet);

private:
	UBarrelComponent* Barrel = nullptr;
	UTurretComponent* Turret = nullptr;
	void MoveBarrel(FVector);
	void MoveTurret(FVector);
};
