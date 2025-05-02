#include "Skill.h"
#include "AnsiColors.h"

Skill::Skill(std::string name, int manaCost, int damage, std::string emoji)
    : name(name), manaCost(manaCost), damage(damage), isUnlocked(false), emoji(emoji) {
}

void Skill::display() const {
    std::cout << emoji << " " << name << " (Mana: " << manaCost << ", Damage: " << damage << ")";
}

void Skill::unlock() {
    isUnlocked = true;
<<<<<<< HEAD
    std::cout << "You have unlocked the skill: " << ANSI_BLOOD_RED << name << ANSI_RESET << "!\n\n";
}
=======
    std::cout << ANSI_GREEN << "You have unlocked the skill: " << ANSI_BLOOD_RED << name << ANSI_RESET << "!\n\n";
}

void Skill::display() const {
    std::cout << name << " (Mana: " << manaCost << ", Damage: " << damage << ")";
    if (!isUnlocked) std::cout << " [Locked]";
    std::cout << std::endl;
}
>>>>>>> 259a4bdd8a00628312bb88158d6771b837f746b3
