#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <stack>
#include "SkillTree.h"
#include "Monster.h"

class Player {
private:
    std::string name;
    int hp;
    int mana;
    int level;
    SkillTree skillTree;
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
    SkillTree& getSkillTree(); // Getter for skill tree

    void learnSkill(SkillNode* root); // note: TreeNode renamed to SkillNode
    void printBattleLog();

    // Add helper for adding to inventory or battle log if needed
    void logBattleAction(const std::string& action);

    bool battle(Monster* monster);
};

#endif
