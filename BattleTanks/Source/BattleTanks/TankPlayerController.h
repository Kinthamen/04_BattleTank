// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

/**
 * Responsible for helping the player AIM
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector & HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.33333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const;
};
