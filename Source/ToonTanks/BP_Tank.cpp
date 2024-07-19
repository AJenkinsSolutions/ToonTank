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