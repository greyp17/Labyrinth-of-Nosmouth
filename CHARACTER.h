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
	int defense{0};
	int accuracy{8};
	int damage{6};
	// Need to add ITEMS class before setting up the vector for inventory...

public:
	//Constructor
	Character(std::string characterName);

	//Member Functions
	void takeDamage(int damage);
	void healHealth(int heal);
	void setDefense(int inputDefense);
	void setAccuracy(int inputAccuracy);
	void setDamage(int inputDamage);
	void setHealth(int inputHealth);

	//Need to add stuff for inventory vector



	//Getters
	int getCharacterX();
	int getCharacterY();
	std::string getCharacterName();
	int getHealth();
	int getDefense();
	int getAccuracy();
	int getDamage();
	
};
