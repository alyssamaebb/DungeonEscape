#ifndef PLAYER_H
#define PLAYER_H

#include "SkillTree.h"

class Player {
private:
    std::string name;
    int level;
    SkillTree skillTree;

public:
    Player(std::string name);
    void levelUp();
    void unlockSkill(const std::string& skillName);
    void displayStats();
    void setSkillTree(SkillTree& tree);
    bool canUseSkill(const std::string& skillName);
};

#endif
