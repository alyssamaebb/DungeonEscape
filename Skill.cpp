#include "Skill.h"
#include "AnsiColors.h"

Skill::Skill(std::string name, std::string icon, int manaCost, int damage)
    : name(name), icon(icon), manaCost(manaCost), damage(damage), isUnlocked(false){
}

void Skill::unlock() {
    isUnlocked = true;
    std::cout << ANSI_GREEN << "You have unlocked the skill: " << ANSI_BLOOD_RED << name << ANSI_RESET << "!\n\n";
}

void Skill::display() const {
    std::cout << name << icon << " (Mana: " << manaCost << ", Damage: " << damage << ")";
    if (!isUnlocked) std::cout << " [Locked]";
    std::cout << std::endl;
}

void Skill::printSkill()
{
    std::cout << name << icon;
}
