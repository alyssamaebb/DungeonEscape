// Created by Alyssa

#include <iostream>
#include "UI.h"

#define ANSI_RESET        "\033[0m"
#define ANSI_BLOOD_RED    "\033[91m"
#define ANSI_BRIGHT_WHITE "\033[97m"
#define ANSI_WARNING_YELL "\033[93m"

// Display the main menu options for the player
void UI::displayMainMenu() {
	std::cout << ANSI_BRIGHT_WHITE "\n====== Escape Game Menu ======\n" ANSI_RESET;
	std::cout << ANSI_BLOOD_RED "1. Move to another room\n" ANSI_RESET;
	std::cout << ANSI_BLOOD_RED "2. View Inventory\n" ANSI_RESET;
	std::cout << ANSI_BLOOD_RED "3. Battle (if monster in room)\n" ANSI_RESET;
	std::cout << ANSI_BLOOD_RED "4. Learn a Skill\n" ANSI_RESET;
	std::cout << ANSI_BLOOD_RED "5. View Battle Log\n" ANSI_RESET;
	std::cout << ANSI_BRIGHT_WHITE "6. Exit Game\n" ANSI_RESET;
}

// Get the player's menu choice
int UI::getMenuChoice() {
	int choice;
	std::cout << ANSI_WARNING_YELL "\nEnter your choice: " ANSI_RESET;
	std::cin >> choice;
	return choice;
}
