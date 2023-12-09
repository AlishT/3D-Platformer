// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ActorMoverAlongSplineComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UNREALENGINEHOUROFCODE_API UActorMoverAlongSplineComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	UActorMoverAlongSplineComponent();

public:
	float Timer = 0.f;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Timer")
	float StartAtProgress = 0.f;
	
	UPROPERTY(BlueprintReadWrite)
	USplineComponent* SplineComponent = nullptr;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void MoveAtSpline();

	UFUNCTION(BlueprintCallable)
	void SetSpline(USplineComponent* Spline);


};

