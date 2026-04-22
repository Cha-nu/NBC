// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FItemData.generated.h"
/**
 * 
 */
USTRUCT(BlueprintType)
struct FItemData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ItemName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Description;

    // 이 아이템을 사용하기 위해 필요한 칭호
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RequiredTitle;

    FItemData() : ItemName(TEXT("None")), Description(TEXT("")), RequiredTitle(TEXT("")) {}
};