// Fill out your copyright notice in the Description page of Project Settings.


#include "PainZone.h"

// Sets default values
APainZone::APainZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	PainZone = CreateDefaultSubobject<UBoxComponent>(TEXT("PainZone"));
	PainZone->SetupAttachment(RootComponent);
	PainZone->OnComponentBeginOverlap.AddDynamic(this, &APainZone::OnBeginOverlap);

}

// Called when the game starts or when spawned
void APainZone::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APainZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APainZone::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, 
	bool bFromSweep, 
	const FHitResult& Hit)
{
	Player = Cast<ABaseCharacter>(OtherActor);

	if (Player)
	{
		GetWorldTimerManager().SetTimer(Handle, this, &APainZone::RepeatingFunction, Time, true, 0.5f);
	}
}

void APainZone::RepeatingFunction()
{
	if (Player->PlayerHealth <= 0)
	{
		GetWorldTimerManager().ClearTimer(Handle);
	}

	if (Player)
	{
		Player->CalculateHealth(Damage);

		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("Health ") + FString::SanitizeFloat(Player->PlayerHealth));
	}
}


