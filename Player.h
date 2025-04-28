#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <stack>
#include "SkillTree.h"
#include "Monster.h"

// Simple inventory node for linked list
struct ItemNode {
    std::string itemName;
    ItemNode* next;
    ItemNode(const std::string& name) : itemName(name), next(nullptr) {}
};

class Player {
private:
    std::string name;
    int hp;
    int mana;
    int level;
    SkillTree skillTree;
    ItemNode* inventoryHead; // Head of linked list
    std::vector<std::string> learnedSkills; // List of unlocked skills
    std::stack<std::string> battleLog; // History of battle actions

public:
    // Default constructor
    Player();

    // Parameterized constructor (already defined)
    Player(std::string name);
    
    void levelUp();
    void unlockSkill(const std::string& skillName);
    void displayStats();
    void setSkillTree(SkillTree& tree);
    bool canUseSkill(const std::string& skillName);
    void useSkill(const std::string& skillName, Monster& monster);
	SkillTree& getSkillTree() { return skillTree; } // Getter for skill tree

    // New methods
    void showInventory();
    void useItem(const std::string& itemName);

    void learnSkill(SkillNode* root); // note: TreeNode renamed to SkillNode
    void printBattleLog();

    // Add helper for adding to inventory or battle log if needed
    void addItem(const std::string& itemName);
    void logBattleAction(const std::string& action);

    bool battle(Monster* monster);
};

#endif
