#include "Player.h"
#include <iostream>

Player::Player(std::string name) : name(name), level(1), inventoryHead(nullptr) {}

void Player::levelUp() {
    level++;
    std::cout << name << " leveled up to Level " << level << "!\n";
}

void Player::unlockSkill(const std::string& skillName) {
    skillTree.unlockSkill(skillName);
    learnedSkills.push_back(skillName);
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

// === New Methods ===

void Player::showInventory() {
    std::cout << "Inventory:\n";
    ItemNode* current = inventoryHead;
    while (current) {
        std::cout << "- " << current->itemName << "\n";
        current = current->next;
    }
}

void Player::useItem(const std::string& itemName) {
    ItemNode* current = inventoryHead;
    ItemNode* prev = nullptr;

    while (current) {
        if (current->itemName == itemName) {
            if (prev) prev->next = current->next;
            else inventoryHead = current->next;

            std::cout << "Used item: " << itemName << "\n";
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
    std::cout << "Item not found: " << itemName << "\n";
}

void Player::learnSkill(SkillNode* node) {
    if (!node) return;

    // Preorder traversal: visit, left, right
    if (!node->skill.isUnlocked) {
        std::cout << "Available Skill: " << node->skill.name << "\n";
        std::cout << "  Mana Cost: " << node->skill.manaCost
            << ", Damage: " << node->skill.damage << "\n";
        std::cout << "  Unlock this skill? (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            if (skillTree.isSkillUnlocked(node->skill.name)) {
                std::cout << "Already unlocked.\n";
            }
            else {
                skillTree.unlockSkill(node->skill.name);
                learnedSkills.push_back(node->skill.name);
                std::cout << "Skill unlocked: " << node->skill.name << "\n";
            }
        }
    }

    learnSkill(node->left);
    learnSkill(node->right);
}

void Player::printBattleLog() {
    std::cout << "=== Battle Log ===\n";
    std::stack<std::string> tempLog = battleLog;
    while (!tempLog.empty()) {
        std::cout << tempLog.top() << "\n";
        tempLog.pop();
    }
}

// Optional helper
void Player::addItem(const std::string& itemName) {
    ItemNode* newItem = new ItemNode(itemName);
    newItem->next = inventoryHead;
    inventoryHead = newItem;
}

void Player::logBattleAction(const std::string& action) {
    battleLog.push(action);
}
