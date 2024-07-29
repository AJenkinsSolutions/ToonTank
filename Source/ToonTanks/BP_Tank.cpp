// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_Tank.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

//Constructor
ABP_Tank::ABP_Tank()
{   
    //Camera Setup
    //1: Spring Arm 
    SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm Component"));   
    //Attach to Root Component
    SpringArmComp->SetupAttachment(RootComponent);
    //Camera
    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
    //Attach Camera to SpringArm
    CameraComp->SetupAttachment(SpringArmComp);

}

void ABP_Tank::BeginPlay()
{
    Super::BeginPlay();
    
    //Getting the player controller Ref
    //Pawn::GetController returns a ''AController*''
    //Cast to APlayerController 
    PlayerControllerRef = Cast<APlayerController>(GetController());

}

void ABP_Tank::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    //Good Practise to use SUPER so we use a parents version of the SetupPlayerComponent
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    //Bind our move function to the move forward axis mapping
    //Param name of axis mapping 
    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ABP_Tank::Move);
    PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ABP_Tank::Turn);

}

void ABP_Tank::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    //TODO GetHitUnderMouseCursor()
    if(PlayerControllerRef){
        
        //Output Variable 
        FHitResult HitResult;
        PlayerControllerRef->GetHitResultUnderCursor(
            ECollisionChannel::ECC_Visibility,
            false,
            HitResult);

        //UE_LOG(LogTemp, Log, TEXT("Impact Point %f"), HitResult.ImpactPoint.Y);
        
        DrawDebugSphere(
        GetWorld(),
        HitResult.ImpactPoint,
        25.f,
        12,
        FColor::Cyan,
        false,
        -1.0f
        );

    }
}


void ABP_Tank::Move(float Value)
{
    //UE_LOG(LogTemp, Log, TEXT("Move Value: %f"), Value);
    
    //Initialize Vector with all zeros

    FVector DeltaLocation = FVector::ZeroVector;

    
    // X = Value * DeltaTime * Speed
    DeltaLocation.X = (Value * Speed) * UGameplayStatics::GetWorldDeltaSeconds(this);
    
    AddActorLocalOffset(DeltaLocation, true);
}

void ABP_Tank::Turn(float Value)
{
    //UE_LOG(LogTemp, Log, TEXT("Turn Value: %f"), Value);
    // FVector DeltaLocation = FVector::ZeroVector;

    // AddActo
    FRotator DeltaRotation = FRotator::ZeroRotator;
    // yaw = value * deltatime * turnRate
    DeltaRotation.Yaw = (Value * TurnRate) * UGameplayStatics::GetWorldDeltaSeconds(this);
    
    AddActorLocalRotation(DeltaRotation, true);

    
}

