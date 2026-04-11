#pragma once
#include <vector>
#include <string>
#include "CHARACTER.h"
#include "Inventory.h"

class Player : public Character {

private:
	//unique player attributes: inventory (doesn't work until item is defined)
	Inventory inventory;


public:
	//Constructor
	Player(std::string playerName, Inventory inventory);

	//Member Functions
	void setInventory(Inventory inventory);
	Inventory getInventory();

	//to get position, health, etc., just use the getters from the Character class
	//e.g. getCharacterX();

	//Getters
};