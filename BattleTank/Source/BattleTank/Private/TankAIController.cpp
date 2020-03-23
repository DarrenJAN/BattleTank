// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"


void ATankAIController::BeginPlay() {
    Super::BeginPlay();

    auto PlayerTank = GetPlayerTank();
    if(!PlayerTank){
        UE_LOG(LogTemp, Warning, TEXT("Tank AI controller can not find player tank."));
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Tank AI controller found player: %s"), *PlayerTank->GetName());
    }
    
}

ATank* ATankAIController::GetControlledTank() const{
    return Cast<ATank>(GetPawn());
}


ATank* ATankAIController::GetPlayerTank() const{
    auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    if(!PlayerPawn) return nullptr;
    return Cast<ATank>(PlayerPawn);
}

