// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_Tank.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


ABP_Tank::ABP_Tank()
{
    SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm Component"));   
    SpringArmComp->SetupAttachment(RootComponent);

    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
    CameraComp->SetupAttachment(SpringArmComp);

}

void ABP_Tank::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    //Good Practise to use SUPER so we use a parents version of the SetupPlayerComponent
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Bind our move function to the move forward axis mapping
    //Param name of axis mapping 
    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ABP_Tank::Move);

}

void ABP_Tank::Move(float Value)
{
    UE_LOG(LogTemp, Log, TEXT("Move Value: %f"), Value);
}
