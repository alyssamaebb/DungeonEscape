#include "Skill.h"
#include <iostream>

Skill::Skill(std::string name, int manaCost, int damage)
    : name(name), manaCost(manaCost), damage(damage), isUnlocked(false) {
}

void Skill::unlock() {
    isUnlocked = true;
    std::cout << "You have unlocked the skill: " << name << "!\n";
}

void Skill::display() const {
    std::cout << name << " (Mana: " << manaCost << ", Damage: " << damage << ")";
    if (!isUnlocked) std::cout << " [Locked]";
    std::cout << std::endl;
}