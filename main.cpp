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

int main()
{
	UI ui;

    	std::string playerName = ui.askPlayerName(); // Ask for player's name first
    	Player player(playerName); // Create player object with that name
	Game game(player); // Create the game object
	Inventory inventory; // Create the inventory for the player

	game.displayCurrentRoom(); // Show the starting room to the player
	std::cout << "\n";

	game.player.unlockSkill("Fireball");
	inventory.addItem("Healing Amulet");
	
	std::cout << ANSI_GREEN << "\nYou have acquired a Healing Amulet!\nMay it bring you luck on your journey..." << ANSI_RESET << std::endl;

	game.start(inventory); // start game loop

	return 0;
}
