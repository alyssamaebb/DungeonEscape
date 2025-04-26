// TEAMATE: Kandice Estrella, Joshua Seepersaud
#include "escape_game_classes.h"
#include "Monster.h"

Monster::Monster(std::string n, int h, int a)
{
	name = n;
	hp = h;
	attack = a;
}
void Monster::battle(Player& player)
{
	std::cout << "The monster hit you with an attack!" << std::endl;
	//This is where the player's health should decrease
}