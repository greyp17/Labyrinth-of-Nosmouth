#pragma once
#include "ITEM.h"
#include "CHARACTER.h"
#include <string>

class Armor : public Item {

private:

	int defense;

public:

	//Constructor
	Armor(std::string itemName, std::string itemType, int defense);

	//Member Functions

	//Polymorphism Functions
	void inspect() override;
	void use(Player& player) override;

	//Getters
	int getDefense();

};