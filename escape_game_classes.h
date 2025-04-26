// escape_game_classes.h

#ifndef ESCAPE_GAME_CLASSES_H
#define ESCAPE_GAME_CLASSES_H

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <regex>
#include <unordered_set>

// Forward declarations
class Room;
class Monster;
class Inventory;
class TreeNode;
class Player;
class Game;
class UI;

//---------------------------------------------
// Game
//---------------------------------------------
class Game {
private:
    std::map<std::string, Room*> dungeonMap;
    Room* currentRoom;
public:
    Game();
    ~Game();
    // Core Methods
    void start();
    void mainMenu();
    void movePlayer();
    void initiateBattle();
    // Dungeon management
    void createDungeon();
    Room* findRoom(const std::string& roomName);
    // Player interaction
    void displayCurrentRoom();
    void manageInventory();
    //void upgradeSkills(); // Optional if keeping the same method in the Skills class
    // Game state
    bool isGameOver();
    void endGame();
    // Utility
    //void displayMap(); // Optional
    //void saveGame();// Optional
    //void loadGame();// Optional
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
