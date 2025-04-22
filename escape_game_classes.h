// escape_game_classes.h

#ifndef ESCAPE_GAME_CLASSES_H
#define ESCAPE_GAME_CLASSES_H

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <regex>

// Forward declarations
class Room;
class Monster;
class Inventory;
class TreeNode;
class Player;
class Game;
class UI;

//---------------------------------------------
// Inventory (Linked List)
//---------------------------------------------
class InventoryNode {
public:
    std::string itemName;
    InventoryNode* next;
    InventoryNode(std::string name);
};

class Inventory {
private:
    InventoryNode* head;
public:
    Inventory();
    ~Inventory();
    void addItem(std::string name);
    bool removeItem(std::string name);
    void display();
    void sort();
    bool search(std::string name);
    bool regexSearch(std::string pattern);
};

//---------------------------------------------
// Monster
//---------------------------------------------
class Monster {
public:
    std::string name;
    int hp, attack;
    Monster(std::string n, int h, int a);
};

//---------------------------------------------
// Skill Tree Node
//---------------------------------------------
class TreeNode {
public:
    std::string skillName;
    bool unlocked;
    TreeNode* left;
    TreeNode* right;
    TreeNode(std::string name);
};

//---------------------------------------------
// Player
//---------------------------------------------
class Player {
public:
    int hp, attack;
    Inventory inventory;
    TreeNode* skillTreeRoot;
    std::stack<std::string> battleLog;
    std::vector<std::string> learnedSkills;

    Player();
    void learnSkill(TreeNode* root);
    void printBattleLog();
    void useItem(std::string name);
};

//---------------------------------------------
// Room (Graph Node)
//---------------------------------------------
class Room {
public:
    std::string name;
    std::string description;
    std::vector<Room*> neighbors;
    Monster* monster;

    Room(std::string n, std::string desc);
    void connect(Room* other);
};

//---------------------------------------------
// UI
//---------------------------------------------
class UI {
public:
    static void displayMainMenu();
    static int getMenuChoice();
};

//---------------------------------------------
// Game
//---------------------------------------------
class Game {
private:
    Player player;
    std::map<std::string, Room*> dungeonMap;
    Room* currentRoom;
public:
    Game();
    ~Game();
    void start();
    void mainMenu();
    void movePlayer();
    void initiateBattle();
};

//---------------------------------------------
// Template Utility Functions
//---------------------------------------------
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
int search(T arr[], int size, T key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) return i;
    }
    return -1;
}

#endif // ESCAPE_GAME_H
