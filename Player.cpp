#include "Player.h"
#include <iostream>

Player::Player(std::string name) : name(name), level(1) {}

void Player::levelUp() {
    level++;
    std::cout << name << " leveled up to Level " << level << "!\n";
}

void Player::unlockSkill(const std::string& skillName) {
    skillTree.unlockSkill(skillName);
}

void Player::displayStats() {
    std::cout << "=== " << name << "'s Stats ===\n";
    std::cout << "Level: " << level << "\n";
    skillTree.displayTree();
}

void Player::setSkillTree(SkillTree& tree) {
    skillTree = tree;
}

bool Player::canUseSkill(const std::string& skillName) {
    return skillTree.isSkillUnlocked(skillName);
}
