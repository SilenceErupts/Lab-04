// Fill out your copyright notice in the Description page of Project Settings.


#include "DwarfCharacter.h"
#include "AIDwarfController.h"

ADwarfCharacter::ADwarfCharacter()
{
	AIControllerClass = AAIDwarfController::StaticClass();
	Health = 20.f;
	Damage = 10.f;
}

void ADwarfCharacter::StartAttack()
{
	AttackDuration = PlayAnimMontage(AttackAnim);
	//ATopDownShmupCharacter* PlayerCharacter = Cast<ATopDownShmupCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetWorldTimerManager().SetTimer(AttackTimerHandle, this, &ADwarfCharacter::ApplyDamage, AttackDuration, true);
}

void ADwarfCharacter::StopAttack()
{
	StopAnimMontage();
	GetWorldTimerManager().ClearTimer(AttackTimerHandle);
}


float ADwarfCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	if (ActualDamage > 0.0f)
	{
		//TODO: Add a debug message on screen to know dwarf got hit
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::Printf(TEXT("Dwarf has been hit")));
		}
		//Reduce health points
		Health -= ActualDamage;
		if (Health <= 0.0f)
		{
			// We're dead
			SetCanBeDamaged(false); // Don't allow further damage
			// TODO: Process death
			// Stop attack animation,
			StopAttack();
			// UnPossess the AI controller, 
			AController* Controller = GetController();
			if (Controller)
			{
				Controller->UnPossess();
			}
			//Play Death animation
			DeathDuration = PlayAnimMontage(DeathAnim);
			// Remove the dwarf from the world
			//Destroy();
			GetWorldTimerManager().SetTimer(DeathTimerHandle, this, &ADwarfCharacter::DestroyAfterDeath, DeathDuration-0.25f, true);
			//this->RemoveFromRoot();
		}
	}
	return ActualDamage;

}

void ADwarfCharacter::ApplyDamage()
{
	// Get the player's pawn
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);

	if (PlayerPawn)
	{
		// Apply damage to the player's pawn
		PlayerPawn->TakeDamage(Damage, FDamageEvent(), GetController(), this);
	}
}

void ADwarfCharacter::DestroyAfterDeath()
{
	Destroy();
}