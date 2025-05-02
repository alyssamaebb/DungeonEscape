#ifndef SKILL_H
#define SKILL_H

#include <string>
#include <iostream>

class Skill {
public:
    std::string name;
    int manaCost;
    int damage;
    bool isUnlocked;
    std::string emoji; // New attribute for the emoji

    Skill(std::string name, int manaCost, int damage, std::string emoji);
    void unlock();
    void display() const;
};

#endif