#include "Game.h"
#include "AnsiColors.h"
#include <limits> // for clearing input buffer
#include <iostream>

// Display a line of text, then press pause until the player presses ENTER
void waitForEnter(const std::string& line) {
    std::cout << line << "\n";
    std::cout << ANSI_GREY << "Press ENTER to continue..." << ANSI_RESET;
    std::cin.get(); // Wait for ENTER key
}

// Constructor: Set up game intro and create the dungeon
Game::Game(Player& player) : player(player) {
	// Display game title
	std::cout << "=============================\n";
	std::cout << "  DUNGEON ESCAPE GAME\n";
	std::cout << "=============================\n\n";

    // Backstory one line at a time
    waitForEnter(ANSI_BLOOD_RED "You wake up in a dark, cold dungeon with no memory of how you got here." ANSI_RESET);
    waitForEnter(ANSI_WARNING_YELL "The stone walls are damp, and the air smells of rust and decay." ANSI_RESET);
    waitForEnter(ANSI_BLOOD_RED "Whispers echo through the stone halls... are they real, or just in your mind?" ANSI_RESET);
    waitForEnter(ANSI_WARNING_YELL "You hear distant footsteps... and realize you are not alone." ANSI_RESET);
    waitForEnter(ANSI_BLOOD_RED "Somewhere ahead lies your only chance at escape - if you can survive." ANSI_RESET);

	// Create the dungeon
	createDungeon();
}

// Destructor: Clean up dynamically allocated rooms
Game::~Game() {
    for (auto& pair : dungeonMap) {
        delete pair.second;
    }
    dungeonMap.clear();
}

// Build the dungeon map by creating and connecting rooms
void Game::createDungeon() {
    // Create rooms
    room1 = new Room("Entrance", "You are at the entrance of the dungeon.\n");
    room2 = new Room("Inventory Room", "You are in a dusty storage room filled with old supplies.\n");
    room3 = new Room("Monster Lair 1", "You are in the lair of a fearsome goblin.\n");
    room4 = new Room("Monster Lair 2", "You are in the lair of a brutal orc.\n");
    room5 = new Room("Exit", "You have reached the final door out of the dungeon.\n");
    
    // Connect rooms
    room1->connect(room2);
    room2->connect(room3);
    room3->connect(room1);
    room3->connect(room2);

    // Add rooms to the dungeon map
    dungeonMap["Entrance"] = room1;
    dungeonMap["Inventory Room"] = room2;
    dungeonMap["Monster Lair 1"] = room3;
    dungeonMap["Monster Lair 2"] = room4;
    dungeonMap["Exit"] = room5;

    // Create and place monsters
    Monster* goblin = new Monster("Goblin", 100, 15);
    Monster* orc = new Monster("Orc", 200, 30);
    dungeonMap["Monster Lair 1"]->setMonster(goblin);
    dungeonMap["Monster Lair 2"]->setMonster(orc);
    
    // Set the starting room
    currentRoom = dungeonMap["Entrance"];
}

// Display the current room's name, description, monster, and neighbors
void Game::displayCurrentRoom() {
    // Check if the current room is valid
    if (currentRoom == nullptr) {
        std::cout << "Error: You are not in any room!" << std::endl;
        return;
    }

    // Display the room description
    std::cout << "==================================================\n";
    std::cout << currentRoom->description << std::endl;

    // Display monster information (if present)
    if (currentRoom->monster != nullptr) {
        std::cout << "A " << currentRoom->monster->name << " is here!" << std::endl;
        std::cout << "Monster HP: " << currentRoom->monster->hp << ", Attack: " << currentRoom->monster->attack << std::endl;
    }

    // Display neighboring rooms
    if (!currentRoom->neighbors.empty()) {
        std::cout << ANSI_WARNING_YELL "Neighboring rooms:" ANSI_RESET << std::endl;
        for (size_t i = 0; i < currentRoom->neighbors.size(); ++i) {
            std::cout << i + 1 << ". " << currentRoom->neighbors[i]->name << std::endl;
        }
        std::cout << "==================================================\n";
    }
    else {
        std::cout << "There are no neighboring rooms." << std::endl;
    }
}

// Allow the player to select and move to a neighboring room
void Game::movePlayer() {
    // Check if the current room is valid
    if (currentRoom == nullptr) {
        std::cout << "Error: You are not in any room!" << std::endl;
        return;
    }

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
    if (choice < 1 || choice >= static_cast<int>(currentRoom->neighbors.size()+1)) {
        std::cout << "Invalid choice. Please try again." << std::endl;
        return;
    }

    // Move to the selected room
    currentRoom = currentRoom->neighbors[choice - 1];
    std::cout << "You moved to: " << currentRoom->name << std::endl;
}
void Game::endGame()
{
    std::cout << "GAME OVER!" << std::endl;
}

// Helper function for main.cpp
void Game::handleBattle(Inventory& inventory)
{
    if (currentRoom && currentRoom->monster) {
        bool monsterDefeated = player.battle(currentRoom->monster);
        if (monsterDefeated) {
            delete currentRoom->monster;
            currentRoom->monster = nullptr;
            if (currentRoom->name == "Monster Lair 1") {
                currentRoom->connect(room4);
                room4->connect(room1);
                room4->connect(room2);
                inventory.addItem("Goblin Key");
                std::cout << ANSI_GREEN << "\nYou have acquired the Goblin Key!" << ANSI_RESET << std::endl;
            }
            else if (currentRoom->name == "Monster Lair 2") {
                currentRoom->connect(room1);
                currentRoom->connect(room2);
                currentRoom->connect(room5);
                inventory.addItem("Orc Key");
                std::cout << ANSI_GREEN << "\nThe Orc Key is hidden in the final room of the dungeon!" << ANSI_RESET << std::endl;
            }
        }
        else {
            endGame();
        }
    }
    else {
        std::cout << "There is no monster to battle in this room.\n";
    }
}

void Game::start(Inventory& inventory)
{
    bool playing = true;
    while (playing) {
        UI::displayMainMenu();
        int choice = UI::getMenuChoice();

        switch (choice) {
        case 1:
            movePlayer();
            displayCurrentRoom();
            break;
        case 2:
            inventory.sort();
            inventory.display();
            break;
        case 3:
            UI::searchInventory(inventory);
            break;
        case 4:
            handleBattle(inventory);
            break;
        case 5:
            player.learnSkill(player.getSkillTree().getRoot());
            break;
        case 6:
            player.printBattleLog();
            break;
        case 7:
            if (room4->monster == nullptr) {
                std::cout << ANSI_BLUE << "\nYou used the Goblin and Orc Keys to escape the Dungeon!" << ANSI_RESET << std::endl;
            }
            UI::displayExitMessage();
            playing = false;
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
