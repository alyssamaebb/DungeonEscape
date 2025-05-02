#include "Skill.h"
#include <iostream>

#define ANSI_RESET        "\033[0m"
#define ANSI_BLOOD_RED    "\033[91m"

Skill::Skill(std::string name, int manaCost, int damage, std::string emoji)
    : name(name), manaCost(manaCost), damage(damage), isUnlocked(false), emoji(emoji) {
}

void Skill::display() const {
    std::cout << emoji << " " << name << " (Mana: " << manaCost << ", Damage: " << damage << ")";
}

void Skill::unlock() {
    isUnlocked = true;
    std::cout << "You have unlocked the skill: " << ANSI_BLOOD_RED << name << ANSI_RESET << "!\n\n";
}