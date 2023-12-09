// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorMoverComponent.h"


// Sets default values for this component's properties
UActorMoverComponent::UActorMoverComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
	// ...
}


// Called when the game starts
void UActorMoverComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	CachedOwner = GetOwner();
}


// Called every frame
void UActorMoverComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	TimePassed += DeltaTime;
	Progress = FMath::Clamp(TimePassed / TimeToMove, 0.0f, 1.0f);
	if (TimePassed >= TimeToMove)
	{
		TimePassed = 0.0f;
		
		MoveDirection *= -1;
		StartMoving();
		return;
	}

	CachedOwner->SetActorLocation(GetNewPosition(Interp), false, nullptr);
}

FVector UActorMoverComponent::GetNewPosition(EEasingType Type)
{
	switch (Type) 
	{
		case EEasingType::Linear:
			return FMath::Lerp(StartLocation, TargetLocation, Progress);

		case EEasingType::CircularIn:
			return FMath::InterpCircularIn(StartLocation, TargetLocation, Progress);
			
		case EEasingType::CircularInOut:
			return FMath::InterpCircularInOut(StartLocation, TargetLocation, Progress);
			
		case EEasingType::CircularOut:
			return FMath::InterpCircularInOut(StartLocation, TargetLocation, Progress);
			
		case EEasingType::EaseIn:
			return FMath::InterpEaseIn(StartLocation, TargetLocation, Progress, MovementExponent);
			
		case EEasingType::EaseInOut:
			return FMath::InterpEaseInOut(StartLocation, TargetLocation, Progress, MovementExponent);
			
		case EEasingType::EaseOut:
			return FMath::InterpEaseOut(StartLocation, TargetLocation, Progress, MovementExponent);
			
		case EEasingType::ExpoIn:
			return FMath::InterpExpoIn(StartLocation, TargetLocation, Progress);
			
		case EEasingType::ExpoInOut:
			return FMath::InterpExpoInOut(StartLocation, TargetLocation, Progress);
			
		case EEasingType::ExpoOut:
			return FMath::InterpExpoOut(StartLocation, TargetLocation, Progress);
			
		case EEasingType::SinIn:
			return FMath::InterpSinIn(StartLocation, TargetLocation, Progress);
			
		case EEasingType::SinInOut:
			return FMath::InterpSinInOut(StartLocation, TargetLocation, Progress);
			
		case EEasingType::SinOut:
			return FMath::InterpSinInOut(StartLocation, TargetLocation, Progress);
	}

	return FVector::ZeroVector;
}

void UActorMoverComponent::StartMoving()
{
	StartLocation = CachedOwner->GetActorLocation();
	TargetLocation = StartLocation + MovementDirection.GetSafeNormal() * DistanceToMove * MoveDirection;
	
	TimeToMove = DistanceToMove / Speed;
}

/*FVector UActorMoverComponent::GetInterp(EasingType Type)
{
	FVector Interp;
	switch (Type) 
	{
		case EasingType::CircularIn:
			Interp = FMath::InterpCircularIn(StartLocation, TargetLocation, Progress);
			break;
		case EasingType::CircularInOut:
			Interp = FMath::InterpCircularInOut(StartLocation, TargetLocation, Progress);
			break;
		case EasingType::CircularOut:
			Interp = FMath::InterpCircularInOut(StartLocation, TargetLocation, Progress);
			break;
		case EasingType::EaseIn:
			Interp = FMath::InterpEaseIn(StartLocation, TargetLocation, Progress, 7.f);
			break;
		case EasingType::EaseInOut:
			Interp = FMath::InterpEaseInOut(StartLocation, TargetLocation, Progress, 3.f);
			break;
		case EasingType::EaseOut:
			Interp = FMath::InterpEaseOut(StartLocation, TargetLocation, Progress, 7.f);
			break;
		case EasingType::ExpoIn:
			Interp = FMath::InterpExpoIn(StartLocation, TargetLocation, Progress);
			break;
		case EasingType::ExpoInOut:
			Interp = FMath::InterpExpoInOut(StartLocation, TargetLocation, Progress);
			break;
		case EasingType::ExpoOut:
			Interp = FMath::InterpExpoOut(StartLocation, TargetLocation, Progress);
			break;
		case EasingType::SinIn:
			Interp = FMath::InterpSinIn(StartLocation, TargetLocation, Progress);
			break;
		case EasingType::SinInOut:
			Interp = FMath::InterpSinInOut(StartLocation, TargetLocation, Progress);
			break;
		case EasingType::SinOut:
			Interp = FMath::InterpSinInOut(StartLocation, TargetLocation, Progress);
			break;
	}

	return Interp;
}

/*enum UActorMoverComponent::EasingType
{
	CircularIn = FMath::InterpCircularIn(1.0f, 0.0f, 0.2),
	CircularInOut = FMath::InterpCircularInOut(),
	CircularOut = FMath::InterpCircularOut(),
	InterpEaseIn = FMath::InterpEaseIn(1.0f, 0.0f, 0.2, 7.0f),
	InterpEaseInOut = FMath::InterpEaseInOut(),
	InterpEaseOut = FMath::InterpEaseOut(),
	InterpExpoIn = FMath::InterpExpoIn(),
	InterpExpoInOut = FMath::InterpEaseInOut(),
	InterpExpoOut = FMath::InterpEaseOut(),
	ExpoIn = FMath::InterpExpoIn(),
	ExpoInOut = FMath::InterpExpoInOut(),
	ExpoOut = FMath::InterpExpoOut(),
	InterpSinIn = FMath::InterpSinIn(),
	InterpSinInOut = FMath::InterpSinInOut(),
	InterpSinOut = FMath::InterpSinOut(),
};
/*Ріння руху
FVector UActorMoverComponent::GetNewPosition(float DeltaTime)
{
	FVector CurrentLocation = CashedOwner->GetActorLocation();

	FVector NewLocation = CurrentLocation + MovementDirection.GetSafeNormal() * DeltaTime * Speed * MoveDirection;

	return NewLocation;
}
*/

