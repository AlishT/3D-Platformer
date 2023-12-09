// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TextRenderComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/SphereComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/ArrowComponent.h"
#include "PaperSpriteComponent.h"
#include "Checkpoint.generated.h"


UCLASS()
class UNREALENGINEHOUROFCODE_API ACheckpoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACheckpoint();

	UPROPERTY(EditDefaultsOnly, Category = "Default")
	UStaticMeshComponent* Button = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Default")
	USphereComponent* CollisionSphere = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Default")
	UTextRenderComponent* Message = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Default")
	UStaticMeshComponent* ButtonARing = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	UPaperSpriteComponent* CheckpointTransform = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Default")
	UArrowComponent* Arrow = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Default", meta = (Multiline = "true"))
	UMaterialInstanceDynamic* DynamicMaterial = nullptr;
	
	UPROPERTY(EditDefaultsOnly, Category = "Default")
	UMaterialInterface* Material = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Default", meta = (Multiline = "true"))
	bool bCheckpointEnabled = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	void OnConstruction(const FTransform& Transform) override;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& Hit);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateSpawnTransform(FTransform Transform);
};
