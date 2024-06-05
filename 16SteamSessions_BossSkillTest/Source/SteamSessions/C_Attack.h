// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C_Attack.generated.h"

UCLASS()
class STEAMSESSIONS_API AC_Attack : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AC_Attack();

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    class UCapsuleComponent* collider;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    class UProjectileMovementComponent* ProjectileMovement;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setting")
    bool isFloor = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setting")
    bool isMove = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setting")
    bool isMonster = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setting")
    bool isSpawning = false;





    // �浹 ó�� �Լ�
    UFUNCTION()
    void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    // ���ط�
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
    float Damage;

    // ���� ���� �ð�
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
    float Duration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
    float Radius;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
    float HalfHeight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
    float CoolTime;


    float time;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    bool isOnCoolDown = false;

private:
    FTimerHandle TimerHandle;

    void DestroySlash();

};
