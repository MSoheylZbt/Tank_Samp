// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "TAnk.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class TANK_SAMP_API ATAnk : public APawn
{
	GENERATED_BODY()

public:
	// Call Automaticly by engine when damage applied to Tank
	float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	UFUNCTION(BlueprintPure, Category = "Health stuff")
	float GetCurrentHealthPercent();
	FTankDelegate OnDeath;
	
private:
	UPROPERTY(EditAnywhere,Category = "Health stuff")
	int32 Health = 100;
	UPROPERTY(VisibleAnywhere, Category = "Health stuff")
	int32 CurrentHealth;
	virtual void BeginPlay() override;
	ATAnk();
	
};