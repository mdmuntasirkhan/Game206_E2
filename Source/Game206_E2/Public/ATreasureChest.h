// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ATreasureChest.generated.h"


class UBoxComponent;
class UStaticMeshComponent;
class UPrimitiveComponent;

UCLASS()
class GAME206_E2_API AATreasureChest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AATreasureChest();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Network communication
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
	// True once its used
	UPROPERTY(Replicated)
	bool bCollected;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called when chest is collected
	UFUNCTION()
	void Collected();
	
	// Overlap Func
	UFUNCTION()
	void OnBeginOverlapComponentEvent(UPrimitiveComponent* OverlappedComponent,
										AActor* OtherActor,
										UPrimitiveComponent* OtherComp,
										int32 OtherBodyIndex,
										bool bFromSweep,
										const FHitResult& SweepResult);
	
	// Mesh
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMeshComponent>TreasureChest_StaticMesh;
	
	// Collision Box
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UBoxComponent> TreasureChest_BoxComponent;
};