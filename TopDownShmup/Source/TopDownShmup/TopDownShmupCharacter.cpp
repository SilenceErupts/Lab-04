// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "TopDownShmupCharacter.h"
#include "TopDownShmup.h"

ATopDownShmupCharacter::ATopDownShmupCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	HealthPoints = 100.f;
}

void ATopDownShmupCharacter::BeginPlay()
{
	// Call base class BeginPlay
	Super::BeginPlay();

	int HealthInt = static_cast<int>(HealthPoints);
	if (GEngine)
	{

		// add the message to the ScreenMessages system
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, FString::Printf(TEXT("Player Health: %i"), HealthInt));
	}
	// Spawn the weapon, if one was specified
	if (WeaponClass)
	{
		UWorld* World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();
			// Need to set rotation like this because otherwise gun points down
			// NOTE: This should probably be a blueprint parameter
			FRotator Rotation(0.0f, 0.0f, -90.0f);
			// Spawn the Weapon
			MyWeapon = World->SpawnActor<AWeapon>(WeaponClass, FVector::ZeroVector,
				Rotation, SpawnParams);
			if (MyWeapon)
			{
				// This is attached to "WeaponPoint" which is defined in the skeleton
				// NOTE: This should probably be a blueprint parameter
				MyWeapon->WeaponMesh->AttachToComponent(GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), TEXT("WeaponPoint"));
				MyWeapon->MyPawn = this;
			}
		}
	}
}

void ATopDownShmupCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATopDownShmupCharacter::OnStartFire()
{
	if (MyWeapon)
	{
		MyWeapon->OnStartFire();
	}
}

void ATopDownShmupCharacter::OnStopFire()
{
	if (MyWeapon)
	{
		MyWeapon->OnStopFire();
	}
}

float ATopDownShmupCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	if (ActualDamage > 0.0f)
	{
		//TODO: Add a debug message on screen to know player got hit
		/*if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("Player has been hit")));
		}*/
		//Reduce health points
		HealthPoints -= ActualDamage;
		int HealthInt = static_cast<int>(HealthPoints);
		if (GEngine)
		{

			// add the message to the ScreenMessages system
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, FString::Printf(TEXT("Player Health: %i"), HealthInt));
		}
		if (HealthPoints <= 0.0f)
		{
			// We're dead
			bIsDead = true;
			// Get the player controller and ignore look and move input
			APlayerController* PlayerController = Cast<APlayerController>(GetController());
			if (PlayerController)
			{
				MyWeapon->OnStopFire();
				PlayerController->SetIgnoreLookInput(true);
				PlayerController->SetIgnoreMoveInput(true);
			}
			//Play Death animation
			DeathDuration = PlayAnimMontage(DeathAnim);
			// Deactivate animation for the player
			GetWorldTimerManager().SetTimer(DeathTimerHandle, this, &ATopDownShmupCharacter::DeactivateAfterDeath, DeathDuration - 0.25f, true);
		}
	}
	return ActualDamage;

}

bool ATopDownShmupCharacter::IsDead()
{
	return bIsDead;
}

void ATopDownShmupCharacter::DeactivateAfterDeath()
{
	GetMesh()->Deactivate();
}