#include "Inventory.h"
#include <iostream>
#include <regex>

#define ANSI_WARNING_YELL    "\033[93m"
#define ANSI_RESET           "\033[0m"

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

// Remove an item by name
bool Inventory::removeItem(std::string name) {
    InventoryNode* current = head;
    InventoryNode* previous = nullptr;

    while (current != nullptr) {
        if (current->itemName == name) {
            if (previous == nullptr) {
                head = current->next;
            }
            else {
                previous->next = current->next;
            }
            delete current;
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
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

// Search for an item using a regular expression
bool Inventory::regexSearch(std::string pattern) {
    InventoryNode* current = head;
    std::regex re(pattern);
    while (current != nullptr) {
        if (std::regex_search(current->itemName, re)) return true;
        current = current->next;
    }
    return false;
}
