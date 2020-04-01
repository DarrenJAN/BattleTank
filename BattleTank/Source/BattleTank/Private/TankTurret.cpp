// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(float Relativespeed){
    //Move the barrel the right amount this frame	
    //Given a max Rotation speed, and the frame time

    Relativespeed  = FMath::Clamp<float>(Relativespeed,-1,1);
    auto RotationChange = Relativespeed * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds;
    auto RawNewRotation = RelativeRotation.Yaw + RotationChange;

    SetRelativeRotation(FRotator(0,RawNewRotation,0));
    // UE_LOG(LogTemp, Warning, TEXT("Elevate function called"));
}