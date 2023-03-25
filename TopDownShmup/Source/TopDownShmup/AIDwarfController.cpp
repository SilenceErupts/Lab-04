// Fill out your copyright notice in the Description page of Project Settings.


#include "AIDwarfController.h"



void AAIDwarfController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	MyPawn = InPawn;
	MyDwarf = Cast<ADwarfCharacter>(MyPawn);
}

void AAIDwarfController::BeginPlay()
{
	Super::BeginPlay();

	SetCurrentState(EDwarfState::EStart);
	//MoveDwarf();
}

void AAIDwarfController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetCurrentState() == EDwarfState::EStart)
	{
		SetCurrentState(EDwarfState::EChasing);
	}

	if (GetCurrentState() == EDwarfState::EAttacking && (PlayerActor->GetDistanceTo(MyPawn) > DwarfRange))
	{
		SetCurrentState(EDwarfState::EChasing);
	}
}

void AAIDwarfController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	SetCurrentState(EDwarfState::EAttacking);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, FString::Printf(TEXT("move completed")));
	}
}

EDwarfState AAIDwarfController::GetCurrentState() const
{
	return CurrentState;
}

void AAIDwarfController::SetCurrentState(EDwarfState NewState)
{
	CurrentState = NewState;
	HandleNewState(CurrentState);
}

void AAIDwarfController::MoveDwarf()
{
	PlayerActor = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	MoveToActor(PlayerActor);
}

void AAIDwarfController::HandleNewState(EDwarfState NewState)
{
	switch (NewState)
	{
		case EDwarfState::EStart:
		{

		}
			break;
		case EDwarfState::EChasing:
		{
			MyDwarf->StopAttack();
			MoveDwarf();
		}
			break;
		case EDwarfState::EAttacking:
		{
			MyDwarf->StartAttack();
		}
			break;
		case EDwarfState::EDead:
		{

		}
			break;
		default:
		case EDwarfState::EUnknown:
		{

		}
			break;
	}
}
