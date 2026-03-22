#include "magician.h"
#include "monster.h"
#include <string>
#include <iostream>
using namespace std;

Magician::Magician(string nickname) : Player(nickname)
{
    this->job_name = "마법사";
    this->setNickname(nickname);
    this->level = 1;
    this->HP = 100;
    this->MP = 50;
    this->accuracy = 30;
    this->power = 25;
    this->defence = 5;
    this->speed = 15;
}

void Magician::attack()
{
    cout << "마법을 사용합니다.!" << '\n';
}

void Magician::attack(Monster *monster)
{
    cout << "마법으로 공격합니다!" << '\n';
    int damage = this->power - monster->getDefence();
    if (damage <= 0)
        damage = 1;
    cout << this->nickname << "이(가) " << monster->getName() << "에게 " << damage << "의 데미지를 입혔습니다!" << '\n';
    monster->setHP(monster->getHP() - damage);
    if (monster->getHP() > 0)
        cout << monster->getName() << "의 남은 HP: " << monster->getHP() << '\n';
}
