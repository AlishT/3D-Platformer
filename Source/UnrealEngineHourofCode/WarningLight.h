// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/PointLightComponent.h>
#include <Components/BoxComponent.h>
#include "BaseCharacter.h"
#include "WarningLight.generated.h"


UCLASS()
class UNREALENGINEHOUROFCODE_API AWarningLight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWarningLight();

	UPROPERTY(EditDefaultsOnly, Category = "WarnigLight")
	UPointLightComponent* WarningLight = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "PainZone")
	UBoxComponent* WarningZone = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*UPROPERTY(EditDefaultsOnly, Category = "Brightness")
	int32 Brightness;*/

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& Hit);

	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComp, 
		AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex);

};
