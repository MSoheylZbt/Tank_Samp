// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "TAnk.generated.h"

#pragma region ForwardDecelartion
class UBarrelComponent;
class UTankAimingComponent;
class UTurretComponent;
class AProjectile;
#pragma endregion



UCLASS()
class TANK_SAMP_API ATAnk : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATAnk();
	void Aimtat(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void BarrelSetter(UBarrelComponent* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void TurretSetter(UTurretComponent* TurretToSet);

	UFUNCTION(BlueprintCallable)
		void Fire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UTankAimingComponent* TankAimComponent = nullptr;

public:

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 6000;
	UPROPERTY(EditAnywhere, Category = Firing)
	TSubclassOf<AProjectile> ProjectileBlueprint;
	UBarrelComponent* BarrelForProjectile;
};