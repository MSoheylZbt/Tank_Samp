// Fill out your copyright notice in the Description page of Project Settings.


#include "SpringWheel.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"


void ASpringWheel::OntHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ApplyForce();
}

// Sets default values
ASpringWheel::ASpringWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickGroup = TG_PostPhysics;

	MassWheelConst = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("PhysConst"));
	SetRootComponent(Cast<UStaticMeshComponent>(MassWheelConst));

	Axel = CreateDefaultSubobject<USphereComponent>(FName("Axel"));
	Axel->SetupAttachment(MassWheelConst);

	Charkh = CreateDefaultSubobject<USphereComponent>(FName(" Wheel"));
	Charkh->SetupAttachment(Axel);

	AxelWheelConst = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("AxelWheelConst"));
	AxelWheelConst->SetupAttachment(Axel);

}

// Called when the game starts or when spawned
void ASpringWheel::BeginPlay()
{
	Super::BeginPlay();
	Charkh->SetNotifyRigidBodyCollision(true);
	Charkh->OnComponentHit.AddDynamic(this, &ASpringWheel::OntHit);
	ConstraintSet();

}

void ASpringWheel::AddDrivingForce(float ForcePercent) // Force Percent is between 0 and 1
{
	TotalForcePercentThisFrame += ForcePercent;
}



void ASpringWheel::ConstraintSet()
{
	if (!GetAttachParentActor()) return;
	auto RootMesh = Cast<UPrimitiveComponent>(GetAttachParentActor()->GetRootComponent());
	if (!RootMesh) return;
	MassWheelConst->SetConstrainedComponents(RootMesh, NAME_None, Axel, NAME_None);
	AxelWheelConst->SetConstrainedComponents(Axel, NAME_None, Charkh, NAME_None);
}

// Called every frame
void ASpringWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetWorld()->TickGroup == TG_PostPhysics)
	{
		TotalForcePercentThisFrame = 0;
	}
}

void ASpringWheel::ApplyForce()
{
	Charkh->AddForce(Axel->GetForwardVector() * TotalForcePercentThisFrame);
}