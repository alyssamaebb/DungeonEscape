// Created by Alyssa

#include <iostream>
#include "UI.h"

void UI::displayMainMenu() {
	std::cout << "\n====== Escape Game Menu ======\n";
	std::cout << "1. Move to another room\n";
	std::cout << "2. View Inventory\n";
	std::cout << "3. Battle (if monster in room)\n";
	std::cout << "4. Learn a Skill\n";
	std::cout << "5. View Battle Log\n";
	std::cout << "6. Exit Game\n";
}
