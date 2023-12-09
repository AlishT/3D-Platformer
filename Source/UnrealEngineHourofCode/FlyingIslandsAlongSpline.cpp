// Fill out your copyright notice in the Description page of Project Settings.


#include "FlyingIslandsAlongSpline.h"

// Sets default values
AFlyingIslandsAlongSpline::AFlyingIslandsAlongSpline()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = DefaultSceneRoot;

	Spline = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	Spline->SetupAttachment(DefaultSceneRoot);


}

// Called when the game starts or when spawned
void AFlyingIslandsAlongSpline::BeginPlay()
{
	Super::BeginPlay();
	
	/*MeshsMover.Add(MeshMoverComponent1);
	MeshsMover.Add(MeshMoverComponent2);
	MeshsMover.Add(MeshMoverComponent3);
	MeshsMover.Add(MeshMoverComponent4);

	StartTime = GetWorld()->GetTimeSeconds();*/
}

// Called every frame
void AFlyingIslandsAlongSpline::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}


/*void AFlyingIslandsAlongSpline::MoveComponent()
{
	float CurrentTime = (GetWorld()->GetTimeSeconds() - StartTime) / TotalPassTime;
	float Distance = Spline->GetSplineLength() * CurrentTime;

	for (int32 Component = 0; Component < MeshsMover.Num(); Component++)
	{
		
		float DistanceAlongSpline = (MeshsMover[Component]->Pointer * Component) + Distance;

		if (DistanceAlongSpline > Spline->GetSplineLength()) 
		{
			DistanceAlongSpline -= Spline->GetSplineLength();
		}
		FVector Location = Spline->GetLocationAtDistanceAlongSpline(DistanceAlongSpline, ESplineCoordinateSpace::World);
		MeshsMover[Component]->SetWorldLocation(Location);
	}
	 
	if (CurrentTime >= 1.f) 
	{
		StartTime = GetWorld()->GetTimeSeconds();
		CurrentTime = (GetWorld()->GetTimeSeconds() - StartTime) / TotalPassTime;
	}
}*/


//FRotator Rotation = Spline->GetRotationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);

	//FVector Direction = Spline->GetDirectionAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
	//FRotator Rotation = FRotationMatrix::MakeFromX(Direction).Rotator();

/*float CurrentSplineTime = (GetWorld()->GetTimeSeconds() - ActorMovers[Component]->StartAtProgress)
		float PointIndex = Spline->GetNumberOfSplinePoints() - ActorMovers[Component]->Pointer;
		float DistanceIndex = Spline->GetDistanceAlongSplineAtSplinePoint(PointIndex);
		float Alfa = ActorMovers[Component]->StartAtProgress / ActorMovers[Component]->TimePased;
		float Distance = FMath::Lerp(0.f, DistanceIndex, Alfa);
		FVector Location = Spline->GetLocationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
		ActorMovers[Component]->SetWorldLocation(Location);

		FRotator Rotation = Spline->GetRotationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
		ActorMovers[Component]->SetWorldRotation(Rotation);
		ActorMovers[Component]->Pointer += 5;*/