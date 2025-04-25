#include "escape_game_classes.h"
#include "Room.h"

Room::Room(std::string n, std::string desc)
{
	name = n;
	description = desc;
	monster = nullptr;
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

void Room::setMonster(Monster* m)
{
	monster = m;
}

void Room::removeMonster()
{
	monster = nullptr;
}

void Room::dfs(Room* currentRoom, std::unordered_set<Room*>& visited)
{
	// Mark the current room as visited
	visited.insert(currentRoom);
	std::cout << "Visited: " << currentRoom->name << std::endl;
	// Check if the room contains a monster
	if (currentRoom->monster != nullptr)
	{
		std::cout << "Monster in room: " << currentRoom->name << std::endl;
	}
	else
	{
		std::cout << "No monster in this room." << std::endl;
	}
	// Recursively visit all connected rooms
	for (Room* neighbor : currentRoom->neighbors) //May need to move this to inside else block to only call recursively if monster not found
	{
		if (visited.find(neighbor) == visited.end())
		{
			neighbor->dfs(neighbor, visited);
		}
	}
}

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
/*
//----------------------------------------------
// Example Adding and Removing Monsters
//----------------------------------------------
{
	// Create monsters
	Monster* monster1 = new Monster("Goblin", 30, 5);
	Monster* monster2 = new Monster("Orc", 50, 10);
	// Set monsters in rooms
	room3->setMonster(monster1);
	room4->setMonster(monster2);
	// Remove monsters from rooms
	room3->removeMonster();
	room4->removeMonster();
}
*/