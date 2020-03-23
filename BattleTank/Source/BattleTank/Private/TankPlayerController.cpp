// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
    Super::BeginPlay();

    auto ControlledTank = GetControlledTank();
    if(!ControlledTank){
        UE_LOG(LogTemp, Warning, TEXT("Tank player controller not possesing to a tank"));
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Tank player controller possesing: %s"), *ControlledTank->GetName());
    }
    
}

ATank* ATankPlayerController::GetControlledTank() const{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    AimTowardCrossHair();
}


void ATankPlayerController::AimTowardCrossHair(){
   
    if(! GetControlledTank()) {
        UE_LOG(LogTemp, Warning, TEXT("Tank player controller not possesing to a tank"));
        return;
    }
    
    FVector HitLocation;
    if(GetSightRayHitLocation(HitLocation)){
        UE_LOG(LogTemp, Warning, TEXT("HitLocation is: %s"), *HitLocation.ToString());
        //TODO Tank aim this Location
    }


    // GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
    //     PlayerViewPointLocation,
    //     PlayerViewRoation
    // };
}


bool ATankPlayerController::GetSightRayHitLocation(FVector& Outlocation) const {
    Outlocation = FVector(1.0);
    return true;
}