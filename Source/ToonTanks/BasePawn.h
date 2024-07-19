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

	

	UPROPERTY(VisibleInstanceOnly)
	int32 VisibleInstanceOnlyInt = 42;

	UPROPERTY(VisibleDefaultsOnly)
	int32 VisibleDefaultOnlyInt = 5;


	UPROPERTY(EditDefaultsOnly)
	int32 EditDefaultsOnlyInt = 9; 

	UPROPERTY(EditInstanceOnly)
	int32 EditInstanceOnlyInt = 14;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 400;

	UPROPERTY(EditInstanceOnly)
	int32 AmmoLeft = 10;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	//Capsule
	//Forward Delcaration 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="MyComponents", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComp;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="MyComponents", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* BaseMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="MyComponents", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* TurrentMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="MyComponents", meta = (AllowPrivateAccess = "true"))
	class USceneComponent* ProjectileSpawnPoint;

	//Exposing to blueprints
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "MyCategory" , meta = (AllowPrivateAccess = "true"))
	int32 VisibleAnywhereInt = 12;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "MyCategory" ,meta = (AllowPrivateAccess = "true"))
	int32 EditAnywhereInt =  24;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
