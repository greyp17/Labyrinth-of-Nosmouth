#pragma once
#include "ITEM.h"

class Armor : public Item {

private:

	std::string type = "armor";
	int defense;

public:

	//Constructor
	Armor(std::string itemName, int defense);

	//Member Functions

	//Getters
	int getArmorDefense();
	std::string getType();

};