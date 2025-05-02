// Created by Alyssa

#include "UI.h"
#include "AnsiColors.h"

#include <iostream>
#include <regex>

std::string UI::askPlayerName() {
    std::string name;
    std::cout << "\n\033[93mBefore your journey begins...\n";
    std::cout << "What is your name, brave adventurer?\n> \033[0m";
    std::getline(std::cin, name);

    if (name.empty()) {
        name = "Unnamed Hero";  // Fallback default
    }

    return name;
}

// Display the main menu options for the player
void UI::displayMainMenu() {
	std::cout << ANSI_BRIGHT_WHITE "\n====== Escape Game Menu ======\n" ANSI_RESET;
	std::cout << ANSI_BLOOD_RED "1. Move to another room\n" ANSI_RESET;
	std::cout << ANSI_BLOOD_RED "2. View Inventory\n" ANSI_RESET;
	std::cout << ANSI_BLOOD_RED "3. Search Inventory\n" ANSI_RESET;
	std::cout << ANSI_BLOOD_RED "4. Battle (if monster in room)\n" ANSI_RESET;
	std::cout << ANSI_BLOOD_RED "5. Learn a Skill\n" ANSI_RESET;
	std::cout << ANSI_BLOOD_RED "6. View Battle Log\n" ANSI_RESET;
	std::cout << ANSI_BRIGHT_WHITE "7. Exit Game\n" ANSI_RESET;
}

// Get the player's menu choice
int UI::getMenuChoice() {
	bool check = true;
	int choice;
	while (check)
	{
		std::cout << ANSI_WARNING_YELL "\nEnter your choice: " ANSI_RESET;
		std::cin >> choice;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid choice. Please try again.\n";
		}
		else
		{
			break;
		}
	}
	return choice;
}

void UI::searchInventory(Inventory& inventory) {
    std::cin.ignore();
    std::string pattern;
    std::cout << "\nEnter a keyword or pattern to search for items: ";
    std::getline(std::cin, pattern);

    inventory.regexSearch(pattern);
}

void UI::displayExitMessage() {
	std::cout << "==================================================\n";
	std::cout << "Thank you for playing Dungeon Escape Game!\n";
}
