// Inventory.h
#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>

// Represents a single item node in the inventory linked list
class InventoryNode {
public:
    std::string itemName; // Name of the item
    InventoryNode* next; //  Pointer to the next item

    InventoryNode(std::string name);
};

// Manages a linked list of inventory items
class Inventory {
private:
    InventoryNode* head; // Head of the linked list
public:
    Inventory();
    ~Inventory();
    
    void addItem(std::string name); // Add an item to inventory
    bool removeItem(std::string name); // Remove an item by name
    void display(); // Display all items in inventory
    void sort(); // Sort inventory items alphabetically
    bool search(std::string name); // Search for an item by name
    bool regexSearch(std::string pattern); // Search for an item using regex pattern
};

#endif // INVENTORY_H
