// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "ActorMoverAlongSplineComponent.h"
#include "FlyingIslandsAlongSpline.generated.h"

UCLASS()
class UNREALENGINEHOUROFCODE_API AFlyingIslandsAlongSpline : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlyingIslandsAlongSpline();

	UPROPERTY(VisibleAnywhere, Category = "RootComponent")
	USceneComponent* DefaultSceneRoot = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category = "SplineComponent")
	USplineComponent* Spline = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
