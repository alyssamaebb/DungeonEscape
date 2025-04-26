#include "escape_game_classes.h"
#include <iostream>

using namespace std;

int main()
{
	Game game; // Create game object

	game.displayCurrentRoom(); // Show starting room
	
	bool playing = true;
	while (playing) {
		std::cout << "\nWhat would  you like to do?\n";
		std::cout << "1. Move to another room\n";
		std::cout << "2. Quit game\n";
		std::cout << "Choice: ";
		int choice;
		std::cin >> choice;

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