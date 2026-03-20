#include "warrior.h"
#include "monster.h"
#include <string>
#include <iostream>
using namespace std;

Warrior::Warrior(string nickname) : Player(nickname)
{
    this->job_name = "전사";
    this->setNickname(nickname);
    this->level = 1;
    this->HP = 100;
    this->MP = 50;
    this->accuracy = 20;
    this->power = 30;
    this->defence = 15;
    this->speed = 10;
}

void Warrior::attack()
{
    cout << "검을 휘두릅니다!" << '\n';
}

void Warrior::attack(Monster *monster)
{
    cout << "검으로 공격합니다!" << '\n';
    int damage = this->power - monster->getDefence();
    if (damage <= 0)
        damage = 1;
    cout << this->nickname << "이(가) " << monster->getName() << "에게 " << damage << "의 데미지를 입혔습니다!" << '\n';
    monster->setHP(monster->getHP() - damage);
    if (monster->getHP() > 0)
        cout << monster->getName() << "의 남은 HP: " << monster->getHP() << '\n';
}
