// TEAMATE: Kandice Estrella
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
		return;
	}
	else
	{
		std::cout << "No monster in this room." << std::endl;
	}
	// Recursively visit all connected rooms
	for (Room* neighbor : currentRoom->neighbors)
	{
		if (visited.find(neighbor) == visited.end())
		{
			neighbor->dfs(neighbor, visited);
		}
	}
}