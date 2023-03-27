// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyCharacter.h"
#include "TopDownShmupCharacter.h"
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

	UPROPERTY(EditDefaultsOnly)
		UAnimMontage* DeathAnim;
	
public:

	FTimerHandle AttackTimerHandle;
	float AttackDuration;

	FTimerHandle DeathTimerHandle;
	float DeathDuration;

	UPROPERTY(EditAnywhere, Category = "Health")
		float Health;

	UPROPERTY(EditAnywhere, Category = "Health")
		float Damage;

	ADwarfCharacter();
	void StartAttack();
	void StopAttack();
	void ApplyDamage();
	void DestroyAfterDeath();

	float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	
};
