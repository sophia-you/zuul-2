#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include "room.h"
using namespace std;

int main()
{
  // HOUSEKEEPING
  vector<Room*> roomList;
  bool playing = true; // determines if the program is running

  // DIRECTIONS
  char* north = new char[100];
  char* south = new char[100];
  char* east = new char[100];
  char* west = new char[100];
  strcpy(north, "north");
  strcpy(south, "south");
  strcpy(east, "east");
  strcpy(west, "west");
  // ROOMS AND ROOM DESCRIPTIONS
  // chow mein noodle house
  char* chowmeinDescription = new char[100];
  strcpy(chowmeinDescription, "You are in the Chow Mein noodle house.");
  Room* chowmein = new Room(chowmeinDescription);
  roomList.push_back(chowmein);

  // rice cake stall
  char* ricecakeDescription = new char[100];
  strcpy(ricecakeDescription, "You have arrived at the rice cake food stall.");
  Room* ricecake = new Room(ricecakeDescription);
  roomList.push_back(ricecake);

  // ramen restaurant
  char* ramenDescription = new char[100];
  strcpy(ramenDescription, "You have walked inside the ramen restaurant.");
  Room* ramen = new Room(ramenDescription);
  roomList.push_back(ramen);

  // sesame ball stall
  char* sesameDescription = new char[100];
  strcpy(sesameDescription, "You have arrived at the sesame ball food stall.");
  Room* sesame = new Room(sesameDescription);
  roomList.push_back(sesame);

  // pancake stall
  char* pancakeDescription = new char[100];
  strcpy(pancakeDescription, "You have arrived at the pancake food stall.");
  Room* pancake = new Room(pancakeDescription);
  roomList.push_back(pancake);

  // spring roll stall
  char* springrollDescription = new char[100];
  strcpy(springrollDescription, "You have arrived at the spring roll food stall.");
  Room* springroll = new Room(springrollDescription);
  roomList.push_back(springroll);

  // wonton stall
  char* wontonDescription = new char[100];
  strcpy(wontonDescription, "You have arrived at the wonton food stall.");
  Room* wonton = new Room(wontonDescription);
  roomList.push_back(wonton);

  // pho restaurant
  char* phoDescription = new char[100];
  strcpy(phoDescription, "You have entered the pho restuarant.");
  Room* pho = new Room(phoDescription);
  roomList.push_back(pho);

  // central park
  char* parkDescription = new char[100];
  strcpy(parkDescription, "You have stepped outside into Central Park. Wild animals roam free in the bamboo forest.");
  Room* park = new Room(parkDescription);
  // udon restaurant
  char* udonDescription = new char[100];
  strcpy(udonDescription, "You have entered the Grand Udon Restaurant.");
  Room* udon = new Room(udonDescription);
  roomList.push_back(udon);

  // tofu palace
  char* tofuDescription = new char[100];
  strcpy(tofuDescription, "You are in the largest restaurant at the Dragon's Market, Tofu Palace.");
  Room* tofu = new Room(tofuDescription);

  // entrance
  char* entranceDescription = new char[100];
  strcpy(ricecakeDescription, "You stand at the entrance of the Dragon's Market.");
  strcpy(entranceDescription, "You stand at the entrance of the Dragon's Market.");
  Room* entrance = new Room(entranceDescription);
  roomList.push_back(entrance);

  // dumpling house
  char* dumplingDescription = new char[100];
  strcpy(dumplingDescription, "You have arrived at the most popular restaurant in the Market, the Dumpling House.");
  Room* dumpling = new Room(dumplingDescription);
  roomList.push_back(dumpling);

  // bathroom
  char* bathroomDescription = new char[100];
  strcpy(bathroomDescription, "You have entered a small, dirty room with an old toilet. It is the bathroom.");
  Room* bathroom = new Room(bathroomDescription);
  roomList.push_back(bathroom);

  // bakery
  char* bakeryDescription = new char[100];
  strcpy(bakeryDescription, "You have arrived at the Fresh Bread Bakery, which sells a variety of aromatic baked goods.");
  Room* bakery = new Room(bakeryDescription);
  roomList.push_back(bakery);

  // EXITS
  chowmein->setExit(east, ricecake);
  chowmein->setExit(south, springroll);
  
  ricecake->setExit(west, chowmein);
  ricecake->setExit(east, ramen);
  ramen->setExit(west, ricecake);
  ramen->setExit(south, park);
  ramen->setExit(east, sesame);
  sesame->setExit(west, ramen);
  sesame->setExit(south, pancake);
  pancake->setExit(north, sesame);
  pancake->setExit(south, udon);
  springroll->setExit(north, chowmein);
  springroll->setExit(south, wonton);
  wonton->setExit(north, springroll);
  wonton->setExit(east, pho);
  pho->setExit(west, wonton);
  pho->setExit(south, tofu);
  pho->setExit(east, park);
  park->setExit(north, ramen);
  park->setExit(west, pho);
  park->setExit(south, entrance);
  park->setExit(east, udon);

  udon->setExit(west, park);
  udon->setExit(north, pancake);
  udon->setExit(south, bakery);

  tofu->setExit(north, pho);
  tofu->setExit(east, entrance);

  entrance->setExit(north, park);
  entrance->setExit(west, tofu);
  entrance->setExit(east, dumpling);

  dumpling->setExit(west, entrance);

  bathroom->setExit(east, bakery);

  bakery->setExit(north, udon);
  bakery->setExit(east, bathroom);

  // ITEMS
  char* thingDescription = new char[10];
  strcpy(thingDescription, "thing");
  Item* thing = new Item(thingDescription);
  cout << thing->description << endl;
  // current room
  Room* currentRoom = new Room();
  currentRoom = entrance; 

  while(playing)
    {
      cout << "Welcome to the Dragon Marketplace!" << endl;
      cout << "A small panda has been abandoned somewhere in this area. He must be rescued and fed. Your task is to find the panda and feed him with four food items around the marketplace." << endl;
      cout << "Your commands are:\tgo\tget\tdrop\tquit" << endl;
      cout << "" << endl;
      cout << currentRoom->description << endl; // print room description

      cout << "EXITS" << endl; // show possible exits
      currentRoom->printExits();
      cout << " " << endl;
      
      cout << "What do you want to do?" << endl; // example input: "go west"

      char firstCommand[10]; // command, ex/ get, drop, go
      char secondCommand[20]; // location or object, ex/ west, panda

      cin >> firstCommand;

      if (strcmp(firstCommand, "quit") == 0) // if the command is "quit', we don't need a second command
	{
	  playing = false; // exit the while loop
	}
      else // we need to find out WHERE to go, WHAT to get/drop, etc
	{
	  cin >> secondCommand;
	  if (strcmp(firstCommand, "go") == 0)
	    {
	      currentRoom = currentRoom->getExit(secondCommand);
	      cout << currentRoom->description << endl;
	    }
	}
    }

}

