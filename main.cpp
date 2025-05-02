// Created by Alyssa

#include "Game.h"
#include "UI.h"
#include "Player.h"
#include "Room.h"
#include "Inventory.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>

#define ANSI_GREEN	"\033[92m"
#define ANSI_RESET	"\033[0m"
#define ANSI_BLUE	"\033[94m"

int main()
{
	SetConsoleOutputCP(CP_UTF8); // Ensures correct character encoding
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
		int choice = UI::getMenuChoice();

		switch (choice) {
		case 1:
			game.movePlayer();
			game.displayCurrentRoom();
			break;
		case 2:
			inventory.sort();
			inventory.display();
			break;
		case 3: 
			UI::searchInventory(inventory);
			break;
		case 4: 
			game.handleBattle(inventory);
           	break;
		case 5:
			player.learnSkill(player.getSkillTree().getRoot());
			break;
		case 6:
			player.printBattleLog();
			break;
		case 7:
			if (game.room4->monster == nullptr)
			{
				std::cout << ANSI_BLUE << "\nYou used the Goblin and Orc Keys to escape the Dungeon!" << ANSI_RESET << std::endl;
				playing = false; // Exit the game
			}
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
