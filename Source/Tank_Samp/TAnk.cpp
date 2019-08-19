// Fill out your copyright notice in the Description page of Project Settings.

#include "TAnk.h"

// Sets default values
ATAnk::ATAnk()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}
// Called when the game starts or when spawned
void ATAnk::BeginPlay()
{
	Super::BeginPlay();
}
// Called to bind functionality to input
void ATAnk::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

