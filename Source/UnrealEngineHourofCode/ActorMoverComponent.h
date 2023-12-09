// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/KismetMathLibrary.h"
#include "ActorMoverComponent.generated.h"

UENUM(BlueprintType)
enum class EEasingType : uint8
{
	Linear,
	CircularIn,
	CircularInOut,
	CircularOut,
	EaseIn,
	EaseInOut,
	EaseOut,
	ExpoIn,
	ExpoInOut,
	ExpoOut,
	SinIn,
	SinInOut,
	SinOut,
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALENGINEHOUROFCODE_API UActorMoverComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActorMoverComponent();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Direction")
	FVector MovementDirection = FVector::ZeroVector;
	
	UPROPERTY()
	FVector StartLocation = FVector::ZeroVector;
	
	UPROPERTY()
	FVector TargetLocation = FVector::ZeroVector;

	UPROPERTY(EditDefaultsOnly, Category = "Distence")
	float DistanceToMove = 0.f;

	UPROPERTY(EditDefaultsOnly, Category = "Speed")
	float Speed = 0.f;

	float TimePassed = 0.f;

	float TimeToMove = 0.f;

	float Progress = 0.f;

	UPROPERTY()
	int32 MoveDirection = -1;
	
	UPROPERTY(Transient)
	AActor* CachedOwner = nullptr;

	UPROPERTY(EditAnywhere, Category = "Interp")
	EEasingType Interp = EEasingType::Linear;

	UPROPERTY(EditAnywhere, meta = (EditCondition =
		"MovementCurve == EEasingType::EaseIn || MovementCurve == EEasingType::EaseOut || MovementCurve == EEasingType::EaseInOut"))
	float MovementExponent = 3.f;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FVector GetNewPosition(EEasingType Type = EEasingType::Linear);
	
	void StartMoving();

};
