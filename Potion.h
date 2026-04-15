#pragma once
#include "ITEM.h"
#include "CHARACTER.h"
#include <string>

class Potion : public Item {

private:



public:

	//Constructor
	Potion(std::string itemName, std::string itemType);

	//Member Functions

	//Polymorphism Functions
	void inspect() override;
	void use(Player& player) override;
	std::string drink(Player& player);

	//Getters
	

};