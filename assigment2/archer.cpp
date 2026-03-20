#include "archer.h"
#include "monster.h"
#include <string>
#include <iostream>
using namespace std;

Archer::Archer(string nickname) : Player(nickname)
{
    this->job_name = "궁수";
    this->setNickname(nickname); 
    this->level = 1;
    this->HP = 100;
    this->MP = 50;
    this->accuracy = 40;
    this->power = 20;
    this->defence = 10;
    this->speed = 20;
}

void Archer::attack()
{
    cout << "활을 쏩니다!" << '\n';
}

void Archer::attack(Monster *monster)
{
    cout << "활을 쏩니다!" << '\n';
    // 궁수: 계산된 데미지/3으로 3회 공격
    for (int i = 0; i < 3; i++)
    {
        int damage = this->power - monster->getDefence();
        if (damage <= 0)
            damage = 1;
        cout << this->nickname << "이(가) " << monster->getName() << "에게 " << damage << "의 데미지를 입혔습니다!" << '\n';
        monster->setHP(monster->getHP() - damage);
        if (monster->getHP() > 0)
            cout << monster->getName() << "의 남은 HP: " << monster->getHP() << '\n';
    }

}
