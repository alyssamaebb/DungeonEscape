// Created by Alyssa

#ifndef ESCAPE_GAME_CLASSES_H
#define ESCAPE_GAME_CLASSES_H

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <regex>
#include <unordered_set>

// Forward declarations
class Room;
class Monster;
class Inventory;
class TreeNode;
class Player;
class Game;
class UI;

//---------------------------------------------
// Template Utility Functions
//---------------------------------------------
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
int search(T arr[], int size, T key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) return i;
    }
    return -1;
}

#endif // ESCAPE_GAME_H
