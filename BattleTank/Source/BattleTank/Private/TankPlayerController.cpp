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
    // );
}


bool ATankPlayerController::GetSightRayHitLocation(FVector& Hitlocation) const {
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);

    auto ScreenLocation = FVector2D(ViewportSizeX *  CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
    //Check
    // UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString());
    
    //Convert 2D screen position to World Space 3D position and direction.
    FVector  WorldLocation; // Ignore this because it is the camera's World Location but it is not needed.
    FVector  WorldDirection;
 
   if(GetLookDirection(ScreenLocation, WorldLocation, WorldDirection)){
       //Check
       //UE_LOG(LogTemp, Warning, TEXT("WorldDirection: %s"), *WorldDirection.ToString());

       //Line-Trace along that LookDirection, and see what we hit up (up to max range)
        GetLookVectorHitLocation(WorldDirection,Hitlocation);
   }

   
    return true;
}

//Convert 2D screen position to World Space 3D position and direction.
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation ,FVector&  WorldLocation, FVector& LookDirection) const{
   return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);
}


bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const{
    FHitResult hitresult;
    auto StartLocation = PlayerCameraManager->GetCameraLocation();
    auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
    //TRUE if a blocking hit is found
    if(GetWorld()->LineTraceSingleByChannel(
        hitresult,
        StartLocation,
        EndLocation, 
        ECollisionChannel::ECC_Visibility
    )){
        HitLocation = hitresult.Location;
        return true;
    } else {
        //False if a blocking hit is not found 
        HitLocation = FVector(0);
        return false;
    }
}