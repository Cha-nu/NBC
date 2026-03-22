#include "thief.h"
#include "monster.h"
#include <string>
#include <iostream>
using namespace std;

Thief::Thief(string nickname) : Player(nickname)
{
    this->job_name = "도적";
    this->setNickname(nickname); 
    this->level = 1;
    this->HP = 100;
    this->MP = 50;
    this->power = 20;
    this->defence = 10;
    this->accuracy = 20;
    this->speed = 20;
}

void Thief::attack()
{
    cout << "단검으로 찌릅니다!" << '\n';
}

void Thief::attack(Monster *monster)
{
    cout << "단검으로 공격합니다!" << '\n';
    // 도적: 계산된 데미지/5으로 5회 공격
    for (int i = 0; i < 5; i++)
    {
        int damage = this->power - monster->getDefence();
        if (damage <= 0)
            damage = 1;
        cout << this->nickname << "이(가) " << monster->getName() << "에게 " << damage << "의 데미지를 입혔습니다!" << '\n';
        monster->setHP(monster->getHP() - damage);
    }
    if (monster->getHP() > 0)
        cout << monster->getName() << "의 남은 HP: " << monster->getHP() << '\n';
}
