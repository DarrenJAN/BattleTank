// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//no need to protect pointer as added at construction 
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
// void ATank::Tick(float DeltaTime)
// {
// 	Super::Tick(DeltaTime);

// }

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector Hitlocation){
	TankAimingComponent->AimAt(Hitlocation, LaunchSpeed);
}


void ATank::SetBarrelReference(UTankBarrel * Barrel){
	this->Barrel = Barrel;
	TankAimingComponent->SetBarrelReference(Barrel);
	
}

void ATank::SetTurretReference(UTankTurret * Turret){
	TankAimingComponent->SetTurretReference(Turret);
}


void ATank::Fire(){
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: Firing"),Time);

	if(!Barrel){	
		UE_LOG(LogTemp, Warning, TEXT("%f: no Barrel found"),Time);
		return;
	}

	//Spawn a projectile at socket location 
	GetWorld()->SpawnActor<AProjectile>(
		ProjectileBlueprint,
		Barrel->GetSocketLocation(FName("Projectile")),
		Barrel->GetSocketRotation(FName("Projectile"))
	);
}