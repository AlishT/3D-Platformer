// Fill out your copyright notice in the Description page of Project Settings.


#include "WarningLight.h"

// Sets default values
AWarningLight::AWarningLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	WarningLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Warning Light"));
	WarningLight->SetupAttachment(RootComponent);
	WarningLight->Intensity = 50000;
	WarningLight->SetVisibility(false, false);

	WarningZone = CreateDefaultSubobject<UBoxComponent>(TEXT("WarningZone"));
	WarningZone->SetupAttachment(RootComponent);
	
	WarningZone->OnComponentBeginOverlap.AddDynamic(this, &AWarningLight::OnBeginOverlap);
	
	WarningZone->OnComponentEndOverlap.AddDynamic(this, &AWarningLight::OnEndOverlap);
}

// Called when the game starts or when spawned
void AWarningLight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWarningLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWarningLight::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, 
	AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, 
	bool bFromSweep, 
	const FHitResult& Hit)
{
	//ABaseCharacter* Player = Cast<ABaseCharacter>(OtherActor);
	WarningLight->SetVisibility(true, false);
	
}

void AWarningLight::OnEndOverlap(UPrimitiveComponent* OverlappedComp, 
	AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex)
{
	WarningLight->SetVisibility(false, false);
}

