// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "DwarfCharacter.h"
#include "AssaultWeapon.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNSHMUP_API AAssaultWeapon : public AWeapon
{
	GENERATED_BODY()

		UPROPERTY(EditDefaultsOnly)
		class UParticleSystem* HitEffect;

protected:
	void WeaponTrace();


public:
	AAssaultWeapon();

	UPROPERTY(EditAnywhere, Category = "Damage")
		float DamageAmount;

	FTimerHandle TimerHandle_WeaponTrace;

	float FireRate;
	float WeaponRange;

	virtual void OnStartFire() override;
	virtual void OnStopFire() override;
};
