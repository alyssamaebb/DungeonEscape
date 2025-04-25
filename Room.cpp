#include "escape_game_classes.h"

Room::Room(std::string n, std::string desc)
{
	name = n;
	description = desc;
	monster = NULL;
}
// Function to connect dungeon rooms as an undirected graph
void Room::connect(Room* other)
{
	// Avoid connecting the same room to itself
	if (this == other) return;
	// Connect the other room to this room if it is not already connected
	if (std::find(neighbors.begin(), neighbors.end(), other) == neighbors.end())
	{
		neighbors.push_back(other);
	}
	// Connect this room to the other room if it is not already connected
	if (std::find(other->neighbors.begin(), other->neighbors.end(), this) == other->neighbors.end())
	{
		other->neighbors.push_back(this);
	}
}
// Function to set the monster in the room


//---------------------------------------------
// Example Room Creation in main.cpp
//---------------------------------------------
/*
{
	// Create rooms
	Room* room1 = new Room("Entrance", "You are at the entrance of the dungeon.");
	Room* room2 = new Room("Inventory", "Select your starting weapons.");
	Room* room3 = new Room("Monster Lair 1", "A lair of a fearsome monster.");
	Room* room4 = new Room("Monster Lair 2", "A lair of a fearsome monster.");
	Room* room5 = new Room("Exit", "A hidden chamber with ancient artifacts.");
	// Connect rooms at the start of the game
	room1->connect(room2);
}
// Connect rooms in the dungeon
	room1->connect(room3);
*/