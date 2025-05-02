// Created by Alyssa

#ifndef UI_H
#define UI_H

#include "Inventory.h"
#include <iostream>
#include <string>
#include <regex>
#include <string>

// Handles user interface display and input gathering
class UI {
public:
    std::string askPlayerName();
    static void displayMainMenu(); // Show the main game meny options
    static int getMenuChoice(); // Get the user's selected menu options
    static void searchInventory(Inventory& inventory); 
    static void displayExitMessage();
};

#endif // UI_H
