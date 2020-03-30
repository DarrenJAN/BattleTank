// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
class ATank;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;

	//start the tank moving the barrel so that a show would hit where 
	// the cross heads
	void AimTowardCrossHair();
	
	//return an OUT parameter, true if hit landscape 
	bool GetSightRayHitLocation(FVector& Outlocation) const;

	//Convert 2D screen position to World Space 3D position and direction.
	bool GetLookDirection(FVector2D ScreenLocation, FVector& WorldLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const;

private:
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;
};
