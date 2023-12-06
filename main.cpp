#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include "room.h"
using namespace std;


/*
 * Author: Sophia You
 * Date: 12/5/2023
 * Description: Zuul is a text-based adventure game. The user puts commands into
 * the command like like "go west," and the program responds by providing a 
 * description of the new room. There are items in many of the rooms that the
 * user can interact with by getting or dropping them.
 * In this game, you must collect all five items and store them in your inventory
 * to win.
 */
int main()
{
  // HOUSEKEEPING
  vector<Room*> roomList; // list of rooms
  vector<Item*> inventory; // player inventory
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

  int numItems = 5;
  
  // panda
  char* pandaDescription = new char[10];
  strcpy(pandaDescription, "panda");
  Item* panda = new Item(pandaDescription);
  (park->roomItems).push_back(panda);

  // tofu
  char* tofuFoodDescription = new char[10];
  strcpy(tofuFoodDescription, "tofu");
  Item* tofuFood = new Item(tofuFoodDescription);
  (tofu->roomItems).push_back(tofuFood);

  // rice cake
  char* cakeDescription = new char[10];
  strcpy(cakeDescription, "ricecake");
  Item* cake = new Item(cakeDescription);
  (ricecake->roomItems).push_back(cake);

  // udon
  char* udonNoodleDescription = new char[10];
  strcpy(udonNoodleDescription, "udon");
  Item* udonNoodle = new Item(udonNoodleDescription);
  (udon->roomItems).push_back(udonNoodle);

  // pancakes
  char* pancakesDescription = new char[10];
  strcpy(pancakesDescription, "pancakes");
  Item* pancakes  = new Item(pancakesDescription);
  (pancake->roomItems).push_back(pancakes);
  
  // current room
  Room* currentRoom = new Room();
  currentRoom = entrance; 

  cout << "Welcome to the Dragon Marketplace!" << endl;
  cout << "A small panda has been abandoned somewhere in this area. He must be rescued and fed. Your task is to find the panda and feed him with four food items around the marketplace." << endl;
  cout << "INSTRUCTIONS: find the panda and four other food items and put them in your inventory." << endl;
      cout << "Your commands are:\tgo\tget\tdrop\tinventory\tquit\thelp" << endl;
      
  while(playing) // while the game is still going
    {
      
      cout << "" << endl;
      cout << currentRoom->description << endl; // print room description

      cout << "EXITS" << endl; // show possible exits
      currentRoom->printExits();
      cout << "" << endl;
      cout << "ITEMS" << endl; // show items in the room
      currentRoom->printItems();
      cout << " " << endl;
      
      cout << "What do you want to do?" << endl; // example input: "go west"

      char firstCommand[10]; // command, ex/ get, drop, go
      char secondCommand[20]; // location or object, ex/ west, panda

      cin >> firstCommand;

      if (strcmp(firstCommand, "quit") == 0) // if the command is "quit', we don't need a second command
	{
	  playing = false; // exit the while loop
	}
      else if (strcmp(firstCommand, "help") == 0)
	{
	  // repeat intro text
	  cout << "INSTRUCTIONS: find the panda and four other food items and put them in your inventory." << endl;
      cout << "Your commands are:\tgo\tget\tdrop\tinventory\tquit\thelp" << endl;
	}
      else if (strcmp(firstCommand, "inventory") == 0)
	{
	  cout << "" << endl;
	  cout << "INVENTORY" << endl;
	  for(vector<Item*>:: iterator it = inventory.begin(); it != inventory.end(); it++)
	    {
	      cout << (*it)->description << endl;
	    }
	  cout << "" << endl;
	}
      else // we need to find out WHERE to go, WHAT to get/drop, etc
	{
	  cin >> secondCommand;
	  if (strcmp(firstCommand, "go") == 0) // change rooms
	    {
	      currentRoom = currentRoom->getExit(secondCommand);
	    }
	  else if (strcmp(firstCommand, "get") == 0)
	    {
	      // add item to inventory and remove from room
	      Item* currentItem = currentRoom->getItem(secondCommand);
	      inventory.push_back(currentItem);

	      // walk through room vector and find the item's location, then remove
	      for(vector<Item*>:: iterator it = currentRoom->roomItems.begin(); it != currentRoom->roomItems.end(); it++)
		{
		  // find item in the vector
		  if(strcmp((*it)->description, currentItem->description) == 0)
		    {
		      (currentRoom->roomItems).erase(it); // erase from the room vector
		      break; // for future sophia: if you forget the break statement you're going to have a segmentation fault
		    }
		}
	    }
	  
	  else if (strcmp(firstCommand, "drop") == 0) // drop an item from inventory into room
	    {
	      // add item to room and remove from inventory                                     
              Item* currentItem = NULL;
	      for(vector<Item*>:: iterator it = inventory.begin(); it != inventory.end(); it++)
                {
		  // find the requested item that matches an item in inventory
		  if (strcmp(secondCommand, (*it)->description) == 0)
		    {
		      currentItem = (*it); // select the current item
		      inventory.erase(it); // remove from inventory
		      break;
		    }
		}
	      currentRoom->roomItems.push_back(currentItem); // add to room
	    }
	}

      // if all five items (panda + food) have been collected, the game is over
      if (inventory.size() == numItems)
	{
	  cout << "Congratulations! You have successfully fed the panda. The game is now over." << endl;
	  playing = false; // break out of the while loop
	}
    }

  // delete stuff created on the heap
  for(vector<Room*>:: iterator it = roomList.begin(); it != roomList.end(); it++)
    {
      delete (*it)->description;
      delete (*it);
      roomList.erase(it);
    }
  
    for(vector<Room*>:: iterator it = inventory.begin(); it != inventory.end(); it++)
    {
      delete (*it);
      inventory.erase(it);
    }

}

