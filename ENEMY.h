#pragma once
#include <string>
#include "CHARACTER.h"

class Enemy : public Character {

private:

public:
	//Constructor
	Enemy(std::string playerName);

	//Member Functions
	void generateStats();

	//to get position, health, etc., just use the getters from the Character class
	//e.g. getCharacterX();

	//Getters
};