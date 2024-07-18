// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	UPROPERTY(VisibleAnywhere)
	int32 VisibleAnywhereInt = 12;

	UPROPERTY(EditAnywhere)
	int32 EditAnywhereInt =  24;

	UPROPERTY(VisibleInstanceOnly)
	int32 VisibleInstanceOnly = 42;



	UPROPERTY(EditAnywhere)
	float Speed = 400;

	UPROPERTY(EditInstanceOnly)
	int32 AmmoLeft = 10;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	//Capsule
	//Forward Delcaration 
	UPROPERTY()
	class UCapsuleComponent* CapsuleComp;
	UPROPERTY()
	class UStaticMeshComponent* BaseMesh;
	UPROPERTY()
	class UStaticMeshComponent* TurrentMesh;
	UPROPERTY()
	class USceneComponent* ProjectileSpawnPoint;




public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
