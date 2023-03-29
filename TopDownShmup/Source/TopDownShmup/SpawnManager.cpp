// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnManager.h"

// Sets default values
ASpawnManager::ASpawnManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	minSpawnTime = 3.5f;
	maxSpawnTime = 5.5f;

}

// Called when the game starts or when spawned
void ASpawnManager::BeginPlay()
{
	Super::BeginPlay();
    Player = Cast<ATopDownShmupCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawnManager::Spawn, FMath::RandRange(minSpawnTime, maxSpawnTime), true);
	
}

// Called every frame
void ASpawnManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnManager::SpawnDwarf()
{
    UWorld* World = GetWorld();
    if (World)
    {
        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = this;
        SpawnParams.Instigator = GetInstigator();
        int spawnPointIndex = FMath::RandRange(0, spawnPoints.Num() - 1);
        ATargetPoint* location = spawnPoints[spawnPointIndex];
        FVector currentLoc = location->GetActorLocation();
        FRotator Rotation(0.0f, 0.0f, 0.0f);
        
        CurrentDwarf = World->SpawnActor<ADwarfCharacter>(DwarfClass, currentLoc, Rotation, SpawnParams);
        CurrentDwarf->SpawnDefaultController();
    }
    GetWorldTimerManager().ClearTimer(SpawnTimerHandle);
    if (!Player->IsDead())
    {
        GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawnManager::Spawn, FMath::RandRange(minSpawnTime, maxSpawnTime), true);
    }
}

void ASpawnManager::Spawn_Implementation()
{
    SpawnDwarf();
}