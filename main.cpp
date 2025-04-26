// Created by Alyssa

#include "Game.h"
#include "UI.h"
#include <iostream>

int main()
{
	Game game; // Create game object

	game.displayCurrentRoom(); // Show the starting room
	
	bool playing = true;
	while (playing) {
		UI::displayMainMenu(); // Show the menu
		int choice = UI::getMenuChoice(); // Get the user's choice

		switch (choice) {
		case 1:
			game.movePlayer(); // Move to another room
			break;
		case 2:
			std::cout << "Thank you for playing Escape Game!\n";
			playing = false; // Exit the game
			break;
		default:
			std::cout << "Invalid choice. Please try again.\n";
		}
	}

	return 0;
}
