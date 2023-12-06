#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"
using namespace std;

Room::Room() // default constructor
{

  description = new char[100];
}

Room::Room(char* newdescription) // constructor with description passed in
{
  description = new char[100];
  strcpy(description, newdescription);
}
Room::~Room() // destructor
{
  delete description;
}
void Room::setExit(char* direction, Room* nextRoom) // set exits of a room
{
  // direction = n/s/e/w and nextRoom = destination
  exits.insert(pair<char*, Room*>(direction, nextRoom));
}
void Room::printExits() // prints all possible exits
{
  // walks through the map of rooms
  for (map<char*, Room*>::iterator it = exits.begin(); it != exits.end(); it++)
    {
      cout << it->first << endl; // prints out the directions
    }
}

// prints out items in the room
void Room::printItems()
{
  for (vector<Item*>::iterator it = roomItems.begin(); it != roomItems.end(); it++)
    {
      cout << (*it)->description << endl; // prints out the description                   
    }
}


// checks if the input command has an exit
Room* Room::getExit(char* input)
{
  cout << "" << endl;
  for(map<char*, Room*>:: iterator it = exits.begin(); it != exits.end(); it++)
    {
      if(strcmp(it->first, input) == 0) // if the direction matches an exit
	{
	  return it->second; // return the room from that exit
	}
    }
  return NULL;
}

// returns an item given a description
Item* Room::getItem(char* input)
{
  cout << "" << endl;
  for(vector<Item*>:: iterator it = roomItems.begin(); it != roomItems.end(); it++)
    {
      if(strcmp((*it)->description, input) == 0) // if the description matches an item     
        {
          return *it; // return the item                  
        }
    }
  return NULL;
}
