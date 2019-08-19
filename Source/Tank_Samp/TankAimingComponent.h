// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EAimState : uint8
{
	Reloading,
	Aiming,
	Locked
};


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
	void AimAt(FVector);
	UPROPERTY(EditAnywhere,Category = "Setup")
	float LaunchSpeed = 6000;

	UFUNCTION(BlueprintCallable , Category = "Setup")
	void BarrelAndTurretSetter(UBarrelComponent* BarrelToSet, UTurretComponent* TurretToSet);


	UPROPERTY(BlueprintReadOnly)
		EAimState CurrentState = EAimState::Aiming;

private:
	UBarrelComponent* Barrel = nullptr;
	UTurretComponent* Turret = nullptr;
	void MoveBarrelAndTurret(FVector);
};
