// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "MyActor.h"


// Sets default values
AMyActor::AMyActor():
	TotalDamage(200),
	DamageTimeInSeconds(1)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMyActor::PostInitProperties()
{
	Super::PostInitProperties();
	CalculateDamagePerSecond();


}

#if WITH_EDITOR
void AMyActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	CalculateDamagePerSecond();
	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

void AMyActor::CalculateDamagePerSecond()
{
	if (DamageTimeInSeconds != 0)
		DamagePerSecond = TotalDamage / DamageTimeInSeconds;
	else
		DamagePerSecond = 0;
}

// Called when the game starts or when spawned Вызывается когда игра стартует или спаунится игрок
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame вызывается каждый кадр
void AMyActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

