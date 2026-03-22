#include "inventory.h"

using namespace std;

int main()
{
    Inventory<Item> inventory(2);

    inventory.AddItem(Item("검", 100));
    inventory.AddItem(Item("방패", 150));
    inventory.AddItem(Item("포션", 50));

    cout << "인벤토리 아이템 목록:" << endl;
    inventory.PrintAllItems();

    inventory.RemoveLastItem();
    cout << "아이템 제거 후 인벤토리 아이템 목록:" << endl;
    inventory.PrintAllItems();

    return 0;
}