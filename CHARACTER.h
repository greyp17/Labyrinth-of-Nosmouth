//Character defines any character that has attributes like health etc. whether it be the player or enemy.
#pragma once
#include <vector>
#include <string>
#include "ITEM.h"

class Character {

private:
	std::string name;
	int xPosition{0};
	int yPosition{0};
	int health{100};
	// Need to add ITEMS class before setting up the vector for inventory...
	Item inventory;

public:
	//Constructor
	Character(std::string characterName);

	//Member Functions
	void takeDamage(int damage);
	void healHealth(int heal);
	//Need to add stuff for inventory vector


	//Getters
	int getCharacterX();
	int getCharacterY();
	std::string getCharacterName();
	int getCharacterHP();
	
};