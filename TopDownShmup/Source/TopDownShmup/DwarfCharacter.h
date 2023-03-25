// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyCharacter.h"
#include "DwarfCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNSHMUP_API ADwarfCharacter : public AEnemyCharacter
{
	GENERATED_BODY()

		UPROPERTY(EditDefaultsOnly)
		UAnimMontage* AttackAnim;
	
public:


	UPROPERTY(EditAnywhere, Category = "Health")
		float Health;

	UPROPERTY(EditAnywhere, Category = "Health")
		float Damage;

	float AttackDuration;

	ADwarfCharacter();
	void StartAttack();
	void StopAttack();

	float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	
};
