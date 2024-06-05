// Fill out your copyright notice in the Description page of Project Settings.


#include "C_SlashAttack.h"
#include "C_AIController.h"
#include "C_BasicMonster.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "C_TopDownCharacter.h"

// Sets default values
AC_SlashAttack::AC_SlashAttack()
{
    PrimaryActorTick.bCanEverTick = true;

    // BoxComponent �ʱ�ȭ
    BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
    BoxComponent->SetBoxExtent(FVector(100.0f, 100.0f, 50.0f)); // ũ�� ����
    BoxComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
    RootComponent = BoxComponent;

    // �浹 �̺�Ʈ ���ε�
    BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AC_SlashAttack::OnOverlapBegin);

    Damage = 20.0f; // �⺻ ���ط� ����
    Duration = 0.5f; // ���� ���� �ð� ����
}

// Called when the game starts or when spawned
void AC_SlashAttack::BeginPlay()
{
    Super::BeginPlay();

    // ���� �ð� �Ŀ� �ı�
    GetWorldTimerManager().SetTimer(TimerHandle, this, &AC_SlashAttack::DestroySlash, Duration, false);
}

// Called every frame
void AC_SlashAttack::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AC_SlashAttack::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor != this)
    {
        AC_BasicMonster* Monster = Cast<AC_BasicMonster>(OtherActor);
        if (Monster)
        {
            GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::MakeRandomColor(), FString::Printf(TEXT("MonsterHit")));

            //UGameplayStatics::ApplyDamage(Monster, Damage, nullptr, this, nullptr);
            Monster->SerTakeDamage(Damage);

            AC_AIController* tmpC = Cast<AC_AIController>(Monster->GetController());
            if (tmpC)
            {
                tmpC->ServerIncreaseAggro(Cast<AC_TopDownCharacter>(GetOwner()), Damage);
            }


        }
    }
}

void AC_SlashAttack::DestroySlash()
{
    Destroy();
}