// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class MYPROJECT_API AMyActor : public AActor
{
private:
	GENERATED_BODY()

	
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	//Доступны в редакторе для чтения и записи
	//UPROPERTY(EditAnywhere, Category = "Damage")
	//	int32 TotalDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
		int32 TotalDamage;//теперь доступен в Blueprint

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Damage")
		int32 DamagePerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
		int32 DamageTimeInSeconds;

	virtual void PostInitProperties();

#if WITH_EDITOR
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent);
#endif

	UFUNCTION(BlueprintCallable, Category="Damage")
	void CalculateDamagePerSecond();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//int32 GetDamagePerSecond() const { return DamagePerSecond; }
	//void SetDamagePerSecond(int32 val) { DamagePerSecond = val; }
};