/*void UActorMoverComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    TimePassed += DeltaTime;

    if (TimePassed >= TimeToMove)
    {
        TimePassed = FMath::Clamp(TimePassed, 0.0f, TimeToMove);
        StartMoving(-MoveDirection);
        MoveDirection *= -1.0f; // Зміна напрямку руху
        return;
    }

    FVector NewLocation = GetNewPosition();
    CashedOwner->SetActorLocation(NewLocation, false, nullptr);
}

void UActorMoverComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	TimePassed += DeltaTime;
	if (TimePassed >= TimeToMove)
	{
		TimePassed = FMath::Clamp(TimePassed, 0.f, TimeToMove);
		StartMoving(-CurrentDirectionMultiplier);
		return;
	}

	const FVector NewPosition = GetNewPosition();
	CachedOwner->SetActorLocation(NewPosition, false, nullptr);
}

FVector UActorMoverComponent::GetNewPosition()
{
    FVector CurrentLocation = MovementDirection.GetSafeNormal() * TimePassed * Speed;

    CurrentLocation *= FMath::InterpEaseIn(1.0f, 0.2f, TimePassed / TimeToMove, 7.0f);

    return StartLocation + CurrentLocation; // Зміна обчислення нової позиції
}

void UActorMoverComponent::StartMoving(float Direction)
{
    StartLocation += GetNewPosition().GetSafeNormal() * Direction; // Зміна початкової позиції
}*/

/*FVector UActorMoverComponent::MoveTo()
{
	FVector DirectionForward, DirectionUp, DirectionRight;

	if (MovementDirection.X != 0)
	{
		DirectionForward = MovementDirection.ForwardVector;

	}

	if (MovementDirection.Y != 0)
	{
		DirectionRight = MovementDirection.RightVector;

	}

	if (MovementDirection.Z != 0)
	{
		DirectionUp = MovementDirection.UpVector;

	}

	return (DirectionForward + DirectionRight + DirectionUp) * Speed;
}*/

/*if (WaitTime > 0) 
	{
		WaitTime -= DeltaTime;
	}

	if (TimeElapsed < LerpDuration) 
	{
		
		MovementDirection += FVector(DistanceToMove, 0.0f, 0.0f);

		Parent->SetActorLocation(FMath::Lerp(StartDirection, MovementDirection, TimeElapsed/LerpDuration));

		TimeElapsed += DeltaTime;
	}*/

	/*CurentDistance += DeltaTime * 200 * MoveDirection;
	if (CurentDistance >= DistanceToMove || CurentDistance <= 0)
	{
		MoveDirection *= -1;
	}
	Actor->SetActorLocation(StartLocation + MovementDirectionNormolize * CurentDistance );*/
	// ..
	/*MovementDirection = Actor->GetActorLocation();
	if (Actor->GetActorLocation().X < DistanceToMove)
	{
		//MovementDirection.X += 200 * DeltaTime;
		MovementDirection.X += DistanceToMove;
		Actor->SetActorLocation(FMath::InterpEaseInOut(Actor->GetActorLocation(), MovementDirection, 0.2, 5));

	}*/
	/*
	MovementDirection = Actor->GetActorLocation();
	MovementDirection.X = UKismetMathLibrary::Ease(MovementDirection.X, DistanceToMove, 0.2, EEasingFunc::Type::ExpoInOut, 5, 2);

	Actor->SetActorLocation(MovementDirection);*/

/*	FVector MoveDelta = DeltaTime * MoveTo() * MoveDirection;
	Location += MoveDelta;

	CurrentDistance = (Location - StartLocation).Size();
	if (CurrentDistance >= DistanceToMove)
	{
		MoveDirection *= -1;
		float Overshoot = CurrentDistance - DistanceToMove;
		Location -= MoveDelta.GetSafeNormal() * Overshoot;
	}*/




