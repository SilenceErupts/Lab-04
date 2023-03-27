// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIEnemyController.h"
#include "DwarfCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "AIDwarfController.generated.h"

/**
 * 
 */

enum class EDwarfState : short
{
	EStart, EChasing, EAttacking, EDead, EUnknown
};

UCLASS()
class TOPDOWNSHMUP_API AAIDwarfController : public AAIEnemyController
{
	GENERATED_BODY()

public:
	APawn* MyPawn;
	APawn* PlayerActor;
	ADwarfCharacter* MyDwarf;

	EDwarfState GetCurrentState() const;
	void SetCurrentState(EDwarfState NewState);

	UPROPERTY(EditAnywhere, Category = "Dwarf Range")
		float DwarfRange = 150.0f;

protected:
	virtual void OnPossess(APawn* InPawn) override;
	virtual void BeginPlay() override;
	virtual void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result) override;
	virtual void Tick(float DeltaTime) override;


private:
	EDwarfState CurrentState;

	void HandleNewState(EDwarfState NewState);
	void MoveDwarf();
};
