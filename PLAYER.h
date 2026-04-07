#pragma once
#include <vector>
#include <string>

class Player {

private:

	std::string name;
	int xPosition{0};
	int yPosition{0};
	// Need to add playerhealth
	// Need to add ITEMS class before setting up the vector for inventory...

public:

	//Constructor
	Player(std::string playerName);

	//Member Functions
	//Need to add takedamage
	//Need to add stuff for inventory vector


	//Getters
	int getPlayerX();
	int getPlayerY();
	std::string getPlayerName();
	// need to add getter for playerhealth
};
