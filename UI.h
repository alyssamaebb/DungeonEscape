// Created by Alyssa

#ifndef UI_H
#define UI_H

#include <string>

// Handles user interface display and input gathering
class UI {
public:
    static void displayMainMenu(); // Show the main game meny options
    static int getMenuChoice(); // Get the user's selected menu options
    std::string askPlayerName();
};

#endif // UI_H
