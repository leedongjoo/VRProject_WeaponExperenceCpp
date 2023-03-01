// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"

#include "PhysicsEngine/PhysicsThrusterComponent.h"
#include "Tracks/MovieSceneEventTrack.h"

// Sets default values
AWeaponBase::AWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GunRoot = CreateDefaultSubobject<USceneComponent>(TEXT("GUNROOT"));
	Frame = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FRAME"));
	GrabPosition = CreateDefaultSubobject<UBoxComponent>(TEXT("GRABPOSITION"));
	FirstGrab = CreateDefaultSubobject<UBoxComponent>(TEXT("FIRSTGRAB"));
	SecondGrab = CreateDefaultSubobject<UBoxComponent>(TEXT("SECONDGRAB"));
	FireTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("FIRETRIGGER"));
	ChargingTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("CHARGINGTRIGGER"));
	PowderTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("POWDERTRIGGER"));
	ChargingBarWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("CHARGINGBARWIDGET"));
	PhysicsThruster = CreateDefaultSubobject<UPhysicsThrusterComponent>(TEXT("PHYSICSTHRUSTERCOMPONENT"));

	
	RootComponent = GunRoot;
	Frame->SetupAttachment(GunRoot);
	FirstGrab->SetupAttachment(Frame);
	ChargingTrigger->SetupAttachment(Frame);
	GrabPosition->SetupAttachment(Frame);
	SecondGrab->SetupAttachment(Frame);
	FireTrigger->SetupAttachment(Frame);
	PowderTrigger->SetupAttachment(Frame);
}

void AWeaponBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	/////*PhysicalThruster의 위치값 설정*/////
	const FTransform FirePos = Frame->GetSocketTransform("FirePos",RTS_World); // 프레임의 총구 소켓 트렌스폼 구해오기
	const FRotator RecoilOffset = FRotator(0.0f, -45.0f, 0.0f); 
	const FQuat Recoil = FirePos.GetRotation() * FQuat(RecoilOffset); // -45도만큼 돌리기
	
	PhysicsThruster->SetWorldLocationAndRotation(FirePos.GetLocation(),Recoil,false); // PhysicThruster의 위치값 설정
	const FAttachmentTransformRules AttachmentTransformRules(EAttachmentRule::SnapToTarget,EAttachmentRule::KeepWorld,EAttachmentRule::SnapToTarget,true);
	
	PhysicsThruster->AttachToComponent(Frame,AttachmentTransformRules,"FirePos"); // 소켓에 붙이기
}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
}




