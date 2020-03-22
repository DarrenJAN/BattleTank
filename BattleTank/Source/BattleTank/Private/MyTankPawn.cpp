// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTankPawn.h"

// Sets default values
AMyTankPawn::AMyTankPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyTankPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTankPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyTankPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

