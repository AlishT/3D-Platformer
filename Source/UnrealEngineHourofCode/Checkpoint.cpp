// Fill out your copyright notice in the Description page of Project Settings.


#include "Checkpoint.h"
#include "PaperSpriteComponent.h"

// Sets default values
ACheckpoint::ACheckpoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Button = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Button;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	CollisionSphere->SetupAttachment(Button);
	CollisionSphere->SetRelativeScale3D(FVector(2.f, 2.f, 2.f));

	ButtonARing = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh2"));
	ButtonARing->SetupAttachment(Button);

	CheckpointTransform = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("CheckpointTransform"));
	CheckpointTransform->SetupAttachment(Button);

	Message = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Checkpoint"));
	Message->SetupAttachment(Button);
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	Arrow->SetupAttachment(Button);

	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ACheckpoint::OnBeginOverlap);
	
}

// Called when the game starts or when spawned
void ACheckpoint::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACheckpoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACheckpoint::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	DynamicMaterial = UMaterialInstanceDynamic::Create(Material, this);

	Button->SetMaterial(0, DynamicMaterial);

}

void ACheckpoint::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, 
	AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, 
	bool bFromSweep, 
	const FHitResult& Hit)
{
	if (!bCheckpointEnabled)
	{
		bCheckpointEnabled = true;

		DynamicMaterial->SetVectorParameterValue(TEXT("Color"), FLinearColor::Blue);

		FTransform SpawnLocation = CheckpointTransform->GetComponentTransform();
		UpdateSpawnTransform(SpawnLocation);

	}
}

