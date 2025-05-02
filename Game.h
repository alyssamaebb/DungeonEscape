// Created by Alyssa

#ifndef GAME_H
#define GAME_H

#include <map>
#include <string>
#include "Room.h"
#include "Player.h"
#include "Monster.h"
#include "Inventory.h"

class Room;

// Handles overall game flow and dungeon management
class Game {
private:
    std::map<std::string, Room*> dungeonMap; // Dungeon represented as a map of rooms
    //Room* currentRoom; // Current room where the player is located
public:
    Room* currentRoom; // Current room where the player is located
    Room* room1;
    Room* room2;
    Room* room3;
    Room* room4;
    Room* room5;
    Player& player;

    Game(Player& player);
    ~Game();

    void start(Inventory& inventory);
    void movePlayer(); // Move to a neighboring room
    void createDungeon(); // Build the dungeon map
    void displayCurrentRoom(); // Display the current room's details
    void endGame();
    void handleBattle(Inventory& inventory);
};

#endif // GAME_H
