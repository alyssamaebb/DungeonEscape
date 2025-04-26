#include "escape_game_classes.h"
#include "Room.h"
#include "Monster.h"
// #include "Player.h"

Game::Game() {
    // Initialize the player
    player = Player();

	// Create the dungeon
	createDungeon();

    // Display initial game state
    std::cout << "Welcome to the Dungeon Escape Game!" << std::endl;
    std::cout << "You are starting in: " << currentRoom->name << std::endl;
    std::cout << currentRoom->description << std::endl;
}
Game::~Game() {
    for (auto& pair : dungeonMap) {
        delete pair.second; // Delete each room
    }
    dungeonMap.clear();
}
void Game::createDungeon() {
    // Create rooms
    Room* room1 = new Room("Entrance", "You are at the entrance of the dungeon.");
    Room* room2 = new Room("Hallway", "A long, dark hallway.");
    Room* room3 = new Room("Monster Lair", "A lair of a fearsome monster.");
    Room* room4 = new Room("Treasure Room", "A room filled with gold and jewels.");
    Room* room5 = new Room("Exit", "The exit of the dungeon.");

    // Connect rooms
    room1->connect(room2);
    room2->connect(room3);
    room3->connect(room4);
    room4->connect(room5);

    // Add rooms to the dungeon map
    dungeonMap["Entrance"] = room1;
    dungeonMap["Hallway"] = room2;
    dungeonMap["Monster Lair"] = room3;
    dungeonMap["Treasure Room"] = room4;
    dungeonMap["Exit"] = room5;

    // Create and place monsters
    Monster* goblin = new Monster("Goblin", 30, 5);
    Monster* orc = new Monster("Orc", 50, 10);
    dungeonMap["Monster Lair"]->setMonster(goblin);
    dungeonMap["Treasure Room"]->setMonster(orc);

    // Set the starting room
    currentRoom = dungeonMap["Entrance"];
}
Room* Game::findRoom(const std::string& roomName) {
    // Search for the room in the dungeon map
    auto it = dungeonMap.find(roomName);

    // If the room is found, return the pointer to the room
    if (it != dungeonMap.end()) {
        return it->second;
    }

    // If the room is not found, return nullptr
    return nullptr;
}

