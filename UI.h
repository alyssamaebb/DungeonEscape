// Created by Alyssa

#ifndef UI_H
#define UI_H

#include <string>
#include "Inventory.h"

// Handles user interface display and input gathering
class UI {
public:
    std::string askPlayerName();
    static void displayMainMenu(); // Show the main game meny options
    static int getMenuChoice(); // Get the user's selected menu options
    static void displaySearchInventoryOption();
    static void searchInventory(Inventory& inventory); 
};

#endif // UI_H
