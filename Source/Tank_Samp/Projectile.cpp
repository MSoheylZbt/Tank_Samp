// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "TimerManager.h"
#include "Engine/EngineTypes.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
	ProjectileMovement->bAutoActivate = false;

	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh"));
	SetRootComponent(Cast<USceneComponent>(CollisionMesh));
	CollisionMesh->SetNotifyRigidBodyCollision(false);
	CollisionMesh->SetVisibility(false);

	FireBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName(" Fire Particle"));
	FireBlast->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);

	HitBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName(" Hit Particle"));
	HitBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	HitBlast->bAutoActivate = false;

	HitForce = CreateDefaultSubobject<URadialForceComponent>(FName("Hit Force "));
	HitForce->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	CollisionMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
	
}

void AProjectile::LaunchProjectile(float LaunchSpeed)
{
	if (!ensure(ProjectileMovement)) { return; }
	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * LaunchSpeed);
	ProjectileMovement->Activate();
}
void AProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse,
	const FHitResult& Hit)
{
	FireBlast->Deactivate();
	HitBlast->Activate();
	HitForce->FireImpulse();

	SetRootComponent(Cast<USceneComponent>(FireBlast));
	CollisionMesh->DestroyComponent();

	UGameplayStatics::ApplyRadialDamage(this, HitDamage, GetActorLocation(), HitForce->Radius, UDamageType::StaticClass(), TArray<AActor*>());

	FTimerHandle TimeHandel;
	GetWorld()->GetTimerManager().SetTimer(TimeHandel, this, &AProjectile::DestroyProjectileDelegate, DestroyDelay);
	
}

void AProjectile::DestroyProjectileDelegate()
{
	/*this->*/Destroy();
}
