// Fill out your copyright notice in the Description page of Project Settings.


#include "ATreasureChest.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Character.h"
#include "Engine/Engine.h"

// Sets default values
AATreasureChest::AATreasureChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Treasure Chest starts closed
	bCollected = false;
	
	// Collision Box and root
	TreasureChest_BoxComponent = CreateDefaultSubobject<UBoxComponent>("Collision Box");
	SetRootComponent(TreasureChest_BoxComponent);
	TreasureChest_BoxComponent->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	TreasureChest_BoxComponent->SetGenerateOverlapEvents(true);
	TreasureChest_BoxComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	
	// Mesh
	TreasureChest_StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Chest Mesh");
	TreasureChest_StaticMesh->SetupAttachment(TreasureChest_BoxComponent);
	TreasureChest_StaticMesh->SetGenerateOverlapEvents(false);
	
	//
	TreasureChest_BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AATreasureChest::OnBeginOverlapComponentEvent);
}

// Called when the game starts or when spawned
void AATreasureChest::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AATreasureChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//
void AATreasureChest::Collected()
{
	// if already collected do nothing
	if (bCollected)
		return;
	
	// Make it open
	bCollected = true;
	
	// Debug message
	UE_LOG(LogTemp, Warning, TEXT("Treasure Chest Collected"));
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage( -1,10,FColor::Red,TEXT("Treasure Chest Collected") );
	}
}

// Overlapping Func
void AATreasureChest::OnBeginOverlapComponentEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//
	if (Cast<ACharacter>(OtherActor))
	{
		Collected();
	}
}
