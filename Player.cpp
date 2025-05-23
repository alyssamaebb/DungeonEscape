#include "Player.h"
#include "Skill.h"
#include <iostream>
#include <cstdlib>

// default constructor
Player::Player() : name("Unknown Player"), level(1), hp(100), mana(100) {
    // Optionally, initialize the skill tree with a default structure
	skillTree.buildTree();

}

// parameterized constructor
Player::Player(std::string name) : name(name), level(1), hp(100), mana(100) {
	skillTree.buildTree();  // Build the skill tree when the player is created
}

void Player::levelUp() {
    level++;
    mana += 20;  // Increase mana as the player levels up (optional)
    std::cout << name << " leveled up to Level " << level << "!\n";
}

void Player::unlockSkill(const std::string& skillName) {
	skillTree.unlockSkill(skillName);
    learnedSkills.push_back(skillName);
}

void Player::displayStats() {
    std::cout << "=== " << name << "'s Stats ===\n";
    std::cout << "Level: " << level << "\n";
    std::cout << "Mana: " << mana << "\n";
    skillTree.displayTree();
}

void Player::setSkillTree(SkillTree& tree) {
    skillTree = tree;
}

bool Player::canUseSkill(const std::string& skillName) {
    return skillTree.isSkillUnlocked(skillName);
}

bool Player::learnSkill(SkillNode* node) {
    if (!node) return false; // Base case: null node

    system("cls");

    // Preorder traversal: visit, left, right
    if (!node->skill.isUnlocked) {
        skillTree.displayTree();  // Display the skill tree
        std::cout << std::endl;

        // Check if the parent skill is unlocked (if not the root)
        if (node != skillTree.getRoot() && !skillTree.isParentUnlocked(skillTree.getRoot(), node->skill.name)) {
            std::cout << "You must unlock the prerequisite skill first.\n";
            return false; // Stop if the parent skill is not unlocked
        }

        // Display skill details and prompt the player to unlock
        std::cout << "Available Skill: " << node->skill.name << "\n";
        std::cout << "  Mana Cost: " << node->skill.manaCost
            << ", Damage: " << node->skill.damage << "\n";
        std::cout << "  Unlock this skill? (y/n): ";
        char choice;
        std::cin >> choice;
        std::cout << std::endl;

        if (choice == 'y' || choice == 'Y') {
            // Unlock the skill
            skillTree.unlockSkill(node->skill.name);
            learnedSkills.push_back(node->skill.name);
            std::cout << "Skill unlocked: " << node->skill.name << "\n\n";
            return true; // Stop further traversal after unlocking a skill
        }
        else {
            std::cout << "Skill not unlocked.\n";
        }
    }

    // Recursively attempt to unlock a skill in the left or right subtree
    if (learnSkill(node->left)) return true;
    if (learnSkill(node->right)) return true;

    return false; // No skill was unlocked in this branch
}

void Player::printBattleLog() {
    std::cout << "=== Battle Log ===\n";
    std::stack<std::string> tempLog = battleLog;
    while (!tempLog.empty()) {
        std::cout << tempLog.top() << "\n";
        tempLog.pop();
    }
}

void Player::logBattleAction(const std::string& action) {
    battleLog.push(action);
}

void Player::useSkill(const std::string& skillName, Monster& monster) {
    if (!canUseSkill(skillName)) {
        std::cout << "Skill " << skillName << " is not unlocked yet.\n";
        return;
    }

    SkillNode* skillNode = skillTree.find(skillTree.getRoot(), skillName);  // Get the skill node from the tree
    if (!skillNode) {
        std::cout << "Skill " << skillName << " not found in the skill tree.\n";
        return;
    }

    if (mana >= skillNode->skill.manaCost) {
        mana -= skillNode->skill.manaCost;  // Deduct mana
        std::cout << std::endl;
        std::cout << name << " used " << skillName << "!\n";
        std::cout << "Mana cost: " << skillNode->skill.manaCost << ", Remaining mana: " << mana << "\n\n";

        // Apply damage to the monster
        int damage = skillNode->skill.damage;
        monster.hp -= damage;  // Call the Monster's takeDamage method
        std::cout << "Dealt " << damage << " damage to " << monster.name << "!\n\n";

        // Log the action
        logBattleAction(name + " used " + skillName + " and dealt " + std::to_string(damage) + " damage to " + monster.name + ".");
    }
    else {
        std::cout << "Not enough mana to use " << skillName << ".\n";
    }
}

SkillTree& Player::getSkillTree()
{
	return skillTree;
}

bool Player::battle(Monster* monster) {
    if (!monster) {
        std::cout << "There is no monster here to battle.\n";
        return NULL;
    }

    std::cout << "A battle begins between " << name << " and " << monster->name << "!\n";

    while (hp > 0 && monster->hp > 0) {
        // Display player's stats
        std::cout << "\n=== " << name << "'s Turn ===\n";
        std::cout << "HP: " << hp << ", Mana: " << mana << "\n";

        // Display available skills with numbers and emojis
        std::cout << "Available Skills:\n";
        for (size_t i = 0; i < learnedSkills.size(); ++i) {
            SkillNode* skillNode = skillTree.find(skillTree.getRoot(), learnedSkills[i]);
            if (skillNode) {
                std::cout << i + 1 << ". " << skillNode->skill.icon << " " << skillNode->skill.name << "\n";
            }
        }

        // Player chooses a skill by number
        std::cout << "Enter the number of the skill to use: ";
        int skillChoice;
        std::cin >> skillChoice;

        // Validate the input
        if (skillChoice < 1 || skillChoice > static_cast<int>(learnedSkills.size())) {
            std::cout << "Invalid choice. Skipping turn.\n";
        }
        else {
            // Use the chosen skill
            std::string chosenSkill = learnedSkills[skillChoice - 1];
            if (canUseSkill(chosenSkill)) {
                useSkill(chosenSkill, *monster);
            }
            else {
                std::cout << "Invalid skill or not enough mana. Skipping turn.\n";
            }
        }

        // Check if the monster is defeated
        if (monster->hp <= 0) {
            std::cout << monster->name << " has been defeated!\n";
            logBattleAction(monster->name + " was defeated!");
            std::cout << "Your stats were replenished by Healing Amulet!\n";
            hp = 100;
            mana = 100;
            return true;
        }

        // Monster's turn to attack
        std::cout << "\n=== " << monster->name << "'s Turn ===\n";
        hp -= monster->attack;
        std::cout << monster->name << " attacks " << name << " for " << monster->attack << " damage!\n";
        logBattleAction(monster->name + " dealt " + std::to_string(monster->attack) + " damage to " + name);

        // Check if the player is defeated
        if (hp <= 0) {
            std::cout << name << " has been defeated!\n";
            logBattleAction(name + " was defeated!");
            hp = 100;
            mana = 100;
            if (monster->name == "Goblin") {
                monster->hp = 100;
            }
            else if (monster->name == "Orc") {
                monster->hp = 200;
            }
            return false;
        }
    }
    return false; // This line is unreachable but keeps the compiler happy
}
