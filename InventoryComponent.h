// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FItemData.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"


UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BLUEPRINTPRACTICE_API UInventoryComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UInventoryComponent();

    // 1. TArray: 가방 (아이템 ID를 순서대로 저장)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    TArray<FName> InventoryArray;

    // 2. TMap: 아이템 데이터베이스 (ID를 Key로 상세 정보 검색)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    TMap<FName, FItemData> ItemDatabase;

    // 3. TSet: 획득한 칭호 (중복 없는 고유 칭호 목록)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    TSet<FString> AcquiredTitles;

    // 기능 함수
	UFUNCTION(BlueprintCallable, Category = "Inventory")
    void AddItemToInventory(FName ItemID);

    UFUNCTION(BlueprintCallable, Category = "Inventory")
    void AcquireTitle(FString NewTitle);

    UFUNCTION(BlueprintCallable, Category = "Inventory")
    void UseItem(FName ItemID);
};
