// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "PhysicsEngine/PhysicsThruster.h"
#include "Components/WidgetComponent.h"
#include "WeaponBase.generated.h"

UCLASS()
class PROJECT_BOWANDMUSKET_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void PostInitializeComponents() override;

	UPROPERTY()
	USceneComponent* GunRoot;

	UPROPERTY(VisibleAnywhere) 
	USkeletalMeshComponent* Frame; // 총기 프레임

	UPROPERTY()
	USceneComponent* GrabPosition; // 첫 번째 그랩 위치

	// Triggers
	UPROPERTY(VisibleAnywhere, Category=Trigger)
	UBoxComponent* FirstGrab; // 첫 번째 그랩 트리거

	UPROPERTY(VisibleAnywhere, Category=Trigger)
	UBoxComponent* SecondGrab; // 두 번째 그랩 트리거

	UPROPERTY(VisibleAnywhere, Category=Trigger)
	UBoxComponent* FireTrigger; // 불 붙이는 위치 트리거

	UPROPERTY(VisibleAnywhere, Category=Trigger)
	UBoxComponent* ChargingTrigger; // 장전 위치 트리거

	UPROPERTY(VisibleAnywhere, Category=Trigger)
	UBoxComponent* PowderTrigger; // 화약 삽입 위치 트리거

	UPROPERTY(VisibleAnywhere, Category=UI)
	class UWidgetComponent* ChargingBarWidget; // 장전 바 위젯
	
	UPROPERTY(VisibleAnywhere, Category=physics)
    UPhysicsThrusterComponent *PhysicsThruster; // 반동 생성기

private:
	
};
