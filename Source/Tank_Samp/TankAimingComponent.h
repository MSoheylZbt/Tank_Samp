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
	Locked ,
	OutOfAmmo
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
	

	void AimAt(FVector);

	EAimState GetFireState();

	UFUNCTION(BlueprintCallable , Category = "Setup")
	void BarrelAndTurretSetter(UBarrelComponent* BarrelToSet, UTurretComponent* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	int GetAmmo();

#pragma region Fire Projectile Needed
	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 8000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTime = 3;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	int Ammo = 3;

	UFUNCTION(BlueprintCallable,Category = "Firing" )
	void Fire();

	double LastFireTime = 0;
#pragma endregion


private:
	UTankAimingComponent();
	void MoveBarrelAndTurret(FVector);
	bool IsBarrelMoving();

	UBarrelComponent* Barrel = nullptr;
	UTurretComponent* Turret = nullptr;
	FVector AimDirection;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void BeginPlay() override;
protected:
	UPROPERTY(BlueprintReadOnly)
	EAimState FireState = EAimState::Reloading;
};
