// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "Engine/Engine.h"

UInventoryComponent::UInventoryComponent()
{
    FItemData SwordData;
    SwordData.ItemName = TEXT("Legendary Sword");
    SwordData.RequiredTitle = TEXT("Hero");
    ItemDatabase.Add(TEXT("Sword_01"), SwordData);
}

void UInventoryComponent::AddItemToInventory(FName ItemID)
{
    InventoryArray.Add(ItemID);
    
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, 
            FString::Printf(TEXT("Acquired item: %s"), *ItemID.ToString()));
    }
}

void UInventoryComponent::AcquireTitle(FString NewTitle)
{
    AcquiredTitles.Add(NewTitle);
    
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, 
            FString::Printf(TEXT("Acquired title: %s"), *NewTitle));
    }
}

void UInventoryComponent::UseItem(FName ItemID)
{
    if (!InventoryArray.Contains(ItemID))
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("The item is not in the inventory."));
        }
        return;
    }

    FItemData* Data = ItemDatabase.Find(ItemID);
    if (Data)
    {
       
        if (Data->RequiredTitle.IsEmpty() || AcquiredTitles.Contains(Data->RequiredTitle))
        {
            if (GEngine)
            {
                GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, 
                    FString::Printf(TEXT("Used the %s item!"), *Data->ItemName));
            }
   
           InventoryArray.RemoveSingle(ItemID);
        }
        else
        {
            if (GEngine)
            {
                GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, 
                    FString::Printf(TEXT("Cannot use: [%s] title is required."), *Data->RequiredTitle));
            }
        }
    }
}