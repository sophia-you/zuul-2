#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <cstring>
#include "room.h"
using namespace std;

// this is the item class. Each item has a descripton
class Item
{
 public:
  Item(); // default constructor
  Item(char*); // constructor with description
  ~Item(); // destructor
  char* description; // item description
};
#endif
