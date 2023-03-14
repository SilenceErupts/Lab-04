// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
	RootComponent = WeaponMesh;
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeapon::OnStartFire()
{
	if (FireLoopSound)
	{
		FireAC = PlayWeaponSound(FireLoopSound);
	}
	if (MuzzleFX)
	{
		MuzzlePC = UGameplayStatics::SpawnEmitterAttached(MuzzleFX, WeaponMesh, TEXT("MuzzleFlashSocket"));
	}
}

void AWeapon::OnStopFire()
{
	if (FireAC)
	{
		FireAC->Stop();
		FireAC = NULL;
	}
	if (FireFinishSound)
	{
		PlayWeaponSound(FireFinishSound);
	}
	if (MuzzlePC)
	{
		MuzzlePC->DeactivateSystem();
		MuzzlePC = nullptr;
	}
}

UAudioComponent* AWeapon::PlayWeaponSound(USoundCue* Sound)
{
	UAudioComponent* AC = NULL;
	if (Sound)
	{
		AC = UGameplayStatics::SpawnSoundAttached(Sound, RootComponent);
	}
	return AC;
}

