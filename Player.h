#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <stack>
#include "SkillTree.h"

// Simple inventory node for linked list
struct ItemNode {
    std::string itemName;
    ItemNode* next;
    ItemNode(const std::string& name) : itemName(name), next(nullptr) {}
};

class Player {
private:
    std::string name;
    int level;
    SkillTree skillTree;
    ItemNode* inventoryHead; // Head of linked list
    std::vector<std::string> learnedSkills; // List of unlocked skills
    std::stack<std::string> battleLog; // History of battle actions

public:
    Player(std::string name);

    void levelUp();
    void unlockSkill(const std::string& skillName);
    void displayStats();
    void setSkillTree(SkillTree& tree);
    bool canUseSkill(const std::string& skillName);

    // New methods
    void showInventory();
    void useItem(const std::string& itemName);

    void learnSkill(SkillNode* root); // note: TreeNode renamed to SkillNode
    void printBattleLog();

    // Add helper for adding to inventory or battle log if needed
    void addItem(const std::string& itemName);
    void logBattleAction(const std::string& action);
};

#endif
