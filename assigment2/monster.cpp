#include "monster.h"
#include "player.h"
#include <iostream>

using namespace std;

Monster::Monster(string name)
{
    this->name = name;
    this->HP = 200;
    this->power = 30;
    this->defence = 10;
    this->speed = 10;
}

void Monster::attack(Player *player)
{
    int damage = this->power - player->getDefence();
    if (damage <= 0)
        damage = 1;
    cout << this->name << "이(가) " << player->getNickname() << "에게 " << damage << "의 데미지를 입혔습니다!" << '\n';
    player->setHP(player->getHP() - damage);
    if (player->getHP() > 0)
        cout << player->getNickname() << "의 남은 HP: " << player->getHP() << '\n';
}

string Monster::getName()
{
    return this->name;
}

int Monster::getHP()
{
    return this->HP;
}

int Monster::getPower()
{
    return this->power;
}

int Monster::getDefence()
{
    return this->defence;
}

int Monster::getSpeed()
{
    return this->speed;
}

void Monster::setName(string name)
{
    this->name = name;
}

void Monster::setHP(int HP)
{
    this->HP = HP;
}

void Monster::setPower(int power)
{
    this->power = power;
}

void Monster::setDefence(int defence)
{
    this->defence = defence;
}

void Monster::setSpeed(int speed)
{
    this->speed = speed;
}
