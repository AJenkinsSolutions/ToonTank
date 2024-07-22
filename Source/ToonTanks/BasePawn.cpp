// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//todo: CreateCapslueComponent()
	//Reassiging the root component
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	//todo: ConstructMeshes&Attach() x3 
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	//BaseMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform, NAME_None)
	BaseMesh->SetupAttachment(CapsuleComp);
	
	TurrentMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turrent Mesh"));
	TurrentMesh->SetupAttachment(BaseMesh);

	//Projectile spawn point
	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("SpawnPoint-Projectile"));
	ProjectileSpawnPoint->SetupAttachment(TurrentMesh);



}



void ABasePawn::RotateTurret(FVector LookAtTarget)
{	
	//World space 
	//Vector from turrent to trace hit result
	//Destination - starting point
	FVector ToTarget = LookAtTarget - TurrentMesh->GetComponentLocation();
	//Init rotation
	FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);
	TurrentMesh->SetWorldRotation(LookAtRotation);


}

// Called every frame
void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



