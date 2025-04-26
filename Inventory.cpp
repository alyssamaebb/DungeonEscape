#include "escape_game_classes.h"
#include <iostream>
#include <regex>

InventoryNode::InventoryNode(std::string name) {
	itemName = name;
	next = nullptr;
}

Inventory::Inventory() {
	head = nullptr;
}

Inventory::~Inventory() {
	InventoryNode* current = head;
	while (current != nullptr) {
		InventoryNode* nextNode = current->next;
		delete current;
		current = nextNode;
	}
}

void Inventory::addItem(std::string name) {
	InventoryNode* newNode = new InventoryNode(name);
	newNode->next = head;
	head = newNode;
}

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

void Inventory::display() {
	InventoryNode* current = head;
	std::cout << "\nYour Inventory:\n";
	while (current != nullptr) {
		std::cout << "- " << current->itemName << "\n";
		current = current->next;
	}
}

void Inventory::sort() {
	// Bubble sort the linked list
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

bool Inventory::search(std::string name) {
	InventoryNode* current = head;
	while (current != nullptr) {
		if (current->itemName == name) {
			return true;
		}
		current = current->next;
	}
	return false;
}

bool Inventory::regexSearch(std::string pattern) { 
	InventoryNode
}