// Created by Alyssa

#ifndef GAME_H
#define GAME_H

#include <map>
#include <string>

class Room;

class Game {
private:
    std::map<std::string, Room*> dungeonMap;
    Room* currentRoom;
public:
    Game();
    ~Game();
    void movePlayer();
    void createDungeon();
    Room* findRoom(const std::string& roomName);
    void displayCurrentRoom();
};

#endif // GAME_H
