// Fill out your copyright notice in the Description page of Project Settings.

#include "TAnk.h"

// Sets default values
ATAnk::ATAnk()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}
float ATAnk::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	int32 DamagePoint = FMath::RoundToInt(Damage);
	float DamageToApply = FMath::Clamp(DamagePoint, 0, CurrentHealth);
	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT(" %s is Dead "), *GetName())
	}
	return DamageToApply;
}
// Called when the game starts or when spawned
void ATAnk::BeginPlay()
{
	Super::BeginPlay();
}


