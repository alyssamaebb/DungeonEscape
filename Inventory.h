// Inventory.h
#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>

class InventoryNode {
public:
    std::string itemName;
    InventoryNode* next;

    InventoryNode(std::string name);
};

class Inventory {
private:
    InventoryNode* head;
public:
    Inventory();
    ~Inventory();
    
    void addItem(std::string name);
    bool removeItem(std::string name);
    void display();
    void sort();
    bool search(std::string name);
    bool regexSearch(std::string pattern);
};

#endif // INVENTORY_H
