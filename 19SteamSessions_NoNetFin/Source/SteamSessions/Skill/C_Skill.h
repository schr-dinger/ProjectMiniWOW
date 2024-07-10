// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C_Skill.generated.h"

UCLASS()
class STEAMSESSIONS_API AC_Skill : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AC_Skill();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public: // ������ ���⿡�� �߰�
    // �÷��̾� ĳ����
    class AC_TopDownCharacter* player;

    // ������ ��Ÿ���� ������Ʈ, �ڽ�, ���Ǿ�, ĸ�� ������Ʈ�� �ִ��� ĳ���� �����ϰ� 
    class UShapeComponent* collider;

    UPROPERTY(VisibleAnywhere)
    class UAnimMontage* SkillMotion;

    // ���ط�
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
    float Damage;

    // ���� ���� �ð�
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
    float Duration;
    // ��ų ��Ÿ��
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
    float CoolTime;


    // ������ ����, ��ų ����, ��Ʈ ����

    // �ִϸ��̼ǵ� ���⼭?

public: // �Լ��� ���⼭ �߰�
    // �浹 ó�� �Լ�
    UFUNCTION()
    void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    //UFUNCTION()
    virtual void SetPlayer(AC_TopDownCharacter* _player) { player = _player; }
    virtual void FireSkill();
    virtual void InactiveSkill();
    
    FORCEINLINE bool IsCoolTime() { return isCoolTime; }
protected:
    FTimerHandle TimerHandle;
    bool isCoolTime;
    float tmpCoolTime;

private:
    void DestroySkill();


};
