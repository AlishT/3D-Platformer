// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorMoverComponent.h"
#include "MovingPlatform.generated.h"

UCLASS()
class UNREALENGINEHOUROFCODE_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

	UPROPERTY(EditDefaultsOnly, Category = "Mesh")
	UStaticMeshComponent* Mesh = nullptr;

	UPROPERTY(EditDefaultsOnly)
	UActorMoverComponent* ActorMoverComponent = nullptr;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
