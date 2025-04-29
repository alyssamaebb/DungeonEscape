#ifndef SKILLTREE_H
#define SKILLTREE_H

#include "Skill.h"

class SkillNode {
public:
    Skill skill;
    SkillNode* left;
    SkillNode* right;

    SkillNode(Skill skill);
};

class SkillTree {
private:
    SkillNode* root;

    void display(SkillNode* node, int indent = 0) const;
    bool isParentUnlocked(SkillNode* node, const std::string& skillName);

public:
    SkillTree();
    ~SkillTree();

    SkillNode* find(SkillNode* node, const std::string& skillName);
    void buildTree(); // Simple hardcoded tree for example
    void displayTree() const;
    void unlockSkill(const std::string& skillName);
    bool isSkillUnlocked(const std::string& skillName);
    SkillNode* getRoot();

    void deleteTree(SkillNode* node); // Destructor helper
};

#endif