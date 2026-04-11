#pragma once
#include "ITEM.h"

class Potion : public Item {

private:

	std::string type = "potion";

public:

	//Constructor
	Potion(std::string itemName);

	//Member Functions

	//Polymorphism Functions
	void inspect() override;
	void use() override;

	//Getters
	std::string getType();

};