#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include "item.h"
using namespace std;

/*
 * This is the Room class. Each room as a description. You can also
 * set exits for this room.
*/
class Room
{
 public:
  Room(); // default constructor
  Room(char*); // constructor with description
  ~Room(); // destructor
  void setExit(char*, Room*); // sets exits in a room
  Room* getExit(char*); // gets location of possible exit
  Item* getItem(char*); // gets item given a description
  void printExits(); // prints out all possible exits
  void printItems(); // prints out items in the room
  map<char*, Room*> exits; // map with <direction, room> of exits
  char* description;
  vector<Item*> roomItems; // vector that holds items
};
#endif
