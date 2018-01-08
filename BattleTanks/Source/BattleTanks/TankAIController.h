// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;

/**
 * Controls the AI actions
 */
UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:
	
	virtual void BeginPlay() override;

	// How close can the AI tank get to the player
	float AcceptanceRadius = 3000;

	UTankAimingComponent* AimingComponent;

public:
	virtual void Tick(float DeltaTime) override;

};
