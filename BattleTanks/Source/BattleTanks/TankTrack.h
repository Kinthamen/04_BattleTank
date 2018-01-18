// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Handles track actions and sets track static mesh
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// Sets a throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category = Input)
		void SetThrottle(float Throttle);
	
	// Max force per track in Newtons
	UPROPERTY(EditDefaultsOnly, Category = Input)
		float TrackMaxDrivingForce = 400000; // Assume 40 ton tank and 1g acceleration

private:
	UTankTrack();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

protected:

	virtual void BeginPlay() override;

	void ApplySidewaysForce();
	void DriveTrack();

	float CurrentThrottle = 0;
};
