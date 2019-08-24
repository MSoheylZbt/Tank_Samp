// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "TAnk.generated.h"





UCLASS()
class TANK_SAMP_API ATAnk : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATAnk();
	// Call Automaticly by engine when damage applied to Tank
	float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	
private:
	UPROPERTY(EditAnywhere,Category = "Health stuff")
	int32 Health = 100;
	UPROPERTY(VisibleAnywhere, Category = "Health stuff")
	int32 CurrentHealth = Health;
	virtual void BeginPlay() override;
};