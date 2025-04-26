// Created by Alyssa

#include "Game.h"
#include "UI.h"
#include "Player.h"
#include <iostream>

int main()
{
	Game game; // Create the game object
	Player player; // Create the player object
	
	game.displayCurrentRoom(); // Show the starting room to the player
	
	bool playing = true;
	while (playing) {
		UI::displayMainMenu(); // Display the main menu
		int choice = UI::getMenuChoice(); // Get the user's menu choice

		switch (choice) {
		case 1:
			game.movePlayer(); // Move to another room
			break;
		case 2:
			player.showInventory(); // Display the player's inventory
			break;
		case 3: 
			std::cout << "(Simple battle logic not fully implemented yet)\n";
			break;
		case 4: 
			player.learnSkill(player.getSkillTree()->getRoot()); // Learn a new skill
			break;
		case 5:
			player.printBattleLog(); // View battle log
			break;
		case 6:
			std::cout << "Thank you for playing Escape Game!\n";
			playing = false; // Exit the game
			break;
		default:
			std::cout << "Invalid choice. Please try again.\n";
		}
	}

	return 0;
}
