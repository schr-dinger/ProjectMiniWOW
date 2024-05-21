// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "C_TopDownController.h"
#include "C_TopDownCharacter.h"
#include "C_AIController.generated.h"

/**
 * 
 */
UCLASS()
class STEAMSESSIONS_API AC_AIController : public AAIController
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
	bool bDrawDebug = true;

	UPROPERTY(EditAnywhere)
	float AttackRange = 150;

	UPROPERTY(EditAnywhere)
	float AdjustCircleHeight = 50;

	UPROPERTY(VisibleDefaultsOnly)
	class UAIPerceptionComponent* Perception;

	UPROPERTY(VisibleDefaultsOnly)
	class UC_AIBehaviorComponent* Behavior;

public:
	AC_AIController();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

	class UC_AIBehaviorComponent* GetBehavior() { return Behavior; }
	float GetAttackRange() { return AttackRange; }
	float GetSightRange();

	TArray<AActor*> PlayerList;

	//Aggro Testing
	TMap<AC_TopDownCharacter*, float> AggroTable;

	// ��׷� ���� ������Ű�� �Լ�
	UFUNCTION()
	void IncreaseAggro(AC_TopDownCharacter* Player, float Amount);

	// ���� ���� ��׷� ���� ���� Ÿ���� ��ȯ�ϴ� �Լ�
	UFUNCTION()
	AC_TopDownCharacter* GetHighestAggroTarget();

	// RPC �Լ�
	UFUNCTION(Server, Reliable)
	void ServerIncreaseAggro(AC_TopDownCharacter* Player, float Amount);

	UFUNCTION(Server, Reliable)
	void UpdateTarget();

private:
	UFUNCTION(Server, Reliable)
	void OnPerceptionUpdated(const TArray<AActor*>& UpdateActors);

private:
	class AC_BasicMonster* ControlledPawn;
	class UAISenseConfig_Sight* Sight;

	bool isAggro = false;
	
};
