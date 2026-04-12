#pragma once
#include <string>
#include "CHARACTER.h"
#include "Inventory.h"
#include "ITEM.h"

class Player : public Character {

private:
	Inventory inventory;

public:
	//Constructor
	Player(std::string playerName);

	//Member Functions
	void invAdd(Item* item);

	Inventory& getInventory();
	

	//to get position, health, etc., just use the getters from the Character class
	//e.g. getCharacterX();

	//Getters
};