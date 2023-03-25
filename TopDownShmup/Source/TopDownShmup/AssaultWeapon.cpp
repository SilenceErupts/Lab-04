// Fill out your copyright notice in the Description page of Project Settings.


#include "AssaultWeapon.h"

AAssaultWeapon::AAssaultWeapon()
{
	FireRate = 0.05f;
	WeaponRange = 10000.0f;
    DamageAmount = 2.f;
}

void AAssaultWeapon::OnStartFire()
{
	Super::OnStartFire();
    GetWorldTimerManager().SetTimer(TimerHandle_WeaponTrace, this, &AAssaultWeapon::WeaponTrace, FireRate, true);
}

void AAssaultWeapon::OnStopFire()
{
	Super::OnStopFire();
    GetWorldTimerManager().ClearTimer(TimerHandle_WeaponTrace);
}

void AAssaultWeapon::WeaponTrace()
{
    static FName WeaponFireTag = FName(TEXT("WeaponTrace"));
    static FName MuzzleSocket = FName(TEXT("MuzzleFlashSocket"));

    // Start from the muzzle's position
    FVector StartPos = WeaponMesh->GetSocketLocation(MuzzleSocket);

    // Get forward vector of MyPawn
    FVector Forward = MyPawn->GetActorForwardVector();

    // Calculate end position
    FVector EndPos = StartPos + (Forward * WeaponRange);

    // Perform line trace to retrieve hit info
    FCollisionQueryParams TraceParams(WeaponFireTag, true, GetInstigator());

    // This fires the ray and checks against all objects w/ collision
    FHitResult Hit(ForceInit);
    GetWorld()->LineTraceSingleByObjectType(Hit, StartPos, EndPos, FCollisionObjectQueryParams::AllObjects, TraceParams);

    // Did this hit anything?
    if (Hit.bBlockingHit)
    {
        // Spawn impact particle effect
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), HitEffect, Hit.Location);

        //Damage check
        ADwarfCharacter* Dwarf = Cast<ADwarfCharacter>(Hit.GetActor());
        if (Dwarf)
        {
            Dwarf->TakeDamage(DamageAmount, FDamageEvent(), GetInstigatorController(), this);
        }
    }
}