// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Item/CItemStrut.h"

#include "C_SaveTopDown.generated.h"

/**
 * 
 */
UCLASS()
class STEAMSESSIONS_API UC_SaveTopDown : public USaveGame
{
	GENERATED_BODY()
public:
	void SaveData(class AC_TopDownController* controller);
	void LoadData(class AC_TopDownController* controller);
public:

	// ĳ���� ���� ü��
	UPROPERTY()
	float characterHp_T;
	UPROPERTY()
	float characterHp_D;
	UPROPERTY()
	float characterHp_H;
	// �κ��丮 ����
	//UPROPERTY()
	//TArray<class ACItemStrut*> items;

	UPROPERTY()
	TArray<FItemBaseC> items;
	UPROPERTY()
	TArray<int32> ItemCounts;

	UPROPERTY()
	FString charName;


};
