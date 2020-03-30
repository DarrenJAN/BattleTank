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
	//-1 is Max downward speed, and +1 is max up movement 
	void Elevate(float Relativespeed);

private:
	UPROPERTY(Editanywhere)
	float MaxDegreePerSecond = 5; // Sensible default

	UPROPERTY(Editanywhere)	
	float MaxElevationDegrees = 40; // Sensible default

	UPROPERTY(Editanywhere)
	float MinElevationDegrees = 0; // Sensible default

};
