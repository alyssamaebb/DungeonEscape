#include "Inventory.h"
#include "AnsiColors.h"
#include <iostream>
#include <regex>

// InventoryNode constructor
InventoryNode::InventoryNode(std::string name) {
    itemName = name;
    next = nullptr;
}

// Inventory constructor
Inventory::Inventory() {
    head = nullptr;
}

// Inventory destructor: deletes all inventory
Inventory::~Inventory() {
    InventoryNode* current = head;
    while (current != nullptr) {
        InventoryNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// Add a new item to the inventory
void Inventory::addItem(std::string name) {
    InventoryNode* newNode = new InventoryNode(name);
    newNode->next = head;
    head = newNode;
}

// Display all items in the inventory
void Inventory::display() {
    InventoryNode* current = head;
    std::cout << "\n" << "====================================\n";
    std::cout << ANSI_WARNING_YELL << "         Your Inventory\n" << ANSI_RESET;
    std::cout << "====================================" << "\n";
    while (current != nullptr) {
        std::cout << "- " << current->itemName << "\n";
        current = current->next;
    }
}

// Sort the inventory using a simple bubble sort
void Inventory::sort() {
    if (!head || !head->next) return;

    bool swapped;
    do {
        swapped = false;
        InventoryNode* current = head;
        while (current->next != nullptr) {
            if (current->itemName > current->next->itemName) {
                std::swap(current->itemName, current->next->itemName);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

// Search for items using a regular expression and display matching names
bool Inventory::regexSearch(std::string pattern) {
    InventoryNode* current = head;
    bool found = false;
    
        std::regex re(pattern, std::regex_constants::icase);

        std::cout << "\nMatching items:\n";

        while (current != nullptr) {
            if (std::regex_search(current->itemName, re)) {
                std::cout << "- " << current->itemName << "\n";
                found = true;
            }
            current = current->next;
        }

        if (!found) {
            std::cout << "No items matched your search.\n";
        }

    return found;
}
