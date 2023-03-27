// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include <string>
#include "Weapon.h"
#include "TopDownShmupCharacter.generated.h"

UCLASS(Blueprintable)
class ATopDownShmupCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(EditDefaultsOnly)
		UAnimMontage* DeathAnim;



protected:
	virtual void BeginPlay() override;


public:

	bool bIsDead;
	bool IsDead();
	void DeactivateAfterDeath();

	FTimerHandle DeathTimerHandle;
	float DeathDuration;

	ATopDownShmupCharacter();

	UPROPERTY(EditAnywhere, Category = Weapon)
	TSubclassOf<AWeapon>WeaponClass;

	UPROPERTY(EditAnywhere, Category = "Health")
		float HealthPoints;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	virtual void OnStartFire();
	virtual void OnStopFire();


	virtual void Tick(float DeltaTime) override;

	float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

private:
	AWeapon* MyWeapon;
};

