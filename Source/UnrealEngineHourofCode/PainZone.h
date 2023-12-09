// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "BaseCharacter.h"
#include "PainZone.generated.h"

UCLASS()
class UNREALENGINEHOUROFCODE_API APainZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APainZone();

	UPROPERTY(EditDefaultsOnly, Category = "PainZone")
	UBoxComponent* PainZone = nullptr;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
	float Damage;

	UPROPERTY(EditDefaultsOnly, Category = "Timer")
	float Time;

	UPROPERTY()
	ABaseCharacter* Player = nullptr;

	UPROPERTY()
	FTimerHandle Handle;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& Hit);

	UFUNCTION()
	void RepeatingFunction();

};
