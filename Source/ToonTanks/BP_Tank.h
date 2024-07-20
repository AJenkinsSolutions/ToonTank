// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "BP_Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ABP_Tank : public ABasePawn
{
	GENERATED_BODY()

public:
	ABP_Tank();
	
private:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="CamerRig", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="CamerRig", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComp;
	
public:

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	void Move(float Value);

};
