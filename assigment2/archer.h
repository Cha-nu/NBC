#pragma once

#include "player.h"
#include <string>
using namespace std;

class Archer : public Player
{
public:
    Archer(string nickname);
    void attack() override;
    void attack(Monster* monster) override;
};