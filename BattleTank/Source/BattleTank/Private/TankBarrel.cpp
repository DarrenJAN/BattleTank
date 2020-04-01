// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::Elevate(float Relativespeed){
    //Move the barrel the right amount this frame	
    //Given a max elevation speed, and the frame time

    Relativespeed  = FMath::Clamp<float>(Relativespeed,-1,1);
    auto ElevationChange = Relativespeed * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds;
    auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
    auto RawNew = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

    SetRelativeRotation(FRotator(RawNew,0,0));
    // UE_LOG(LogTemp, Warning, TEXT("Elevate function called"));
}