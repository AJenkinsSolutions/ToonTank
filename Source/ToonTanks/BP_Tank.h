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

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:

	virtual void BeginPlay() override;
	
private:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="CamerRig", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="CamerRig", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere, Category="Movement")
	float Speed = 200.f;

	UPROPERTY(EditAnywhere, Category="Movement")
	float TurnRate = 200.f;

	
	void Move(float Value);
	void Turn(float Value);

	//Reference to the Player controller to get inputs
	APlayerController* PlayerControllerRef;


	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
