// Created by Alyssa

#include "UI.h"
#include <iostream>
#include <string>
#include <regex>

#define ANSI_RESET        "\033[0m"
#define ANSI_BLOOD_RED    "\033[91m"
#define ANSI_BRIGHT_WHITE "\033[97m"
#define ANSI_WARNING_YELL "\033[93m"

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
	int choice;
	std::cout << ANSI_WARNING_YELL "\nEnter your choice: " ANSI_RESET;
	std::cin >> choice;
	return choice;
}

void UI::searchInventory(Inventory& inventory) {
    std::cin.ignore();
    std::string pattern;
    std::cout << "\nEnter a keyword or pattern to search for items: ";
    std::getline(std::cin, pattern);

    inventory.regexSearch(pattern);
}
