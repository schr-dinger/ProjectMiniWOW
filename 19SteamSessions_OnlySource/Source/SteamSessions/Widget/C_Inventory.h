// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Item/CItemStrut.h"
//#include "Input/Reply.h"

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "C_Inventory.generated.h"

/**
 * 
 */
UCLASS()
class STEAMSESSIONS_API UC_Inventory : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeOnInitialized() override;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;


public:
	UPROPERTY(VisibleAnywhere)
	TArray<class UC_InventoryButton*> buttons;

	UPROPERTY(VisibleAnywhere)
	TArray<class UImage*> itemIcons;

	UPROPERTY(VisibleAnywhere)
	TArray<class UTextBlock*> itemCount;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ACItemStrut> ItemClass;

	UPROPERTY(VisibleAnywhere)
	class UButton* moveButtonC;

	bool canMoveInven;
	FVector2D tmpMousePos;

public:
	UFUNCTION()
	void MouseClick(int32 buttonNum);
	UFUNCTION()
	void MouseHovered(int32 buttonNum);
	UFUNCTION()
	void MouseUnHovered(int32 buttonNum);
	UFUNCTION()
	void OffWidget();

	UFUNCTION()
	void MoveInven();
	UFUNCTION()
	void StopInven();

	void SetInven();
	void SetCoolTime();
	void SetPlayer(class ACharacter* _player);

	void UseItemA(TArray<ACItemStrut*>& _items, int32 num);
	bool AddInven(ACItemStrut* addItem);
	void SetReadyLoad();

public:

public:
	UPROPERTY(EditDefaultsOnly)
	class UDataTable* dataTable;

	//TArray<FItemBaseC*> itemsP; // 240516 : ��밡������... ��������Ƽ ���� ���ϸ� ��� ����
	//TArray<FItemBaseC> itemsP; // 240606 ������ ����ϸ� ������ ���̺��� �ٲ� -> ���ͽ������� ����
	UPROPERTY(VisibleAnywhere)
	TArray<class ACItemStrut*> items; // 240606: �̰ɷ� ����************************
	UPROPERTY()
	class ACItemStrut* onMouseItem;
	UPROPERTY()
	class ACItemStrut* onHoveredItem;

	//FItemBaseC* onMouseItem;
	int32 tmpInvenNum;
	//FItemBaseC* onHoveredItem;
	bool isHovered;
	int32 tmpHoveredNum;
	bool bcanDoubleClick = false;
	float doubleClickTime = 0.0f;

	// Ŭ���� ���콺 ���� �ٴ� ������ ����
	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<UUserWidget> onMouseIconClass;

	UPROPERTY(VisibleAnywhere, Category = "Widget")
	class UC_InventoryOnMouseIcon* onMouseIconWidget;

	// ȣ���� �ߴ� ������ ���� ����
	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<UUserWidget> onHoveredIconClass;

	UPROPERTY(VisibleAnywhere, Category = "Widget")
	class UC_InventoryButtonHovered* onHoveredWidget;
public:
	// ������ ��� �׽�Ʈ
	UPROPERTY(EditAnywhere, SaveGame)
	TSubclassOf<ACItemStrut> tItem;

	// �÷��̾�
	UPROPERTY()
	class ACharacter* player;

	UPROPERTY()
	class AC_TopDownController* mainController;
};
