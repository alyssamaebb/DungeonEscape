// TEAMATE: Kandice Estrella, Joshua Seepersaud
#ifndef MONSTER_H
#define MONSTER_H

//---------------------------------------------
// Monster
//---------------------------------------------
class Monster {
public:
    std::string name;
    int hp, attack;
    Monster(std::string n, int h, int a);
    void battle(Player& player);
};

#endif