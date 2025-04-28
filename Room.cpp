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