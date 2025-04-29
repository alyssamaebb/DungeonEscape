#include "SkillTree.h"
#include <iostream>

SkillNode::SkillNode(Skill skill) : skill(skill), left(nullptr), right(nullptr) {}

SkillTree::SkillTree() : root(nullptr) {}

SkillTree::~SkillTree() {
    deleteTree(root);
}

void SkillTree::deleteTree(SkillNode* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

void SkillTree::buildTree() {
    // Example tree (hardcoded for now)
    root = new SkillNode(Skill("Fireball", 10, 25));
    root->left = new SkillNode(Skill("Flame Burst", 15, 35));
    root->right = new SkillNode(Skill("Inferno", 20, 50));
    root->left->left = new SkillNode(Skill("Ember Nova", 25, 70));
    root->right->right = new SkillNode(Skill("Hellfire", 30, 90));
}

void SkillTree::display(SkillNode* node, int indent) const {
    if (!node) return;

    if (node->right) display(node->right, indent + 4);

    if (indent) std::cout << std::string(indent, ' ');
    node->skill.display();

    if (node->left) display(node->left, indent + 4);
}

void SkillTree::displayTree() const {
    std::cout << "=== Skill Tree ===\n";
    display(root);
    std::cout << "==================\n";
}

SkillNode* SkillTree::find(SkillNode* node, const std::string& skillName) {
    if (!node) return nullptr;
    if (node->skill.name == skillName) return node;

    SkillNode* leftResult = find(node->left, skillName);
    if (leftResult) return leftResult;

    return find(node->right, skillName);
}

bool SkillTree::isParentUnlocked(SkillNode* node, const std::string& skillName) {
    if (!node) return false;

    if ((node->left && node->left->skill.name == skillName) ||
        (node->right && node->right->skill.name == skillName)) {
        return node->skill.isUnlocked;
    }

    return isParentUnlocked(node->left, skillName) || isParentUnlocked(node->right, skillName);
}

void SkillTree::unlockSkill(const std::string& skillName) {
    SkillNode* target = find(root, skillName);

    if (!target) {
        std::cout << "Skill not found.\n";
        return;
    }

    if (target->skill.isUnlocked) {
        std::cout << skillName << " is already unlocked.\n";
        return;
    }

    if (target == root || isParentUnlocked(root, skillName)) {
        target->skill.unlock();
    }
    else {
        std::cout << "You must unlock the prerequisite skill first.\n";
    }
}

bool SkillTree::isSkillUnlocked(const std::string& skillName) {
    SkillNode* node = find(root, skillName);
    return node && node->skill.isUnlocked;
}

SkillNode* SkillTree::getRoot()
{
    return root;
}
