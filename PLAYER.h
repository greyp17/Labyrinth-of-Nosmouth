#pragma once
#include <vector>
#include <string>
#include "CHARACTER.h"
#include "Inventory.h"

class Player : public Character {

private:
	Inventory inventory;

public:
	//Constructor
	Player(std::string playerName);

	//Member Functions
	void invAdd(Item* item);

	//to get position, health, etc., just use the getters from the Character class
	//e.g. getCharacterX();

	//Getters
};