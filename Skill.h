#ifndef SKILL_H
#define SKILL_H

#include <string>
#include <iostream>

class Skill {
public:
    std::string name;
    std::string icon;
    int manaCost;
    int damage;
    bool isUnlocked;

    Skill(std::string name, std::string icon, int manaCost, int damage);
    void unlock();
    void display() const;
};

#endif