// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	


public:
	void Elevate(float DegreesPerSecond);

private:
	UPROPERTY(Editanywhere)
	float MaxDegreePerSecond = 20; // Sensible default

	UPROPERTY(Editanywhere)	
	float MaxElevationDegrees = 40; // Sensible default

	UPROPERTY(Editanywhere)
	float MinElevationDegrees = 0; // Sensible default

};
