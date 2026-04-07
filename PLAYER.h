#pragma once
#include <vector>
#include <string>

class Player {

private:

	std::string name;
	int xPosition{0};
	int yPosition{0};
	int health{100};
	// Need to add ITEMS class before setting up the vector for inventory...

public:

	//Constructor
	Player(std::string playerName);

	//Member Functions
	//Need to add takedamage
	void takeDamage(int damage);
	void healHealth(int heal);
	//Need to add stuff for inventory vector


	//Getters
	int getPlayerX();
	int getPlayerY();
	std::string getPlayerName();
	int getPlayerHP();
	
};
