#include "escape_game_classes.h"
#include "Room.h"
#include "Monster.h"
// #include "Player.h"

#include <limits> // for clearing input buffer

// Helper function to display a line and wait for ENTER
void waitForEnter(const std::string& line) {
    std::cout << line << "\n";
	std::cout << "Press ENTER to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get(); // Wait for ENTER key
}

Game::Game() {
	// Display game title
	std::cout << "=============================\n";
	std::cout << "  DUNGEON ESCAPE GAME\n";
	std::cout << "=============================\n\n";

    // Backstory one line at a time
    waitForEnter("You wake up in a dark, cold dungeon with no memory of how you got here.");
    waitForEnter("The stone walls are damp, and the air smells of rust and decay.");
    waitForEnter("Whispers echo through the stone halls... are they real, or just in your mind?");
    waitForEnter("You hear distant footsteps... and realize you are not alone.");
    waitForEnter("Somewhere ahead lies your only chance at escape - if you can survive.");

	// Create the dungeon
	createDungeon();

    // Display starting room
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
void Game::displayCurrentRoom() {
    // Check if the current room is valid
    if (currentRoom == nullptr) {
        std::cout << "Error: You are not in any room!" << std::endl;
        return;
    }

    // Display the room name
    std::cout << "You are in: " << currentRoom->name << std::endl;

    // Display the room description
    std::cout << currentRoom->description << std::endl;

    // Display monster information (if present)
    if (currentRoom->monster != nullptr) {
        std::cout << "A " << currentRoom->monster->name << " is here!" << std::endl;
        std::cout << "Monster HP: " << currentRoom->monster->hp << ", Attack: " << currentRoom->monster->attack << std::endl;
    }
    else {
        std::cout << "There are no monsters in this room." << std::endl;
    }

    // Display neighboring rooms
    if (!currentRoom->neighbors.empty()) {
        std::cout << "Neighboring rooms:" << std::endl;
        for (size_t i = 0; i < currentRoom->neighbors.size(); ++i) {
            std::cout << i + 1 << ". " << currentRoom->neighbors[i]->name << std::endl;
        }
    }
    else {
        std::cout << "There are no neighboring rooms." << std::endl;
    }
}
void Game::movePlayer() {
    // Check if the current room is valid
    if (currentRoom == nullptr) {
        std::cout << "Error: You are not in any room!" << std::endl;
        return;
    }

    // Display the current room and its neighbors
    std::cout << "You are in: " << currentRoom->name << std::endl;
    std::cout << currentRoom->description << std::endl;

    if (currentRoom->neighbors.empty()) {
        std::cout << "There are no neighboring rooms to move to." << std::endl;
        return;
    }

    std::cout << "Neighboring rooms:" << std::endl;
    for (size_t i = 0; i < currentRoom->neighbors.size(); ++i) {
        std::cout << i + 1 << ". " << currentRoom->neighbors[i]->name << std::endl;
    }

    // Get the player's choice
    int choice;
    std::cout << "Enter the number of the room you want to move to: ";
    std::cin >> choice;

    // Validate the choice
    if (choice < 1 || choice > static_cast<int>(currentRoom->neighbors.size())) {
        std::cout << "Invalid choice. Please try again." << std::endl;
        return;
    }

    // Move to the selected room
    currentRoom = currentRoom->neighbors[choice - 1];
    std::cout << "You moved to: " << currentRoom->name << std::endl;

    // Display the new room's details
    displayCurrentRoom();
}