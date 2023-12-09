// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorMoverAlongSplineComponent.h"

UActorMoverAlongSplineComponent::UActorMoverAlongSplineComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UActorMoverAlongSplineComponent::MoveAtSpline()
{
	float SplineTime = FMath::Fmod(Timer + StartAtProgress * SplineComponent->Duration, SplineComponent->Duration);
	FVector Location = SplineComponent->GetLocationAtTime(SplineTime, ESplineCoordinateSpace::World, true);

	SetWorldLocation(Location);
}

void UActorMoverAlongSplineComponent::SetSpline(USplineComponent* Spline)
{
	SplineComponent = Spline;
}

void UActorMoverAlongSplineComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	Timer += DeltaTime;
	
	if (Timer >= SplineComponent->Duration)
	{
		Timer = 0.f;
	}
	MoveAtSpline();
}




/*void UActorMoverAlongSplineComponent::MoveAtSpline(USplineComponent* Spline)
{
	float CurrentTime = (GetWorld()->GetTimeSeconds() - StartTime) / TotalPassedTime;
	Distance = Spline->GetSplineLength() * CurrentTime;

	if (CurrentTime >= 1.f)
	{
		StartTime = GetWorld()->GetTimeSeconds();
		CurrentTime = (GetWorld()->GetTimeSeconds() - StartTime) / TotalPassedTime;
	}
	
	void UActorMoverAlongSplineComponent::SetMeshAtSpline(USplineComponent* Spline)
{
	SplineComponent = Spline;

	Pointer = SplineComponent->GetNumberOfSplinePoints() * StartAtProgress;
	if (Pointer > SplineComponent->GetSplineLength())
	{
		Pointer -= SplineComponent->GetSplineLength();
	}

	StartLocation = SplineComponent->GetLocationAtSplinePoint(Pointer, ESplineCoordinateSpace::World);

	SetWorldLocation(StartLocation);
}


	Pionter = Progress * SplineComponent->GetSplineLenght() * StartAtProgress;
	StartLocation = SplineComponent->GetLocationAtDistanceAlongeSpline(Pointer, ESplineCoordinate::World);
	SetWorloLocation(StartLocatoin);
}

{
	FVector Location = SplineComponent->GetLocationAtTime(Progress, ESplineCoordinateSpace::World, false);

	StatrLocation+=Location;
}
}*/