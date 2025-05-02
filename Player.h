#ifndef PLAYER_H
#define PLAYER_H

#include "SkillTree.h"
#include "Skill.h"
#include "Monster.h"
#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <cstdlib>

class Player {
private:
    int hp;
    int mana;
    int level;
    SkillTree skillTree;
    std::vector<std::string> learnedSkills;
    std::stack<std::string> battleLog;

public:
    std::string name;

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
    SkillTree& getSkillTree();

    bool learnSkill(SkillNode* root);
    void printBattleLog();

    // Add helper for adding to inventory or battle log if needed
    void logBattleAction(const std::string& action);

    bool battle(Monster* monster);
};

#endif
