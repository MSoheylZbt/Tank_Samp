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
class AProjectile;
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


	UFUNCTION(BlueprintCallable , Category = "Setup")
	void BarrelAndTurretSetter(UBarrelComponent* BarrelToSet, UTurretComponent* TurretToSet);


	UPROPERTY(BlueprintReadOnly)
	EAimState FireState = EAimState::Reloading;

#pragma region FireProjectileNeed
	UPROPERTY(EditAnywhere, Category = "Setup")
	float LaunchSpeed = 6000;
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	TSubclassOf<AProjectile> ProjectileBlueprint;
	float ReloadTime = 3;
	double LastFireTime = 0;
	UFUNCTION(BlueprintCallable,Category = "Setup" )
	void Fire();
#pragma endregion



private:
	UBarrelComponent* Barrel = nullptr;
	UTurretComponent* Turret = nullptr;
	FVector AimDirection;

	void MoveBarrelAndTurret(FVector);

	bool IsBarrelMoving();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void BeginPlay() override;
};
