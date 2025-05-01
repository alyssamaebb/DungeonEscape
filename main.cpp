// Created by Alyssa

#include "Game.h"
#include "UI.h"
#include "Player.h"
#include "Room.h"
#include "Inventory.h"
#include <iostream>
#include <cstdlib>

#define ANSI_GREEN	"\033[92m"
#define ANSI_RESET	"\033[0m"
#define ANSI_BLUE	"\033[94m"

// Helper function to handle battling
void handleBattle(Game& game, Player& player, Inventory& inventory)
{
	Room* currentRoom = game.currentRoom;
	if (currentRoom && currentRoom->monster) {
        bool monsterDefeated = player.battle(currentRoom->monster);
        if (monsterDefeated) {
            delete currentRoom->monster;
            currentRoom->monster = nullptr;
			if (currentRoom->name == "Monster Lair 1")
			{
				currentRoom->connect(game.room4);
				game.room4->connect(game.room1);
				game.room4->connect(game.room2);
				inventory.addItem("Goblin Key");
				std::cout << ANSI_GREEN << "\nYou have acquired the Goblin Key!" << ANSI_RESET << std::endl;
			}
			else if (currentRoom->name == "Monster Lair 2")
			{
				currentRoom->connect(game.room1);
				currentRoom->connect(game.room2);
				currentRoom->connect(game.room5);
				inventory.addItem("Orc Key");
				std::cout << ANSI_GREEN << "\nYou have acquired the Orc Key!" << ANSI_RESET << std::endl;
			}
        }
		else
		{
			game.endGame();
		}
    }
    else {
        std::cout << "There is no monster to battle in this room.\n";
    }
}

int main()
{
	UI ui;

    	// Ask for player's name first
    	std::string playerName = ui.askPlayerName();

    	// Create player object with that name
    	Player player(playerName);
	
	Game game(player); // Create the game object
	Inventory inventory; // Create the inventory for the player

	game.displayCurrentRoom(); // Show the starting room to the player
	std::cout << "\n";

	game.player.unlockSkill("Fireball");
	
	inventory.addItem("Healing Amulet");
	std::cout << ANSI_GREEN << "\nYou have acquired a Healing Amulet!\nMay it bring you luck on your journey..." << ANSI_RESET << std::endl;
	
	bool playing = true;
	while (playing) {
		UI::displayMainMenu(); // Display the main menu
		int choice = UI::getMenuChoice(); // Get the user's menu choice

		switch (choice) {
		case 1:
			game.movePlayer(); // Move to another room
			game.displayCurrentRoom(); // Show the new room immediately
			break;
		case 2:
			inventory.sort();
			inventory.display();
			//player.showInventory(); // Display the player's inventory
			break;
		case 3: 
			handleBattle(game, player, inventory); // Use helper function for battling
           		break;
		case 4: 
			player.learnSkill(player.getSkillTree().getRoot()); // Learn a new skill
			break;
		case 5:
			player.printBattleLog(); // View battle log
			break;
		case 6:
			std::cout << ANSI_BLUE << "\nYou used the Goblin and Orc Keys to escape the Dungeon!" << ANSI_RESET << std::endl;
			std::cout << "==================================================\n";
			std::cout << "Thank you for playing Dungeon Escape Game!\n";
			playing = false; // Exit the game
			break;
		default:
			std::cout << "Invalid choice. Please try again.\n";
		}
	}

	return 0;
}
