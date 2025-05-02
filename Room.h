// TEAMATE: Kandice Estrella
#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <string>

class Monster; // Forward declaration

//---------------------------------------------
// Room (Graph Node)
//---------------------------------------------
class Room {
public:
    std::string name;
    std::string description;
    std::vector<Room*> neighbors;
    Monster* monster;

    Room(std::string n, std::string desc);
    void connect(Room* other);
    void setMonster(Monster* m);
    void removeMonster();
};

#endif
