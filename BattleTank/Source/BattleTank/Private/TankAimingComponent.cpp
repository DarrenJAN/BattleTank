// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector Hitlocation,float LaunchSpeed){
	if(!Barrel) {return;}

	auto OurTankName = GetOwner()->GetName();
	auto BarrelLocation = Barrel->GetComponentLocation().ToString();
	// UE_LOG(LogTemp, Warning, TEXT("%s is aiming at this HitLocation is: %s  from the Barrel location: %s,"), *OurTankName, *Hitlocation.ToString(), *BarrelLocation);
	// UE_LOG(LogTemp, Warning, TEXT("Launch Speed is %f"),LaunchSpeed );

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	//Calculate the OutLaunchVelocity 
	bool suggestResult = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation, 
		Hitlocation,
		LaunchSpeed,
		false,
		0,
		0, 
		ESuggestProjVelocityTraceOption::DoNotTrace
		);

	if( suggestResult) {
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		UE_LOG(LogTemp, Warning, TEXT("%s is aiming at %s"),*OurTankName, *AimDirection.ToString());
	}

	
	
}


void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * Barrel){
	this->Barrel = Barrel;
}