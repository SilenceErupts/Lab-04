// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/TargetPoint.h"
#include "TopDownShmupCharacter.h"
#include "DwarfCharacter.h"
#include "SpawnManager.generated.h"

UCLASS()
class TOPDOWNSHMUP_API ASpawnManager : public AActor
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere, Category = "Spawn")
		TArray<ATargetPoint*> spawnPoints;
	UPROPERTY(EditAnywhere, Category = "Spawn")
		TSubclassOf<ACharacter> currentTarget;
	UPROPERTY(EditAnywhere, Category = "Spawn")
		float minSpawnTime;
	UPROPERTY(EditAnywhere, Category = "Spawn")
		float maxSpawnTime;
	UPROPERTY(EditAnywhere, Category = "Spawn")
		TSubclassOf<ADwarfCharacter> DwarfClass;
	ADwarfCharacter* CurrentDwarf;

	UFUNCTION(BlueprintNativeEvent)
		void Spawn();
	virtual void Spawn_Implementation();


	// Sets default values for this actor's properties
	ASpawnManager();

	FTimerHandle SpawnTimerHandle;
	void SpawnDwarf();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	ATopDownShmupCharacter* Player;

};
