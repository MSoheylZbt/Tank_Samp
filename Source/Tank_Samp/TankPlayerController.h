// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
class ATAnk;
UCLASS()
class TANK_SAMP_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.3333;
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;


	ATAnk* GetControlledTank() const;
	void AimTowardsCrosshair();
	bool GetSightRayLocation(FVector&);
	bool ConvertScreenPosToWorldDirection(FVector2D, FVector&) const;
	bool GetLookVectorHitLocation(FVector&,FVector) const ;

};
