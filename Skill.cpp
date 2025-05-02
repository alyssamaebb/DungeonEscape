#include "Skill.h"
#include "AnsiColors.h"

Skill::Skill(std::string name, int manaCost, int damage)
    : name(name), manaCost(manaCost), damage(damage), isUnlocked(false){
}

void Skill::unlock() {
    isUnlocked = true;
    std::cout << ANSI_GREEN << "You have unlocked the skill: " << ANSI_BLOOD_RED << name << ANSI_RESET << "!\n\n";
}

void Skill::display() const {
    std::cout << name << " (Mana: " << manaCost << ", Damage: " << damage << ")";
    if (!isUnlocked) std::cout << " [Locked]";
    std::cout << std::endl;
}
