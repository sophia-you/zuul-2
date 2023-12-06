#include <iostream>
#include <cstring>
#include "room.h"
#include "item.h"
using namespace std;

Item::Item() // default constructor
{
  description = new char[100];
}

Item::Item(char* newdescription) // you can set the description
{
  description = new char[100];
  strcpy(description, newdescription);
}

Item::~Item() // destructor
{
  delete description;
}
